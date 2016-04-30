
                    .include    "Platform.inc"

                    .global     DDRSDRAMInitial

                    .extern     ExceptionHandler
                    .extern     SWI_Handler
                    .extern     IRQ_Handler
                    .extern     FIQ_Handler
                    .extern     g_PlatformName

                    .equ        CPSR_Mode_USR,       0x10
                    .equ        CPSR_Mode_FIQ,       0x11
                    .equ        CPSR_Mode_IRQ,       0x12
                    .equ        CPSR_Mode_SVC,       0x13
                    .equ        CPSR_Mode_ABT,       0x17
                    .equ        CPSR_Mode_UND,       0x1B
                    .equ        CPSR_Mode_SYS,       0x1F
                    .equ        CPSR_Mode_Mask,      0x1F

                    .equ        CPSR_I_Bit,          0x80
                    .equ        CPSR_F_Bit,          0x40

/*******************************************************************************************
 CPWAIT
 r0 will be changed!
*******************************************************************************************/
                    .macro CPWAIT

                    mrc         p15,        0, r0, c2, c0, 0                /* arbitrary read of cp15 */
                    mov         r0,         r0                              /* wait for it */
                    sub         pc,         pc, #4

                    .endm

/*******************************************************************************************
  Program execution starts here.

  The Bootrom copies the first block of NAND into SRAM and jump to SRAM to run.
  The address of SRAM is 0x5C010000(A1) or 0x5C014000 (B1).

  The beginning of SRAM from 0x5C000000 cannot be used. It is dangerous especially when XDB is used! This should be a bug of XDB & MH!!**??????**
  8 byte zeroes are required at start of the image by B0 or after B0 boot ROM.
  We do not know if the Bootrom will copy from 8th byte from NAND or Bootrom will copy first block NAND to 0x5C013FF8 (B1).  **???????**
*******************************************************************************************/

#                    .section startup

                    .align  4

START:

/*******************************************************************************************
 Vector table
*******************************************************************************************/

VECTOR_TABLE:
                    b           HW_RESET
                    ldr         PC, VECTOR_Undefined
                    ldr         PC, VECTOR_SWI
                    ldr         PC, VECTOR_Prefetch
                    ldr         PC, VECTOR_Abort
                    ldr         PC, VECTOR_Reserve
                    ldr         PC, VECTOR_IRQ
                    ldr         PC, VECTOR_FIQ

PLATFORM_NAME:      .long       g_PlatformName

VECTOR_Undefined:   .long       EXC_UndefInstruction
VECTOR_SWI:         .long       INT_SWI
VECTOR_Prefetch:    .long       EXC_PrefetchAbort
VECTOR_Abort:       .long       EXC_DataAbort
VECTOR_Reserve:     .long       EXC_Reserve
VECTOR_IRQ:         .long       INT_IRQ
VECTOR_FIQ:         .long       INT_FIQ

/*******************************************************************************************
 Exception
*******************************************************************************************/

EXC_UndefInstruction:
                    ldr         r0, =1
                    b           EXC_DefaultProcess

EXC_PrefetchAbort:
                    ldr         r0, =2
                    b           EXC_DefaultProcess

EXC_DataAbort:
                    ldr         r0, =3
                    b           EXC_DefaultProcess

EXC_Reserve:
                    ldr         r0, =4
                    b           EXC_DefaultProcess

EXC_DefaultProcess:
                    mov         r1, fp
                    mov         r2, lr
                    bl          ExceptionHandler
EXC_DefaultLoop:
                    b           EXC_DefaultLoop

/*******************************************************************************************
 Interrupt
*******************************************************************************************/
API_TARGET:
                    .long       0

