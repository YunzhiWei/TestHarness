
/*
    I2C Slave Address
*/

#define DA9034_I2C_ADDRESS                                  0x68

/*
    Reg Address
*/

#define DA9034_CHIP_ID                                      0x00

#define DA9034_EVENT_A                                      0x01
#define DA9034_EVENT_B                                      0x02
#define DA9034_EVENT_C                                      0x03
#define DA9034_EVENT_D                                      0x04

#define DA9034_STATUS_A                                     0x05
#define DA9034_STATUS_B                                     0x06

#define DA9034_nIRQ_MASK_A                                  0x07
#define DA9034_nIRQ_MASK_B                                  0x08
#define DA9034_nIRQ_MASK_C                                  0x09
#define DA9034_nIRQ_MASK_D                                  0x0A

#define DA9034_SYS_CTRL_A                                   0x0B
#define DA9034_SYS_CTRL_B                                   0x0C

#define DA9034_FAULT_LOG                                    0x0D
#define DA9034_OVER1                                        0x10
#define DA9034_APPS_OVER2                                   0x11
#define DA9034_COMM_OVER2                                   0x21
#define DA9034_APPS_OVER3                                   0x12
#define DA9034_COMM_OVER3                                   0x22

#define DA9034_LDO6_4_3                                     0x13
#define DA9034_LDO9_8_7                                     0x14
#define DA9034_LDO11_10                                     0x15
#define DA9034_LDO13_12                                     0x16
#define DA9034_LDO15_14                                     0x17

#define DA9034_BUCK_SLEEP                                   0x18

#define DA9034_LDO_nSLEEP_1                                 0x19
#define DA9034_LDO_nSLEEP_2                                 0x1A

#define DA9034_LDO_SLEEP_BIT_1                              0x1B
#define DA9034_LDO_SLEEP_BIT_2                              0x1C

#define DA9034_VCC1                                         0x20
#define DA9034_ADTV1                                        0x23
#define DA9034_ADTV2                                        0x24
#define DA9034_BUCK1_AVRC                                   0x25
#define DA9034_SDTV1                                        0x29
#define DA9034_SDTV2                                        0x2A
#define DA9034_SVRC                                         0x2B
#define DA9034_MDTV1                                        0x32
#define DA9034_MDTV2                                        0x33
#define DA9034_MVRC                                         0x34
#define DA9034_CDTV1                                        0x26
#define DA9034_CDTV2                                        0x27
#define DA9034_CVRC                                         0x28
#define DA9034_LED1_CONTROL                                 0x35
#define DA9034_LED2_CONTROL                                 0x36
#define DA9034_LEDPC_CONTROL1                               0x37
#define DA9034_LEDPC_CONTROL2                               0x38
#define DA9034_LEDPC_CONTROL3                               0x39
#define DA9034_LEDPC_CONTROL4                               0x3A
#define DA9034_LEDPC_CONTROL5                               0x3B
#define DA9034_WLED_CONTROL_1                               0x3C
#define DA9034_WLED_CONTROL_2                               0x3D
#define DA9034_FLASH_CONTROL_1                              0x3E
#define DA9034_FLASH_CONTROL_2                              0x3F
#define DA9034_VIBRA_CONTROL                                0x40
#define DA9034_MISC                                         0x41
#define DA9034_CHARGE_CONTROL                               0x42
#define DA9034_CCTR_CONTROL                                 0x43
#define DA9034_TCTR_CONTROL                                 0x44
#define DA9034_CHARGE_PULSE                                 0x45
#define DA9034_DAC_MSB                                      0x46
#define DA9034_DAC_LSB                                      0x47
#define DA9034_UART_ADDR                                    0x48
#define DA9034_UART_CONTROL                                 0x49
#define DA9034_UART_TX_DATA                                 0x4A
#define DA9034_UART_RX_DATA                                 0x4B
#define DA9034_ADC_MAN_CONTROL                              0x50
#define DA9034_ADC_AUTO_CONTROL1                            0x51
#define DA9034_ADC_AUTO_CONTROL2                            0x52
#define DA9034_TSI_CONTROL_1                                0x53
#define DA9034_TSI_CONTROL_2                                0x54
#define DA9034_VBAT_MON                                     0x55
#define DA9034_VBATHIGHP                                    0x56
#define DA9034_VBATHIGHN                                    0x57
#define DA9034_TBATLOW                                      0x58
#define DA9034_AUTO4HIGH                                    0x59
#define DA9034_AUTO4LOW                                     0x5A
#define DA9034_AUTO5HIGH                                    0x5B
#define DA9034_AUTO5LOW                                     0x5C
#define DA9034_AUTO6HIGH                                    0x5D
#define DA9034_AUTO6LOW                                     0x5E
#define DA9034_MAN_RES_LSB                                  0x5F
#define DA9034_MAN_RES_MSB                                  0x60
#define DA9034_VBAT_RES                                     0x61
#define DA9034_VBATMIN_RES                                  0x62
#define DA9034_ICHMAX_RES                                   0x63
#define DA9034_ICHMIN_RES                                   0x64
#define DA9034_ICHAVERAGE_RES                               0x65
#define DA9034_VCHMAX_RES                                   0x66
#define DA9034_VCHMIN_RES                                   0x67
#define DA9034_TBAT_RES                                     0x68
#define DA9034_AUTO4_RES                                    0x69
#define DA9034_AUTO5_RES                                    0x6A
#define DA9034_AUTO6_RES                                    0x6B
#define DA9034_TSI_X_MSB                                    0x6C
#define DA9034_TSI_Y_MSB                                    0x6D
#define DA9034_TSI_X_Y_LSB                                  0x6E
#define DA9034_MUX_MONO                                     0x70
#define DA9034_MUX_BEAR                                     0x71
#define DA9034_MUX_LINE                                     0x72
#define DA9034_MUX_STEREO1                                  0x73
#define DA9034_MUX_STEREO2                                  0x74
#define DA9034_TX_PGA_MUX                                   0x7E
#define DA9034_AUDIO_LINE_AMP                               0x75
#define DA9034_STEREO_AMPLITUDE_CH1                         0x76
#define DA9034_STEREO_AMPLITUDE_CH2                         0x77
#define DA9034_MONO_VOL                                     0x79
#define DA9034_BEAR_VOL                                     0x7A
#define DA9034_TX_PGA                                       0x7C
#define DA9034_MICAMP                                       0x7D
#define DA9034_AUXI1_2                                      0x82
#define DA9034_AUXI3                                        0x83
#define DA9034_STEREO_DAC_CONTROL                           0x78
#define DA9034_I2S_CONTROL                                  0x7B
#define DA9034_VOICE_CODEC_ADC_CONTROL                      0x7F
#define DA9034_VOICE_CODEC_VDAC_CONTROL                     0x80
#define DA9034_SIDETONE                                     0x81
#define DA9034_PGA_DACS                                     0x84
#define DA9034_SOFT_START_RAMP                              0x85

