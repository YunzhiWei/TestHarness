
#include "_Platform.h"

#define REG_PSPR                        (*MH_PSPR)

//#define RUNNING_MODE_MOBM

const U8 g_PlatformName[] = PLATFORM_TYPE;

static void GotoTarget(void)
{
    int err;
    U32 id, addr, size, target;

    target = (PSPR_MASK_STYLE | PSPR_MASK_PARAMETER) & REG_PSPR;

    switch(target)
    {
    case PSPR_DEFAULT:
        REG_PSPR = PSPR_GOTO_WM_RESET;
    case PSPR_GOTO_WM_RESET:
    case PSPR_GOTO_ULDR:
    case PSPR_GOTO_WM_RESUME:
        err = UPD_LoadImage(UPD_STORE_POS_BLOCK_ID_SCREEN, UPD_STORE_RAM_ADDRESS_SCREEN, FB_BASE_RGB565_SIZE);
        if(
            (err != ERR_CODE_SUCCESS) &&
            (err != ERR_CODE_NAND_DBERR)
            )
        {
            ErrCodeDisplay(err);
            DBG_BreakPoint(NULL);
            return;
        }

        LCD_FBBaseSet(DISP_FRAME_BUFFER_ADDRESS);

        id   = UPD_STORE_POS_BLOCK_ID_IPL;
        addr = UPD_STORE_RAM_ADDRESS_IPL;
        size = UPD_STORE_BLOCK_NUMBER_IPL * NAND_BLOCK_SIZE;
        break;

    case PSPR_GOTO_EBOOT:
        id   = UPD_STORE_POS_BLOCK_ID_EBOOT;
        addr = UPD_STORE_RAM_ADDRESS_EBOOT;
        size = UPD_STORE_BLOCK_NUMBER_EBOOT * NAND_BLOCK_SIZE;
        break;

    case PSPR_GOTO_HWTESTER:
        id   = UPD_STORE_POS_BLOCK_ID_HWTESTER;
        addr = UPD_STORE_RAM_ADDRESS_HWTESTER;
        size = UPD_STORE_BLOCK_NUMBER_HWTESTER * NAND_BLOCK_SIZE;
        break;

    case PSPR_GOTO_MOBM:

    default:
        return;
    }

    err = UPD_LoadImage(id, addr, size);
    if(
        (err == ERR_CODE_SUCCESS) ||
        (err == ERR_CODE_NAND_DBERR)
        )
    {
        JumpToRun(addr);
    }
    else
    {
        ErrCodeDisplay(err);
        DBG_BreakPoint(NULL);
        return;
    }
}

static void FindOutWhere2Go(void)
{
    U32 row, col;
    U32 scode[KP_SCAN_CODE_NUMBER];

    if(ERR_CODE_KP_MULTI == KP_MatrixScan(&row, &col, scode))
    {
        DBG_TraceHex("Get Key", scode[0]);

        switch(scode[0])
        {
        case USER_SEL_GOTO_MOBM:
            DBG_TraceStrLine("MOBM");
            REG_PSPR = PSPR_GOTO_MOBM;
            break;
        case USER_SEL_GOTO_HWT:
            DBG_TraceStrLine("HWT");
            REG_PSPR = PSPR_GOTO_HWTESTER;
            break;
        case USER_SEL_GOTO_EBOOT1:
        case USER_SEL_GOTO_EBOOT2:
            DBG_TraceStrLine("EB");
            REG_PSPR = PSPR_GOTO_EBOOT;
            break;
        case USER_SEL_GOTO_ULDR:
            DBG_TraceStrLine("UL");
            REG_PSPR = PSPR_GOTO_ULDR;
            break;
        case USER_SEL_GOTO_CLEANBOOT:
            DBG_TraceStrLine("CB");
            REG_PSPR |= PSPR_FLAG_FMD_CLEANBOOT;
            break;
        case USER_SEL_GOTO_KITL:
            DBG_TraceStrLine("KT");
            REG_PSPR |= PSPR_FLAG_USB_KITL;
            break;
        default:
            REG_PSPR = PSPR_GOTO_MOBM;
            DBG_TraceHex("0", scode[0]);
            DBG_TraceHex("1", scode[1]);
            DBG_TraceHex("2", scode[2]);
            DBG_TraceHex("3", scode[3]);
            break;
        }
    }
    else if(
        ((PSPR_GOTO_WM_RESET | PSPR_FLAG_FMD_CLEANBOOT) == REG_PSPR) ||
        ((PSPR_GOTO_ULDR) == REG_PSPR)
        )
    {
        DBG_TraceStrLine("Known PSPR");
    }
    else
    {
        DBG_TraceStrLine("Normal");
        REG_PSPR = PSPR_GOTO_WM_RESET;
    }
}

void GotoSleep(void)
{
#ifdef PLATFORM_NAME_GRYPHUS
    REG_PSPR = PSPR_GOTO_MOBM;

    Touch_DeInitial();

    GPIO_ModemReset();
    DISP_BK_CONTROL(0);
    LCD_Disable();

    PMIC_LDOEnableOnSleep();

    PMIC_GetEvent();
    PIN_ClearEdgeFlag(PIN_PMIC_INT);

    PWRMode_PreSleep();
    PWRMode_Set(PWR_MODE_S2D3C4_SLEEP);
#endif
}

