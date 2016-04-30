
#include "_Platform.h"

#ifdef INCLUDE_MODULE_AUDIO

#include "Audio_Function.c"

// wav format
#define RIFF_ID                         "RIFF"
#define WAVE_ID                         "WAVE"

typedef struct
{
    BYTE    m_strChunkID[4];
    U32     m_dwChunkSize;
    BYTE    m_strFormat[4];
}__attribute__ ((__packed__)) t_RiffChunkDescriptor;

typedef struct
{
    BYTE    m_strSubchunk1ID[4];
    U32     m_dwSubchunk1Size;
    U16     m_wAudioFormat;
    U16     m_wNumChannels;
    U32     m_dwSampleRate;
    U32     m_dwByteRate;
    U16     m_wBlockAligh;
    U16     m_BitsPerSample;
}__attribute__ ((__packed__)) t_FmtSubchunkDescriptor;

typedef struct
{
    BYTE    m_strSubchunk2ID[4];
    U32     m_dwSubchunk2Size;
}__attribute__ ((__packed__)) t_DataSubchunkDescriptor;

typedef struct
{
    t_RiffChunkDescriptor    m_RiffInfo;
    t_FmtSubchunkDescriptor  m_FmtInfo;
    t_DataSubchunkDescriptor m_DataInfo;
}__attribute__ ((__packed__)) t_WaveFileHead;
// wav format end

/*
typedef enum{
    MIC_BOARD   = 0,
    MIC_HEADSET = 1,
}e_MIC_TYPE;
*/

static int Audio_DumpWaveFileHeader(t_WaveFileHead* pHeader)
{
    if( (0 != StrCompare(RIFF_ID, pHeader->m_RiffInfo.m_strChunkID))  ||
        (0 != StrCompare(WAVE_ID, pHeader->m_RiffInfo.m_strFormat))   )
    {
        MY_TraceStrLine("Not a WAV file!");
        return(ERR_CODE_WAV_FORMAT);
    }

    DBG_TraceString("\r\n");
    DBG_TraceString("m_RiffInfo.m_strChunkID: ");
    DBG_PutChar(pHeader->m_RiffInfo.m_strChunkID[0]);
    DBG_PutChar(pHeader->m_RiffInfo.m_strChunkID[1]);
    DBG_PutChar(pHeader->m_RiffInfo.m_strChunkID[2]);
    DBG_PutChar(pHeader->m_RiffInfo.m_strChunkID[3]);

    DBG_TraceHex("m_RiffInfo.m_dwChunkSize", pHeader->m_RiffInfo.m_dwChunkSize);

    DBG_TraceString("\r\n");
    DBG_TraceString("m_RiffInfo.m_strFormat: ");
    DBG_PutChar(pHeader->m_RiffInfo.m_strFormat[0]);
    DBG_PutChar(pHeader->m_RiffInfo.m_strFormat[1]);
    DBG_PutChar(pHeader->m_RiffInfo.m_strFormat[2]);
    DBG_PutChar(pHeader->m_RiffInfo.m_strFormat[3]);

    DBG_TraceString("\r\n");
    DBG_TraceString("m_FmtInfo.m_strSubchunk1ID: ");
    DBG_PutChar(pHeader->m_FmtInfo.m_strSubchunk1ID[0]);
    DBG_PutChar(pHeader->m_FmtInfo.m_strSubchunk1ID[1]);
    DBG_PutChar(pHeader->m_FmtInfo.m_strSubchunk1ID[2]);
    DBG_PutChar(pHeader->m_FmtInfo.m_strSubchunk1ID[3]);

    DBG_TraceHex("m_FmtInfo.m_dwSubchunk1Size", pHeader->m_FmtInfo.m_dwSubchunk1Size);
    DBG_TraceHex("m_FmtInfo.m_wAudioFormat",   (pHeader->m_FmtInfo.m_wAudioFormat & 0x00FF));
    DBG_TraceHex("m_FmtInfo.m_wNumChannels",   (pHeader->m_FmtInfo.m_wNumChannels & 0x00FF));
    DBG_TraceHex("m_FmtInfo.m_dwSampleRate",    pHeader->m_FmtInfo.m_dwSampleRate);
    DBG_TraceHex("m_FmtInfo.m_dwByteRate",      pHeader->m_FmtInfo.m_dwByteRate);
    DBG_TraceHex("m_FmtInfo.m_wBlockAligh",    (pHeader->m_FmtInfo.m_wBlockAligh & 0x00FF));
    DBG_TraceHex("m_FmtInfo.m_BitsPerSample",  (pHeader->m_FmtInfo.m_BitsPerSample & 0x00FF));

    DBG_TraceString("\r\n");
    DBG_TraceString("m_DataInfo.m_strSubchunk2ID: ");
    DBG_PutChar(pHeader->m_DataInfo.m_strSubchunk2ID[0]);
    DBG_PutChar(pHeader->m_DataInfo.m_strSubchunk2ID[1]);
    DBG_PutChar(pHeader->m_DataInfo.m_strSubchunk2ID[2]);
    DBG_PutChar(pHeader->m_DataInfo.m_strSubchunk2ID[3]);

    DBG_TraceHex("m_DataInfo.m_dwSubchunk2Size", pHeader->m_DataInfo.m_dwSubchunk2Size);

    return(ERR_CODE_NONE);
}

