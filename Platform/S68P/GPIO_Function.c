
void GPIO_INTHandlerGPIO1(void)
{
    DBG_TraceStrLine("INT GPIO1");
}

void GPIO_INTHandler(void)
{
    if(GPIO_REG_GEDR0 & GPIO_PMIC_INT)
    {
        GPIO_REG_GEDR0 = GPIO_PMIC_INT;

        SetEvent(MAIN_EVENT_PMIC_EVENT);
    }
}

void GPIO_PanelBackLight(int iOnOff)
{
    if(iOnOff == 0) GPIO_REG_GPCR0 = GPIO_PANEL_BK_LIGHT;
    else            GPIO_REG_GPSR0 = GPIO_PANEL_BK_LIGHT;
}

void GPIO_PanelReset(void)
{
    GPIO_REG_GPCR2 = GPIO_PANEL_RESET;
    msSleep(100);
    GPIO_REG_GPSR2 = GPIO_PANEL_RESET;
    msSleep(100);
}

void GPIO_Write24BitToSPI(U8 *pSerial)
{
    U32 i;
    U32 mask;

    GPIO_REG_GPCR3 = GPIO_PANEL_SPI_CS;

    for(i = 0; i < 3; i++)
    {
        for(mask = 0x80; mask > 0; mask >>= 1)
        {
            GPIO_REG_GPCR2 = GPIO_PANEL_SPI_CLK;

            if (pSerial[i] & mask)
            {
                GPIO_REG_GPSR2 = GPIO_PANEL_SPI_SI;
            }
            else
            {
                GPIO_REG_GPCR2 = GPIO_PANEL_SPI_SI;
            }

            GPIO_REG_GPSR2 = GPIO_PANEL_SPI_CLK;
        }
    }

    GPIO_REG_GPSR3 = GPIO_PANEL_SPI_CS;
}

void GPIO_ModemReset(void)
{

    GPIO_REG_GPCR3 = GPIO_AP_RST_BB;
    msSleep(200);
    GPIO_REG_GPSR0 = GPIO_BB_ON;
    //msSleep(4000);
}

void GPIO_ModemOff(void)
{
    //msSleep(5000);
    GPIO_REG_GPCR0 = GPIO_BB_ON;
    GPIO_REG_GPSR3 = GPIO_AP_RST_BB;
}

void GPIO_FM2010_BYPASS(void)
{
    GPIO_REG_GPSR3 = GPIO_FM2010_PWD;
    msSleep(200);
    GPIO_REG_GPCR1 = GPIO_FM2010_RST;
    msSleep(200);
    GPIO_REG_GPSR1 = GPIO_FM2010_RST;

    GPIO_REG_GPSR1 = GPIO_FM2010_IRQ_ANA;
}

void GPIO_SPKEnable(void)
{
    GPIO_REG_GPSR1 = GPIO_SPK_SD;
}

void GPIO_SPKDisable(void)
{
    GPIO_REG_GPCR1 = GPIO_SPK_SD;
}


