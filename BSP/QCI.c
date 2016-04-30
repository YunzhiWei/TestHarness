
#include "_Platform.h"

#ifdef INCLUDE_MODULE_QCI

// register

#define REG_CICR0                       (*MH_CICR0)
#define REG_CICR1                       (*MH_CICR1)
#define REG_CICR2                       (*MH_CICR2)
#define REG_CICR3                       (*MH_CICR3)
#define REG_CICR4                       (*MH_CICR4)

#define REG_CIDADR0                     (*MH_CIDADR0)
#define REG_CIDADR1                     (*MH_CIDADR1)
#define REG_CIDADR2                     (*MH_CIDADR2)
#define REG_CIFR0                       (*MH_CIFR0)

#define CIF_DMA_TARGET0                 MH_CIBR0
#define CIF_DMA_TARGET1                 MH_CIBR1
#define CIF_DMA_TARGET2                 MH_CIBR2

// Parameter

#define CAM_CICR0_VAL                   (CICR0_EOFXM|CICR0_BSM|CICR0_FUM|CICR0_TOM|CICR0_EOLM|CICR0_QDM|CICR0_CDM|CICR0_SOFM|CICR0_EOFM|CICR0_FOM)
#ifdef OVERLAY2_MODE_RGB
#define CAM_CICR1_VAL                   (CICR1_PPL(OVERLAY2_WIDTH)|CICR1_YCBCRF(YCBCRF_PLANAR)|CICR1_RAW_BPP(0)|CICR1_COLORSP(COLORSP_RGB)|CICR1_DW(2)|CICR1_BIT8)
#endif
#ifdef OVERLAY2_MODE_YUV
#define CAM_CICR1_VAL                   (CICR1_PPL(OVERLAY2_WIDTH)|CICR1_YCBCRF(YCBCRF_PLANAR)|CICR1_RAW_BPP(0)|CICR1_COLORSP(COLORSP_YUV)|CICR1_DW(2))
#endif
#define CAM_CICR2_VAL                   (CICR2_BLW(0)|CICR2_ELW(0)|CICR2_HSW(0)|CICR2_BFPW(0)|CICR2_FSW(0))
#define CAM_CICR3_VAL                   (CICR3_BFW(1)|CICR3_EFW(0)|CICR3_VSW(0)|CICR3_LPF(OVERLAY2_HEIGHT))
#define CAM_CICR4_VAL                   (CICR4_PCLK_EN|CICR4_MCLK_EN|CICR4_DIV(3))

#ifdef OVERLAY2_MODE_RGB
const static CIF_DMA_Descriptor_t tDMADesc = {
    DMA_DESC_CIF_RGB_ADDR,
    (U32)CIF_DMA_TARGET0,
    FB_OVERLAY2_RGB_ADDR,
    FB_OVERLAY2_RGB_SIZE | CICMD_INCTRGADDR
};
#endif

#ifdef OVERLAY2_MODE_YUV
const static CIF_DMA_Descriptor_t tDMADesc_Y = {
    DMA_DESC_CIF_Y_ADDR,
    (U32)CIF_DMA_TARGET0,
    FB_OVERLAY2_Y_ADDR,
    FB_OVERLAY2_Y_SIZE| CICMD_INCTRGADDR
};

const static CIF_DMA_Descriptor_t tDMADesc_U = {
    DMA_DESC_CIF_U_ADDR,
    (U32)CIF_DMA_TARGET1,
    FB_OVERLAY2_U_ADDR,
    FB_OVERLAY2_U_SIZE| CICMD_INCTRGADDR
};

const static CIF_DMA_Descriptor_t tDMADesc_V = {
    DMA_DESC_CIF_V_ADDR,
    (U32)CIF_DMA_TARGET2,
    FB_OVERLAY2_V_ADDR,
    FB_OVERLAY2_V_SIZE| CICMD_INCTRGADDR
};
#endif

void CIF_Initial(void)
{
    REG_CICR0=CAM_CICR0_VAL;
    REG_CICR1=CAM_CICR1_VAL;
    REG_CICR2=CAM_CICR2_VAL;
    REG_CICR3=CAM_CICR3_VAL;
    REG_CICR4=CAM_CICR4_VAL;

    msSleep(100);

#if 0
    DBG_TraceHex("CICR0", REG_CICR0);
    DBG_TraceHex("CICR1", REG_CICR1);
    DBG_TraceHex("CICR2", REG_CICR2);
    DBG_TraceHex("CICR3", REG_CICR3);
    DBG_TraceHex("CICR4", REG_CICR4);
#endif
}

void CIF_DMA_Init(void)
{
    U32 offset, temp;
    U32 * desc;
    U32 i;

#ifdef OVERLAY2_MODE_RGB
    MemCopy((void*)DMA_DESC_CIF_RGB_ADDR, (void*)(&tDMADesc), sizeof(tDMADesc));

    REG_CIDADR0 = DMA_DESC_CIF_RGB_ADDR;
    REG_CIFR0   = CIFR0_FEN0;
#endif

#ifdef OVERLAY2_MODE_YUV
    MemCopy((void*)DMA_DESC_CIF_Y_ADDR, (void*)(&tDMADesc_Y), sizeof(tDMADesc_Y));
    MemCopy((void*)DMA_DESC_CIF_U_ADDR, (void*)(&tDMADesc_U), sizeof(tDMADesc_U));
    MemCopy((void*)DMA_DESC_CIF_V_ADDR, (void*)(&tDMADesc_V), sizeof(tDMADesc_V));


    REG_CIDADR0 = DMA_DESC_CIF_Y_ADDR;
    REG_CIDADR1 = DMA_DESC_CIF_U_ADDR;
    REG_CIDADR2 = DMA_DESC_CIF_V_ADDR;
    REG_CIFR0   = CIFR0_FEN0 | CIFR0_FEN1 |CIFR0_FEN2;
#endif
    return;
}

void CIF_Enable(void)
{
    REG_CICR0 |=CICR0_ENB;
}

void CIF_Disable(void)
{
    REG_CICR0 &=~CICR0_ENB;
}

#endif

