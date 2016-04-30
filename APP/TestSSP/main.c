#include "_type.h"
#include "APIStub.h"


/****************
    Test Code
****************/

//#define TEST_SSP_ID                     SSP_ID_2

#define TEST_BUFFER_BASE                BUFFER_XMODEM_FILE_BASE
#define TEST_BUFFER_SIZE                (BUFFER_XMODEM_FILE_SIZE)
#define TEST_BUFFER_STEP                (8*1024)

void tSPISend(void)
{
#ifdef TEST_SSP_ID
#define TEST_SSP_ID_SPI                 TEST_SSP_ID
#else
#define TEST_SSP_ID_SPI                 SSP_ID_2
#endif

    // This test function is for SPI reference

    U8 data[] = {0x81, 0, 0};

    SSP_Initial(TEST_SSP_ID_SPI, SSP_ID_SPI_LCD, SSP_SAMPLE_RATE_SPI, SSP_SAMPLE_BIT_08, SSP_CHANNEL_NONE);

    SSP_Enable(TEST_SSP_ID_SPI);

    while(!DBG_GotEvent)
    {
        SSP_Wait4Idle(TEST_SSP_ID_SPI);
        SSP_SendB2B(TEST_SSP_ID_SPI, data, sizeof(data)/sizeof(U8));
        SSP_Wait4Idle(TEST_SSP_ID_SPI);
        msSleep(1);
    }
    DBG_GET_BYTE;

    SSP_Disable(TEST_SSP_ID_SPI);
}

void tI2SSend(void)
{
    U32                     data[] = {0x80, 0, 0, 0};
    SSP_SAMPLE_RATE_t sampleRate[] = {SSP_SAMPLE_RATE_I2S_4K, SSP_SAMPLE_RATE_I2S_8K, SSP_SAMPLE_RATE_I2S_11K, SSP_SAMPLE_RATE_I2S_16K, SSP_SAMPLE_RATE_I2S_22K, SSP_SAMPLE_RATE_I2S_44K};
    SSP_SAMPLE_BIT_t   sampleBit[] = {SSP_SAMPLE_BIT_08, SSP_SAMPLE_BIT_16, SSP_SAMPLE_BIT_32};
    SSP_CHANNEL_t      sampleChn[] = {SSP_CHANNEL_LEFT, SSP_CHANNEL_RIGHT, SSP_CHANNEL_STEREO};
    U32 r, b, c;
    U32 pSampleAddress, stepNumber, burstNumber;

#ifdef TEST_SSP_ID
#define TEST_SSP_ID_I2S                 TEST_SSP_ID

    pSampleAddress = (U32)data;
    burstNumber    = 4;
    stepNumber     = 0;

#else
#define TEST_SSP_ID_I2S                 SSP_ID_3

    pSampleAddress = TEST_BUFFER_BASE;
    burstNumber    = TEST_BUFFER_STEP;
    stepNumber     = TEST_BUFFER_STEP;

#endif

    b = DBG_GetDecDef("bit", 1, 0);
    if(b >= (sizeof(sampleBit)/sizeof(SSP_SAMPLE_BIT_t)))
    {
        b = 0;
    }
    DBG_TraceHex("Bit", sampleBit[b]);

    c = DBG_GetDecDef("channel", 1, 0);
    if(c >= (sizeof(sampleChn)/sizeof(SSP_CHANNEL_t)))
    {
        c = 0;
    }
    DBG_TraceHex("Chn", sampleChn[c]);

    r = DBG_GetDecDef("rate", 1, 0);
    if(r >= (sizeof(sampleRate)/sizeof(SSP_SAMPLE_RATE_t)))
    {
        r = 0;
    }
    DBG_TraceHex("SCR", sampleRate[r]);

    SSP_Initial(TEST_SSP_ID_I2S, SSP_ID_I2S_AUDIO_OUT, sampleRate[r], sampleBit[b], sampleChn[c]);
    SSP_Enable(TEST_SSP_ID_I2S);

    while(!DBG_GotEvent)
    {
        if(sampleBit[b] == SSP_SAMPLE_BIT_08)
        {
            SSP_SendB2D(TEST_SSP_ID_I2S, (U8*)pSampleAddress, burstNumber);
            pSampleAddress += (stepNumber << 0);            // Sample type is U8
        }
        else if(sampleBit[b] == SSP_SAMPLE_BIT_16)
        {
            SSP_SendW2D(TEST_SSP_ID_I2S, (U16*)pSampleAddress, burstNumber);
            pSampleAddress += (stepNumber << 1);            // Sample type is U16
        }
        else if(sampleBit[b] == SSP_SAMPLE_BIT_32)
        {
            SSP_SendD2D(TEST_SSP_ID_I2S, (U32*)pSampleAddress, burstNumber);
            pSampleAddress += (stepNumber << 2);            // Sample type is U32
        }

        if(pSampleAddress >= (TEST_BUFFER_BASE + TEST_BUFFER_SIZE))
        {
            break;
        }
    }
    DBG_GET_BYTE;

    SSP_Disable(TEST_SSP_ID_I2S);
}

