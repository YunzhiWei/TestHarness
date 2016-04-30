
#include "_Platform.h"

#ifdef INCLUDE_MODULE_EVENT

#define REG_PSPR                        (*MH_PSPR)

static void OnU2DStop(void)
{
    INT_Disable();                      // To prevent unexpected Interrupt

    FS_AutoBatch(FS_DISK_RAM);

    REG_PSPR = PSPR_FLAG_FMD_CLEANBOOT | PSPR_GOTO_WM_RESET;

    INT_Initial();
}

static void OnMMCSDInsert(void)
{
    SD_Initial();
    if(ERR_CODE_NONE != SD_OnCardInsert()) return;

    INT_Disable();                      // To prevent unexpected Interrupt

    FS_AutoBatch(FS_DISK_SD);

    REG_PSPR = PSPR_FLAG_FMD_CLEANBOOT | PSPR_GOTO_WM_RESET;

    INT_Initial();
}

static void OnCameraKeyDown(void)
{
#ifdef INCLUDE_MODULE_CAMERA
    static U32 s;

    if(++s & 1)
    {
        MY_TraceStrLine("Camera ON ...")
        CAM_ON();
        MY_TraceString("DONE!")
    }
    else
    {
        MY_TraceStrLine("Camera OFF ...")
        CAM_OFF();
        MY_TraceString("DONE!")
    }
#endif
}

static void OnUSBCalbeIn(void)
{
#ifdef INCLUDE_MODULE_UDC
    UDC_Initial();
#endif
#ifdef INCLUDE_MODULE_U2D
    USB_SerialInitial();
#endif
}

#define USE_USB_SERIAL_FOR_DEBUG

static void OnHyperTerminalOpenUSBSerial(void)
{
#ifdef USE_USB_SERIAL_FOR_DEBUG
    __DBG_InitialUSB();
#else
    DBG_TraceStrLine("HyperTerminal Open!");
    SERIAL_Dump();
#endif
}

static void OnHyperTerminalCloseUSBSerial(void)
{
#ifdef USE_USB_SERIAL_FOR_DEBUG
    __DBG_InitialUART();
#else
    DBG_TraceStrLine("HyperTerminal Close!");
    SERIAL_Dump();
#endif
}

extern void GotoSleep(void);
static void OnPowerOff(void)
{
    GotoSleep();
}

/*
    We did not DO any protection here !!!
*/

static U32 g_Event;

void SetEvent(Event_Flag_t tFlag)
{
    g_Event |= tFlag;
}

void ClearEvent(Event_Flag_t tFlag)
{
    g_Event &=~ tFlag;
}

typedef void (*FP_EventHandler_t)(void);

char OnMenuIdle(void)
{
    // Please refer to Event_Flag_t defination for the handlers' order !!!
    const FP_EventHandler_t handle[] = {
        OnU2DStop,
        OnMMCSDInsert,
#ifdef INCLUDE_MODULE_PMIC
        PMIC_INTHandler,
#else
        NULL,
#endif
        OnPowerOff,
#ifdef INCLUDE_MODULE_TOUCH
        Touch_OnPenDown,
        Touch_OnTouchDAReady,
#else
        NULL,
        NULL,
#endif
        OnCameraKeyDown,
        OnUSBCalbeIn,
#ifdef INCLUDE_MODULE_SERIAL
        OnHyperTerminalOpenUSBSerial,
        OnHyperTerminalCloseUSBSerial
#else
        NULL,
        NULL
#endif
    };

    U32 mask;
    int i;

    while(1)
    {
        if(DBG_IsDataReady()) return(DBG_GetChar());

        for(i=0, mask = 1; i < sizeof(handle)/sizeof(FP_EventHandler_t);i++, mask <<= 1)
        {
            if(g_Event & mask)
            {
                ClearEvent(mask);

                if(handle[i] != NULL) handle[i]();

                return(ASCII_CODE_NAK);                // Make the menu not refresh
            }
        }
    }
}

#endif