/*
    Reg Bit
*/

#define CHIP_ID_NEW_RELEASE_CODE_NRC_MASK                   (0xfu << 4)
#define CHIP_ID_MINOR_REVISION_CODE_MRC_MASK                (0xfu << 0)

#define EVENT_A_CH_IOVER                                    (0x1u << 7)
#define EVENT_A_REV_IOVER                                   (0x1u << 6)
#define EVENT_A_VBAT_MON                                    (0x1u << 5)
#define EVENT_A_TBAT                                        (0x1u << 4)
#define EVENT_A_CHDET                                       (0x1u << 3)
#define EVENT_A_nEXTON                                      (0x1u << 2)
#define EVENT_A_nONKEY                                      (0x1u << 0)

#define EVENT_B_SRP_READY_0_6                               (0x1u << 7)
#define EVENT_B_SESSION_VALID_1_8                           (0x1u << 6)
#define EVENT_B_VBUS_VALID_3_8                              (0x1u << 5)
#define EVENT_B_VBUS_VALID_4_55                             (0x1u << 4)
#define EVENT_B_OTGCP_IOVER                                 (0x1u << 3)
#define EVENT_B_USB_DEV                                     (0x1u << 2)
#define EVENT_B_CH_CCTO                                     (0x1u << 1)
#define EVENT_B_CH_TCTO                                     (0x1u << 0)

#define EVENT_C_TSI_READY                                   (0x1u << 5)
#define EVENT_C_PEN_DOWN                                    (0x1u << 4)
#define EVENT_C_ADC_AUTO6                                   (0x1u << 3)
#define EVENT_C_ADC_AUTO5                                   (0x1u << 2)
#define EVENT_C_ADC_AUTO4                                   (0x1u << 1)
#define EVENT_C_ADC_MAN                                     (0x1u << 0)

#define EVENT_D_WATCHDOG                                    (0x1u << 5)
#define EVENT_D_HOOKSWITCH                                  (0x1u << 4)
#define EVENT_D_HEADSET                                     (0x1u << 3)
#define EVENT_D_UART_TIME_OUT                               (0x1u << 2)
#define EVENT_D_UART_RX_COMPLETE                            (0x1u << 1)
#define EVENT_D_UART_TX_COMPLETE                            (0x1u << 0)

#define STATUS_A_MCLK_DETECT                                (0x1u << 7)
#define STATUS_A_PEN_DOWN                                   (0x1u << 6)
#define STATUS_A_VBAT_MON                                   (0x1u << 5)
#define STATUS_A_TBAT                                       (0x1u << 4)
#define STATUS_A_CHDET                                      (0x1u << 3)
#define STATUS_A_nEXTON                                     (0x1u << 2)
#define STATUS_A_nONKEY                                     (0x1u << 0)

#define STATUS_B_SRP_READY_0_6                              (0x1u << 7)
#define STATUS_B_SESSION_VALID_1_8                          (0x1u << 6)
#define STATUS_B_VBUS_VALID_3_8                             (0x1u << 5)
#define STATUS_B_VBUS_VALID_4_55                            (0x1u << 4)
#define STATUS_B_HOOKSWITCH                                 (0x1u << 2)
#define STATUS_B_HEADSET                                    (0x1u << 1)
#define STATUS_B_USB_DEV                                    (0x1u << 0)

#define nIRQ_MASK_A_CH_IOVER                                (0x1u << 7)
#define nIRQ_MASK_A_REV_IOVER                               (0x1u << 6)
#define nIRQ_MASK_A_VBAT_MON                                (0x1u << 5)
#define nIRQ_MASK_A_TBAT                                    (0x1u << 4)
#define nIRQ_MASK_A_CHDET                                   (0x1u << 3)
#define nIRQ_MASK_A_nEXTON                                  (0x1u << 2)
#define nIRQ_MASK_A_nONKEY                                  (0x1u << 0)

#define nIRQ_MASK_B_SRP_READY_0_6                           (0x1u << 7)
#define nIRQ_MASK_B_SESSION_VALID_1_8                       (0x1u << 6)
#define nIRQ_MASK_B_VBUS_VALID_3_8                          (0x1u << 5)
#define nIRQ_MASK_B_VBUS_VALID_4_55                         (0x1u << 4)
#define nIRQ_MASK_B_OTGCP_IOVER                             (0x1u << 3)
#define nIRQ_MASK_B_USB_DEV                                 (0x1u << 2)
#define nIRQ_MASK_B_CH_CCTO                                 (0x1u << 1)
#define nIRQ_MASK_B_CH_TCTO                                 (0x1u << 0)

