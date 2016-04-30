
//#include "Camera_OV2620.c"                                // Camera on Zylonite Main Board
#include "Camera_OV7660.c"                                  // Camera on Zylonite Key Board

void CAM_PowerON(void)
{
    U8 data[][2] = {
        {0x14, 0x27},
        {0x07, 0xC2},
        {0x03, 0xD6}
        };

    //First, the Arava Power Management IC needs to set up one of the camera voltages.
    if(I2CWrite(0x92, data[0], 2, TRUE ) == FALSE)
    {
        DBG_TraceStrLine("CAM_Initial Fail");
        return;
    }

    //Power up Camera through I2C
    I2CWrite(0xE8, data[1], 2, TRUE);
    I2CWrite(0xE8, data[2], 2, TRUE);
}

void CAM_PowerOFF(void)
{
}


