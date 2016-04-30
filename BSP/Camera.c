
#include "_Platform.h"

#ifdef INCLUDE_MODULE_CAMERA

#include "Camera_Function.c"

static void CAM_Initial(void)
{
    U32 i;

    for(i=0; i<sizeof(CAM_Command)/sizeof(CAM_Command_t);i++)
    {
        if(!I2C_Write(CAM_I2C_SLAVE_ADDRESS, (U8*)(&CAM_Command[i]), sizeof(CAM_Command_Format_t), TRUE))
        {
            DBG_TraceStrLine("CAM_Initial Fail");
            return;
        }

#ifndef CAM_DELAY_FIX_TIME
        msSleep(CAM_Command[i].m_wDelay);
#else
        msSleep(CAM_DELAY_FIX_TIME);
#endif
    }
}

void CAM_ON(void)
{
    CIF_Initial();

    CAM_PowerON();
    CAM_Initial();
    CIF_DMA_Init();
    CIF_Enable();

    LCD_Overlay2Enable();
}

void CAM_OFF(void)
{
    LCD_Overlay2Disable();

    CAM_PowerOFF();
    CIF_Disable();
}

#endif

