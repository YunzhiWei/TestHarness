
void GPIO_INTHandlerGPIO1(void)
{
    DBG_TraceStrLine("INT GPIO1");
}

void GPIO_INTHandler(void)
{
    if(GPIO_REG_GEDR3 & GPIO_PMIC_INT)
    {
        GPIO_REG_GEDR3 = GPIO_PMIC_INT;

        SetEvent(MAIN_EVENT_PMIC_EVENT);
    }

    if(GPIO_REG_GEDR0 & GPIO_TF_CD)
    {
        msSleep(5);
        if(0 == (GPIO_REG_GPLR0 & GPIO_TF_CD))
        {
            SetEvent(MAIN_EVENT_MMCSD_INSERT);
        }

        GPIO_REG_GEDR0 = GPIO_TF_CD;
    }
}

void GPIO_PanelReset(void)
{
    GPIO_REG_GPCR2 = GPIO_LCM_RST;
    msSleep(20);
    GPIO_REG_GPSR2 = GPIO_LCM_RST;
}

void GPIO_CameraReset(void)
{
    GPIO_REG_GPCR1 = GPIO_CIF_RST;
    msSleep(10);
    GPIO_REG_GPSR1 = GPIO_CIF_RST;
}

void GPIO_CameraPowerON(void)
{
    GPIO_REG_GPCR2 = GPIO_CIF_SD;
}

void GPIO_CameraPowerOFF(void)
{
    GPIO_REG_GPSR2 = GPIO_CIF_SD;
}

void GPIO_SPKEnable(void)
{
    GPIO_REG_GPSR2 = GPIO_MP3_OP_ON;
}

void GPIO_SPKDisable(void)
{
    GPIO_REG_GPCR2 = GPIO_MP3_OP_ON;
}

static void GPIO_MP3OP(void)
{
    if(DBG_GetDec("0: Low, other: High", 1))
    {
        GPIO_REG_GPSR2 = GPIO_MP3_OP_ON;
    }
    else
    {
        GPIO_REG_GPCR2 = GPIO_MP3_OP_ON;
    }
}

void GPIO_ModemResetHi(void)
{
    GPIO_REG_GPSR2 = GPIO_MODEM_RST;
}

void GPIO_ModemResetLo(void)
{
    GPIO_REG_GPCR2 = GPIO_MODEM_RST;
}

void GPIO_ModemOnKeyHi(void)
{
    GPIO_REG_GPSR2 = GPIO_MODEM_ONKEY;
}

void GPIO_ModemOnKeyLo(void)
{
    GPIO_REG_GPCR2 = GPIO_MODEM_ONKEY;
}

void GPIO_ModemReset(void)
{
    GPIO_REG_GPCR2 = GPIO_MODEM_RST;
    msSleep(10);
    GPIO_REG_GPSR2 = GPIO_MODEM_RST;
}

void GPIO_ModemONKEY(U32 dwPulse)
{
    GPIO_ModemOnKeyHi();
    msSleep(dwPulse);
    GPIO_ModemOnKeyLo();
}

U32 GPIO_ModemStatus(void)
{
    return(GPIO_REG_GPLR2 & GPIO_MODEM_STATUS);
}

