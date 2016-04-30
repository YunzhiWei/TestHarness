
#include "Camera_MT9M111_BSP.c"

static void CAM_PowerON(void)
{
    GPIO_CameraPowerON();
}

static void CAM_PowerOFF(void)
{
    GPIO_CameraPowerOFF();
}