#define nIRQ_MASK_C_TSI_READY                               (0x1u << 5)
#define nIRQ_MASK_C_PEN_DOWN                                (0x1u << 4)
#define nIRQ_MASK_C_ADC_AUTO6                               (0x1u << 3)
#define nIRQ_MASK_C_ADC_AUTO5                               (0x1u << 2)
#define nIRQ_MASK_C_ADC_AUTO4                               (0x1u << 1)
#define nIRQ_MASK_C_ADC_MAN                                 (0x1u << 0)

#define nIRQ_MASK_D_WATCHDOG                                (0x1u << 5)
#define nIRQ_MASK_D_HOOKSWITCH                              (0x1u << 4)
#define nIRQ_MASK_D_HEADSET                                 (0x1u << 3)
#define nIRQ_MASK_D_UART_TIME_OUT                           (0x1u << 2)
#define nIRQ_MASK_D_UART_RX_COMPLETE                        (0x1u << 1)
#define nIRQ_MASK_D_UART_TX_COMPLETE                        (0x1u << 0)

#define SYS_CTRL_A_WATCHDOG                                 (0x1u << 7)
#define SYS_CTRL_A_TWD_SCALE(x)                             ((0x7u & (x)) << 4)
#define SYS_CTRL_A_WATCHDOG_nIRQ                            (0x1u << 3)
#define SYS_CTRL_A_WATCHDOG_ENABLE                          (0x1u << 2)
#define SYS_CTRL_A_SLEEP                                    (0x1u << 1)
#define SYS_CTRL_A_nSLEEP_PIN_ENABLE                        (0x1u << 0)

#define SYS_CTRL_B_MCLKDIV(x)                               ((0x3u & (x)) << 6)
#define SYS_CTRL_B_nONKEY_SHUT_ENABLE                       (0x1u << 5)
#define SYS_CTRL_B_CLOCK_BUFFER_ENABLE                      (0x1u << 4)
#define SYS_CTRL_B_AUTO_SWITCH                              (0x1u << 3)
#define SYS_CTRL_B_nONKEY_PRESS_TIME                        (0x1u << 2)
#define SYS_CTRL_B_MCLKDEL(x)                               ((0x3u & (x)) << 0)

#define FAULT_LOG_nONKEY_SHUT                               (0x1u << 6)
#define FAULT_LOG_OVER_TEMP                                 (0x1u << 5)
#define FAULT_LOG_VBAT_OVER                                 (0x1u << 4)
#define FAULT_LOG_TWDMAX_ERROR                              (0x1u << 3)
#define FAULT_LOG_TWDMIN_ERROR                              (0x1u << 2)
#define FAULT_LOG_VBAT_UNDER                                (0x1u << 1)
#define FAULT_LOG_SYS_EN                                    (0x1u << 0)

#define OVER1_SEL_LDO_DRIVE                                 (0x1u << 4)
#define OVER1_LDO2_ENABLE                                   (0x1u << 2)
#define OVER1_BUCK1_ENABLE                                  (0x1u << 0)

#define APPS_OVER2_LDO13_ENABLE                             (0x1u << 7)
#define APPS_OVER2_LDO12_ENABLE                             (0x1u << 6)
#define APPS_OVER2_LDO11_ENABLE                             (0x1u << 5)
#define APPS_OVER2_LDO10_ENABLE                             (0x1u << 4)
#define APPS_OVER2_LDO9_ENABLE                              (0x1u << 3)
#define APPS_OVER2_LDO8_ENABLE                              (0x1u << 2)
#define APPS_OVER2_LDO7_ENABLE                              (0x1u << 1)
#define APPS_OVER2_LDO6_ENABLE                              (0x1u << 0)

#define COMM_OVER2_LDO13_ENABLE                             (0x1u << 7)
#define COMM_OVER2_LDO12_ENABLE                             (0x1u << 6)
#define COMM_OVER2_LDO11_ENABLE                             (0x1u << 5)
#define COMM_OVER2_LDO10_ENABLE                             (0x1u << 4)
#define COMM_OVER2_LDO9_ENABLE                              (0x1u << 3)
#define COMM_OVER2_LDO8_ENABLE                              (0x1u << 2)
#define COMM_OVER2_LDO7_ENABLE                              (0x1u << 1)
#define COMM_OVER2_LDO6_ENABLE                              (0x1u << 0)

#define APPS_OVER3_LDO5_ENABLE                              (0x1u << 7)
#define APPS_OVER3_LDO4_ENABLE                              (0x1u << 6)
#define APPS_OVER3_LDO3_ENABLE                              (0x1u << 5)
#define APPS_OVER3_LDO1_ENABLE                              (0x1u << 4)
#define APPS_OVER3_BUCK2_ENABLE                             (0x1u << 3)
#define APPS_OVER3_RF_GP_ENABLE                             (0x1u << 2)
#define APPS_OVER3_LDO15_ENABLE                             (0x1u << 1)
#define APPS_OVER3_LDO14_ENABLE                             (0x1u << 0)

#define COMM_OVER3_LDO5_ENABLE                              (0x1u << 7)
#define COMM_OVER3_LDO4_ENABLE                              (0x1u << 6)
#define COMM_OVER3_LDO3_ENABLE                              (0x1u << 5)
#define COMM_OVER3_LDO1_ENABLE                              (0x1u << 4)
#define COMM_OVER3_BUCK2_ENABLE                             (0x1u << 3)
#define COMM_OVER3_RF_GP_ENABLE                             (0x1u << 2)
#define COMM_OVER3_LDO15_ENABLE                             (0x1u << 1)
#define COMM_OVER3_LDO14_ENABLE                             (0x1u << 0)