INT_SWI:
                    stmfd       sp!,        {r0-r1, lr}

                    mrs         r0,         spsr
                    stmfd       sp!,        {r0}

                    ldr         r0,         [lr, #-4]                           /* get the 'swi' number */
                    bic         r0,         r0, #0xff000000

#lllll:              b lllll
#                    bl          SWI_Handler                                     /* !!! Function call will not protect the registers !!! */

                    ldr         r1,         =API_ENTRANCE
                    add         r1,         r1, r0, lsl#2                       /* r1 = r1 + (r0 * 4) */
                    ldr         r0,         [r1]
                    ldr         r1,         =API_TARGET
                    str         r0,         [r1]

                    ldmfd       sp!,        {r0}
                    msr         spsr,       r0

                    ldmfd       sp!,        {r0-r1, lr}

                    mrs         lr,         spsr
                    msr         cpsr,       lr

                    ldr         pc,         API_TARGET


INT_IRQ:
                    sub         lr,         lr, #4
                    stmfd       sp!,        {r0-r12,lr}

                    bl          IRQ_Handler

                    ldmfd       sp!,        {r0-r12,pc}^

INT_FIQ:
                    sub         lr,         lr, #4
                    stmfd       sp!,        {r0-r12,lr}

                    bl          FIQ_Handler

                    ldmfd       sp!,        {r0-r12,pc}^

/*******************************************************************************************
 HW_Reset from here
*******************************************************************************************/
HW_RESET:

                    /* ARM core initial */

                    /* Put the processor into SVC mode with interrupts disabled (IRQ and FIQ). */
                    ldr         r0,         =(CPSR_I_Bit | CPSR_F_Bit | CPSR_Mode_SVC)
                    msr         CPSR,       r0

                    /* Processor Initial */
                    bl          EnableCoprocessor
                    bl          EnableAccessAllDomain
                    bl          SetFrequency

                    bl          TurnOffCache

                    /* Memory Initial */
.equ                SYS_SRAM_MASK,          0x03FFFFFF

                    adr         r0,         VECTOR_TABLE
                    bic         r0,         r0, #SYS_SRAM_MASK
                    ldr         r1,         =SYS_SRAM_BASE
                    cmp         r0,         r1
                    bne         DDR_INITIAL_DONE                    /* IF the current program is NOT executing in SRAM */
                    bl          DDRSDRAMInitial                     /* We will skip DDR initial. (We suppose the DDR is ready for use.) */
DDR_INITIAL_DONE:

/* ONLY need to do this in MOBM */
                    bl          GotoTarget

                    /* Pins Configure */

                    bl          TurnOnAllClocks

                    /* Prepare to Run */
                    bl          CopyRunningCodeToTarget

                    ldr         pc,         TARGET_GOON_ADDRESS

                    nop
                    nop
GO_INTO_TARGET_POINT:
                    nop
                    nop

/*******************************************************************************************
   Now jump to 'C'
*******************************************************************************************/
/*
    Disorder "InitialStack, MMU Enable & CPSR setting" may cause bug!!!
    So, please be careful when touch these parts: InitialStack, MMU Function Call, and CPSR setting
*/

                    .extern     MMUSetup

                    bl          InitialStack                        /* Just to clear the I-bit and F-bit again. This is the workarround for the MMU bug. */
                    bl          MMUSetup

                    .extern     Startup

                    bl          InitialStack                        /* Just to clear the I-bit and F-bit again. This is the workarround for the MMU bug. */

                    ldr         r1,         =__end_bss
                    adr         r0,         VECTOR_TABLE
                    mov         fp,         #0
                    bl          Startup

#####                    mov         r0,         #(CPSR_Mode_SYS)        /* Enable I-bit & F-bit */
#####                    msr         CPSR,       r0

                    .extern     Main
MAINLOOP:
                    bl          Main

                    b           MAINLOOP


/********************************************************************
  Used to correct the PC pointer to the Target Address
********************************************************************/
                    .align      4
TARGET_GOON_ADDRESS:
                    .long       GO_INTO_TARGET_POINT

/*/*******************************************************************
;   If it is reset from WM suspend, we will go to resume
;*******************************************************************/
.equ                PSPR_GOTO_WM_RESUME,    (0x475404)
.equ                PSPR_MASK_GOTO,         (0xFFFFFF)

                    .align      4
                    .type       GotoTarget,function
GotoTarget:
                    /* Check Hardware Reset source */
                    ldr         r0,        =MH_ARSR
                    ldr         r1,        [r0]
                    ldr         r0,        =0
                    cmp         r1,        r0                       /* ANY RESET, except 'Sleep Wake Up', */
                    bne         GotoTarget_RETURN                   /* MUST go through Boot Up Process    */

                    /* Check OEM Defined Reset source */
                    ldr         r0,        =MH_PSPR
                    ldr         r1,        [r0]
                    ldr         r0,        =PSPR_MASK_GOTO
                    and         r1,        r1, r0
                    ldr         r0,        =PSPR_GOTO_WM_RESUME
                    cmp         r0,        r1
                    bne         GotoTarget_RETURN

                    /* Resume */
                    ldr         r1,        =0x80800000
                    ldr         r2,        =0x80800004
                    ldr         r0,        [r2]
                    ldr         pc,        [r1]

GotoTarget_RETURN:
                    mov         pc,         lr

/*******************************************************************
   No matter where we are, we will copy the code to the Target
*******************************************************************/

                    .align      4
                    .type       CopyRunningCodeToTarget,function
CopyRunningCodeToTarget:

                    adr         r0,         VECTOR_TABLE
                    ldr         r1,         =__start_copy
                    cmp         r0,         r1
                    beq         COPY_CODE_RETURN

                    ldr         r2,         =__end_copy

GOON_COPYCODE:
                    ldmia       r0!,        {r3 - r12}
                    stmia       r1!,        {r3 - r12}
                    cmp         r2,         r1
                    bge         GOON_COPYCODE

COPY_CODE_RETURN:
                    mov         pc,         lr



/*******************************************************************
  Turn off caches, flush caches, flush tlb's, drain write buffer, etc.
*******************************************************************/

                    .align      4
                    .type       TurnOffCache,function
TurnOffCache:

                    mov         r0,         #0x78                           /* zero to off (bit[6:3] must be 1) */
                    mcr         p15,        0, r0, c1, c0, 0                /* caches off -- MMU off or ID map */
                    CPWAIT
                    mcr         p15,        0, r0, c7, c7, 0                /* Invalidate the I & D cache, and BTB -- r0 ignored */
                    CPWAIT
                    mcr         p15,        0, r0, c8, c7, 0                /* Flush the I & D TLB -- r0 ignored */
                    CPWAIT
                    mcr         p15,        0, r0, c7, c10, 4               /* Drain write buffer */
                    CPWAIT

                    mov         pc,         lr

/********************************************************************
 Initial stack point
********************************************************************/
                    .align      4
                    .type       InitialStack,function
InitialStack:

                    ldr         r2,         =EXE_STACK_LAST

                    mov         r0,         #(CPSR_I_Bit | CPSR_F_Bit | CPSR_Mode_FIQ)
                    msr         CPSR,       r0
                    sub         r2,         r2, #EXE_STACK_INDIVIDUAL_SIZE
                    mov         SP,         r2

                    mov         r0,         #(CPSR_I_Bit | CPSR_F_Bit | CPSR_Mode_IRQ)
                    msr         CPSR,       r0
                    sub         r2,         r2, #EXE_STACK_INDIVIDUAL_SIZE
                    mov         SP,         r2

                    mov         r0,         #(CPSR_I_Bit | CPSR_F_Bit | CPSR_Mode_ABT)
                    msr         CPSR,       r0
                    sub         r2,         r2, #EXE_STACK_INDIVIDUAL_SIZE
                    mov         SP,         r2

                    mov         r0,         #(CPSR_I_Bit | CPSR_F_Bit | CPSR_Mode_UND)
                    msr         CPSR,       r0
                    sub         r2,         r2, #EXE_STACK_INDIVIDUAL_SIZE
                    mov         SP,         r2

                    mov         r0,         #(CPSR_I_Bit | CPSR_F_Bit | CPSR_Mode_SYS)
                    msr         CPSR,       r0
                    sub         r2,         r2, #EXE_STACK_INDIVIDUAL_SIZE
                    mov         SP,         r2

#####                    mov         r0,         #(CPSR_I_Bit | CPSR_F_Bit | CPSR_Mode_SVC)
                    mov         r0,         #(CPSR_Mode_SVC)
                    msr         CPSR,       r0
                    sub         r2,         r2, #EXE_STACK_INDIVIDUAL_SIZE
                    mov         SP,         r2

                    mov         pc,         lr

/********************************************************************
*   Initialize DDR SDRAM
********************************************************************/

.equ                RCOMP_SETALWAYS,        (0x1<<24)          /* Resistive compensation always_set bit */
.equ                RCOMP_RCRNG_VALUE,      (0x2<<25)          /* Resistive compensation range */
.equ                RCOMP_SWEVAL,           (0x1<<31)          /* set-Start an Rcomp evaluation cycle; Once cycle is complete, it will be cleared. */

.equ                MDCNFG_DCSE0,           (0x1<<0)           /* SDRAM partition enable */
.equ                MDCNFG_DCSE1,           (0x1<<1)
.equ                MDCNFG_DMCEN,           (0x1<<30)          /* Enable Dynamic Memory Controller */
.equ                MDCNFG_SETALWAYS,       (0x1<<31 | 0x1<<10)
.equ                MDCNFG_DTC,             (0x3<<8)           /* tRP=3clks,CL=3,tRCD=3clks,tRAS=6clks,tRC=10clks */
.equ                MDCNFG_DRAC,            (0x1<<5)           /* 13 row address bits */
.equ                MDCNFG_DCAC,            (0x1<<3)           /* 10 column address bits */
.equ                MDCNFG_DBW,             (0x1<<2)           /* 16 bits SDRAM data bus width */

.equ                MDMRS_MDCS0,            (0x1<<30)          /* Control assertion of chip select o during MRS command */
.equ                MDMRS_MDCOND,           (0x1<<29)          /* Control conditioning of SDRAM */

.equ                DMCISR_SLFREF,          (0x1<<7)           /* Self-Refresh Status bit */
.equ                DMCISR_DLP,             (0x1<<29)          /* Delay lines Programmed by Hardware Calibration(HC) */

.equ                DDR_RCOMP,              0x1                /* We add the RCOMP when initiliazing the DDR SDRAM */

                    .align      4
                    .type       DDRSDRAMInitial,function
DDRSDRAMInitial:

                    /* Disabling DDR to make sure its off before we configure it. */
                    ldr         r0,         =MH_MDCNFG
                    ldr         r3,         [r0]
                    bic         r3,         r3, #MDCNFG_DMCEN
                    str         r3,         [r0]
                    ldr         r3,         [r0]

                    /* STEP 1: Delay at least 100uS to allow internal clocks for SDCLK to stabilize. */
                    /* This is a required hardware reset power-on wait period. */

                    ldr         r0,         =MH_OSCR0
                    ldr         r2,         [r0]
                    add         r2,         r2, #0x150                      /* wait about 100uS */
DDR_STEP1:
                    ldr         r1,         [r0]
                    cmp         r1,         r2
                    bmi         DDR_STEP1

                    /* STEP 2: Set up EMPI register */

                    ldr         r4,         =MH_EMPI
                    ldr         r3,         =EMPI_VALUE
                    str         r3,         [r4]
                    ldr         r3,         [r4]

                    /* STEP 3: Program MDCNFG then enable the occupied DRAM partitions. */
                    /* MDCNFG[DMCEN] must remain deasserted! */

                    ldr         r2,         =(MDCNFG_SETALWAYS | MDCNFG_DTC | MDCNFG_DRAC | MDCNFG_DCAC | MDCNFG_DBW)
                    ldr         r4,         =MH_MDCNFG
                    str         r2,         [r4]
                    ldr         r2,         [r4]
                    orr         r2,         r2, #MDCNFG_DCSE0
                    str         r2,         [r4]
                    ldr         r2,         [r4]

                    /* Step 4: Wait a typical NOP power-up waiting period required by SDRAM (Typically */
                    /* 200 uS) Steps 5 & 6 can be executited during this waiting period. However, */
                    /* xlli will do the wait now and then perform steps 5 & 6. */

                    ldr         r0,         =MH_OSCR0
                    ldr         r2,         [r0]
                    add         r2,         r2, #0x2A0
DDR_STEP2:
                    ldr         r1,         [r0]
                    cmp         r1,         r2
                    bmi         DDR_STEP2

                    .ifdef DDR_RCOMP

                    /* In early silicon it has been observed that the Rcomp eval may not complete */
                    /* although the SWEVAL bit was set. The edits below will set this bit up to */
                    /* four times before exiting.

                    mov         r1,         #4                              /* Set up Rcomp retry loop count */

                    /* STEP 5: Perform Resistive Compensation calibration cycle (RCOMP) */

                    ldr         r4,         =MH_RCOMP
DDR_STEP3:
                    ldr         r3,         =(REI_VALUE | RCOMP_RCRNG_VALUE)
                    str         r3,         [r4]
                    /*Initiates an Rcomp evaluation cycle */
                    orr         r3,         r3, #RCOMP_SWEVAL
                    str         r3,         [r4]

                    /* Wait for Rcomp evaluation cycle to complete - RCOMP[SWEVAL] clears. */
                    /* A "time out" counter is in this loop - just in case the eval bit doesn't clear */
                    /* so there is an exit path. */

                    mov         r0,         #0x10000
DDR_STEP4:
                    ldr         r2,         [r4]
                    subs        r0,         r0, #1
                    beq         DDR_STEP9
                    ands        r2,         r2, #RCOMP_SWEVAL   /*check whether RCOMP_SWEVAL is cleared/complete. */
                    bne         DDR_STEP4

DDR_STEP8:
                    b           DDR_STEP10

DDR_STEP9:
                    subs        r1,         r1, #1                          /* Decrement re-try count */
                    bne         DDR_STEP3                                   /* Try again if count is not zero */
                    b           DDR_STEP8                                          /* Otherwise - time to give up on this... */

DDR_STEP10:

                    /* Change the default PAD register PCODE, NCODE, PSLEW, and NSLEW values */
                    /* to new dafault values as follows: */
                    /* All eight pad register sets are updated */

                    ldr         r2,         =PAD_VALUE_1
                    ldr         r1,         =MH_PADMDMSB
                    str         r2,         [r1]
                    ldr         r1,         =MH_PADMDLSB
                    str         r2,         [r1]

                    ldr         r2,         =PAD_VALUE_2
                    ldr         r1,         =MH_PADMA
                    str         r2,         [r1]
                    ldr         r1,         =MH_PADSDRAM
                    str         r2,         [r1]
                    ldr         r1,         =MH_PADSDCLK
                    str         r2,         [r1]
                    ldr         r1,         =MH_PADSDCS
                    str         r2,         [r1]
                    ldr         r1,         =MH_PADSMEM
                    str         r2,         [r1]
                    ldr         r1,         =MH_PADSCLK
                    str         r2,         [r1]

                    /* Setup DDR Hardware Calibration Register register with a preliminary value to */
                    /* configure the strobe data lines */
                    ldr         r1,         =MH_DDRHCAL
                    ldr         r2,         =DDRHCAL_VALUE
                    str         r2,         [r1]

                    /* Wait for hardware calibration to complete */
                    ldr         r4,         =MH_DMCISR
                    ldr         r1,         [r4]
                    ands        r1,         r1, #DMCISR_DLP
                    str         r1,         [r4]

                    .endif /* END IF DDR_RCOMP */

                    /* Take SDRAM out of self-refresh... */
                    ldr         r4,         =MH_DMCISR
                    mov         r0,         #DMCISR_SLFREF
                    str         r0,         [r4]
                    ldr         r0,         [r4]

                    /* STEP 6: Write the Mode Register Set Config Register (MDMRS) */
                    ldr         r0,         =MH_MDMRS
                    ldr         r2,         =(MDMRS_MDCS0 | MDMRS_MDCOND | MRS_COMMAND_VALUE)
                    str         r2,         [r0]
                    ldr         r2,         [r0]

                    /* STEP 7: Program the MDREFR with the desired refresh interval */
                    ldr         r0,         =MH_MDREFR
                    ldr         r1,         =DRI_VALUE
                    str         r1,         [r0]
                    ldr         r1,         [r0]

                    /* STEP 8: Enable the dynamic memory controller */
                    ldr         r0,         =MH_MDCNFG
                    ldr         r1,         [r0]
                    orr         r1,         r1, #MDCNFG_DMCEN
                    str         r1,         [r0]
                    ldr         r1,         [r0]

                    mov         pc,         lr

/********************************************************************
  Turn on all the clocks
********************************************************************/
                    .align      4
                    .type       TurnOnAllClocks,function
TurnOnAllClocks:

                    mvn         r0,         #0
                    ldr         r1,         =MH_D0CKENA
                    str         r0,         [r1]
                    ldr         r1,         =MH_D0CKENB
                    str         r0,         [r1]

                    mov         pc,         lr


/********************************************************************
 Set Frequency
********************************************************************/
                    .align      4
                    .type       SetFrequency,function
SetFrequency:

                    ldr         r1,         =MH_ACCR
                    ldr         r2,         =ACCR_VALUE
                    str         r2,         [r1]
                    ldr         r2,         [r1]

                    mov         r0,         #3                              /* (1<<1): Frequency Change; (1<<0): Turbo Mode */
                    mcr         p14,        0, r0, c6, c0, 0                /* initiate the frequency change sequence */
WAIT_FREQ_DONE:
                    ldr         r0,         [r1]
                    and         r0,         r0, r2
                    cmp         r0,         r2
                    bne         WAIT_FREQ_DONE                                        /* looping until the frequency change is finished */

                    mov         pc,         lr

/********************************************************************
 grant manager access to all domains
********************************************************************/
                    .align      4
                    .type       EnableAccessAllDomain,function
EnableAccessAllDomain:

                    mvn         r0,         #0
                    mcr         p15,        0, r0, c3, c0, 0

                    /* CPWAIT */
                    mrc         p15,        0, r0, c2, c0, 0
                    mov         r0,         r0
                    sub         pc,         pc, #4

                    mov         pc,         lr

/********************************************************************
 Enable all coprocessor registsers
********************************************************************/
                    .align      4
                    .type       EnableCoprocessor,function
EnableCoprocessor:

                    ldr         r0,         =0x00003FFF
                    mcr         p15,        0, r0, c15, c1, 0

                    /* CPWAIT */
                    mrc         p15,        0, r0, c2, c0, 0
                    mov         r0,         r0
                    sub         pc,         pc, #4

                    mov         pc,         lr

/********************************************************************
  Attach the MFPR values table
********************************************************************/

                    .macro      APIEntrance     NAME_FUNC, NAME_API

                    .extern     \NAME_FUNC
                    .long       \NAME_FUNC

                    .endm

#                    .section   tables
                    .align      4
#                    .ltorg
API_ENTRANCE:
                    .include    "_APIEntrance._s"

    .end

