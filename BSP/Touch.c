#include "_platform.h"

#ifdef INCLUDE_MODULE_TOUCH

void Touch_Initial(void)
{
    PMIC_ADCPowerON();
    PMIC_SetModePenDownDetect();
    PMIC_INTEnable(PMIC_INT_PEN_DOWN);
}

void Touch_DeInitial(void)
{
    PMIC_INTDisable((PMIC_INT_PEN_DOWN | PMIC_INT_TSI_READY));
    PMIC_ADCPowerOFF();
}

void Touch_OnPenDown(void)
{
    PMIC_SetModeAutoSample();
    PMIC_INTEnable(PMIC_INT_TSI_READY);
}

void Touch_OnTouchDAReady(void)
{
#define PEN_UP_VALUE_X  0x03E8
#define PEN_UP_VALUE_Y  0x03E8

    U16 x,y;

    PMIC_ReadXY(&x, &y);

    MY_TraceString("\r\n");  MY_TraceHex(NULL, x); MY_TraceHex(NULL, y);

    if((x >= PEN_UP_VALUE_X) || (y >= PEN_UP_VALUE_Y))
    {
        PMIC_SetModePenDownDetect();
        PMIC_INTEnable(PMIC_INT_PEN_DOWN);
    }
    else
    {
        PMIC_INTEnable(PMIC_INT_TSI_READY);
    }
}

#endif