#define LDO6_4_3_LDO6_TRIM(x)                               ((0x7u & (x)) << 5)
#define LDO6_4_3_LDO4_SEL_2V9                               (1u << 4)
#define LDO6_4_3_LDO4_SEL_1V8                               (0u << 4)
#define LDO6_4_3_LDO3_TRIM(x)                               ((0xfu & (x)) << 0)

#define LDO9_8_7_LDO9_TRIM(x)                               ((0x7u & (x)) << 5)
#define LDO9_8_7_LDO8_TRIM(x)                               ((0x3u & (x)) << 3)
#define LDO9_8_7_LDO7_TRIM(x)                               ((0x7u & (x)) << 0)

#define LDO11_10_LDO11_TRIM(x)                              ((0xfu & (x)) << 4)
#define LDO11_10_BUCK2_SEL_1V9                              (1u << 3)
#define LDO11_10_BUCK2_SEL_1V8                              (0u << 3)
#define LDO11_10_LDO10_TRIM(x)                              ((0x7u & (x)) << 0)

#define LDO_13_12_LDO13_TRIM(x)                             ((0xfu & (x)) << 4)
#define LDO_13_12_LDO12_TRIM(x)                             ((0xfu & (x)) << 0)

#define LDO_15_14_LDO15_TRIM(x)                             ((0xfu & (x)) << 4)
#define LDO_15_14_LDO14_TRIM(x)                             ((0xfu & (x)) << 0)

#define BUCK_SLEEP_BUCK1_AUTO_SLEEP                         (0x1u << 6)
#define BUCK_SLEEP_BUCK2_SLEEP_BIT_ENABLE                   (0x1u << 5)
#define BUCK_SLEEP_BUCK1_SLEEP_BIT_ENABLE                   (0x1u << 3)
#define BUCK_SLEEP_BUCK_nSLEEP_ENABLE                       (0x1u << 2)
#define BUCK_SLEEP_BUCK1_nSLEEP_ENABLE                      (0x1u << 0)

#define LDO_nSLEEP_1_LDO13_nSLEEP_ENABLE                    (0x1u << 7)
#define LDO_nSLEEP_1_LDO12_nSLEEP_ENABLE                    (0x1u << 6)
#define LDO_nSLEEP_1_LDO11_nSLEEP_ENABLE                    (0x1u << 5)
#define LDO_nSLEEP_1_LDO10_nSLEEP_ENABLE                    (0x1u << 4)
#define LDO_nSLEEP_1_LDO9_nSLEEP_ENABLE                     (0x1u << 3)
#define LDO_nSLEEP_1_LDO8_nSLEEP_ENABLE                     (0x1u << 2)
#define LDO_nSLEEP_1_LDO7_nSLEEP_ENABLE                     (0x1u << 1)
#define LDO_nSLEEP_1_LDO6_nSLEEP_ENABLE                     (0x1u << 0)

#define LDO_SLEEP_BIT_1_LDO13_nSLEEP_ENABLE                 (0x1u << 7)
#define LDO_SLEEP_BIT_1_LDO12_nSLEEP_ENABLE                 (0x1u << 6)
#define LDO_SLEEP_BIT_1_LDO11_nSLEEP_ENABLE                 (0x1u << 5)
#define LDO_SLEEP_BIT_1_LDO10_nSLEEP_ENABLE                 (0x1u << 4)
#define LDO_SLEEP_BIT_1_LDO9_nSLEEP_ENABLE                  (0x1u << 3)
#define LDO_SLEEP_BIT_1_LDO8_nSLEEP_ENABLE                  (0x1u << 2)
#define LDO_SLEEP_BIT_1_LDO7_nSLEEP_ENABLE                  (0x1u << 1)
#define LDO_SLEEP_BIT_1_LDO6_nSLEEP_ENABLE                  (0x1u << 0)

#define LDO_nSLEEP_2_LDO5_nSLEEP_ENABLE                     (0x1u << 5)
#define LDO_nSLEEP_2_LDO4_nSLEEP_ENABLE                     (0x1u << 4)
#define LDO_nSLEEP_2_LDO2_nSLEEP_ENABLE                     (0x1u << 3)
#define LDO_nSLEEP_2_RF_GP_nSLEEP_ENABLE                    (0x1u << 2)
#define LDO_nSLEEP_2_LDO15_nSLEEP_ENABLE                    (0x1u << 1)
#define LDO_nSLEEP_2_LDO14_nSLEEP_ENABLE                    (0x1u << 0)

#define LDO_SLEEP_BIT_2_LDO5_nSLEEP_ENABLE                  (0x1u << 5)
#define LDO_SLEEP_BIT_2_LDO4_nSLEEP_ENABLE                  (0x1u << 4)
#define LDO_SLEEP_BIT_2_LDO2_nSLEEP_ENABLE                  (0x1u << 3)
#define LDO_SLEEP_BIT_2_RF_GP_nSLEEP_ENABLE                 (0x1u << 2)
#define LDO_SLEEP_BIT_2_LDO15_nSLEEP_ENABLE                 (0x1u << 1)
#define LDO_SLEEP_BIT_2_LDO14_nSLEEP_ENABLE                 (0x1u << 0)

#define VCC1_MVT_SEL_1                                      (0x0u << 7)
#define VCC1_MVT_SEL_2                                      (0x1u << 7)
#define VCC1_MVT_GO                                         (0x1u << 6)
#define VCC1_SRAM_SEL_1                                     (0x0u << 5)
#define VCC1_SRAM_SEL_2                                     (0x1u << 5)
#define VCC1_SRAM_GO                                        (0x1u << 4)
#define VCC1_APPS_SEL_1                                     (0x0u << 1)
#define VCC1_APPS_SEL_2                                     (0x1u << 1)
#define VCC1_APPS_GO                                        (0x1u << 0)

