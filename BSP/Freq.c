#include "_Platform.h"

#ifdef INCLUDE_MODULE_FREQ

/*
    Problem:

        {SYS_FREQ_8_1_104, FALSE} & {SYS_FREQ_8_2_104, FALSE} have different speed test result.
        {SYS_FREQ_16_2_208, FALSE} & {SYS_FREQ_16_2_208, TRUE} have same speed test result.

    Conclusion:

        IF ONLY XN is not 1, XN will take effect even T bit is SET or NOT.

    Problem:

        ONLY SET/CLEAR T bit cannot make Turbo Mode Enable/Disable.

    Workaround:

        XN must be set as (2, 4)/(1) with T bit SET/CLEAR to Enable/Disable Turbo mode.
*/

#define FrequencyChangeTrigger(f)       WriteClkCfg(CLKCFG_MASK & f)

#define REG_ACCR                        (*MH_ACCR)
#define REG_ACSR                        (*MH_ACSR)
#define REG_AICSR                       (*MH_AICSR)

typedef struct{
    U32    m_dwAccr;
    U32    m_bTurboEn;
}FREQ_PARA_t;

#if 0
#define SYS_FREQ_8_1_104 \
                    ACCR_XL(XL_TIMES_8) |\
                    ACCR_XN(XN_TIMES_1) |\
                    ACCR_DMCFS(DMCFS_260M) |\
                    ACCR_HSS(HSS_104M) |\
                    ACCR_XSPCLK(XSPCLK_NULL) |\
                    ACCR_SFLFS(SFLFS_104M) |\
                    ACCR_SMCFS(SMCFS_104M) |\
                    ACCR_VAUF(VAUF_104MHz)

#define SYS_FREQ_8_2_104 \
                    ACCR_XL(XL_TIMES_8) |\
                    ACCR_XN(XN_TIMES_2) |\
                    ACCR_DMCFS(DMCFS_260M) |\
                    ACCR_HSS(HSS_104M) |\
                    ACCR_XSPCLK(XSPCLK_NULL) |\
                    ACCR_SFLFS(SFLFS_104M) |\
                    ACCR_SMCFS(SMCFS_104M) |\
                    ACCR_VAUF(VAUF_104MHz)

#define SYS_FREQ_16_2_208 \
                    ACCR_XL(XL_TIMES_16) |\
                    ACCR_XN(XN_TIMES_2) |\
                    ACCR_DMCFS(DMCFS_260M) |\
                    ACCR_HSS(HSS_104M) |\
                    ACCR_XSPCLK(XSPCLK_NULL) |\
                    ACCR_SFLFS(SFLFS_104M) |\
                    ACCR_SMCFS(SMCFS_104M) |\
                    ACCR_VAUF(VAUF_104MHz)

static FREQ_PARA_t para[] = {
    {SYS_FREQ_8_1_104, FALSE},
    {SYS_FREQ_8_2_104, FALSE},
    {SYS_FREQ_16_2_208, FALSE},
    {SYS_FREQ_16_2_208, TRUE},
};

#else

// This set frequency has problem for LCD.

#define SYS_FREQ_8_1_104 \
                    ACCR_XL(XL_TIMES_8) |\
                    ACCR_XN(XN_TIMES_1) |\
                    ACCR_DMCFS(DMCFS_260M) |\
                    ACCR_HSS(HSS_104M) |\
                    ACCR_XSPCLK(XSPCLK_NULL) |\
                    ACCR_SFLFS(SFLFS_104M) |\
                    ACCR_SMCFS(SMCFS_78M) |\
                    ACCR_VAUF(VAUF_78MHz)

#define SYS_FREQ_16_1_208 \
                    ACCR_XL(XL_TIMES_16) |\
                    ACCR_XN(XN_TIMES_1) |\
                    ACCR_DMCFS(DMCFS_260M) |\
                    ACCR_HSS(HSS_104M) |\
                    ACCR_XSPCLK(XSPCLK_NULL) |\
                    ACCR_SFLFS(SFLFS_156M) |\
                    ACCR_SMCFS(SMCFS_104M) |\
                    ACCR_VAUF(VAUF_78MHz)

