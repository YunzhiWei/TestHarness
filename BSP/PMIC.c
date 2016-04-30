#include "_Platform.h"

#ifdef INCLUDE_MODULE_PMIC

#define REG_SET_SIZE                    2
#define REG_SET_SIZE_SHIFT              1
typedef U8                              RegSet_t[REG_SET_SIZE];

static int RegSet(const RegSet_t *pRegSet, U32 dwCount)
{
    return(I2C_Write(DA9034_I2C_ADDRESS, (U8*)pRegSet, (dwCount << REG_SET_SIZE_SHIFT), 1));
}

static int PageRead(U8 bRegAddr, U8 *pValue, U32 dwSize)
{
    int ret;

    if((ret = I2C_Write(DA9034_I2C_ADDRESS, &bRegAddr, 1, 1)) != ERR_CODE_SUCCESS)
    {
        return(ret);
    }

    if((ret = I2C_Read(DA9034_I2C_ADDRESS, pValue, dwSize, 1)) != ERR_CODE_SUCCESS)
    {
        return(ret);
    }

    return(ERR_CODE_SUCCESS);
}

#define BIT_OP_MAX_COUNT                4

static int RegBitSet(U8 bRegAddr, const U8* pSetting, U32 dwCount)
{
    RegSet_t setting[BIT_OP_MAX_COUNT];
    U8       value[BIT_OP_MAX_COUNT];
    U32      i;

    if((dwCount == 0) || (dwCount > 4)) return(ERR_CODE_PMIC_PARAMETER);

    PageRead(bRegAddr, value, dwCount);

    for(i=0;i<dwCount;i++)
    {
        setting[i][0] = bRegAddr + i;
        setting[i][1] = value[i] | pSetting[i];
    }
    RegSet((const RegSet_t *)setting, dwCount);
}

static int RegBitClear(U8 bRegAddr, const U8* pClearing, U32 dwCount)
{
    RegSet_t setting[BIT_OP_MAX_COUNT];
    U8       value[BIT_OP_MAX_COUNT];
    U32      i;

    if((dwCount == 0) || (dwCount > 4)) return(ERR_CODE_PMIC_PARAMETER);

    PageRead(bRegAddr, value, dwCount);

    for(i=0;i<dwCount;i++)
    {
        setting[i][0] = bRegAddr + i;
        setting[i][1] = value[i] & (~pClearing[i]);
    }
    RegSet((const RegSet_t *)setting, dwCount);
}

void PMIC_SetReg(U8 bRegAddr, U8 bRegVal)
{
    RegSet_t setting[] = {
        {0, 0}
    };

    setting[0][0] = bRegAddr;
    setting[0][1] = bRegVal;

    RegSet((const RegSet_t*)setting, sizeof(setting)/sizeof(RegSet_t));
}

void PMIC_LDOEnableOnSleep(void)
{
    const RegSet_t setting[] =
    {
        {DA9034_LDO_nSLEEP_1, 0},
        {DA9034_LDO_nSLEEP_2, 0}
    };

    if(ERR_CODE_SUCCESS != RegSet(setting, sizeof(setting)/sizeof(RegSet_t))) DBG_BreakPoint("PMIC_LDOEnableOnSleep");
}

void PMIC_Backlight(U8 bPersentage)
{
    RegSet_t setting[] =
    {
        {DA9034_WLED_CONTROL_1, 0},
        {DA9034_WLED_CONTROL_2, 0}
    };

    setting[0][1] = WLED_CONTROL_1_WLED_PWM(bPersentage);
    if(bPersentage == 0)
    {
        setting[1][1] = 0;
    }
    else
    {
        setting[1][1] = WLED_CONTROL_2_BOOST_ENABLE | WLED_CONTROL_2_WLED_ISET(0x0E);
    }

    RegSet((const RegSet_t *)setting, sizeof(setting)/sizeof(RegSet_t));
}

U8 PMIC_GetStatus(PMIC_Status_t tID)
{
/*
    Please refer to PMIC_Status_t !!!
*/
    U8  regAddr[] = {DA9034_STATUS_A, DA9034_STATUS_B};
    U8  s;
    int ret;

    while((ret = PageRead(regAddr[tID], &s, 1)) != ERR_CODE_SUCCESS)
    {
        MY_TraceStrLine("SA ERR");
        ErrCodeDisplay(ret);
    }

    return(s);
}

U32 PMIC_GetEvent(void)
{
    U32 evt;
    int ret;

    while((ret = PageRead(DA9034_EVENT_A, (U8*)(&evt), sizeof(evt))) != ERR_CODE_SUCCESS)
    {
        MY_TraceStrLine("GE ERR");
        ErrCodeDisplay(ret);
    }

    return(evt);
}