#define ADTV1_APPS_TRIM1(x)                                 ((0x1fu & (x)) << 0)
#define ADTV2_APPS_TRIM2(x)                                 ((0x1fu & (x)) << 0)
#define BUCK1_AVRC_APPS_STEP(x)                             ((0x3u  & (x)) << 3)
#define BUCK1_AVRC_APPS_RATE(x)                             ((0x7u  & (x)) << 0)

#define SDTV1_SRAM_TRIM1(x)                                 ((0x1fu & (x)) << 0)
#define SDTV2_SRAM_TRIM2(x)                                 ((0x1fu & (x)) << 0)
#define SVRC_SRAM_STEP(x)                                   ((0x3u  & (x)) << 3)
#define SVRC_SRAM_RATE(x)                                   ((0x7u  & (x)) << 0)

#define MDTV1_MVT_TRIM1(x)                                  ((0xfu & (x)) << 0)
#define MDTV2_MVT_TRIM2(x)                                  ((0xfu & (x)) << 0)
#define MVRC_MVT_STEP(x)                                    ((0x3u  & (x)) << 3)
#define MVRC_MVT_RATE(x)                                    ((0x7u  & (x)) << 0)

#define CDTV1_RESEVED
#define CDTV2_RESEVED
#define CVRC_RESEVED

#define LED1_CONTROL_LED1_RAMP                              (0x1u << 7)
#define LED1_CONTROL_LED1_PWM(x)                            ((0x7fu & (x)) << 0)

#define LED2_CONTROL_LED2_RAMP                              (0x1u << 7)
#define LED2_CONTROL_LED2_PWM(x)                            ((0x7fu & (x)) << 0)

#define LEDPC_CONTROL1_LEDPC_WINDOW(x)                      ((0xffu & (x)) << 0)
#define LEDPC_CONTROL2_LEDPC_WINDOW(x)                      ((0xffu & (x)) << 0)
#define LEDPC_CONTROL3_LEDPC_WINDOW(x)                      ((0xffu & (x)) << 0)
#define LEDPC_CONTROL4_LEDPC_WINDOW(x)                      ((0xffu & (x)) << 0)
#define LEDPC_CONTROL5_LEDPC_WINDOW(x)                      ((0xffu & (x)) << 0)

#define WLED_CONTROL_1_WLED_RAMP                            (0x1u << 7)
#define WLED_CONTROL_1_WLED_PWM(x)                          ((0x7fu & (x)) << 0)

#define WLED_CONTROL_2_BOOST_ENABLE                         (0x1u << 5)
#define WLED_CONTROL_2_WLED_ISET(x)                         ((0x1fu & (x)) << 0)

#define FLASH_CONTROL_1_TORCH_ON                            (0x1u << 5)
#define FLASH_CONTROL_1_FLASH_ON_PIN_ENABLE                 (0x1u << 4)
#define FLASH_CONTROL_1_FLASH_TIME(x)                       ((0xfu & (x)) << 0)

#define FLASH_CONTROL_2_FLASH_ISET(x)                       ((0x1fu & (x)) << 0)

#define VIBRA_CONTROL_VIBRA_PWM(x)                          ((0x7fu & (x)) << 1)
#define VIBRA_CONTROL_VIBRA_LDO                             (0x1u << 0)

#define MISC_VBUS_COMPS_ENABLE                              (0x1u << 7)
#define MISC_USBSR_ENABLE                                   (0x1u << 6)
#define MISC_USBCP_ENABLE                                   (0x1u << 5)
#define MISC_I_TBAT_ALWAYS_ON                               (0x1u << 4)
#define MISC_ID_BAT_ALWAYS_ON                               (0x1u << 3)
#define MISC_REMCON_FILTER                                  (0x1u << 2)
#define MISC_REMCON_ENABLE                                  (0x1u << 1)
#define MISC_REMCON_AUTO                                    (0x1u << 0)

#define CHARGE_CONTROL_CHARGE_ENABLE                        (0x1u << 7)
#define CHARGE_CONTROL_ISET(x)                              ((0xfu & (x)) << 3)
#define CHARGE_CONTROL_VSET(x)                              ((0x7u & (x)) << 0)

#define CCTR_CONTROL_CCTR(x)                                ((0x1fu & (x)) << 0)

#define TCTR_REVERSE_SUPPLY_ENABLE                          (1u << 4)
#define TCTR_CONTROL_TCTR(x)                                ((0xfu & (x)) << 0)

#define CHARGE_PULSE_PPULSECLK(x)                           ((0x3u & (x)) << 6)
#define CHARGE_PULSE_TPULSEOFF(x)                           ((0x7u & (x)) << 3)
#define CHARGE_PULSE_TPULSEON(x)                            ((0x7u & (x)) << 0)

#define DAC_MSB_DAC(x)                                      ((0xffu & (x)) << 0)
#define DAC_LSB_DAC_ENABLE                                  (1u << 3)
#define DAC_LSB_DAC(x)                                      ((0x7u & (x)) << 0)

#define UART_ADDR_UART_ADDR(x)                              ((0x7fu & (x)) << 0)

#define UART_CONTROL_UART_RESET                             (0x1u << 2)
#define UART_CONTROL_UART_RBW                               (0x1u << 1)
#define UART_CONTROL_UART_GO                                (0x1u << 0)

#define UART_UART_TX_DATA(x)                                ((0xffu & (x)) << 0)
#define UART_UART_RX_DATA(x)                                ((0xffu & (x)) << 0)

