
#include "_Platform.h"
#ifdef INCLUDE_MODULE_LCD

/*
    Bug:

    1. DMA chain will cause  LCD Disable-Done lost.
             Test:
             1> Use DMA chain
             2> Disable LCD
             3> Repeat this test

             Workaround: use DMA branch to use single DMA descriptor.

    2. Base DMA brach will cause problem.
             Test:
             1> Use single DMA descriptor and base frame buffer is in SRAM.
             2> Call branch function: base display is all right at this time.
             3> Enable overlay1
             4> Disable overlay 1: base display is not right at this time.

    3. LCCR6 could be only write once after LCD enabled.
             Test:
             1> Enable LCD.
             2> Turn off fetching base frame data using LCCR6.
             3> Turn on fetching base frame data. LCD will not work now.

             Workaround: Before changing LCCR6, always disable LCD controller.

    4. If we read LCCR0 after PXA310 reset, the program will crash!!!
       So, we can not invoke LCD_Disable in MOBM startup beginning.
*/

//
// LCD Controller Register Summary
//
#define     LCD_LCCR0                   (*MH_LCCR0)
#define     LCD_LCCR1                   (*MH_LCCR1)
#define     LCD_LCCR2                   (*MH_LCCR2)
#define     LCD_LCCR3                   (*MH_LCCR3)
#define     LCD_LCCR4                   (*MH_LCCR4)
#define     LCD_LCCR5                   (*MH_LCCR5)
#define     LCD_LCCR6                   (*MH_LCCR6)
#define     LCD_FBR0                    (*MH_FBR0)
#define     LCD_FBR1                    (*MH_FBR1)
#define     LCD_FBR2                    (*MH_FBR2)
#define     LCD_FBR3                    (*MH_FBR3)
#define     LCD_FBR4                    (*MH_FBR4)
#define     LCD_LCSR1                   (*MH_LCSR1)
#define     LCD_LCSR0                   (*MH_LCSR0)
#define     LCD_LIIDR                   (*MH_LIIDR)
#define     LCD_TRGBR                   (*MH_TRGBR)
#define     LCD_TCR                     (*MH_TCR)
#define     LCD_OVL1C1                  (*MH_OVL1C1)
#define     LCD_OVL1C2                  (*MH_OVL1C2)
#define     LCD_OVL2C1                  (*MH_OVL2C1)
#define     LCD_OVL2C2                  (*MH_OVL2C2)
#define     LCD_CCR                     (*MH_CCR)
#define     LCD_CMDCR                   (*MH_CMDCR)
#define     LCD_PRSR                    (*MH_PRSR)
#define     LCD_FBR5                    (*MH_FBR5)
#define     LCD_FBR6                    (*MH_FBR6)
#define     LCD_FDADR0                  (*MH_FDADR0)
#define     LCD_FSADR0                  (*MH_FSADR0)
#define     LCD_FIDR0                   (*MH_FIDR0)
#define     LCD_LDCMD0                  (*MH_LDCMD0)
#define     LCD_FDADR1                  (*MH_FDADR1)
#define     LCD_FSADR1                  (*MH_FSADR1)
#define     LCD_FIDR1                   (*MH_FIDR1)
#define     LCD_LDCMD1                  (*MH_LDCMD1)
#define     LCD_FDADR2                  (*MH_FDADR2)
#define     LCD_FSADR2                  (*MH_FSADR2)
#define     LCD_FIDR2                   (*MH_FIDR2)
#define     LCD_LDCMD2                  (*MH_LDCMD2)
#define     LCD_FDADR3                  (*MH_FDADR3)
#define     LCD_FSADR3                  (*MH_FSADR3)
#define     LCD_FIDR3                   (*MH_FIDR3)
#define     LCD_LDCMD3                  (*MH_LDCMD3)
#define     LCD_FDADR4                  (*MH_FDADR4)
#define     LCD_FSADR4                  (*MH_FSADR4)
#define     LCD_FIDR4                   (*MH_FIDR4)
#define     LCD_LDCMD4                  (*MH_LDCMD4)
#define     LCD_FDADR5                  (*MH_FDADR5)
#define     LCD_FSADR5                  (*MH_FSADR5)
#define     LCD_FIDR5                   (*MH_FIDR5)
#define     LCD_LDCMD5                  (*MH_LDCMD5)
#define     LCD_FDADR6                  (*MH_FDADR6)
#define     LCD_FSADR6                  (*MH_FSADR6)
#define     LCD_FIDR6                   (*MH_FIDR6)
#define     LCD_LDCMD6                  (*MH_LDCMD6)
#define     LCD_LCDBSCNTR               (*MH_LCDBSCNTR)