#define SYS_FREQ_16_2_416 \
                    ACCR_XL(XL_TIMES_16) |\
                    ACCR_XN(XN_TIMES_2) |\
                    ACCR_DMCFS(DMCFS_260M) |\
                    ACCR_HSS(HSS_156M) |\
                    ACCR_XSPCLK(XSPCLK_NULL) |\
                    ACCR_SFLFS(SFLFS_208M) |\
                    ACCR_SMCFS(SMCFS_104M) |\
                    ACCR_VAUF(VAUF_104MHz)

#define SYS_FREQ_24_2_624 \
                    ACCR_XL(XL_TIMES_24) |\
                    ACCR_XN(XN_TIMES_2) |\
                    ACCR_DMCFS(DMCFS_260M) |\
                    ACCR_HSS(HSS_S_208M) |\
                    ACCR_XSPCLK(XSPCLK_NULL) |\
                    ACCR_SFLFS(SFL_S_312M) |\
                    ACCR_SMCFS(SMCFS_208M) |\
                    ACCR_VAUF(VAUF_156MHz)

#define SYS_FREQ_24_2_624_2 \
                    ACCR_XL(XL_TIMES_24) |\
                    ACCR_XN(XN_TIMES_2) |\
                    ACCR_DMCFS(DMCFS_260M) |\
                    ACCR_HSS(HSS_S_312M) |\
                    ACCR_XSPCLK(XSPCLK_NULL) |\
                    ACCR_SFLFS(SFL_S_312M) |\
                    ACCR_SMCFS(SMCFS_208M) |\
                    ACCR_VAUF(VAUF_104MHz)

FREQ_PARA_t para[] = {
    {SYS_FREQ_8_1_104,    FALSE},
    {SYS_FREQ_16_1_208,   FALSE},
    {SYS_FREQ_16_2_416,   TRUE},
    {SYS_FREQ_24_2_624,   TRUE},
    {SYS_FREQ_24_2_624_2, TRUE},
};

#endif

static void Freq_Change(U32 dwAccr, BOOL bTurboEnable)
{
    REG_ACCR = dwAccr;

    if(bTurboEnable)
    {
        FrequencyChangeTrigger(CLKCFG_T | CLKCFG_F);
    }
    else
    {
        FrequencyChangeTrigger(CLKCFG_F);
    }

    dwAccr &= (ACSR_XL_MASK | ACSR_XN_MASK);
    dwAccr |= ACSR_XPLCK | ACSR_SPLCK;

    while((dwAccr & REG_ACSR) != dwAccr)
    {
        DBG_TraceHex("ACSR", REG_ACSR);
    }
}

void Freq_Set(void)
{
#define SYS_FREQ_ID  3
    Freq_Change(para[SYS_FREQ_ID].m_dwAccr, para[SYS_FREQ_ID].m_bTurboEn);
}

void Freq_TurboEnable(U32 dwRatio)
{
    U32 accr;

    accr = REG_ACCR;
    DBG_TraceHex("ACCR", accr);
    accr &= ~ ACSR_XN_MASK;
    accr |= ACCR_XN(dwRatio);
    DBG_TraceHex("ACCR", accr);
    REG_ACCR = accr;

    WriteClkCfg(CLKCFG_T);
}

void Freq_TurboDisable(void)
{
    U32 accr;

    accr = REG_ACCR;
    DBG_TraceHex("ACCR", accr);
    accr &= ~ ACSR_XN_MASK;
    accr |= ACCR_XN(XN_TIMES_1);
    DBG_TraceHex("ACCR", accr);
    REG_ACCR = accr;

    WriteClkCfg(CLKCFG_T);
}

#endif //INCLUDE_MODULE_FREQ