#define ADC_MAN_CONTROL_IDBAT_ENABLE                        (0x1u << 5)
#define ADC_MAN_CONTROL_LDO_ADC_ENABLE                      (0x1u << 4)
#define ADC_MAN_CONTROL_MAN_CONV                            (0x1u << 3)
#define ADC_MAN_CONTROL_ADC_MANUAL_MUX_SEL(x)               ((0x7u & (x)) << 0)

#define ADC_AUTO_CONTROL1_DEBOUNCE_VBAT_MON                 (0x1u << 6)
#define ADC_AUTO_CONTROL1_AUTO_TBAT_ENABLE                  (0x1u << 5)
#define ADC_AUTO_CONTROL1_AUTO_VBAT_EXTRA                   (0x1u << 4)
#define ADC_AUTO_CONTROL1_AUTO_VCH_ENABLE                   (0x1u << 3)
#define ADC_AUTO_CONTROL1_AUTO_ICH_ENABLE                   (0x1u << 2)
#define ADC_AUTO_CONTROL1_AUTO_VBAT_ENABLE                  (0x1u << 1)
#define ADC_AUTO_CONTROL1_AUTO_ADC_SLEEP_ENABLE             (0x1u << 0)

#define ADC_AUTO_CONTROL2_PEN_DETECT_ENABLE                 (0x1u << 4)
#define ADC_AUTO_CONTROL2_AUTO_TSI_ENABLE                   (0x1u << 3)
#define ADC_AUTO_CONTROL2_AUTO6_ENABLE                      (0x1u << 2)
#define ADC_AUTO_CONTROL2_AUTO5_ENABLE                      (0x1u << 1)
#define ADC_AUTO_CONTROL2_AUTO4_ENABLE                      (0x1u << 0)

#define TSI_CONTROL_1_TSI_SKIP(x)                           ((0x7u & (x)) << 3)
#define TSI_CONTROL_1_TSI_DELAY(x)                          ((0x7u & (x)) << 0)

#define TSI_CONTROL_2_ADCREF                                (1u << 7)
#define TSI_CONTROL_2_TSI_MANUAL                            (1u << 6)
#define TSI_CONTROL_2_TSI_MUX(x)                            ((0x3u & (x)) << 4)
#define TSI_CONTROL_2_TSI_SEL(x)                            ((0xfu & (x)) << 0)

#define VBAT_VBAT_MON(x)                                    ((0xffu & (x)) << 0)
#define VBAT_VBATHIGHP(x)                                   ((0xffu & (x)) << 0)
#define VBAT_VBATHIGHN(x)                                   ((0xffu & (x)) << 0)
#define VBAT_VBATLOW(x)                                     ((0xffu & (x)) << 0)
#define AUTO4_AUTO4HIGH(x)                                  ((0xffu & (x)) << 0)
#define AUTO4_AUTO4LOW(x)                                   ((0xffu & (x)) << 0)
#define AUTO5_AUTO5HIGH(x)                                  ((0xffu & (x)) << 0)
#define AUTO5_AUTO5LOW(x)                                   ((0xffu & (x)) << 0)
#define AUTO6_AUTO6HIGH(x)                                  ((0xffu & (x)) << 0)
#define AUTO6_AUTO6LOW(x)                                   ((0xffu & (x)) << 0)

#define MAN_RES_LSB_MANRES                                  ((0x3u & (x)) << 0)
#define MAN_RES_MSB_MANRES                                  ((0xffu & (x)) << 0)

#define VBAT_VBAT_RES(x)                                    ((0xffu & (x)) << 0)
#define VBAT_VBATMIN_RES(x)                                 ((0xffu & (x)) << 0)

#define ICH_ICHMAX_RES(x)                                   ((0xffu & (x)) << 0)
#define ICH_ICHMIN_RES(x)                                   ((0xffu & (x)) << 0)
#define ICH_ICHAVERAGE_RES(x)                               ((0xffu & (x)) << 0)
#define VCH_VCHMAX_RES(x)                                   ((0xffu & (x)) << 0)
#define VCH_VCHMIN_RES(x)                                   ((0xffu & (x)) << 0)
#define TBAT__TBAT_RES(x)                                   ((0xffu & (x)) << 0)
#define AUTO4_AUTO4_RES(x)                                  ((0xffu & (x)) << 0)
#define AUTO5_AUTO5_RES(x)                                  ((0xffu & (x)) << 0)
#define AUTO6_AUTO6_RES(x)                                  ((0xffu & (x)) << 0)

#define TSI_TSI_X_MSB(x)                                    ((0xffu & (x)) << 0)
#define TSI_TSI_Y_MSB(x)                                    ((0xffu & (x)) << 0)
#define TSI_XY_LSB_PEN_DOWN                                 (1u << 4)
#define TSI_XY_LSB_TSI_Y(x)                                 ((0x3u & (x)) << 2)
#define TSI_XY_LSB_TSI_X(x)                                 ((0x3u & (x)) << 0)

#define MUX_XXXX_AUXI_1                                     (1u << 0)
#define MUX_XXXX_AUXI_2                                     (1u << 1)
#define MUX_XXXX_AUXI_3                                     (1u << 2)
#define MUX_XXXX_DAC_1                                      (1u << 3)
#define MUX_XXXX_DAC_2                                      (1u << 4)
#define MUX_XXXX_DAC_3                                      (1u << 5)
#define MUX_XXXX_AUXI_2_INV                                 (1u << 6)
#define MUX_XXXX_OUT_MIC                                    (1u << 7)

#define TX_PGA_MUX_AUXI_2                                   (1u << 0)
#define TX_PGA_MUX_AUXI_1                                   (1u << 1)
#define TX_PGA_MUX_MIC_DIFF(x)                              ((0x3u & x) << 2)
#define TX_PGA_MUX_AUXI_2_INV                               (1u << 4)
#define TX_PGA_MUX_AUXI_3                                   (1u << 5)
#define TX_PGA_MUX_DAC_1                                    (1u << 6)
#define TX_PGA_MUX_DAC_2                                    (1u << 7)