#define LCD_LCCR0_VAL                   ( \
                                        LCCR0_OUC |\
                                        LCCR0_CMDIM | \
                                        LCCR0_RDSTM | LCCR0_OUM | LCCR0_BM | \
                                        LCCR0_PDD(0) | \
                                        LCCR0_QDM | \
                                        LCCR0_PAS | LCCR0_EFM | LCCR0_IUM | LCCR0_SFM | \
                                        LCCR0_LDM | LCCR0_ENB \
                                        )

#define LCD_LCCR1_VAL                   ( \
                                        LCCR1_BLW(LCCR1_BLW_BEGIN_OF_LINE_WAIT) | \
                                        LCCR1_ELW(LCCR1_ELW_END_OF_LINE_WAIT) | \
                                        LCCR1_HSW(LCCR1_HSW_LSYNC_PULSE_WIDTH) | \
                                        LCCR1_PPL(LCD_WIDTH) \
                                        )

#define LCD_LCCR2_VAL                   ( \
                                        LCCR2_BFW(LCCR2_BFW_BEGIN_OF_FRAME_WAIT) | \
                                        LCCR2_EFW(LCCR2_EFW_END_OF_FRAME_WAIT) | \
                                        LCCR2_VSW(LCCR2_VSW_FSYNC_PULSE_WIDTH) | \
                                        LCCR2_LPP(LCD_HEIGHT) \
                                        )

#define LCD_LCCR3_VAL                   ( \
                                        LCCR3_PDFOR(PDFOR_FORMAT1) | \
                                        LCCR3_BPP(LCCR3_BPP_BIT_PER_PIXEL) | \
                                        LCCR3_PCP(LCCR3_PCP_PIXEL_CLK_POLARITY) | \
                                        LCCR3_HSP(LCCR3_HSP_HORI_SYNC_POLARITY) | \
                                        LCCR3_VSP(LCCR3_VSP_VERT_SYNC_POLARITY) | \
                                        LCCR3_API(0) | \
                                        LCCR3_ACB(0) | \
                                        LCCR3_PCD(LCCR3_PCD_PIXEL_CLK_DIVIDE) \
                                        )

#define LCD_LCCR4_VAL                   ( \
                                        LCCR4_PCD_DIV(LCCR4_PCD_DIV_FORMULA_SEL) | \
                                        LCCR4_PAL_FOR(PAL_PDFOR_16BIT_NO_TRANSPARENCY) | \
                                        LCCR4_K3(0) | \
                                        LCCR4_K2(0) | \
                                        LCCR4_K1(0) \
                                        )

#define LCD_OVL1C1_VAL                  ( \
                                        OVL1C1_BPP1(BPP1_25BIT) | \
                                        OVL1C1_LPO1(OVERLAY1_HEIGHT - 1) | \
                                        OVL1C1_PPL1(OVERLAY1_WIDTH - 1) \
                                        )

#define LCD_OVL1C2_VAL                  ( \
                                        OVL1C2_01YPOS(40) | \
                                        OVL1C2_O1XPOS(60) \
                                        )

// BPP2_16BIT: The MSB is the transparent bit.
#define LCD_OVL2C1_VAL                  ( \
                                        OVL2C1_BPP2(BPP2_16BIT) | \
                                        OVL2C1_LPO2(OVERLAY2_HEIGHT - 1) | \
                                        OVL2C1_PPL2(OVERLAY2_WIDTH - 1) \
                                        )

#ifdef OVERLAY2_MODE_RGB
#define LCD_OVL2C2_VAL                  ( \
                                        OVL2C1_FOR(OL2_FOR_RGB) | \
                                        OVL2C1_O2YPOS(30) | \
                                        OVL2C1_O2XPOS(60) \
                                        )
