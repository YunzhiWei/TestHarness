
                    .global              JumpToRun

                    .global              WriteClkCfg
                    .global              ReadClkCfg

                    .global              PWRMode_Set

                    .global              GetPC
                    .global              GetCPUInformation

                    .global              MMUBaseSet
                    .global              MMUEnable

                    .global              EnableICache
                    .global              EnableDCache

                    .global              DummyFunction

#                    .text

/*******************************************************************************************
 CPWAIT
 r0 will be changed!
*******************************************************************************************/
                    .macro CPWAIT

                    mrc                 p15,        0, r0, c2, c0, 0                /* arbitrary read of cp15 */
                    mov                 r0,         r0                              /* wait for it */
                    sub                 pc,         pc, #4

                    .endm

/*******************************************************************
 JumpToRun
   This function will never return.

*******************************************************************/

                    .align  4
                    .type   JumpToRun, function
JumpToRun:

                    mov                 pc,         r0


/*******************************************************************
 WriteClkCfg
*******************************************************************/

                    .align  4
                    .type   WriteClkCfg , function
WriteClkCfg :

                    mcr                 p14,        0, r0, c6, c0, 0                /* Write ClkCFG */
                    nop
                    nop
                    nop
                    nop

                    sub                 pc,         pc, #4

                    mov                 pc,         lr


/*******************************************************************
 ReadClkCfg
*******************************************************************/
                    .align  4
                    .type   ReadClkCfg , function
ReadClkCfg :

                    mrc                 p14,        0, r0, c6, c0, 0                /* Read clkcfg */
                    nop
                    nop
                    nop
                    nop

                    sub                 pc,         pc, #4

                    mov                 pc,         lr


/*******************************************************************
 CPU Mode Set
 r0 = mode (idle, standby, sleep ...)
*******************************************************************/
                    .align  4
                    .type   PWRMode_Set , function
PWRMode_Set :

                    mcr                 p14,        0, r0, c7, c0, 0

                    nop
                    nop
                    nop
                    nop
                    nop
                    nop

                    sub                 pc,         pc, #4

                    mov                 pc,         lr

/*******************************************************************
 Get PC
*******************************************************************/
                    .align  4
                    .type   GetPC , function
GetPC :

                    mov                 r0,         pc

                    sub                 pc,         pc, #4

                    mov                 pc,         lr


/*******************************************************************
 Return
*******************************************************************/

                    .align  4
                    .type   GetCPUInformation , function
GetCPUInformation :

                    mrc                 p15,        0, r0, c0, c0, 0
                    mov                 pc,         lr


/*******************************************************************

/******************************************************************/

                    .align  4
                    .type   MMUBaseSet , function
MMUBaseSet :

                    stmfd               sp!,        {r0, lr}                        /* The stack should be initialed!!! */

                    mcr                 p15,        0, r0, c2, c0

                    CPWAIT

                    ldmfd               sp!,        {r0, pc}^

                    mov                 pc,         lr


/*******************************************************************

*******************************************************************/

                    .align  4
                    .type   MMUEnable , function
MMUEnable :

                    stmfd               sp!,        {r0, lr}                        /* The stack should be initialed!!! */

                    mrc                 p15,        0, r0, c1, c0, 0                /* read cp15, register 1 */
                    mov                 r0,         r0, lsl #18                     /* clearing the upper 18-bits */
                    mov                 r0,         r0, lsr #18
                    orr                 r0,         r0, #0x1                        /* turn on the mmu */
                    mcr                 p15,        0, r0, c1, c0, 0                /* write to cp15, register 1 */

                    CPWAIT

                    ldmfd               sp!,        {r0, pc}^

                    mov                 pc,         lr


/*******************************************************************

*******************************************************************/

                    .align  4
                    .type   EnableICache , function
EnableICache :

                    stmfd               sp!,        {r0, lr}

                    mcr                 p15,        0, r0, c7, c5, 6                /* invalidate the branch target buffer */
                    mrc                 p15,        0, r0, c1, c0, 0                /* read the control register */
                    mov                 r0,         r0, lsl #18                     /* upper 18 bits must be */
                    mov                 r0,         r0, lsr #18                     /* written as zeros */
                    orr                 r0,         r0, #0x1000                     /* set bit 12 -- the i bit -- enable i-cache */
                    orr                 r0,         r0, #0x800                      /* set bit 11 -- the z bit -- enable branch target buffer */
                    mcr                 p15,        0, r0, c1, c0, 0                /* write the control register */

                    CPWAIT

                    ldmfd               sp!,        {r0, pc}^

                    mov                 pc,         lr

/*******************************************************************

*******************************************************************/

                    .align  4
                    .type   EnableDCache , function
EnableDCache :

                    stmfd               sp!,        {r0, lr}

                    mcr                 p15,        0, r0, c7, c10, 4               /* drain pending data operations... (see chapter 7.2.8, register 7: cache functions) */
                    mrc                 p15,        0, r0, c1, c0, 0                /* get current control register */
                    orr                 r0,         r0, #4                          /* enable dcache by setting ?c? (bit 2) */
                    mcr                 p15,        0, r0, c1, c0, 0                /* and update the control register */

                    CPWAIT

                    ldmfd               sp!,        {r0, pc}^

                    mov                 pc,         lr


/*******************************************************************
 Test for Fenq
*******************************************************************/
                    .align  4
                    .type   DummyFunction , function
DummyFunction :

                    nop
                    nop
                    nop
                    nop
                    subs                r0,         r0, #1
                    bne                 DummyFunction

                    mov                 pc,         lr


.end

