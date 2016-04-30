
void Audio_EnableI2StoHeadset(void)
{
    GPIO_SPKDisable();

    // i2s to stereo
    PMIC_SetStereo1Mux(MUX_XXXX_DAC_1);
    PMIC_SetStereo2Mux(MUX_XXXX_DAC_2);

    // stereo gain 15DB
    PMIC_SetStereo1Gain((STEREO_AMPLITUDE_CH1_STEREO_EN | STEREO_AMPLITUDE_CH1_AMP_CH1(0x00)));
    PMIC_SetStereo2Gain(STEREO_AMPLITUDE_CH2_AMP_CH2(0x00));

    // DAC1, DAC2 gain
    PMIC_SetDAC1Gain(PGA_DAC1_GAIN(0));
    PMIC_SetDAC2Gain(PGA_DAC2_GAIN(0));
}

void Audio_EnableI2StoSpeaker(void)
{
    GPIO_SPKEnable();

    // i2s to stereo
    PMIC_SetMonoMux((MUX_XXXX_DAC_1 | MUX_XXXX_DAC_2));

    // stereo gain 15DB
    PMIC_SetMonoGain((MONO_VOL_MONO_EN | MONO_VOL_MONO_GAIN(0x00)));

    // DAC1, DAC2 gain
    PMIC_SetDAC1Gain(PGA_DAC1_GAIN(0));
    PMIC_SetDAC2Gain(PGA_DAC2_GAIN(0));
}

void Audio_EnableI2StoReceiver(void)
{
    GPIO_SPKDisable();

    // i2s to stereo
    PMIC_SetBearMux((MUX_XXXX_DAC_1 | MUX_XXXX_DAC_2));

    // stereo gain 15DB
    PMIC_SetBearGain((BEAR_VOL_BEAR_EN | BEAR_VOL_BEAR_GAIN(0x00)));

    // DAC1, DAC2 gain
    PMIC_SetDAC1Gain(PGA_DAC1_GAIN(0));
    PMIC_SetDAC2Gain(PGA_DAC2_GAIN(0));
}