#endif
#ifdef OVERLAY2_MODE_YUV
#define LCD_OVL2C2_VAL                  ( \
                                        OVL2C1_FOR(OL2_FOR_YUV422PL) | \
                                        OVL2C1_O2YPOS(30) | \
                                        OVL2C1_O2XPOS(60) \
                                        )
#endif

const static LCD_DMA_Descriptor_t tDMADescBase = {
    DMA_DESC_LCD_BASE_ADDR,
    FB_BASE_RGB565_ADDR,
    0,
    FB_BASE_RGB565_SIZE
};

// Test case: Descriptor Link for discrete frame buffer
#define DIVID_RATIO                     4
#define BUF_RATIO_1                     1
#define BUF_RATIO_2                     (DIVID_RATIO - BUF_RATIO_1)

#define BUF_SIZE_1                      ((BUF_RATIO_1) * (FB_BASE_RGB565_SIZE/DIVID_RATIO))
#define BUF_SIZE_2                      ((BUF_RATIO_2)  * (FB_BASE_RGB565_SIZE/DIVID_RATIO))
#define BUF_ADDR_1                      (FB_BASE_RGB565_ADDR)
//#define BUF_ADDR_2                    (FB_BASE_RGB565_ADDR + BUF_SIZE_1)
//#define BUF_ADDR_2                    FB_BASE_RGB565_ADDR
//#define BUF_ADDR_2                    0
#define BUF_ADDR_2                      BUFFER_XMODEM_FILE_BASE

#ifdef  TEST_LCD_DMA_DESC_LINK
const static LCD_DMA_Descriptor_t tDMADescBase_D[] = {
    {
    DMA_DESC_LCD_BASE_ADDR + sizeof(LCD_DMA_Descriptor_t),
    BUF_ADDR_1,
    0,
    BUF_SIZE_1
    },
    {
    DMA_DESC_LCD_BASE_ADDR,
    BUF_ADDR_2,
    0,
    BUF_SIZE_2
    }
};
#endif

const static LCD_DMA_Descriptor_t tDMADescOL1 = {
    DMA_DESC_LCD_OL1_RGB_ADDR,
    FB_OVERLAY1_RGB_ADDR, //BUFFER_CAMERA_BASE, //FB_OVERLAY1_RGB_ADDR,
    0,
    FB_OVERLAY1_RGB_SIZE
};

const static LCD_DMA_Descriptor_t tDMADescOL2 = {
    DMA_DESC_LCD_OL2_RGB_ADDR,
    FB_OVERLAY2_RGB_ADDR, //BUFFER_CAMERA_BASE,  //FB_OVERLAY2_RGB_ADDR,
    0,
    FB_OVERLAY2_RGB_SIZE
};

const static LCD_DMA_Descriptor_t tDMADescOL2_Y = {
    DMA_DESC_LCD_OL2_Y_ADDR,
    FB_OVERLAY2_Y_ADDR,
    0,
    FB_OVERLAY2_Y_SIZE
};

const static LCD_DMA_Descriptor_t tDMADescOL2_U = {
    DMA_DESC_LCD_OL2_U_ADDR,
    FB_OVERLAY2_U_ADDR,
    0,
    FB_OVERLAY2_U_SIZE
};

const static LCD_DMA_Descriptor_t tDMADescOL2_V = {
    DMA_DESC_LCD_OL2_V_ADDR,
    FB_OVERLAY2_V_ADDR,
    0,
    FB_OVERLAY2_V_SIZE
};

//*******************************************************************************************

void LCD_FBBaseSet(U32 dwAddress)
{
    LCD_DMA_Descriptor_t *p;

    p = (LCD_DMA_Descriptor_t *)DMA_DESC_LCD_BASE_ADDR;
    p->dwSourceAddr = dwAddress;
}

void LCD_BaseBranch(void)
{
    const static LCD_DMA_Descriptor_t branch = {
        DMA_DESC_LCD_BRANCH_ADDR,
        FB_BASE_RGB565_ADDR,
        0,
        FB_BASE_RGB565_SIZE | LDCMDx_EOFInt
    };

    MemCopy((void*)DMA_DESC_LCD_BRANCH_ADDR,     (void*)(&branch),             DMA_DESC_LCD_BRANCH_SIZE);

    DBG_TraceStrLine("Base Branch ... ");

    LCD_FBR0 = DMA_DESC_LCD_BRANCH_ADDR | FBRx_BINT | FBRx_BRA;

    while(!((LCD_LCSR0) & LCSR0_BS0)) { ; }
    LCD_LCSR0 = LCSR0_BS0;

    LCD_FBR0 = DMA_DESC_LCD_BRANCH_ADDR;
    DBG_TraceStrLine("Done");
}