static void Audio_DACEnable(void)
{
    PMIC_DACSetting(
              STEREO_DAC_CONTROL_DAC_NON_INV_1 |
              STEREO_DAC_CONTROL_DAC_NON_INV_2 |
              STEREO_DAC_CONTROL_DAC_MUTE_1_OFF |
              STEREO_DAC_CONTROL_DAC_MUTE_2_OFF |
              STEREO_DAC_CONTROL_HPF_BYPASS_1_OFF |
              STEREO_DAC_CONTROL_HPF_BYPASS_2_OFF |
              STEREO_DAC_CONTROL_DAC_ON
              );
}

static void Audio_DACDisable(void)
{
    PMIC_DACSetting(
              STEREO_DAC_CONTROL_DAC_NON_INV_1 |
              STEREO_DAC_CONTROL_DAC_NON_INV_2 |
              STEREO_DAC_CONTROL_DAC_MUTE_1_OFF |
              STEREO_DAC_CONTROL_DAC_MUTE_2_OFF |
              STEREO_DAC_CONTROL_HPF_BYPASS_1_OFF |
              STEREO_DAC_CONTROL_HPF_BYPASS_2_OFF |
              STEREO_DAC_CONTROL_DAC_OFF
              );
}

static void Audio_VADCEnable(void)
{
    PMIC_VoiceADCSetting(
              VOICE_CODEC_ADC_CONTROL_ADC_MUTE_OFF |
              ADC_OUT_GAIN_12DB |
              PCM_SAMPLE_RATE_8K |
              TX_HPF_8K_4TH |
              VOICE_CODEC_ADC_CONTROL_ADC_ON
              );
}

static void Audio_VADCDisable(void)
{
    PMIC_VoiceADCSetting(
              VOICE_CODEC_ADC_CONTROL_ADC_MUTE_OFF |
              ADC_OUT_GAIN_12DB |
              PCM_SAMPLE_RATE_8K |
              TX_HPF_8K_4TH |
              VOICE_CODEC_ADC_CONTROL_ADC_OFF
              );
}

static void Audio_BoardMicEnable(void)
{
    PMIC_SetTxPGAMux(TX_PGA_MUX_MIC_DIFF(3));
    PMIC_SetTxPGAGain(TX_TX_PGA(0));

    PMIC_SetMicAmpGain(
                  MICAMP_MICAMP(7) |
                  MICAMP_MICAMP_ENABLE |
                  MICAMP_MICBIAS_INT_ENABLE
                  );
}

static void Audio_HeadsetMicEnable(void)
{
    PMIC_SetTxPGAMux(TX_PGA_MUX_MIC_DIFF(3));
    PMIC_SetTxPGAGain(TX_TX_PGA(0));

    PMIC_SetMicAmpGain(
                  MICAMP_MICAMP(7) |
                  MICAMP_MICAMP_ENABLE |
                  MICAMP_MICBIAS_EXT_ENABLE |
                  MICAMP_SELMIC2
                  );
}