static void CheckCondition(U32 dwCondition)
{
#ifdef PLATFORM_NAME_GRYPHUS

#define CONDITION_MAIN_BATTERY_VOLTAGE_THRESHOLD            0x58

    if(dwCondition & BOOT_UP_CONDITION_VOTAGE)
    {
        U32 vol;

        vol = PMIC_GetBatteryVoltage();
        MY_TraceHex("Voltage", vol);

        if(vol < CONDITION_MAIN_BATTERY_VOLTAGE_THRESHOLD)
        {
            MY_TraceStrLine("Low Battery!");
            DBG_CountDown(2);
            GotoSleep();
        }
    }

    if(dwCondition & BOOT_UP_CONDITION_ONKEY)
    {
        U8 status;

        status = PMIC_GetStatus(PMIC_STATUS_A);
        if(status & STATUS_A_nONKEY)
        {
            MY_TraceStrLine("Hold Power Button Down to Turn on Device!");
            DBG_CountDown(2);
            GotoSleep();
        }
    }

    if(GPIO_ModemStatus() == 0)
    {
        MY_TraceStrLine("Modem ON");
    }
#endif
}

static void PrepareUUID(void)
{
    MemCopy((void*)RESERVED_UUID_ADDR, (void*)RUNTIME_PROGRAM_BASE, RESERVED_UUID_SIZE);
}

void Startup(U32 dwStartAddr, U32 dwEndAddr)
{
//    EnableICache();
//    EnableDCache();

    __DBG_InitialUART();

//    LCD_Disable(); // For MOBM, because the LCD clock is not turn on, this function will block the process !!!
                     // And because Clock_Initial will clear the LCD clock, LCD_Disable must be invoke before Clock_Initial.

    Clock_Initial();

    Freq_Set();

    PWRMode_Initial();

    PIN_Initial();
    GPIO_Initial();

    GPIO_PanelReset();
    // Delay must be added before Panel Operation
    // msSleep(100);

#ifdef PLATFORM_NAME_GRYPHUS
    GPIO_ModemResetHi();                // Reset will turn off NXP modem
#endif
#ifdef INCLUDE_MODULE_I2C
    I2C_Initial();
#endif
    UART_Initial(UART_ID_DBG, 115200, 0, 0);
    UART_PutString(UART_ID_DBG, "\r\n\r\n\r\nUART Opened!");
    // Delay must be added before next string output from UART
    // msSleep(200);

#ifdef INCLUDE_MODULE_PMIC
    PMIC_Initial();
    PMIC_GetEvent();
#endif
#ifdef PIN_PMIC_INT
    PIN_ClearEdgeFlag(PIN_PMIC_INT);
#endif

#ifdef PLATFORM_NAME_GRYPHUS
    SSP_Initial(SSP_ID_2, SSP_ID_SPI_LCD, SSP_SAMPLE_RATE_SPI, SSP_SAMPLE_BIT_08, SSP_CHANNEL_NONE);
    SSP_Enable(SSP_ID_2);
    SSP_SendB2B(SSP_ID_2, "Dummy", 10); // without sending dummy bytes, some strange bytes may be read out for the first time read.
#endif

    KP_Initial();

    Nand_ControllerInit();
    BBM_Init();

    CS_Initial();
    MY_TraceStrLine((U8*)g_PlatformName);
    MY_TraceStrLine(PROGRAM_NAME " " VERSION_NUMBER "\r\n" __DATE__ " " __TIME__);
    DBG_TraceHex("start address", dwStartAddr);
    DBG_TraceHex("Run time space size", dwEndAddr - dwStartAddr);

    LCD_Initial();
    LCD_Enable();

    Panel_Initial();

    Clock_Enable(CLOCK_REG_SET_A, CKENA_LCD, TRUE);
    DISP_BK_CONTROL(100);

#ifdef PLATFORM_NAME_GRYPHUS
    SSP_Disable(SSP_ID_2);
#endif

#ifdef RUNNING_MODE_MOBM
    CheckCondition(PWRMode_GetBootupScenario());
#endif

    if(dwEndAddr > BUFFER_SHARED_UNION_BASE) DBG_BreakPoint("Space Overflow!!!");

    PrepareUUID();

#ifdef PLATFORM_NAME_GRYPHUS
    GPIO_MODEMPOWERON;
#endif

#ifdef RUNNING_MODE_MOBM
    FindOutWhere2Go();
    GotoTarget();
#else
    RTC_Initial(2009, 2, 28, 10, 10, 59);
    DBG_BreakPoint("Ready?");
#endif

    RMD_Format();

    ClearEvent(MAIN_EVENT_ALL);

    INT_Initial();

    KP_INTEnable();

#ifdef INCLUDE_MODULE_TOUCH
    Touch_Initial();
#endif

}

#if 0
    DBG_TraceString( VT100_CMD_CLEARSCREEN );
    DBG_TraceString(
        VT100_ATTR_START \
        VT100_ATTR_CLR_FT_RED VT100_ATTR_AND \
        VT100_ATTR_CLR_CK_BLACK VT100_ATTR_AND \
        VT100_ATTR_BOLD_ON VT100_ATTR_AND \
        VT100_ATTR_BLINK_ON \
        VT100_ATTR_END \
        "hello");
    DBG_TraceString(VT100_ATTR_START VT100_ATTR_OFF_ALL VT100_ATTR_END);
#endif


