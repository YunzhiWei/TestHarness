
void Panel_Initial(void)
{
#include "Panel_SPFD5408B.c"

    U32 i;

    for(i = 0;CmdSerial[i] != 0;i+=3)
    {
        GPIO_Write24BitToSPI(CmdSerial + i);
    }

    msSleep(500);
}