BOOL LCD_Initial(void)
{
    if((SYS_SRAM_BASE + SYS_SRAM_SIZE)   <  DMA_END_ADDR)
    {
        DBG_TraceStrLine("SRAM overflow!");
        return(FALSE);
    }

#ifdef  TEST_LCD_DMA_DESC_LINK
    MemCopy((void*)DMA_DESC_LCD_BASE_ADDR,     (void*)(&tDMADescBase_D),      sizeof(tDMADescBase_D));
#else
    MemCopy((void*)DMA_DESC_LCD_BASE_ADDR,     (void*)(&tDMADescBase),        DMA_DESC_LCD_BASE_SIZE);
#endif

    MemCopy((void*)DMA_DESC_LCD_OL1_RGB_ADDR,  (void*)(&tDMADescOL1),         DMA_DESC_LCD_OL1_RGB_SIZE);
    MemCopy((void*)DMA_DESC_LCD_OL2_RGB_ADDR,  (void*)(&tDMADescOL2),         DMA_DESC_LCD_OL2_RGB_SIZE);

    MemCopy((void*)DMA_DESC_LCD_OL2_Y_ADDR,    (void*)(&tDMADescOL2_Y),       DMA_DESC_LCD_OL2_Y_SIZE);
    MemCopy((void*)DMA_DESC_LCD_OL2_U_ADDR,    (void*)(&tDMADescOL2_U),       DMA_DESC_LCD_OL2_U_SIZE);
    MemCopy((void*)DMA_DESC_LCD_OL2_V_ADDR,    (void*)(&tDMADescOL2_V),       DMA_DESC_LCD_OL2_V_SIZE);

    return(TRUE);
}

void LCD_Enable(void)
{
    DBG_TraceStrLine("LCD Enable");

    if(LCD_LCCR0 != 0)
    {
        DBG_TraceStrLine("Cannot enable two times without disable");
        DBG_TraceHex("LCCR0", LCD_LCCR0);
        return;
    }

    LCD_LCCR1 =   LCD_LCCR1_VAL;
    LCD_LCCR2 =   LCD_LCCR2_VAL;
    LCD_LCCR3 =   LCD_LCCR3_VAL;
    LCD_LCCR4 =   LCD_LCCR4_VAL;

    // DMA
    LCD_FDADR0 = DMA_DESC_LCD_BASE_ADDR;

    LCD_LCCR0 =  LCD_LCCR0_VAL;

    return;
}

void LCD_Disable(void)
{
    if(LCD_LCCR0 == 0)
    {
        DBG_TraceStrLine("Cannot disable two times without enable");
        DBG_TraceHex("LCCR0", LCD_LCCR0);
        return;
    }

    DBG_TraceStrLine("LCD Disable ... ");

    LCD_LCCR0 |= LCCR0_DIS;
    while ((LCD_LCSR0 & LCSR0_LDD)==0);
    DBG_TraceString("Done");

    LCD_LCSR0 = LCSR0_LDD;

    LCD_LCCR0 = 0;
//    LCD_LCSR0 = 0x000007FF;     // sticky - clear register

    return;
}

void LCD_QuickEnable(void)
{
    DBG_TraceStrLine("Quick Enable");

    // DMA
    LCD_FDADR0 = DMA_DESC_LCD_PALETTE_ADDR;

    LCD_LCCR0 |= LCCR0_ENB;

    return;
}

void LCD_QuickDisable(void)
{
    DBG_TraceStrLine("Quick Disable ...");

    LCD_LCCR0 &=~ LCCR0_ENB;
    while(!((LCD_LCSR0) & LCSR0_QD)) { ; }
    DBG_TraceStrLine("Done");

    LCD_LCSR0 = LCSR0_QD;

    return;
}