#define AUDIO_LINE_AMP_GPO_0                                (0u << 6)
#define AUDIO_LINE_AMP_GPO_1                                (1u << 6)
#define AUDIO_LINE_AMP_LINE_SOFT_START                      (0u << 5)
#define AUDIO_LINE_AMP_LINE_FAST_START                      (1u << 5)
#define AUDIO_LINE_AMP_LINE_AMP_ENABLE                      (1u << 4)
#define AUDIO_LINE_AMP_GAIN(x)                              ((0xfu & (x)) << 0)

#define STEREO_AMPLITUDE_CH1_STEREO_EN                      (1u << 7)
#define STEREO_AMPLITUDE_CH1_STEREO_TRAC                    (1u << 6)
#define STEREO_AMPLITUDE_CH1_AMP_CH1(x)                     ((0x3fu & (x)) << 0)

#define STEREO_AMPLITUDE_CH2_STEREO_TRAC                    (1u << 6)
#define STEREO_AMPLITUDE_CH2_AMP_CH2(x)                     ((0x3fu & (x)) << 0)

#define MONO_VOL_MONO_SOFT_START                            (0u << 7)
#define MONO_VOL_MONO_FAST_START                            (1u << 7)
#define MONO_VOL_MONO_EN                                    (1u << 6)
#define MONO_VOL_MONO_GAIN(x)                               ((0x3fu & (x)) << 0)

#define BEAR_VOL_BEAR_SOFT_START                            (0u << 7)
#define BEAR_VOL_BEAR_FAST_START                            (1u << 7)
#define BEAR_VOL_BEAR_EN                                    (1u << 6)
#define BEAR_VOL_BEAR_GAIN(x)                               ((0x3fu & (x)) << 0)

#define TX_TX_PGA(x)                                        ((0xfu & (x)) << 1)
#define TX_TX_PGA_DSP                                       (1u << 0)

#define MICAMP_MICBIAS_EXT_ENABLE                           (1u << 6)
#define MICAMP_MICBIAS_INT_ENABLE                           (1u << 5)
#define MICAMP_SELMIC2                                      (1u << 4)
#define MICAMP_MICAMP_ENABLE                                (1u << 3)
#define MICAMP_MICAMP(x)                                    ((0x7u & (x)) << 0)

#define AUXI2_ENABLE                                        (1u << 7)
#define AUXI2_GAIN(x)                                       ((0x3u & (x)) << 4)
#define AUXI1_ENABLE                                        (1u << 3)
#define AUXI1_GAIN(x)                                       ((0x3u & (x)) << 0)

#define AUXI3_ENABLE                                        (1u << 3)
#define AUXI3_GAIN(x)                                       ((0x3u & (x)) << 0)

#define STEREO_DAC_CONTROL_DAC_OFF                          (0x0u << 7)
#define STEREO_DAC_CONTROL_DAC_ON                           (0x1u << 7)
#define STEREO_DAC_CONTROL_HPF_BYPASS_2_OFF                 (0x0u << 6)
#define STEREO_DAC_CONTROL_HPF_BYPASS_2_ON                  (0x1u << 6)
#define STEREO_DAC_CONTROL_HPF_BYPASS_1_OFF                 (0x0u << 5)
#define STEREO_DAC_CONTROL_HPF_BYPASS_1_ON                  (0x1u << 5)
#define STEREO_DAC_CONTROL_DAC_MUTE_2_OFF                   (0x0u << 4)
#define STEREO_DAC_CONTROL_DAC_MUTE_2_ON                    (0x1u << 4)
#define STEREO_DAC_CONTROL_DAC_MUTE_1_OFF                   (0x0u << 3)
#define STEREO_DAC_CONTROL_DAC_MUTE_1_ON                    (0x1u << 3)
#define STEREO_DAC_CONTROL_DAC_NON_INV_2                    (0x0u << 2)
#define STEREO_DAC_CONTROL_DAC_INV_2                        (0x1u << 2)
#define STEREO_DAC_CONTROL_DAC_NON_INV_1                    (0x0u << 1)
#define STEREO_DAC_CONTROL_DAC_INV_1                        (0x1u << 1)

#define I2S_CONTROL_SYNC_INPUT                              (0x0u << 7)
#define I2S_CONTROL_SYNC_OUTPUT                             (0x1u << 7)
#define I2S_CONTROL_SRM_OFF                                 (0x0u << 6)
#define I2S_CONTROL_SRM_EN                                  (0x1u << 6)
#define I2S_CONTROL_I2S_SLAVE                               (0x0u << 5)
#define I2S_CONTROL_I2S_MASTER                              (0x1u << 5)
#define I2S_CONTROL_I2S_NORMAL_MODE                         (0x0u << 4)
#define I2S_CONTROL_I2S_MSB_MODE                            (0x1u << 4)
#define I2S_CONTROL_DAC_SR(x)                               ((0xfu & (x)) << 0)

#define VOICE_CODEC_ADC_CONTROL_ADC_MUTE_OFF                (0x0u << 7)
#define VOICE_CODEC_ADC_CONTROL_ADC_MUTE_ON                 (0x1u << 7)
#define VOICE_CODEC_ADC_CONTROL_ADC_OUT_GAIN(x)             ((0x3u & (x)) << 5)
#define VOICE_CODEC_ADC_CONTROL_CODEC_SR(x)                 ((0x3u & (x)) << 3)
#define VOICE_CODEC_ADC_CONTROL_TX_HPF_SEL(x)               ((0x3u & (x)) << 1)
#define VOICE_CODEC_ADC_CONTROL_ADC_OFF                     (0x0u << 0)
#define VOICE_CODEC_ADC_CONTROL_ADC_ON                      (0x1u << 0)

