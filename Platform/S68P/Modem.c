#if 0
static U32 tModemStatus(U32 dwLastStatus)
{
#define DBG_MSG_POS_STATUS              0, 300
    U32 status;

    status = GPIO_ModemStatus();

    if(status == dwLastStatus) return(status);

    if(status)
    {
//        FB_PutString(DBG_MSG_POS_STATUS, "OFF");
    }
    else
    {
//        FB_PutString(DBG_MSG_POS_STATUS, "ON ");
    }

    return(status);
}
#endif

static void tFullControl(U32 dwBaud, U32 dwEPSPEN)
{
    U32 status;

    DBG_TraceHex("Parity", dwEPSPEN);
//    DBG_CountDown(3);

    DBG_TraceString("UART_ID_DBG INIT...\r\n");
    UART_Initial(UART_ID_DBG,   115200,   dwEPSPEN, 0);
    DBG_TraceString("UART_ID_DBG INIT END\r\n");

    DBG_TraceString("UART_ID_MODEM INIT...\r\n");
    UART_Initial(UART_ID_MODEM, dwBaud,   dwEPSPEN, 0);//UART_FLOW_CONTROL_AUTO);
    DBG_TraceString("UART_ID_MODEM INIT END\r\n");

    //status = tModemStatus((U32)(-1));
      // DBG_TraceHex("status", status);
    while(1)
    {
        char r;

        if(UART_IsDataReady(UART_ID_MODEM))
        {
            UART_PutChar(UART_ID_DBG, UART_GetChar(UART_ID_MODEM));
        }
        if(UART_IsDataReady(UART_ID_DBG))
        {
            r = UART_GetChar(UART_ID_DBG);
            if(ASCII_CODE_ESC == r) break;
            UART_PutChar(UART_ID_MODEM, r);
        }
        msSleep(1);
    }

    DBG_TraceStrLine("Parity - None\r\n\r\n");
//    DBG_CountDown(3);

    UART_Initial(UART_ID_DBG, 115200, 0, 0);
}

static void tUpdateFirmware(void)
{
    U32  baud;

    baud = DBG_GetDecDef("Baud", 6, 115200);

    tFullControl(baud, (LCR_PEN | LCR_EPS(LCR_EPS_EVEN)));
}

static void tATCmd(void)
{
    U32  baud;

#if 0
    U32* pPinReg;

    pPinReg = 0x40E10500;
    *pPinReg &= ~0x7;
    pPinReg = 0x40E10504;
    *pPinReg &= ~0x7;
    pPinReg = 0x40E10508;
    *pPinReg &= ~0x7;
    pPinReg = 0x40E1050C;
    *pPinReg &= ~0x7;
#endif

    baud = DBG_GetDecDef("Baud", 6, 115200);

#if 0
    PMU_AudioSelectPCMDrive(PCM_SELECT_LDO3);
    PMU_AudioRecordGain(RECORD_GAIN_DSP, 0x01);
    PMU_AudioRecordGain(RECORD_GAIN_TX_PGA, 0x0F);

    PMU_AudioVoiceADCControl(VOICE_CODEC_ADC_ON, TRUE);
    PMU_AudioVoiceADCControl(VOICE_CODEC_ADC_MUTE, FALSE);
    PMU_AudioVoiceADCSampleRate(VOICE_ADC_SAMPLERATE_8K);
    PMU_AudioVoiceADCHPFControl(VOICE_HPF_2ND);

    PMU_AudioVoiceVDACControl(VOICE_VDAC_CONTROL_VDAC_MUTE, FALSE);
    PMU_AudioVoiceVDACControl(VOICE_VDAC_CONTROL_VDAC_INV, FALSE);
    PMU_AudioVoiceVDACControl(VOICE_VDAC_CONTROL_HPF_BYPASS, TRUE);
    PMU_AudioVoiceVDACControl(VOICE_VDAC_CONTROL_PCM_HIZ, FALSE);
    PMU_AudioVoiceVDACControl(VOICE_VDAC_CONTROL_PCM_LOOP, FALSE);
    PMU_AudioVoiceVDACControl(VOICE_VDAC_CONTROL_VDAC_ON, TRUE);

    PMU_AudioStereoControl(STEREO_DAC_ON, TRUE);
    PMU_AudioStereoControl(STEREO_DAC_AMP_ON, TRUE);

    PMU_AudioRecordMicSelect(MIC_SELECT_INT);
    PMU_AudioMicAmpEnable(TRUE);
    PMU_AudioRecordGain(RECORD_GAIN_MIC, 0x00);
    PMU_AudioRecordPathSet(0x0c);

    PMU_AudioPlaybackPathSet(PLAYBACK_MUX_BEAR, 0x20);
    PMU_AudioPlaybackGain(PLAYBACK_GAIN_BEAR, 0x00);
    PMU_AudioAllMonoControl(BEAR_ENABLE, TRUE);
    PMU_AudioAllMonoControl(BEAR_FAST_START, TRUE);
#endif

    tFullControl(baud, 0);
}

static MENU_REC l_Module[] = {
    {'a', "AT",        tATCmd},
    {'U', "Update",    tUpdateFirmware},

    {'\0'}
};

void TestModem(void)
{
#if 0
    U32* pPinReg;

    pPinReg = 0x40E10500;
    *pPinReg |= 0x1;
    pPinReg = 0x40E10504;
    *pPinReg |= 0x1;
    pPinReg = 0x40E10508;
    *pPinReg |= 0x1;
    pPinReg = 0x40E1050C;
    *pPinReg |= 0x1;
#endif

//#define AUTO_FULL_CONTROL
#ifdef  AUTO_FULL_CONTROL

    static U32  t = 3000;

//    tModemStatus();

    if(t < 2000)
    {
        DBG_TraceStrLine("Reset");
        //GPIO_ModemReset();
        msSleep(t);
        //GPIO_MODEMPOWERON ;
    }

    tFullControl(460800, 0);
#endif

    MenuFunction("Modem Test", l_Module);

#ifdef  AUTO_FULL_CONTROL
    DBG_TraceDec("t", t);
    t = DBG_GetDecDef("next t", 5, t);
#endif
}


