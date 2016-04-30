#include "_platform.h"

#ifdef INCLUDE_MODULE_SSP

/*
    Attention:

    1. Working in I2S mode, the clock will not stop after Initial.
    2. Working in I2S mode, the FRAME signal will not stop even there is no more valid data, until the Initial function is invoked again.
    3. When I2S's setting is SSCR0_E_DSS(E_DSS_16BIT) & SSPSP_SFRMWDTH(16) | SSPSP_FSRT, the output timing is beautiful.
       When I2S's setting is SSCR0_E_DSS(E_DSS_16BIT) & SSPSP_SFRMWDTH(32) | SSPSP_FSRT, the output timing is not so good.

    Here is the values according to APP notes description
        SSCR0_MOD(MOD_NETWORK) | SSCR0_FPCKE | SSCR0_FRDC(2) | SSCR0_TIM | SSCR0_RIM | SSCR0_SCR(SCR_000) | SSCR0_FRF(FRF_PSP) | SSCR0_E_DSS(E_DSS_16BIT)) | SSCR0_ACS  // E_DSS_32BIT E_DSS_08BIT
        SSCR1_TTE | SSCR1_RFT(7) | SSCR1_TFT(6)
        SSPSP_E_DMYSTOP(16) | SSPSP_SFRMWDTH(16) | SSPSP_SCMODE(SCMODE_FALLING_RISING_LO) | SSPSP_SFRMP(SFRMP_SFRM_NORMAL_I2S) | SSPSP_FSRT(FSRT_NORMAL_I2S))
        SSACD_ACPS(4) | SSACD_ACDS(4)
        SSACDD_NUM(0x659) | SSACDD_DEN(0x40)

    But it is not same as the Example reg value
    In example:

        FPCKE is cleared.
        EDSS is set.  ???
        EDMYSTOP is cleared. ???
        SSPSP_SFRMWDTH(32)
        SSACD_ACPS(SSACR_ACPS_DITHER) | SSACD_ACDS(SSACR_ACDS_1)

        // this value is same as the APP notes example
        SSCR0_MOD(MOD_NETWORK) | SSCR0_FRDC(2) | SSCR0_TIM | SSCR0_RIM | SSCR0_SCR(SCR_000) | SSCR0_FRF(FRF_PSP) | SSCR0_E_DSS(E_DSS_32BIT) | SSCR0_ACS,
        SSCR1_TTE | SSCR1_EBCEI | SSCR1_TSRE | SSCR1_RSRE | SSCR1_TINTE | SSCR1_PINTE | SSCR1_RFT(7) | SSCR1_TFT(6),
        SSPSP_E_DMYSTOP(0) | SSPSP_SFRMWDTH(32) | SSPSP_SCMODE(SCMODE_FALLING_RISING_LO) | SSPSP_SFRMP(SFRMP_SFRM_NORMAL_I2S) | SSPSP_FSRT(FSRT_NORMAL_I2S),
        SSACD_ACPS(SSACR_ACPS_DITHER) | SSACD_ACDS(SSACR_ACDS_1),
        SSACDD_NUM(0x659) | SSACDD_DEN(0x40)

        // this value is same as the BSP driver
        SSCR0_MOD(MOD_NETWORK) | SSCR0_FPCKE | SSCR0_FRDC(2) | SSCR0_TIM | SSCR0_RIM | SSCR0_SCR(SCR_000) | SSCR0_FRF(FRF_PSP) | SSCR0_E_DSS(E_DSS_16BIT) | SSCR0_ACS,
        SSCR1_TTE | SSCR1_RFT(7) | SSCR1_TFT(7),
        SSPSP_E_DMYSTOP(16) | SSPSP_SFRMWDTH(32) | SSPSP_SCMODE(SCMODE_FALLING_RISING_LO) | SSPSP_SFRMP(SFRMP_SFRM_MSB_JUSTIFIED) | SSPSP_FSRT(FSRT_SFRM_MSB_JUSTIFIED),
        SSACD_ACPS(SSACR_ACPS_32842) | SSACD_ACDS(SSACR_ACDS_16),
        SSACDD_NUM(0) | SSACDD_DEN(0)
*/

