#define INCLUDE_MODULE_PMIC

typedef enum{
    PMIC_STATUS_A                       = 0,
    PMIC_STATUS_B                       = 1,
}PMIC_Status_t;

// event A
#define PMIC_INT_nONKEY                 EVENT_A_nONKEY
#define PMIC_INT_nEXTON                 EVENT_A_nEXTON
#define PMIC_INT_CHDET                  EVENT_A_CHDET
#define PMIC_INT_TBAT                   EVENT_A_TBAT
#define PMIC_INT_VBAT_MON               EVENT_A_VBAT_MON
#define PMIC_INT_REV_IOVER              EVENT_A_REV_IOVER
#define PMIC_INT_CH_IOVER               EVENT_A_CH_IOVER

// event B
#define PMIC_INT_CH_TCTO                (EVENT_B_CH_TCTO << 8)
#define PMIC_INT_CH_CCTO                (EVENT_B_CH_CCTO << 8)
#define PMIC_INT_USB_DEV                (EVENT_B_USB_DEV << 8)
#define PMIC_INT_OTGCP_IOVER            (EVENT_B_OTGCP_IOVER << 8)
#define PMIC_INT_VBUS_VALID_4_55        (EVENT_B_VBUS_VALID_4_55 << 8)
#define PMIC_INT_VBUS_VALID_3_8         (EVENT_B_VBUS_VALID_3_8 << 8)
#define PMIC_INT_SESSION_VALID_1_8      (EVENT_B_SESSION_VALID_1_8 << 8)
#define PMIC_INT_SRP_READY_0_6          (EVENT_B_SRP_READY_0_6 << 8)

// event C
#define PMIC_INT_ADC_MAN                (EVENT_C_ADC_MAN << 16)
#define PMIC_INT_ADC_AUTO4              (EVENT_C_ADC_AUTO4 << 16)
#define PMIC_INT_ADC_AUTO5              (EVENT_C_ADC_AUTO5 << 16)
#define PMIC_INT_ADC_AUTO6              (EVENT_C_ADC_AUTO6 << 16)
#define PMIC_INT_PEN_DOWN               (EVENT_C_PEN_DOWN << 16)
#define PMIC_INT_TSI_READY              (EVENT_C_TSI_READY << 16)

// event D
#define PMIC_INT_UART_TX_COMPLETE       (EVENT_D_UART_TX_COMPLETE << 24)
#define PMIC_INT_UART_RX_COMPLETE       (EVENT_D_UART_RX_COMPLETE << 24)
#define PMIC_INT_UART_TIME_OUT          (EVENT_D_UART_TIME_OUT << 24)
#define PMIC_INT_HEADSET                (EVENT_D_HEADSET << 24)
#define PMIC_INT_HOOKSWITCH             (EVENT_D_HOOKSWITCH << 24)
#define PMIC_INT_WATCHDOG               (EVENT_D_WATCHDOG << 24)

#define PMIC_INT_ALL                    0xFFFFFFFF

// Audio Path
#define I2S_SAMPLE_RATE_8K              I2S_CONTROL_DAC_SR(0x0)
#define I2S_SAMPLE_RATE_11K025          I2S_CONTROL_DAC_SR(0x1)
#define I2S_SAMPLE_RATE_12K             I2S_CONTROL_DAC_SR(0x2)
#define I2S_SAMPLE_RATE_16K             I2S_CONTROL_DAC_SR(0x3)
#define I2S_SAMPLE_RATE_22K05           I2S_CONTROL_DAC_SR(0x4)
#define I2S_SAMPLE_RATE_24K             I2S_CONTROL_DAC_SR(0x5)
#define I2S_SAMPLE_RATE_32K             I2S_CONTROL_DAC_SR(0x6)
#define I2S_SAMPLE_RATE_44K1            I2S_CONTROL_DAC_SR(0x7)
#define I2S_SAMPLE_RATE_48K             I2S_CONTROL_DAC_SR(0xF)

