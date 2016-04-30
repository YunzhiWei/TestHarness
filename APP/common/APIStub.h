#include "_type.h"

#include "_Platform_Gryphus.h"

/*
    Auto Calculate
*/

#define NAND_HW_ECC_RESULT_SIZE         (6 * (NAND_SECTOR_SIZE/512))

#define NAND_SECTOR_NUMBER_PER_BLOCK    (NAND_BLOCK_SIZE/NAND_SECTOR_SIZE)
#define NAND_BLOCK_NUMBER_IN_TOTAL      (NAND_TOTAL_SIZE/NAND_BLOCK_SIZE)

#include "public.h"
#include "UART.h"
#include "Debug.h"
#include "Menu.h"
#include "NAND.h"
#include "BadBlockManager.h"            // Flash.h will not be compiled without this.
#include "Flash.h"
#include "Timer.h"

#include "MMCSD.h"

#include "SSP.h"

#include "FAT.h"

// Timer : Timer Module
#define TIMER_DELAY_SLEEP                                   0
#define msSleep(t)                                          Timer_Delay(TIMER_DELAY_SLEEP, e_TIMER_UNIT_1mS, t)

#define DBG_PUT_BYTE(v)                                     __DBG_PUT_BYTE(v)
#define DBG_GET_BYTE                                        __DBG_GET_BYTE
#define DBG_GotEvent                                        __DBG_GotEvent

//#define DBG_TRACE(p1, p2)                                 if(p1>0) __DBG_Pringtf p2;
#define DBG_CountDown(p1)                                   __DBG_CountDown(p1)
#define DBG_TraceString(p1)                                 __DBG_TraceString(p1)
#define DBG_TraceStrLine(p1)                                __DBG_TraceStrLine(p1)
#define DBG_TraceByte(p1)                                   __DBG_TraceByte(p1)
#define DBG_TraceMem(p1, p2, p3)                            __DBG_TraceMem((U8*)(p1), (U8*)(p2), (U32)(p3))
#define DBG_TraceHex(p1, p2)                                __DBG_TraceHex(p1, p2, (sizeof(p2)))
#define DBG_TraceX(p1, p2, p3)                              __DBG_TraceHex(p1, p2, p3)
#define DBG_GetHex(p1, p2)                                  __DBG_GetHex(p1, p2, 0)
#define DBG_GetHexDef(p1, p2, p3)                           __DBG_GetHex(p1, p2, p3)
#define DBG_TraceDec(p1, p2)                                __DBG_TraceDec(p1, p2)
#define DBG_GetDec(p1, p2)                                  __DBG_GetDec(p1, p2, 0)
#define DBG_GetDecDef(p1, p2, p3)                           __DBG_GetDec(p1, p2, p3)
#define DBG_BreakPoint(p)                                   __DBG_BreakPoint(p)
#define DBG_MemSet(p1, p2, p3)                              MemSet(p1, p2, p3);

#define DBG_FILELINE                                        { DBG_TraceDec("@", __LINE__); DBG_TraceString((U8*)(__FILE__)); }