void LCD_Overlay1Enable(void)
{
    DBG_TraceStrLine("OL1 Enable");

    if((LCD_OVL1C1 & OVL1C1_O1EN) == OVL1C1_O1EN)
    {
        DBG_TraceStrLine("Cannot enable two times without disable");
//        return; // Let BUG happen!!
    }

    LCD_OVL1C1 = LCD_OVL1C1_VAL;
    LCD_OVL1C2 = LCD_OVL1C2_VAL;

    // DMA
    LCD_FDADR1 = DMA_DESC_LCD_OL1_RGB_ADDR;

    LCD_OVL1C1 |= OVL1C1_O1EN;
}

void LCD_Overlay1Disable(void)
{
    const static LCD_DMA_Descriptor_t branch1 = {
        DMA_DESC_LCD_OL1_RGB_ADDR,
        FB_OVERLAY1_RGB_ADDR,
        0,
        FB_OVERLAY1_RGB_SIZE | LDCMDx_EOFInt
    };

    if((LCD_OVL1C1 & OVL1C1_O1EN) == 0)
    {
        DBG_TraceStrLine("Cannot disable two times without enable");
        return;
    }

    MemCopy((void*)DMA_DESC_LCD_BRANCH_ADDR,     (void*)(&branch1),      DMA_DESC_LCD_BRANCH_SIZE);

    DBG_TraceStrLine("OL1 Disable");

#if 0
    DBG_TraceStrLine("LCSR1 value");
    while(!DBG_GotEvent)
    {
        DBG_TraceHex(NULL, (U32)(LCD_LCSR1));
        DBG_TraceString("\r");
    }
    DBG_GET_BYTE;
#endif

    LCD_OVL1C1 &=~ OVL1C1_O1EN;
    LCD_FBR1 = DMA_DESC_LCD_BRANCH_ADDR | FBRx_BINT | FBRx_BRA;

#if 0
    while(!DBG_GotEvent)
    {
        DBG_TraceHex(NULL, (U32)(LCD_LCSR1));
        DBG_TraceString("\r");
    }
    DBG_GET_BYTE;
#else
    while(!((LCD_LCSR1) & LCSR1_BS1)) { ; }
#endif

    LCD_LCSR1 = LCSR1_BS1;
    LCD_FBR1 = DMA_DESC_LCD_BRANCH_ADDR;
}

void LCD_Overlay2Enable(void)
{
    if((LCD_OVL2C1 & OVL2C1_O2EN) == OVL2C1_O2EN)
    {
        DBG_TraceStrLine("Cannot enable two times without disable");
        return;
    }

    DBG_TraceStrLine("OL2 Enable");

    LCD_OVL2C1 = LCD_OVL2C1_VAL;
    LCD_OVL2C2 = LCD_OVL2C2_VAL;

    // DMA
#ifdef OVERLAY2_MODE_RGB
    LCD_FDADR2 = DMA_DESC_LCD_OL2_RGB_ADDR;
#endif
#ifdef OVERLAY2_MODE_YUV
    LCD_FDADR2 = DMA_DESC_LCD_OL2_Y_ADDR;
    LCD_FDADR3 = DMA_DESC_LCD_OL2_U_ADDR;
    LCD_FDADR4 = DMA_DESC_LCD_OL2_V_ADDR;
#endif

    LCD_OVL2C1 |= OVL2C1_O2EN;
}