// ADC Out Gain
#define ADC_OUT_GAIN_12DB               VOICE_CODEC_ADC_CONTROL_ADC_OUT_GAIN(0)
#define ADC_OUT_GAIN_6DB                VOICE_CODEC_ADC_CONTROL_ADC_OUT_GAIN(1)
#define ADC_OUT_GAIN_0DB                VOICE_CODEC_ADC_CONTROL_ADC_OUT_GAIN(2)
#define ADC_OUT_GAIN_n6DB               VOICE_CODEC_ADC_CONTROL_ADC_OUT_GAIN(3)

// Codec sample rate
#define PCM_SAMPLE_RATE_8K              VOICE_CODEC_ADC_CONTROL_CODEC_SR(0)
#define PCM_SAMPLE_RATE_16K             VOICE_CODEC_ADC_CONTROL_CODEC_SR(1)
#define PCM_SAMPLE_RATE_32K             VOICE_CODEC_ADC_CONTROL_CODEC_SR(2)
#define PCM_SAMPLE_RATE_32K_            VOICE_CODEC_ADC_CONTROL_CODEC_SR(3)

// Tx hpf sel
#define TX_HPF_8K_1ST                   VOICE_CODEC_ADC_CONTROL_TX_HPF_SEL(0)
#define TX_HPF_8K_4TH                   VOICE_CODEC_ADC_CONTROL_TX_HPF_SEL(1)
#define TX_HPF_8K_4TH_BURST_NOISE       VOICE_CODEC_ADC_CONTROL_TX_HPF_SEL(2)
#define TX_HPF_8K_4TH_CAR_NOISE         VOICE_CODEC_ADC_CONTROL_TX_HPF_SEL(3)
#define TX_HPF_16K_1ST                  VOICE_CODEC_ADC_CONTROL_TX_HPF_SEL(0)
#define TX_HPF_16K_2ND                  VOICE_CODEC_ADC_CONTROL_TX_HPF_SEL(1)
#define TX_HPF_16K_3RD                  VOICE_CODEC_ADC_CONTROL_TX_HPF_SEL(2)
#define TX_HPF_16K_4TH                  VOICE_CODEC_ADC_CONTROL_TX_HPF_SEL(3)

// HPF selection
#define VDAC_HPF_8K_1ST                 VOICD_CODEC_VDAC_CONTROL_VDAC_HPF_SEL(0)
#define VDAC_HPF_8K_4TH                 VOICD_CODEC_VDAC_CONTROL_VDAC_HPF_SEL(1)
#define VDAC_HPF_8K_4TH_BURST_NOISE     VOICD_CODEC_VDAC_CONTROL_VDAC_HPF_SEL(2)
#define VDAC_HPF_8K_4TH_CAR_NOISE       VOICD_CODEC_VDAC_CONTROL_VDAC_HPF_SEL(3)
#define VDAC_HPF_16K_1ST                VOICD_CODEC_VDAC_CONTROL_VDAC_HPF_SEL(0)
#define VDAC_HPF_16K_2ND                VOICD_CODEC_VDAC_CONTROL_VDAC_HPF_SEL(1)
#define VDAC_HPF_16K_3RD                VOICD_CODEC_VDAC_CONTROL_VDAC_HPF_SEL(2)
#define VDAC_HPF_16K_4TH                VOICD_CODEC_VDAC_CONTROL_VDAC_HPF_SEL(3)

// Sidetone Gain
#define ST_GAIN_0DB                     SIDETONE_ST_GAIN(0x00)
#define ST_GAIN_n46DB5                  SIDETONE_ST_GAIN(0x1F)

// Soft ramp
#define XXXX_RAMP_62MS5                 SOFT_START_RAMP_STEREO(0)
#define XXXX_RAMP_125MS                 SOFT_START_RAMP_STEREO(1)
#define XXXX_RAMP_250MS                 SOFT_START_RAMP_STEREO(2)
#define XXXX_RAMP_500MS                 SOFT_START_RAMP_STEREO(3)

void PMIC_Initial(void);
U32  PMIC_GetBatteryVoltage(void);
void PMIC_Backlight(U8 cPersentage);
void PMIC_LDOEnableOnSleep(void);
U8   PMIC_GetStatus(PMIC_Status_t tID);
U32  PMIC_GetEvent(void);