typedef struct s_SSP_REGs {
    volatile U32 m_SSCR0;               // [0x00] Control register 0
    volatile U32 m_SSCR1;               // [0x04] Control register 1
    volatile U32 m_SSSR;                // [0x08] Status register
    volatile U32 m_SSITR;               // [0x0C] Interrupt Test register
    volatile U32 m_SSDR;                // [0x10] Data Write Register/SSP1 Data Read register
    volatile U32 m_reserved[5];         // [0x14 ~ 0x24]
    volatile U32 m_SSTO;                // [0x28] Time Out register
    volatile U32 m_SSPSP;               // [0x2C] Programmable Serial Protocol register
    volatile U32 m_SSTSA;               // [0x30] TX Time Slot Active register
    volatile U32 m_SSRSA;               // [0x34] RX Time Slot Active register
    volatile U32 m_SSTSS;               // [0x38] Time Slot Status register
    volatile U32 m_SSACD;               // [0x3C] Audio Clock Divider register
    volatile U32 m_SSACDD;              // [0x40] Audio Clock Dither Divider register
}SSP_REGs_t;

typedef struct s_SSP_REGs_INIT_VALUE {
    U32 m_SSCR0;                        // [0x00] Control register 0
    U32 m_SSCR1;                        // [0x04] Control register 1
    U32 m_SSPSP;                        // [0x2C] Programmable Serial Protocol register
}SSP_REGs_INIT_VAL_t;

static SSP_REGs_t *m_SSP[] = {
    (SSP_REGs_t *)MH_SSP1_BASE,
    (SSP_REGs_t *)MH_SSP2_BASE,
    (SSP_REGs_t *)MH_SSP3_BASE,
    (SSP_REGs_t *)MH_SSP4_BASE
};

const static SSP_REGs_INIT_VAL_t m_SSP_Reg_Value[] = {
    {   // SSP2 -- SPI[LCD]
        SSCR0_MOD(MOD_NORMAL) | SSCR0_FRF(FRF_SPI),
        SSCR1_RFT(7) | SSCR1_TFT(7) | SSCR1_SPH(SPH_HALF_CLK_AFTER) | SSCR1_SPO(SPO_IDLE_HIGH),
        0
    },
    {   // SSP3 -- I2S[Audio OUT]
        SSCR0_MOD(MOD_NETWORK) | SSCR0_FRDC(2) | SSCR0_TIM | SSCR0_RIM | SSCR0_FRF(FRF_PSP),
        SSCR1_TTE | SSCR1_RFT(7) | SSCR1_TFT(7),
        SSPSP_SFRMWDTH(32) | SSPSP_SCMODE(SCMODE_FALLING_RISING_LO) | SSPSP_SFRMP(SFRMP_SFRM_MSB_JUSTIFIED) | SSPSP_FSRT(FSRT_SFRM_MSB_JUSTIFIED)
    },
    {   // SSP4 -- PCM[Audio IN]
        SSCR0_MOD(MOD_NORMAL) | SSCR0_FRF(FRF_SSP),
        SSCR1_RFT(7) | SSCR1_TFT(7) |SSCR1_SCFR | SSCR1_RWOT,   // SSCR1_RWOT is for receive function ONLY;
        0
    },
    {   // SSP4 -- PCM[Audio OUT]
        SSCR0_MOD(MOD_NORMAL) | SSCR0_FRF(FRF_SSP),
        SSCR1_RFT(7) | SSCR1_TFT(7) |SSCR1_SCFR,                // | SSCR1_LBM, // LMB (Loop back mode) for test ONLY
        0
    }
};

void SSP_Disable(SSP_MODULE_ID_t tMID)
{
    m_SSP[tMID]->m_SSCR0   = 0;
}

void SSP_Enable(SSP_MODULE_ID_t tMID)
{
    m_SSP[tMID]->m_SSCR0  |= SSCR0_SSE;
}