typedef enum{
    I2S_8K        =  8000,
    I2S_11K025    =  11025,
    I2S_12K       =  12000,
    I2S_16K       =  16000,
    I2S_22K05     =  22050,
    I2S_24K       =  24000,
    I2S_32K       =  32000,
    I2S_44K1      =  44100,
    I2S_48K       =  48000
}e_HW_I2S_SAMPLE_RATE;

typedef enum{
    PCM_8K        =  8000,
    PCM_16K       =  16000,
    PCM_32K       =  32000,
    PCM_32K_      =  32000
}e_HW_PCM_SAMPLE_RATE;

typedef enum{
    BIT_PER_SAMPLE_8    =   0x08,
    BIT_PER_SAMPLE_16   =   0x10,
    BIT_PER_SAMPLE_32   =   0x20
}e_BIT_PER_SAMPLE;

void Audio_Play(e_HW_I2S_SAMPLE_RATE e_SampleRate, e_BIT_PER_SAMPLE e_BitsPerSample, U16 wNumChannels, U8 *pData, U32 dwLength)
{
    U8 path, SampleRate, Seconds;
    SSP_SAMPLE_RATE_t sspSampleRate;
    SSP_SAMPLE_BIT_t sspSampleBit;
    SSP_CHANNEL_t sspNumChannels;

    path = DBG_GetDecDef("Please Select 0-SPK 1-REC 2-Headset: ", 1, 2);

    if(path == 0)
    {
        Audio_EnableI2StoSpeaker();
    }
    else if(path == 1)
    {
        Audio_EnableI2StoReceiver();
    }
    else
    {
        Audio_EnableI2StoHeadset();
    }

    Audio_DACEnable();

    switch(e_SampleRate)
    {
        case I2S_8K:
            SampleRate = I2S_SAMPLE_RATE_8K;
            sspSampleRate = SSP_SAMPLE_RATE_I2S_8K;
            break;
        case I2S_11K025:
            SampleRate = I2S_SAMPLE_RATE_11K025;
            sspSampleRate = SSP_SAMPLE_RATE_I2S_11K;
            break;
        case I2S_16K:
            SampleRate = I2S_SAMPLE_RATE_16K;
            sspSampleRate = SSP_SAMPLE_RATE_I2S_16K;
            break;
        case I2S_22K05:
            SampleRate = I2S_SAMPLE_RATE_22K05;
            sspSampleRate = SSP_SAMPLE_RATE_I2S_22K;
            break;
        case I2S_44K1:
            SampleRate = I2S_SAMPLE_RATE_44K1;
            sspSampleRate = SSP_SAMPLE_RATE_I2S_44K;
            break;
        case I2S_12K:
        case I2S_24K:
        case I2S_32K:
        case I2S_48K:
        default:
            DBG_TraceStrLine("unsupported sample rate");
            goto ERROR;
    }

    switch(e_BitsPerSample)
    {
        case BIT_PER_SAMPLE_8:
            sspSampleBit = SSP_SAMPLE_BIT_08;
            break;
        case BIT_PER_SAMPLE_16:
            sspSampleBit = SSP_SAMPLE_BIT_16;
            break;
        case BIT_PER_SAMPLE_32:
            sspSampleBit = SSP_SAMPLE_BIT_32;
            break;
        default:
            DBG_TraceStrLine("unsupported Bits Per Sample");
            goto ERROR;
    }

    if(wNumChannels == 1)
    {
        sspNumChannels = SSP_CHANNEL_LEFT;
    }
    else if(wNumChannels == 2)
    {
        sspNumChannels = SSP_CHANNEL_STEREO;
    }
    else
    {
        DBG_TraceStrLine("unsupported Num Channels");
        goto ERROR;
    }

    // I2S control
    PMIC_I2SSetting(
                  SampleRate |
                  I2S_CONTROL_I2S_SLAVE |
                  I2S_CONTROL_SRM_OFF |
                  I2S_CONTROL_SYNC_INPUT |
                  I2S_CONTROL_I2S_MSB_MODE
                  );
//    PMIC_I2SSetting(SampleRate, I2S_CONTROL_I2S_MASTER, I2S_CONTROL_SRM_OFF, I2S_CONTROL_SYNC_INPUT, I2S_CONTROL_I2S_NORMAL_MODE);

    SSP_Initial(SSP_AUDIO_PLAY, SSP_ID_I2S_AUDIO_OUT, sspSampleRate, sspSampleBit, sspNumChannels);
    SSP_Enable(SSP_AUDIO_PLAY);

    DBG_TraceString("\r\nstart play");

    Seconds = (U32)(dwLength / (e_SampleRate * wNumChannels * e_BitsPerSample / 8));
    DBG_TraceString("\r\nplay time: ");DBG_TraceDec(NULL, Seconds / 60);DBG_TraceString(" min ");DBG_TraceDec(NULL, Seconds % 60);DBG_TraceString(" sec\r\n");

    switch(e_BitsPerSample)
    {
        case BIT_PER_SAMPLE_8:
           SSP_SendB2D(SSP_AUDIO_PLAY, pData, (U32)(dwLength * 8 / e_BitsPerSample));
           break;
        case BIT_PER_SAMPLE_16:
           SSP_SendW2D(SSP_AUDIO_PLAY, (U16*)pData, (U32)(dwLength * 8 / e_BitsPerSample));
           break;
        case BIT_PER_SAMPLE_32:
           SSP_SendD2D(SSP_AUDIO_PLAY, (U32*)pData, (U32)(dwLength * 8 / e_BitsPerSample));
           break;
    }

    SSP_Disable(SSP_AUDIO_PLAY);

    DBG_TraceString("\r\nend play");

ERROR:
    Audio_DACEnable();
    return;
}

