
void GPIO_INTHandlerGPIO1(void)
{
    DBG_TraceStrLine("INT GPIO1");
}

void GPIO_INTHandler(void)
{
    if(GPIO_REG_GEDR3 & GPIO_107_KP_DKIN0)
    {
        DBG_TraceHex("[107]", GPIO_REG_GEDR3);
        GPIO_REG_GEDR3 = GPIO_107_KP_DKIN0;
    }
    if(GPIO_REG_GEDR3 & GPIO_108_KP_DKIN1)
    {
        DBG_TraceHex("[108]", GPIO_REG_GEDR3);
        GPIO_REG_GEDR3 = GPIO_108_KP_DKIN1;
    }
}

void GPIO_PanelReset(void)
{
}

static void GPIO_LCDResolution(void)
{
    if(DBG_GetDec("0: VGA, other: QVGA", 1))
    {
        GPIO_REG_GPSR2 = GPIO_LCD_VSYNC;
    }
    else
    {
        GPIO_REG_GPCR2 = GPIO_LCD_VSYNC;
    }
}

