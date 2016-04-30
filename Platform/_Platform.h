/*
    This Platform.h is the platform center.
    Each Module must provide its header file to Platform.h only if it wants to provide functions to the platform.
    Each Module must include this Platform.h in its source file if only it wants any resource from others.
    No Module can use any resource from other Modules directly without this Platform.h as middleware.
*/

#include "_type.h"

#include "_Cooperate.h"
#include "Platform.h"

//#define FONT_SELECT_8X12
#ifdef DISPLAY_RESOLUSION_QVGA_PORTRAIT
#define FONT_SELECT_11X17
#endif
#ifdef DISPLAY_RESOLUSION_VGA_PORTRAIT
#define FONT_SELECT_32X18
#endif

/*
    Auto Calculate
*/

#define NAND_HW_ECC_RESULT_SIZE         (6 * (NAND_SECTOR_SIZE/512))

#define NAND_SECTOR_NUMBER_PER_BLOCK    (NAND_BLOCK_SIZE/NAND_SECTOR_SIZE)
#define NAND_BLOCK_NUMBER_IN_TOTAL      (NAND_TOTAL_SIZE/NAND_BLOCK_SIZE)
#define NAND_SPARE_SIZE_PER_BLOCK       (NAND_SPAREAREA_SIZE * NAND_SECTOR_NUMBER_PER_BLOCK)

/*
    Individual Resource: Import from Global Definition and Each Module
*/

// Global Definition

// Global Resource

// Global Functions: Provided by other modules

// Required: MUST be included

#include "_ErrCode.h"
#include "ASMRoutines.h"
#include "VT100.h"
#include "public.h"
#include "MMU.h"
#include "crc1021.h"
#include "xModem.h"
#include "StreamOut.h"
#include "debug.h"
#include "Menu.h"
#include "FAL.h"
#include "FAT.h"
#include "FBFunction.h"

#include "Event.h"
#include "Clock.h"
#include "Freq.h"
#include "PWRMode.h"
#include "UART.h"
#include "timer.h"
#include "PIN.h"
#include "GPIO.h"
#include "Interrupt.h"

// Platform Modules

#include "PlatformModules.h"

// Optional: May be included or not

#include "Update.h"
#include "FileSys.h"

#include "Console.h"
#include "FIFO.h"

/*
    System Resource: Export to All Modules
*/

//    Program Name and Version information

#define PROGRAM_NAME                                        "Sparrow"
#define VERSION_NUMBER                                      "Ver 020?"

// Timer : Timer Module
#define TIMER_DELAY_SLEEP                                   0
#define TIMER_FOR_ON_KEY                                    4
#define msSleep(t)                                          Timer_Delay(TIMER_DELAY_SLEEP, e_TIMER_UNIT_1mS, t)

// Debug Input & Output : Debug Module

#ifdef INCLUDE_MODULE_DEBUG

#define DBG_GetChar                                         __DBG_GetChar
#define DBG_IsDataReady                                     __DBG_IsDataReady

#define DBG_GET_BYTE                                        __DBG_GetChar()
#define DBG_GotEvent                                        __DBG_IsDataReady()

#define DBG_TraceMem(p1, p2, p3)                            __DBG_TraceMem((U8*)(p1), (U8*)(p2), (U32)(p3))
#define DBG_GetHex(p1, p2)                                  __DBG_GetHex(p1, p2, 0)
#define DBG_GetHexDef(p1, p2, p3)                           __DBG_GetHex(p1, p2, p3)
#define DBG_GetDec(p1, p2)                                  __DBG_GetDec(p1, p2, 0)
#define DBG_GetDecDef(p1, p2, p3)                           __DBG_GetDec(p1, p2, p3)
#define DBG_GetString(p1, p2, p3)                           __DBG_GetString(p1, p2, p3)
#define DBG_BreakPoint(p)                                   __DBG_BreakPoint(p)
#define DBG_CountDown(p1)                                   __DBG_CountDown(p1)

#define DBG_PutChar(v)                                      __DBG_PutChar(v)
#define DBG_TraceString(p1)                                 __DBG_TraceString(p1)
#define DBG_TraceStrLine(p1)                                __DBG_TraceStrLine(p1)
#define DBG_TraceByte(p)                                    SO_TraceByte(__DBG_PutChar, p);
#define DBG_TraceHex(p1, p2)                                SO_TraceHex(__DBG_PutChar, __DBG_TraceString, p1, p2, (sizeof(p2)))
#define DBG_TraceX(p1, p2, p3)                              SO_TraceHex(__DBG_PutChar, __DBG_TraceString, p1, p2, p3)
#define DBG_TraceDec(p1, p2)                                SO_TraceDec(__DBG_TraceString, p1, p2)

#define UI_PutChar(c)                                       CS_PutChar(c);
#define UI_TraceString(s)                                   CS_PutString(s);
#define UI_TraceStrLine(s)                                  CS_PutStrLine(s);
#define UI_TraceByte(p)                                     SO_TraceByte(CS_PutChar, p);
#define UI_TraceHex(p1, p2)                                 SO_TraceHex(CS_PutChar, CS_PutString, p1, p2, sizeof(p2));
#define UI_TraceDec(p1, p2)                                 SO_TraceDec(CS_PutString, p1, p2);

#define MY_PutChar(c)                                       DBG_PutChar(c);      CS_PutChar(c);
#define MY_TraceString(s)                                   DBG_TraceString(s);  CS_PutString(s);
#define MY_TraceStrLine(s)                                  DBG_TraceStrLine(s); CS_PutStrLine(s);
#define MY_TraceHex(p1, p2)                                 DBG_TraceHex(p1, p2);UI_TraceHex(p1, p2);
#define MY_TraceDec(p1, p2)                                 DBG_TraceDec(p1, p2);UI_TraceDec(p1, p2);

#define DBG_FILELINE                                        { DBG_TraceDec("@", __LINE__); DBG_TraceString((U8*)(__FILE__)); }

#else

#define MY_PUT_BYTE(c)
#define MY_TraceString(s)
#define MY_TraceStrLine(s)

#define DBG_TraceString(p1)
#define DBG_TraceByte(p1)
#define DBG_TraceMem(p1, p2, p3)
#define DBG_TraceX(p1, p2, p3)
#define DBG_TraceHex(p1, p2)
#define DBG_GetHex(p1, p2)                                 0
#define DBG_GetString(p1, p2, p3)                          0
#define DBG_BreakPoint(p)
#define DBG_MemSet(p1, p2, p3)

#define DBG_FILELINE

#endif

