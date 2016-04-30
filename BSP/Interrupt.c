
#include "_Platform.h"

/*

*/

#define REG_ICMR                        (*MH_ICMR)
#define REG_ICLR                        (*MH_ICLR)
#define REG_ICCR                        (*MH_ICCR)
#define REG_IPR0                        (*MH_IPR0)
#define REG_ICIP                        (*MH_ICIP)
#define REG_ICFP                        (*MH_ICFP)
#define REG_ICMR2                       (*MH_ICMR2)
#define REG_ICLR2                       (*MH_ICLR2)
#define REG_ICCR2                       (*MH_ICCR2)
#define REG_IPR02                       (*MH_IPR02)
#define REG_ICIP2                       (*MH_ICIP2)
#define REG_ICFP2                       (*MH_ICFP2)

/*
*/

void INT_Disable(void)
{
    // Mask all interrupts
    REG_ICMR = 0;
}

void INT_Initial(void)
{
    // Mask all interrupts
    REG_ICMR = 0;

    // IRQ: all the interrupt will be IRQ BY DEFAULT
    REG_ICLR = 0;

    // FIQ: the following interrupt will be set as FIQ
    REG_ICLR |= 0;

    // Enable the following interrupts
#ifdef INCLUDE_MODULE_UDC
    REG_ICMR  = INTC_OSMR1 | INTC_KEYPAD | INTC_GPIOXX_2 | INTC_GPIO1| INTC_USBCLIENT;
#else
    REG_ICMR  = INTC_OSMR1 | INTC_KEYPAD | INTC_GPIOXX_2 | INTC_GPIO1;
#endif

#ifdef INCLUDE_MODULE_U2D
    REG_ICMR2 = INTC_USBHSCLIENT;
#endif

    // Only enabled and unmasked interrupt bring core out of idle
    REG_ICCR = 1;
}

//*******************************************************************************************

void ExceptionHandler(U32 dwStyle, U32 dwFpAddr, U32 dwExcpAddr)
{
#define __fp__          (*(p-3))
#define __sp__          (*(p-2))
#define __lr__          (*(p-1))
#define __pc__          (*(p-0))

    static char *excpPrompt[] = {
        "UndefInstruction",
        "PrefetchAbort",
        "DataAbort",
        "RESException",
    };
    U32 *p;

    if(dwStyle > (sizeof(excpPrompt)/sizeof(char*)))
    {
        DBG_TraceHex("Unknown Exception", dwStyle);
    }
    else
    {
        DBG_TraceString("\r\n\r\n\r\n !!! --- ");
        DBG_TraceString(excpPrompt[dwStyle]);
        DBG_TraceHex("fail at", dwExcpAddr);
        DBG_TraceHex("link start", dwFpAddr);

        DBG_TraceString("\r\n   fp       sp       lr       pc");
        DBG_TraceString("\r\n-------------------------------------");

        p = (U32*)dwFpAddr;
        while(p)
        {
            DBG_TraceString("\r\n");
            DBG_TraceHex(NULL, __fp__);
            DBG_TraceHex(NULL, __sp__);
            DBG_TraceHex(NULL, __lr__);
            DBG_TraceHex(NULL, __pc__);

            p = (U32*)(__fp__);
        }
    }
#undef __fp__
#undef __sp__
#undef __lr__
#undef __pc__
}

void IRQ_Handler(void)
{
//    DBG_TraceHex("ICIP", REG_ICIP);

#ifdef INCLUDE_MODULE_UDC
     if(REG_ICIP & INTC_USBCLIENT)
    {
        UDC_Handler();
    }
#endif //INCLUDE_MODULE_UDC
#ifdef INCLUDE_MODULE_U2D
    if(REG_ICIP2 & INTC_USBHSCLIENT)
    {
        U2D_Handler();
    }
#endif //INCLUDE_MODULE_U2D
    if(REG_ICIP & INTC_OSMR1)
    {
        OSTimer01_INTHandler();
    }

#ifdef INCLUDE_MODULE_KEYPAD
    if(REG_ICIP & INTC_KEYPAD)
    {
        KP_INTHandler();
    }
#endif //INCLUDE_MODULE_KEYPAD
    if(REG_ICIP & INTC_GPIOXX_2)
    {
        GPIO_INTHandler();
    }
    if(REG_ICIP & INTC_GPIO1)
    {
        GPIO_INTHandlerGPIO1();
    }
}

void FIQ_Handler(void)
{
    DBG_TraceHex("ICHP", REG_ICFP);
}

void SWI_Handler(U32 dwID)
{
    DBG_TraceHex("SWI", dwID);
}