U32 PMIC_GetMask(void)
{
    U32 evt;

    if(PageRead(DA9034_nIRQ_MASK_A, (U8*)(&evt), sizeof(evt)) == FALSE)
    {
        MY_TraceStrLine("ERR: I2C");
        return((U8)(-1));
    }

    return(evt);
}

void PMIC_INTEnable(U32 dwEnable)
{
    RegBitClear(DA9034_nIRQ_MASK_A, (U8*)(&dwEnable), 4);
}

void PMIC_INTDisable(U32 dwDisable)
{
    RegBitSet(DA9034_nIRQ_MASK_A, (U8*)(&dwDisable), 4);
}

static void WatchdogDisable(void)
{
    const U8 setting[1]  = {SYS_CTRL_A_WATCHDOG};
    const U8 clearing[1] = {SYS_CTRL_A_WATCHDOG_ENABLE};

    RegBitSet(DA9034_SYS_CTRL_A,   setting,  1);
    RegBitClear(DA9034_SYS_CTRL_A, clearing, 1);
}

// DA9034 ADC

// !!! Pay attention to the conflict among the same registers' using !!!

static U32 g_dwADCPowerUserCounter;
void PMIC_ADCPowerON(void)
{
    const RegSet_t setting[] = {
        {DA9034_ADC_MAN_CONTROL,   ADC_MAN_CONTROL_LDO_ADC_ENABLE},
    };

    RegSet(setting, sizeof(setting)/sizeof(RegSet_t));
    g_dwADCPowerUserCounter++;

    DBG_TraceDec("User CNT", g_dwADCPowerUserCounter);
}
void PMIC_ADCPowerOFF(void)
{
    const RegSet_t clearing[] = {
        {DA9034_ADC_MAN_CONTROL,   0},
    };

    if(g_dwADCPowerUserCounter > 0) g_dwADCPowerUserCounter--;
    if(0 == g_dwADCPowerUserCounter) RegSet(clearing, sizeof(clearing)/sizeof(RegSet_t));

    DBG_TraceDec("User CNT", g_dwADCPowerUserCounter);
}

U32 PMIC_GetBatteryVoltage(void)
{
    U8 vol;

    const RegSet_t setting[] = {
        {DA9034_ADC_AUTO_CONTROL1, ADC_AUTO_CONTROL1_AUTO_VBAT_ENABLE | ADC_AUTO_CONTROL1_DEBOUNCE_VBAT_MON}
    };
    const RegSet_t clearing[] = {
        {DA9034_ADC_AUTO_CONTROL1, 0}
    };

    PMIC_ADCPowerON();
    RegSet(setting, sizeof(setting)/sizeof(RegSet_t));

    PageRead(DA9034_VBAT_RES, &vol, 1);

    PMIC_ADCPowerOFF();
    RegSet(clearing, sizeof(clearing)/sizeof(RegSet_t));

    return((U32)vol);
}

void PMIC_ReadXY(U16 *pwX, U16 *pwY)
{
    U8 value[3];

    PageRead(DA9034_TSI_X_MSB, value, 3);

    *pwX = ((U16)value[0] << 2) | (TSI_XY_LSB_TSI_X(0xff) >> 0);
    *pwY = ((U16)value[1] << 2) | (TSI_XY_LSB_TSI_Y(0xff) >> 2);
}

// DA9034 Interrupt Event

static void OnOnkey(void)
{
    if((PMIC_GetStatus(PMIC_STATUS_A) & STATUS_A_nONKEY) == 0)
    {   // Press Down
        Timer_Start(TIMER_FOR_ON_KEY, e_TIMER_UNIT_1mS);
    }
    else
    {   // Release Up
        if(Timer_Stop(TIMER_FOR_ON_KEY) > 1000) SetEvent(MAIN_EVENT_POWER_OFF);
    }
}

static void OnUSBCable(void)
{
    if((STATUS_B_USB_DEV & PMIC_GetStatus(PMIC_STATUS_B)) == STATUS_B_USB_DEV)
    {
        SetEvent(MAIN_EVENT_USB_CABLE_IN);
    }
}

void PMIC_INTHandler(void)
{
    U32 event;

    PMIC_INTDisable((PMIC_INT_PEN_DOWN | PMIC_INT_TSI_READY));

    event = PMIC_GetEvent();

    if(event & (~(PMIC_INT_nONKEY | PMIC_INT_TSI_READY | PMIC_INT_PEN_DOWN | PMIC_INT_USB_DEV)))
    {
        DBG_TraceHex("PMIC EV", event);
    }

    if(event & PMIC_INT_TSI_READY)
    {
        SetEvent(MAIN_EVENT_TOUCH_READY);
    }
    if(event & PMIC_INT_PEN_DOWN)
    {
        SetEvent(MAIN_EVENT_TOUCH_DOWN);
    }
    if(event & PMIC_INT_nONKEY)
    {
        OnOnkey();
    }
    if(event & PMIC_INT_USB_DEV)
    {
        OnUSBCable();
    }
#if 0
    if(event & PMIC_INT_CHDET)
    {
//        DA9034_GetACChargerStatus();
    }
#endif
}