#define VOICD_CODEC_VDAC_CONTROL_PCM_LOOP_OFF               (0x0u << 7)
#define VOICD_CODEC_VDAC_CONTROL_PCM_LOOP_ON                (0x1u << 7)
#define VOICD_CODEC_VDAC_CONTROL_PCM_SDO_DISABLE            (0x0u << 6)
#define VOICD_CODEC_VDAC_CONTROL_PCM_SDO_ENABLE             (0x1u << 6)
#define VOICD_CODEC_VDAC_CONTROL_VDAC_HPF_SEL(x)            ((0x3u & (x)) << 4)
#define VOICD_CODEC_VDAC_CONTROL_VDAC_OFF                   (0x0u << 3)
#define VOICD_CODEC_VDAC_CONTROL_VDAC_ON                    (0x1u << 3)
#define VOICD_CODEC_VDAC_CONTROL_VDAC_HPF_BYPASS_OFF        (0x0u << 2)
#define VOICD_CODEC_VDAC_CONTROL_VDAC_HPF_BYPASS_ON         (0x1u << 2)
#define VOICD_CODEC_VDAC_CONTROL_VDAC_INV_OFF               (0x0u << 1)
#define VOICD_CODEC_VDAC_CONTROL_VDAC_INV_ON                (0x1u << 1)
#define VOICD_CODEC_VDAC_CONTROL_VDAC_MUTE_OFF              (0x0u << 0)
#define VOICD_CODEC_VDAC_CONTROL_VDAC_MUTE_ON               (0x1u << 0)

#define SIDETONE_ST_DISABLE                                 (0x0u << 7)
#define SIDETONE_ST_ENABLE                                  (0x1u << 7)
#define SIDETONE_GAIN_COMPENSATION_ENABLE                   (0x0u << 6)
#define SIDETONE_GAIN_COMPENSATION_DISABLE                  (0x1u << 6)
#define SIDETONE_GAIN_SELECTION_MONO                        (0x0u << 5)
#define SIDETONE_GAIN_SELECTION_STEREO                      (0x1u << 5)
#define SIDETONE_ST_GAIN(x)                                 ((0x1fu & (x)) << 0)

#define PGA_DAC3_GAIN(x)                                    ((0x3u & (x)) << 4)
#define PGA_DAC2_GAIN(x)                                    ((0x3u & (x)) << 2)
#define PGA_DAC1_GAIN(x)                                    ((0x3u & (x)) << 0)

#define SOFT_START_RAMP_STEREO(x)                           ((0x3u & (x)) << 6)
#define SOFT_START_RAMP_LINE(x)                             ((0x3u & (x)) << 4)
#define SOFT_START_RAMP_MONO(x)                             ((0x3u & (x)) << 2)
#define SOFT_START_RAMP_BEAR(x)                             ((0x3u & (x)) << 0)
/*
    Votage
*/

#define DA9034_BUCK1_1V375                                  ADTV1_APPS_TRIM1(0x1A)    // 1.375V
#define DA9034_BUCK1_1V4                                    ADTV1_APPS_TRIM1(0x1B)    // 1.4V
#define DA9034_BUCK1_1V1                                    ADTV1_APPS_TRIM1(0x0f)    // 1.1V
#define DA9034_BUCK2_1V8                                    LDO11_10_BUCK2_SEL_1V8    // 1.8V
#define DA9034_LDO1_1V8                                     MDTV1_MVT_TRIM1(0x4)      // 1.8V
#define DA9034_LDO2_1V4                                     SDTV1_SRAM_TRIM1(0x1B)    // 1.4V
#define DA9034_LDO2_1V1                                     SDTV1_SRAM_TRIM1(0x0F)    // 1.4V
#define DA9034_LDO3_2V8                                     LDO6_4_3_LDO3_TRIM(0xA)   // 2.8V
#define DA9034_LDO4_1V8                                     LDO6_4_3_LDO4_SEL_1V8     // 1.8V
#define DA9034_LDO5_3V1                                                               // 3.1V Fixed
#define DA9034_LDO6_2V65                                    LDO6_4_3_LDO6_TRIM(0x3)   // 2.65V
#define DA9034_LDO7_2V8                                     LDO9_8_7_LDO7_TRIM(0x2)   // 2.8V
#define DA9034_LDO8_2V8                                     LDO9_8_7_LDO8_TRIM(0x2)   // 2.8V
#define DA9034_LDO9_2V85                                    LDO9_8_7_LDO9_TRIM(0x3)   // 2.85V
#define DA9034_LDO10_2V85                                   LDO11_10_LDO10_TRIM(0x3)  // 2.85V
#define DA9034_LDO11_3V                                     LDO11_10_LDO11_TRIM(0xC)  // 3V
#define DA9034_LDO11_1V8                                    LDO11_10_LDO11_TRIM(0x0)  // 1.8V
#define DA9034_LDO12_2V9                                    LDO_13_12_LDO12_TRIM(0xC) // 2.9V
#define DA9034_LDO12_2V85                                   LDO_13_12_LDO12_TRIM(0xB) // 2.85V
#define DA9034_LDO13_1V8                                    LDO_13_12_LDO13_TRIM(0x0) // 1.8V
#define DA9034_LDO13_2V9                                    LDO_13_12_LDO13_TRIM(0xB) // 1.8V
#define DA9034_LDO14_2V9                                    LDO_15_14_LDO14_TRIM(0xB) // 2.9V
#define DA9034_LDO15_2V9                                    LDO_15_14_LDO15_TRIM(0xB) // 2.9V