void PMIC_SetReg(U8 bRegAddr, U8 bRegVal);

void PMIC_INTEnable(U32 dwEnable);
void PMIC_INTDisable(U32 dwDisable);

void PMIC_INTHandler(void);

void PMIC_TouchPowerOFF(void);
void PMIC_TouchPowerON(void);
void PMIC_ReadXY(U16 *pwX, U16 *pwY);

#define PMIC_SetModePenDownDetect(dummy) PMIC_SetReg(DA9034_ADC_AUTO_CONTROL2, ADC_AUTO_CONTROL2_PEN_DETECT_ENABLE);
#define PMIC_SetModeAutoSample(dummy)    PMIC_SetReg(DA9034_ADC_AUTO_CONTROL2, ADC_AUTO_CONTROL2_AUTO_TSI_ENABLE);

#define PMIC_I2SSetting(y)              PMIC_SetReg(DA9034_I2S_CONTROL,             (y))
#define PMIC_DACSetting(y)              PMIC_SetReg(DA9034_STEREO_DAC_CONTROL,      (y))
#define PMIC_VoiceADCSetting(y)         PMIC_SetReg(DA9034_VOICE_CODEC_ADC_CONTROL, (y))
#define PMIC_VoiceDACSetting(y)         PMIC_SetReg(DA9034_VOICE_CODEC_VDAC_CONTROL,(y))
#define PMIC_SidetoneSetting(y)         PMIC_SetReg(DA9034_SIDETONE,                (y))
#define PMIC_StartRampSetting(y)        PMIC_SetReg(DA9034_SOFT_START_RAMP,         (y))
#define PMIC_SetMonoGain(y)             PMIC_SetReg(DA9034_MONO_VOL,                (y))
#define PMIC_SetBearGain(y)             PMIC_SetReg(DA9034_BEAR_VOL,                (y))
#define PMIC_SetLineoutGain(y)          PMIC_SetReg(DA9034_AUDIO_LINE_AMP,          (y))
#define PMIC_SetStereo1Gain(y)          PMIC_SetReg(DA9034_STEREO_AMPLITUDE_CH1,    (y))
#define PMIC_SetStereo2Gain(y)          PMIC_SetReg(DA9034_STEREO_AMPLITUDE_CH2,    (y))
#define PMIC_SetTxPGAGain(y)            PMIC_SetReg(DA9034_TX_PGA,                  (y))
#define PMIC_SetMicAmpGain(y)           PMIC_SetReg(DA9034_MICAMP,                  (y))
#define PMIC_SetAUX1Gain(y)             PMIC_SetReg(DA9034_AUXI1_2,                 (y))
#define PMIC_SetAUX2Gain(y)             PMIC_SetReg(DA9034_AUXI1_2,                 (y))
#define PMIC_SetAUX3Gain(y)             PMIC_SetReg(DA9034_AUXI3,                   (y))
#define PMIC_SetDAC1Gain(y)             PMIC_SetReg(DA9034_PGA_DACS,                (y))
#define PMIC_SetDAC2Gain(y)             PMIC_SetReg(DA9034_PGA_DACS,                (y))
#define PMIC_SetDAC3Gain(y)             PMIC_SetReg(DA9034_PGA_DACS,                (y))
#define PMIC_SetMonoMux(y)              PMIC_SetReg(DA9034_MUX_MONO,                (y))
#define PMIC_SetBearMux(y)              PMIC_SetReg(DA9034_MUX_BEAR,                (y))
#define PMIC_SetLineoutMux(y)           PMIC_SetReg(DA9034_MUX_LINE,                (y))
#define PMIC_SetStereo1Mux(y)           PMIC_SetReg(DA9034_MUX_STEREO1,             (y))
#define PMIC_SetStereo2Mux(y)           PMIC_SetReg(DA9034_MUX_STEREO2,             (y))
#define PMIC_SetTxPGAMux(y)             PMIC_SetReg(DA9034_TX_PGA_MUX,              (y))