// DA9034 Initial

void PMIC_Initial(void)
{
    const RegSet_t setting[] =
    {
        // Setting Change Speed
        {DA9034_BUCK1_AVRC,      (BUCK1_AVRC_APPS_RATE(0x2))},
        {DA9034_SVRC,            (SVRC_SRAM_RATE(0x2))},
        {DA9034_MVRC,            (MVRC_MVT_RATE(0x2))},

        // Voltage Setting
        {DA9034_ADTV1,           DA9034_BUCK1_VOLTAGE1},
        {DA9034_ADTV2,           DA9034_BUCK1_VOLTAGE2},

        {DA9034_MDTV1,           DA9034_LDO1_VOLTAGE1},
        {DA9034_MDTV2,           DA9034_LDO1_VOLTAGE2},

        {DA9034_SDTV1,           DA9034_LDO2_VOLTAGE1},
        {DA9034_SDTV2,           DA9034_LDO2_VOLTAGE2},

        {DA9034_LDO6_4_3,        DA9034_LDO3_VOLTAGE | DA9034_LDO4_VOLTAGE | DA9034_LDO6_VOLTAGE},
        {DA9034_LDO9_8_7,        DA9034_LDO7_VOLTAGE | DA9034_LDO8_VOLTAGE | DA9034_LDO9_VOLTAGE},
        {DA9034_LDO11_10,        DA9034_LDO10_VOLTAGE | DA9034_LDO11_VOLTAGE | DA9034_BUCK2_VOLTAGE},
        {DA9034_LDO13_12,        DA9034_LDO12_VOLTAGE | DA9034_LDO13_VOLTAGE},
        {DA9034_LDO15_14,        DA9034_LDO14_VOLTAGE | DA9034_LDO15_VOLTAGE},

        // Power ON/OFF setting
        {DA9034_VCC1,            VCC1_APPS_SEL_1 | VCC1_APPS_GO},
        {DA9034_OVER1,           DA9034_POWER_ENABLE_SET1},
        {DA9034_APPS_OVER2,      DA9034_POWER_ENABLE_SET2},
        {DA9034_COMM_OVER2,      0},
        {DA9034_APPS_OVER3,      DA9034_POWER_ENABLE_SET3},
        {DA9034_COMM_OVER3,      0},

        // Power ON/OFF setting in Sleep mode
        {DA9034_BUCK_SLEEP,      BUCK_SLEEP_BUCK2_SLEEP_BIT_ENABLE | BUCK_SLEEP_BUCK1_nSLEEP_ENABLE | BUCK_SLEEP_BUCK_nSLEEP_ENABLE},
        {DA9034_LDO_nSLEEP_1,    DA9034_POWER_ENABLE_nSLEEP1},
        {DA9034_LDO_nSLEEP_2,    DA9034_POWER_ENABLE_nSLEEP2},

        {DA9034_LDO_SLEEP_BIT_1, 0},
        {DA9034_LDO_SLEEP_BIT_2, 0},

        // IRQ setting
        {DA9034_nIRQ_MASK_A,     0xff},
        {DA9034_nIRQ_MASK_B,     0xff},
        {DA9034_nIRQ_MASK_C,     0xff},
        {DA9034_nIRQ_MASK_D,     0xff},

        // Other Setting
        {DA9034_SYS_CTRL_A,      (SYS_CTRL_A_nSLEEP_PIN_ENABLE | SYS_CTRL_A_TWD_SCALE(0x7))},
        {DA9034_SYS_CTRL_B,      (SYS_CTRL_B_nONKEY_PRESS_TIME | SYS_CTRL_B_nONKEY_SHUT_ENABLE)},

        {DA9034_TSI_CONTROL_1,   (TSI_CONTROL_1_TSI_SKIP(0x2) | TSI_CONTROL_1_TSI_DELAY(0x2))},
        {DA9034_TSI_CONTROL_2,   0}
    };

    if(ERR_CODE_SUCCESS != RegSet(setting, sizeof(setting)/sizeof(RegSet_t))) DBG_BreakPoint("PMIC_Initial");

    WatchdogDisable();

    PMIC_GetEvent();
    PMIC_INTEnable((PMIC_INT_nONKEY | PMIC_INT_USB_DEV));

    g_dwADCPowerUserCounter = 0;
}

#endif