void LCD_Overlay2Disable(void)
{
#ifdef OVERLAY2_MODE_RGB
    const static LCD_DMA_Descriptor_t branch2 = {
        DMA_DESC_LCD_OL2_RGB_ADDR,
        FB_OVERLAY2_RGB_ADDR,
        0,
        FB_OVERLAY2_RGB_SIZE | LDCMDx_EOFInt
    };
#endif
#ifdef OVERLAY2_MODE_YUV
    const static LCD_DMA_Descriptor_t branch2Y = {
        DMA_DESC_LCD_OL2_Y_ADDR,
        FB_OVERLAY2_Y_ADDR,
        0,
        FB_OVERLAY2_Y_SIZE | LDCMDx_EOFInt
    };
    const static LCD_DMA_Descriptor_t branch2U = {
        DMA_DESC_LCD_OL2_U_ADDR,
        FB_OVERLAY2_U_ADDR,
        0,
        FB_OVERLAY2_U_SIZE | LDCMDx_EOFInt
    };
    const static LCD_DMA_Descriptor_t branch2V = {
        DMA_DESC_LCD_OL2_V_ADDR,
        FB_OVERLAY2_V_ADDR,
        0,
        FB_OVERLAY2_V_SIZE | LDCMDx_EOFInt
    };
#endif

    if((LCD_OVL2C1 & OVL2C1_O2EN) == 0)
    {
        DBG_TraceStrLine("Cannot disable two times without enable");
        return;
    }

#ifdef OVERLAY2_MODE_RGB
    MemCopy((void*)DMA_DESC_LCD_BRANCH_ADDR,     (void*)(&branch2),      DMA_DESC_LCD_BRANCH_SIZE);
#endif
#ifdef OVERLAY2_MODE_YUV
    MemCopy((void*)DMA_DESC_LCD_BRANCH_Y_ADDR,   (void*)(&branch2Y),     DMA_DESC_LCD_BRANCH_Y_SIZE);
    MemCopy((void*)DMA_DESC_LCD_BRANCH_U_ADDR,   (void*)(&branch2U),     DMA_DESC_LCD_BRANCH_U_SIZE);
    MemCopy((void*)DMA_DESC_LCD_BRANCH_V_ADDR,   (void*)(&branch2V),     DMA_DESC_LCD_BRANCH_V_SIZE);
#endif

    DBG_TraceStrLine("OL2 Disable");

#if 0
    DBG_TraceStrLine("LCSR1 value");
    while(!DBG_GotEvent)
    {
        DBG_TraceHex(NULL, (U32)(LCD_LCSR1));
        DBG_TraceString("\r");
    }
    DBG_GET_BYTE;
#endif

    LCD_OVL2C1 &=~ OVL2C1_O2EN;
#ifdef OVERLAY2_MODE_RGB
    LCD_FBR2 = DMA_DESC_LCD_BRANCH_ADDR | FBRx_BINT | FBRx_BRA;
#endif
#ifdef OVERLAY2_MODE_YUV
    LCD_FBR2 = DMA_DESC_LCD_BRANCH_Y_ADDR | FBRx_BINT | FBRx_BRA;
    LCD_FBR3 = DMA_DESC_LCD_BRANCH_U_ADDR | FBRx_BINT | FBRx_BRA;
    LCD_FBR4 = DMA_DESC_LCD_BRANCH_V_ADDR | FBRx_BINT | FBRx_BRA;
#endif

#if 0
    while(!DBG_GotEvent)
    {
        DBG_TraceHex(NULL, (U32)(LCD_LCSR1));
        DBG_TraceString("\r");
    }
    DBG_GET_BYTE;
#else
    while((LCSR1_BS2 |LCSR1_BS2 |LCSR1_BS2) != ((LCD_LCSR1) & (LCSR1_BS2 |LCSR1_BS2 |LCSR1_BS2))) { ; }
#endif

#ifdef OVERLAY2_MODE_RGB
    LCD_LCSR1 = LCSR1_BS2;
#endif
#ifdef OVERLAY2_MODE_YUV
    LCD_LCSR1 = LCSR1_BS2;
    LCD_LCSR1 = LCSR1_BS3;
    LCD_LCSR1 = LCSR1_BS4;
#endif

#ifdef OVERLAY2_MODE_RGB
    LCD_FBR2 = DMA_DESC_LCD_BRANCH_ADDR;
#endif
#ifdef OVERLAY2_MODE_YUV
    LCD_FBR2 = DMA_DESC_LCD_BRANCH_Y_ADDR;
    LCD_FBR3 = DMA_DESC_LCD_BRANCH_U_ADDR;
    LCD_FBR4 = DMA_DESC_LCD_BRANCH_V_ADDR;
#endif
}

void LCD_BaseFrameDMAOff(U32 dwRed, U32 dwGreen, U32 dwBlue)
{
    LCD_LCCR6 = LCCR6_BF_OFF | LCCR6_B_BLUE(dwBlue) | LCCR6_B_GREEN(dwGreen) | LCCR6_B_RED(dwRed);
}

void LCD_BaseFrameDMAOn(void)
{
    LCD_LCCR6 = 0;
}

#endif