void tPCMSend(void)
{
#ifdef TEST_SSP_ID
#define TEST_SSP_ID_PCM                 TEST_SSP_ID
#else
#define TEST_SSP_ID_PCM                 SSP_ID_4
#endif

typedef U32 PCMSample;

    PCMSample data[] = {(PCMSample)(-1), 0xA, 0x3};

    SSP_Initial(TEST_SSP_ID_PCM, SSP_ID_PCM_AUDIO_OUT, SSP_SAMPLE_RATE_SPI, SSP_SAMPLE_BIT_32, SSP_CHANNEL_NONE);

    SSP_Enable(TEST_SSP_ID_PCM);

    while(!DBG_GotEvent)
    {
        SSP_SendD2D(TEST_SSP_ID_PCM, data, sizeof(data)/sizeof(PCMSample));
    }
    DBG_GET_BYTE;

    SSP_Disable(TEST_SSP_ID_PCM);
}

void tPCMReceive(void)
{
#ifdef TEST_SSP_ID
#define TEST_SSP_ID_PCM                 TEST_SSP_ID
#else
#define TEST_SSP_ID_PCM                 SSP_ID_4
#endif

    U32 *pSampleAddress;

    MemSet((void*)TEST_BUFFER_BASE, (U8)(-1), 10);

    SSP_Initial(TEST_SSP_ID_PCM, SSP_ID_PCM_AUDIO_IN, SSP_SAMPLE_RATE_PCM_8K, SSP_SAMPLE_BIT_32, SSP_CHANNEL_NONE);

    SSP_Enable(TEST_SSP_ID_PCM);

    pSampleAddress = (U32*)TEST_BUFFER_BASE;
    while(!DBG_GotEvent)
    {
        SSP_ReceiveD2D(TEST_SSP_ID_PCM, pSampleAddress, TEST_BUFFER_STEP);
        pSampleAddress += TEST_BUFFER_STEP;
        if(((U32)pSampleAddress) >= (U32)(TEST_BUFFER_BASE + TEST_BUFFER_SIZE))
        {
            break;
        }
    }
    DBG_GET_BYTE;

    DBG_TraceMem("Data", TEST_BUFFER_BASE, 8);

    SSP_Disable(TEST_SSP_ID_PCM);
}

static MENU_REC l_Module[] = {
    {'b', "SPISend",                tSPISend},
    {'s', "I2SSend",                tI2SSend},
    {'r', "PCMReceiv",              tPCMReceive},
    {'p', "PCMSend",                tPCMSend},
    {'\0'}
};

void Main(void)
{
//    DBG_BreakPoint("Hello");
//    DBG_CountDown(3);

    MenuFunction("SSP Test", l_Module);
    DBG_BreakPoint("Bye");
//    DBG_CountDown(3);
}