void Audio_PlayWaveFile(U32 pBufAddr)
{
    t_WaveFileHead *p;
    p = (t_WaveFileHead*)pBufAddr;

    if(ERR_CODE_NONE != Audio_DumpWaveFileHeader(p)) return;

    Audio_Play((e_HW_I2S_SAMPLE_RATE)p->m_FmtInfo.m_dwSampleRate, (e_BIT_PER_SAMPLE)p->m_FmtInfo.m_BitsPerSample, p->m_FmtInfo.m_wNumChannels, (U8*)(p + 1), p->m_DataInfo.m_dwSubchunk2Size);
}

void Audio_Record(U32 dwBufAddr)
{
    U8 mic, Seconds = 10;
    t_WaveFileHead defaultHeader = {
            {"RIFF", sizeof(t_FmtSubchunkDescriptor) + sizeof(t_DataSubchunkDescriptor) + 10 * (8000 * 1 * 8 / 8), "WAVE"},
            {"fmt ", 0x10, 1, 1, 8000, 8000, 1, 8},
            {"data", 10 * (8000 * 1 * 8 / 8)},
        };
    t_WaveFileHead *p;

    p = (t_WaveFileHead *)dwBufAddr;

    MemCopy((PBYTE)dwBufAddr, (PBYTE)(&defaultHeader), sizeof(defaultHeader));

    mic = DBG_GetDecDef("Please Select 0-Board 1-Headset: ", 1, 0);

    if(mic == 0)
    {
        Audio_BoardMicEnable();
    }
    else
    {
        Audio_HeadsetMicEnable();
    }

    Audio_VADCEnable();

    SSP_Initial(SSP_AUDIO_RECORD, SSP_ID_PCM_AUDIO_IN, SSP_SAMPLE_RATE_PCM_8K, SSP_SAMPLE_BIT_32, SSP_CHANNEL_NONE);
    SSP_Enable(SSP_AUDIO_RECORD);

    DBG_TraceString("start record\r\n");
//    SSP_ReceiveD2D(SSP_AUDIO_RECORD, (U8*)(p + 1), p->m_DataInfo.m_dwSubchunk2Size * 8 / 8);
//  SSP_ReceiveB2B(SSP_AUDIO_RECORD, (U8*)(pBuffer + sizeof(t_WaveFileHead)), p->m_DataInfo.m_dwSubchunk2Size * 8 / 8);
    SSP_Disable(SSP_AUDIO_RECORD);

    Audio_PlayWaveFile(dwBufAddr);
}

#endif