void SSP_Initial(SSP_MODULE_ID_t tMID, SSP_CONFIG_ID_t tCID, SSP_SAMPLE_RATE_t tSampleRate, SSP_SAMPLE_BIT_t tSampleBit, SSP_CHANNEL_t tChannel)
{
    U32 edss[] = {E_DSS_32BIT, E_DSS_18BIT, E_DSS_16BIT, E_DSS_08BIT};
    U32 stop[] = {0, 14, 16, 24};

    m_SSP[tMID]->m_SSCR0   = m_SSP_Reg_Value[tCID].m_SSCR0 | tSampleRate | SSCR0_E_DSS(edss[tSampleBit]);
    m_SSP[tMID]->m_SSCR1   = m_SSP_Reg_Value[tCID].m_SSCR1;
    m_SSP[tMID]->m_SSPSP   = m_SSP_Reg_Value[tCID].m_SSPSP | SSPSP_E_DMYSTOP(stop[tSampleBit]);

    m_SSP[tMID]->m_SSTSA   = tChannel;
}

void SSP_Wait4Idle(SSP_MODULE_ID_t tMID)
{   // Make sure the Sync will be high
    while((m_SSP[tMID]->m_SSSR) & SSSR_BSY)
    {
        DBG_PutChar('#');
        msSleep(1);
    }
}

void SSP_SendB2B(SSP_MODULE_ID_t tMID, U8 *pData, U32 dwLength)
{
    volatile U8* p;

    p = (volatile U8*)(&(m_SSP[tMID]->m_SSDR));

    while(dwLength-- > 0)
    {
        while(!((m_SSP[tMID]->m_SSSR) & SSSR_TNF))
        {
//            DBG_PutChar('.');
        }
        *p = *pData++;
    }
}

void SSP_SendB2D(SSP_MODULE_ID_t tMID, U8 *pData, U32 dwNumber)
{
    while(dwNumber-- > 0)
    {
        while(!((m_SSP[tMID]->m_SSSR) & SSSR_TNF))
        {
//            DBG_PutChar('.');
        }
        m_SSP[tMID]->m_SSDR = (U32)(*pData++);
    }
}

void SSP_SendW2D(SSP_MODULE_ID_t tMID, U16 *pData, U32 dwNumber)
{
    while(dwNumber-- > 0)
    {
        while(!((m_SSP[tMID]->m_SSSR) & SSSR_TNF))
        {
//            DBG_PutChar('.');
        }
        m_SSP[tMID]->m_SSDR = (U32)(*pData++);
    }
}

void SSP_SendD2D(SSP_MODULE_ID_t tMID, U32 *pData, U32 dwNumber)
{
    while(dwNumber-- > 0)
    {
        while(!((m_SSP[tMID]->m_SSSR) & SSSR_TNF))
        {
//            DBG_PutChar('.');
        }
        m_SSP[tMID]->m_SSDR = (U32)(*pData++);
    }
}

U32 SSP_ReceiveB2B(SSP_MODULE_ID_t tMID, U8 *pData, U32 dwNumber)
{
    U32 i;

    for(i=0;i < dwNumber;i++)
    {
        if((m_SSP[tMID]->m_SSSR) & SSSR_RNE)
        {
            *pData++ = (U8)(m_SSP[tMID]->m_SSDR);
        }
        else
        {
            break;
        }
    }

    return(i);
}

void SSP_ReceiveD2W(SSP_MODULE_ID_t tMID, U16 *pData, U32 dwNumber)
{
    while(dwNumber-- > 0)
    {
        while(!((m_SSP[tMID]->m_SSSR) & SSSR_RNE))
        {
            //DBG_PutChar('~');
        }

        *pData++ = (U16)(m_SSP[tMID]->m_SSDR);
        //DBG_TraceHex("",(U16)(*(pData-1)));
    }
}

void SSP_ReceiveD2D(SSP_MODULE_ID_t tMID, U32 *pData, U32 dwNumber)
{
    while(dwNumber-- > 0)
    {
        while(!((m_SSP[tMID]->m_SSSR) & SSSR_RNE))
        {
            //DBG_PutChar('~');
        }

        *pData++ = m_SSP[tMID]->m_SSDR;
        //DBG_TraceHex("",(U32)(*(pData-1)));
    }
}

#endif

