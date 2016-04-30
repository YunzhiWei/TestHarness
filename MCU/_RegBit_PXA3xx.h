//
// Slave Power Management Unit
//
#define ASCR_RDH                        (1u << 31)
#define ASCR_D1S                        (1u << 2)           /* application subsystem d1 state status */
#define ASCR_D2S                        (1u << 1)           /* application subsystem d2 state status */
#define ASCR_D3S                        (1u << 0)           /* application subsystem d3 state status */

#define ARSR_GPR                        (1u << 3)           /* GPIO reset */
#define ARSR_LPMR                       (1u << 2)           /* S3 low-power mode exit reset */
#define ARSR_WDT                        (1u << 1)           /* watchdog time-out reset */
#define ARSR_HWR                        (1u << 0)           /* hardware/power-on reset */

#define PSR_BFS                         (1u << 2)           /* Enter DeepSleep by Battery Fault */
#define PSR_SS3S                        (1u << 1)           /* Enter DeepSleep by Software */
#define PSR_SS2S                        (1u << 0)           /* Enter     Sleep by Software */

/* Low power mode wake-up source, 1: enable, 0: disable */
#define ADnESR_WK_RTC                   (1u << 31)
#define ADnESR_WK_OST                   (1u << 30)
#define ADnESR_WK_KP                    (1u << 21)
#define ADnESR_WK_GPIN(n)               (((1u << n) & 0x3FFF) << 2 )   /* Generic wake up */
#define ADnESR_WK_EXT(n)                (((n & 1u) + 1) << 0 ) /* EXT_WAKE<1:0> */

/* In low power mode, power supply for  internal SRAM bank array,  1: Power On, 0: Power Off */
#define ADnR_ADn_R3                     (1u << 3)
//Reserved at new Developer Manual: #define ADnR_ADn_R1                     (1u << 1)
#define ADnR_ADn_R0                     (1u << 0)

#define AD3SR_WEKP                      (1u << 21)          /* wake-up status for a keypad from d3 to d0 state */

//
// INTC Bit definitions for interrupt signals 0..31
//
#define INTC_RTCALARM                   (0x1u << 31)
#define INTC_RTC_TIC                    (0x1u << 30)
#define INTC_OSMR3                      (0x1u << 29)
#define INTC_OSMR2                      (0x1u << 28)
#define INTC_OSMR1                      (0x1u << 27)
#define INTC_OSMR0                      (0x1u << 26)
#define INTC_DMAC                       (0x1u << 25)
#define INTC_SSP                        (0x1u << 24)
#define INTC_MMC                        (0x1u << 23)
#define INTC_FFUART                     (0x1u << 22)
#define INTC_BTUART                     (0x1u << 21)
#define INTC_STUART                     (0x1u << 20)
#define INTC_ICP                        (0x1u << 19)
#define INTC_I2C                        (0x1u << 18)
#define INTC_LCD                        (0x1u << 17)
#define INTC_SSP2                       (0x1u << 16)
#define INTC_USIM                       (0x1u << 15)
#define INTC_AC97                       (0x1u << 14)
#define INTC_I2S                        (0x1u << 13)
#define INTC_PMU                        (0x1u << 12)
#define INTC_USBCLIENT                  (0x1u << 11)
#define INTC_GPIOXX_2                   (0x1u << 10)
#define INTC_GPIO1                      (0x1u << 9)
#define INTC_GPIO0                      (0x1u << 8)
#define INTC_OSMRXX_4                   (0x1u << 7)
#define INTC_PWRI2C                     (0x1u << 6)
#define INTC_MEMSTICK                   (0x1u << 5)
#define INTC_KEYPAD                     (0x1u << 4)
#define INTC_USBOHCI                    (0x1u << 3)
#define INTC_USBNONOHCI                 (0x1u << 2)
#define INTC_BASEBAND                   (0x1u << 1)
#define INTC_SSP3                       (0x1u << 0)

//
// INTC Bit definitions for interrupt signals 32..33
//

#define INTC_CAPTURE                    (0x1u << 1)         /* Camera Capture interface */
#define INTC_CTM                        (0x1u << 0)         /* Trusted Platform Module (Caddo) */
#define INTC_USBHSCLIENT                (0x1u << 14)        /* USB 2.0 Client */

// UART
#define IER_DMAE                        (1 << 7)            /* DMA Requests Enable */
#define IER_UUE                         (1 << 6)            /* UART Unit Enable */
#define IER_NRZE                        (1 << 5)            /* NRZ coding Enable */
#define IER_RTIOE                       (1 << 4)            /* Receiver Time Out Interrupt Enable */
#define IER_MIE                         (1 << 3)            /* Modem Interrupt Enable */
#define IER_RLSE                        (1 << 2)            /* Receiver Line Status Interrupt Enable */
#define IER_TIE                         (1 << 1)            /* Transmit Data request Interrupt Enable */
#define IER_RAVIE                       (1 << 0)            /* Receiver Data Available Interrupt Enable */

#define IIR_FIFOES                      (3 << 6)            /* FIFO Mode Enable Status */
#define IIR_EOC                         (1 << 3)            /* DMA End of discrptor chain */
#define IIR_ABL                         (1 << 3)            /* Auto baud lock */
#define IIR_TOD                         (1 << 3)            /* Time Out Detected */
#define IIR_IID                         (1 << 1)            /* Interrupt Source Encoded (mask) */
#define IIR_IP                          (1 << 0)            /* Interrupt Pending (active low) */

#define FCR_ITL                         (1 << 6)            /* Interrupt Trigger Level */
#define FCR_BUS                         (1 << 5)            /* 32-bit Peripheral BUS */
#define FCR_TRAIL                       (1 << 4)            /* Trailing Bytes */
#define FCR_TIL                         (1 << 4)            /* Transmit Interrupt Level */
#define FCR_RESETTF                     (1 << 2)            /* Reset Transmitter FIFO */
#define FCR_RESETRF                     (1 << 1)            /* Reset Receiver FIFO */
#define FCR_TRFIFOE                     (1 << 0)            /* Transmit and Receive FIFO Enable */

#define FOR_BCNT                        (0x3f)              /* byte count in receive FIFO (mask) */

#define LCR_DLAB                        (1 << 7)            /* Divisor Latch Access Bit */
#define LCR_SB                          (1 << 6)            /* Set Break */
#define LCR_STKYP                       (1 << 5)            /* Sticky Parity */
#define LCR_EPS(n)                      ((n & 1) << 4)      /* Even Parity Select */
#define LCR_PEN                         (1 << 3)            /* Parity Enable */
#define LCR_STB                         (1 << 2)            /* Stop Bit */
#define LCR_WLS                         (1 << 0)            /* Word Length Select */
#define LCR_EPS_ODD                     0
#define LCR_EPS_EVEN                    1

#define LSR_FIFOE                       (1 << 7)            /* FIFO Error Status */
#define LSR_TEMT                        (1 << 6)            /* Transmitter Empty */
#define LSR_TDRQ                        (1 << 5)            /* Transmit Data Request */
#define LSR_BI                          (1 << 4)            /* Break Interrupt */
#define LSR_FE                          (1 << 3)            /* Framing Error */
#define LSR_PE                          (1 << 2)            /* Parity Error */
#define LSR_OE                          (1 << 1)            /* Overrun Error */
#define LSR_DR                          (1 << 0)            /* Data Ready */

#define MCR_AFE                         (1 << 5)            /* Auto Flow Control Enable */
#define MCR_LOOP                        (1 << 4)            /**/
#define MCR_OUT2                        (1 << 3)            /* force MSR_DCD in loopback mode */
#define MCR_OUT1                        (1 << 2)            /* force MSR_RI in loopback mode */
#define MCR_RTS                         (1 << 1)            /* Request to Send */
#define MCR_DTR                         (1 << 0)            /* Data Terminal Ready */

#define MSR_DCD                         (1 << 7)            /* Data Carrier Detect */
#define MSR_RI                          (1 << 6)            /* Ring Indicator */
#define MSR_DSR                         (1 << 5)            /* Data Set Ready */
#define MSR_CTS                         (1 << 4)             /* Clear To Send */
#define MSR_DDCD                        (1 << 3)            /* Delta Data Carrier Detect */
#define MSR_TERI                        (1 << 2)            /* Trailing Edge Ring Indicator */
#define MSR_DDSR                        (1 << 1)            /* Delta Data Set Ready */
#define MSR_DCTS                        (1 << 0)            /* Delta Clear To Send */

#define ISR_RXPL                        (1 << 4)            /* Receive Data Polarity */
#define ISR_TXPL                        (1 << 3)            /* Transmit Data Polarity */
#define ISR_XMODE                       (1 << 2)            /* Transmit Pulse Width Select */
#define ISR_RCVEIR                      (1 << 1)            /* Receiver SIR Enable */
#define ISR_XMITIR                      (1 << 0)            /* Transmitter SIR Enable */

#define ABR_ABT                         (1 << 3)            /* Baud Rate Calculation(formular/table) */
#define ABR_ABUP                        (1 << 2)            /* Divisor Latch(Processor/UART) */
#define ABR_ABLIE                       (1 << 1)            /* Auto-baud-lock interrupt enable */
#define ABR_ABE                         (1 << 0)            /* Auto baud enable */

#define ACR_CNT                         (0xff)              /* auto baud count value of (mask) */

//
// Clock Enable Register (CLKEN) Bits
//
#define CKENA_LCD                       (0x1u << 1)         /* LCD Clock Enable */
#define CKENA_USB                       (0x1u << 2)         /* USB Host Clock Enable */
#define CKENA_CAM                       (0x1u << 3)         /* Camera Interface Clock Enable */
#define CKENA_NAND                      (0x1u << 4)         /* NAND Flash Controller Clock Enable */
#define CKENA_MMC3                      (0x1u << 5)         /* MMC3 Clock Enable */
#define CKENA_U2D                       (0x1u << 6)         /* U2D Clock Enable */
#define CKENA_DMC                       (0x1u << 8)         /* Dynamic Memory Controller Clock Enable */
#define CKENA_SMC                       (0x1u << 9)         /* Static Memory Controller Clock Enable */
#define CKENA_SRAM                      (0x1u << 10)        /* Internal SRAM Clock Enable */
#define CKENA_BTROM                     (0x1u << 11)        /* Boot ROM Clock Enable */
#define CKENA_MMC0                      (0x1u << 12)        /* MMC0 Clock Enable */
#define CKENA_MMC1                      (0x1u << 13)        /* MMC1 Clock Enable */
#define CKENA_KEYP                      (0x1u << 14)        /* KeyPad Controller Clock Enable */
#define CKENA_IR                        (0x1u << 15)        /* Consumer IR Clock Enable */
#define CKENA_USIM0                     (0x1u << 17)        /* USIM[0] Clock Enable */
#define CKENA_USIM1                     (0x1u << 18)        /* USIM[1] Clock Enable */
#define CKENA_UDC                       (0x1u << 20)        /* UDC Clock Enable */
#define CKENA_UART2                     (0x1u << 21)        /* UART2 Clock Enable */
#define CKENA_UART1                     (0x1u << 22)        /* UART1 Clock Enable */
#define CKENA_UART3                     (0x1u << 23)        /* UART3 Clock Enable */
#define CKENA_AC97                      (0x1u << 24)        /* AC97 Clock Enable */
#define CKENA_SSP1                      (0x1u << 26)        /* SSP1 Clock Enable */
#define CKENA_SSP2                      (0x1u << 27)        /* SSP2 Clock Enable */
#define CKENA_SSP3                      (0x1u << 28)        /* SSP3 Clock Enable */
#define CKENA_SSP4                      (0x1u << 29)        /* SSP4 Clock Enable */
#define CKENA_MSL0                      (0x1u << 30)        /* MSL0 Clock Enable */

#define CKENA_SET_ALWAYS                ((0x1u << 31) | (0x1u << 19)) /* Not only based on Developer Manual, but based on Real Testing */

#define CKENB_PWM01                     (0x1u << 0)         /* PWM[0:1] Clock Enable */
#define CKENB_PWM23                     (0x1u << 1)         /* PWM[2:3] Clock Enable */
#define CKENB_I2C                       (0x1u << 4)         /* Standard I2C Clock Enable */
#define CKENB_GPIO                      (0x1u << 7)         /* GPIO Clock Enable */
#define CKENB_1WIRE                     (0x1u << 8)         /* 1-Wire Clock Enable */
#define CKENB_HSIO2                     (0x1u << 9)         /* HSIO2 Clock Enable, must be set before enter low power mode */
#define CKENB_GCU                       (0x1u << 10)        /* HSIO GCU Clock Enable */
#define CKENB_VAU                       (0x1u << 11)        /* Video Accelerator Unit Clock Enable */
#define CKENB_MINIM                     (0x1u << 16)        /* Mini-IM Clock Enable */
#define CKENB_MINLCD                    (0x1u << 17)        /* Mini-LCD Clock Enable */

#define CKENB_SET_ALWAYS                ((0x3FFFu << 18) | (0x0Fu << 12) | (0x01u << 6)  | (0x03u << 2)) /* Not only based on Developer Manual, but based on Real Testing */

//
// Oscillator Configuration Register (OSCC) Bits
//
#define OSCC_VCXOST(n)                  ((n&0xFF) << 0)     /* Wait Time for processor oscillator stabilization */
#define OSCC_TENS0                      (1 << 8)            /* CLK_TOUT S0 Enable */
#define OSCC_TENS2                      (1 << 9)            /* CLK_TOUT S2 Enable */
#define OSCC_TENS3                      (1 << 10)           /* CLK_TOUT S3 Enable */
#define OSCC_PEN                        (1 << 11)           /* CLK_POUT Enable */
#define OSCC_TD                         (1 << 16)           /* Frequency Change due to Temperature Condition Disable */
#define OSCC_TSEL(n)                    ((n&3) << 20)       /* Temperatur Sensor Throttle Trigger Select */

#define OSCC_TSEL_100C                  0                   /* 100 C */
#define OSCC_TSEL_90C                   1                   /* 90 C */
#define OSCC_TSEL_95C                   2                   /* 95 C */
#define OSCC_TSEL_105C                  3                   /* 105 C */

//
// Power Management Unit Voltage Change Control Register (PVCR)
//
#define PVCR_READPOINTER                (0x1<<20)
#define PVCR_VCSA                       (0x1<<14)
#define PVCR_CMDDELAY                   (0x1<<7)
#define PVCR_SLAVEADDR                  (0x1<<0)

//
// Power Manager Unit General Configuration Register (PCFR)
//
#define PCFR_FVC                        (0x1 << 10)
#define PCFR_PI2C_EN                    (0x1 << 6)
#define PCFR_SYSEN_EN                   (0x1 << 5)
#define PCFR_GPR_EN                     (0x1 << 4)

//
// Power Management Unit Control Register (PMCR)
//
#define PMCR_SWGR                       (0x1u << 31)


// Power Manager I2C Command Register File (PCMD)
#define PCMD_MBC                        (0x1 << 12)
#define PCMD_DCE                        (0x1 << 11)
#define PCMD_LC                         (0x1 << 10)
#define PCMD_SQC                        (0x3 << 8)

// PSSR
#define PSSR_SSS                        (1<<0)
#define PSSR_PH                         (1<<4)

// RCSR
#define RCSR_GPR                        (1<<3)
#define RCSR_SMR                        (1<<2)
#define RCSR_WDR                        (1<<1)
#define RCSR_HWR                        (1<<0)

#define PKWR_WE93                       (1<<10)
#define PWER_WE1                        (1<<1)

//
// PWM
//
// DCR
#define DCR_FD                          (1<<10)

//
// LCD
//

// LCD Controller Control Register 0 (LCCR0)
#define LCCR0_ENB                       (1<<0)
#define LCCR0_CMS                       (1<<1)
#define LCCR0_SDS                       (1<<2)
#define LCCR0_LDM                       (1<<3)
#define LCCR0_SFM                       (1<<4)
#define LCCR0_IUM                       (1<<5)
#define LCCR0_EFM                       (1<<6)
#define LCCR0_PAS                       (1<<7)
#define LCCR0_BLE                       (1<<8)
#define LCCR0_DPD                       (1<<9)
#define LCCR0_DIS                       (1<<10)
#define LCCR0_QDM                       (1<<11)
#define LCCR0_PDD(n)                    ((n) << 12)
#define LCCR0_BM                        (1<<20)
#define LCCR0_OUM                       (1<<21)
#define LCCR0_LCDT                      (1<<22)
#define LCCR0_RDSTM                     (1<<23)
#define LCCR0_CMDIM                     (1<<24)
#define LCCR0_OUC                       (1<<25)
#define LCCR0_LDDALT                    (1<<26)

//
// LCD Controller Control Register 1 (LCCR1)
//
#define LCCR1_PPL(n)                    ((n)-1)
#define LCCR1_HSW(n)                    ((n) << 10)
#define LCCR1_ELW(n)                    ((n) << 16)
#define LCCR1_BLW(n)                    ((n) << 24)

//
// LCD Controller Control Register 2 (LCCR2)
//
#define LCCR2_LPP(n)                    ((n)-1)
#define LCCR2_VSW(n)                    ((n) << 10)
#define LCCR2_EFW(n)                    ((n) << 16)
#define LCCR2_BFW(n)                    ((n) << 24)

//
// LCD Controller Control Register 3 (LCCR3)
//
#define LCCR3_PCD(n)                    ((n))
#define LCCR3_ACB(n)                    ((n) << 8)
#define LCCR3_API(n)                    ((n) << 16)
#define LCCR3_VSP(n)                    ((n&0x01)<<20)
#define LCCR3_HSP(n)                    ((n&0x01)<<21)
#define LCCR3_PCP(n)                    ((n&0x01)<<22)
#define LCCR3_OEP                       (1<<23)
#define LCCR3_DPC                       (1<<27)
#define LCCR3_BPP(n)                    ((((n) & 0x7) << 24) | (((n) & 0x8) << 29))
#define LCCR3_PDFOR(n)                  ((n) << 30)

#define VSP_VSYNC_ACTIVE_HIGH           0
#define VSP_VSYNC_ACTIVE_LOW            1
#define HSP_HSYNC_ACTIVE_HIGH           0
#define HSP_HSYNC_ACTIVE_LOW            1
#define PCP_PIXEL_CLK_DATA_ON_RISING    0
#define PCP_PIXEL_CLK_DATA_ON_FALLING   1

#define BPP_8BIT_PER_PIXEL              3
#define BPP_16BIT_PER_PIXEL             4

#define PDFOR_FORMAT1                   0
#define PDFOR_FORMAT2                   1
#define PDFOR_FORMAT3                   2
#define PDFOR_FORMAT4                   3

//
// LCD Controller Control Register 4 (LCCR4)
//
#define LCCR4_K1(n)                     ((n))
#define LCCR4_K2(n)                     ((n) << 3)
#define LCCR4_K3(n)                     ((n) << 6)
#define LCCR4_REOFM0                    (1 << 9)
#define LCCR4_REOFM1                    (1 << 10)
#define LCCR4_REOFM2                    (1 << 11)
#define LCCR4_REOFM3                    (1 << 12)
#define LCCR4_REOFM4                    (1 << 13)
#define LCCR4_REOFM5                    (1 << 14)
#define LCCR4_PAL_FOR(n)                ((n) << 15)
#define LCCR4_SENSE_PCD_CHG_EN          (1 << 25)
#define LCCR4_SENSE_MD_PCD(x)           ((x) << 17)
#define LCCR4_REOFM6                    (1 << 26)
#define LCCR4_PCD_DIV(n)                ((n&0x01) << 31)

#define PCD_DIV_FORMULA0                0                   /* Pixel Clock=LCLK/2*(PCD+1) */
#define PCD_DIV_FORMULA1                1                   /* Pixel Clock=LCLK/(PCD+1) */

#define PAL_PDFOR_16BIT_NO_TRANSPARENCY 0
#define PAL_PDFOR_25BIT_16BIT           1
#define PAL_PDFOR_25BIT_18BIT           2
#define PAL_PDFOR_25BIT_24BIT           3

//
// LCD Controller Control Register 5 (LCCR5)
//
#define LCCR5_SOFM1                     0x00000001
#define LCCR5_SOFM2                     0x00000002
#define LCCR5_SOFM3                     0x00000004
#define LCCR5_SOFM4                     0x00000008
#define LCCR5_SOFM5                     0x00000010
#define LCCR5_SOFM6                     0x00000020
#define LCCR5_EOFM1                     0x00000100
#define LCCR5_EOFM2                     0x00000200
#define LCCR5_EOFM3                     0x00000400
#define LCCR5_EOFM4                     0x00000800
#define LCCR5_EOFM5                     0x00001000
#define LCCR5_EOFM6                     0x00002000
#define LCCR5_BSM1                      0x00010000
#define LCCR5_BSM2                      0x00020000
#define LCCR5_BSM3                      0x00040000
#define LCCR5_BSM4                      0x00080000
#define LCCR5_BSM5                      0x00100000
#define LCCR5_BSM6                      0x00200000
#define LCCR5_IUM1                      0x01000000
#define LCCR5_IUM2                      0x02000000
#define LCCR5_IUM3                      0x04000000
#define LCCR5_IUM4                      0x08000000
#define LCCR5_IUM5                      0x10000000
#define LCCR5_IUM6                      0x20000000

//
// LCD Controller Control Register 6 (LCCR6)
//
#define LCCR6_B_BLUE(n)                 ((n&0xFF) << 0)
#define LCCR6_B_GREEN(n)                ((n&0xFF) << 8)
#define LCCR6_B_RED(n)                  ((n&0xFF) << 16)
#define LCCR6_BF_OFF                    (1u << 31)

//
// LCD Controller Overlay Control Register OVL1C1
//
#define OVL1C1_PPL1(n)                  ((n))
#define OVL1C1_LPO1(n)                  ((n) << 10)
#define OVL1C1_BPP1(n)                  ((n) << 20)
#define OVL1C1_O1EN                     0x80000000

#define BPP1_24BIT_NO_TBIT              0
#define BPP1_16BIT                      4
#define BPP1_24BIT                      9
#define BPP1_25BIT                      10

//
// LCD Controller Overlay Control Register OVL1C2
//
#define OVL1C2_O1XPOS(n)                ((n))
#define OVL1C2_01YPOS(n)                ((n) << 10)

//
// LCD Controller Overlay Control Register OVL2C1
//
#define OVL2C1_PPL2(n)                  ((n))
#define OVL2C1_LPO2(n)                  ((n) << 10)
#define OVL2C1_BPP2(n)                  ((n) << 20)
#define OVL2C1_O2EN                     0x80000000

#define BPP2_16BIT                      4
#define BPP2_24BIT                      9
#define BPP2_25BIT                      10

//
// LCD Controller Overlay Control Register OVL2C2
//
#define OVL2C1_O2XPOS(n)                ((n))
#define OVL2C1_O2YPOS(n)                ((n) << 10)
#define OVL2C1_FOR(n)                   ((n) << 20)

#define OL2_FOR_RGB                     0
#define OL2_FOR_YUV444PK                1
#define OL2_FOR_YUV444PL                2
#define OL2_FOR_YUV422PL                3
#define OL2_FOR_YUV420PL                4

//
// LCD Controller Cursor Control Register (CCR)
//
#define CCR_CURMS(n)                    ((n))
#define CCR_CXPOS(n)                    ((n) << 5)
#define CCR_CYPOS(n)                    ((n) << 15)
#define CCR_CEN                         0x80000000

//
// LCD Controller Command Control Register (CMDCR)
//
#define CMDCR_SYNC_CNT(n)               ((n))

//
// LCD Controller Panel Read Status Register (PRSR)
//
#define PRSR_DATA(n)                    ((n) & 0xff)
#define PRSR_A0                         0x00000100
#define PRSR_ST_OK                      0x00000200
#define PRSR_CON_ST                     0x00000400

//
// LCD Controller Status Register (LCSR0)
//
#define LCSR0_LDD                       0x00000001
#define LCSR0_SOF0                      0x00000002
#define LCSR0_BER                       0x00000004
#define LCSR0_ABC                       0x00000008
#define LCSR0_IU0                       0x00000010
#define LCSR0_IU1                       0x00000020
#define LCSR0_OU                        0x00000040
#define LCSR0_QD                        0x00000080
#define LCSR0_EOF0                      0x00000100
#define LCSR0_BS0                       0x00000200
#define LCSR0_SINT                      0x00000400
#define LCSR0_RD_ST                     0x00000800
#define LCSR0_CMD_INTR                  0x00001000
#define LCSR0_BER_CH(n)                 (((n) & 0x7FFFFFFF) >> 28)

//
// LCD Controller Status Register (LCSR1)
//
#define LCSR1_SOF1                      0x00000001
#define LCSR1_SOF2                      0x00000002
#define LCSR1_SOF3                      0x00000004
#define LCSR1_SOF4                      0x00000008
#define LCSR1_SOF5                      0x00000010
#define LCSR1_SOF6                      0x00000020
#define LCSR1_EOF1                      0x00000100
#define LCSR1_EOF2                      0x00000200
#define LCSR1_EOF3                      0x00000400
#define LCSR1_EOF4                      0x00000800
#define LCSR1_EOF5                      0x00001000
#define LCSR1_EOF6                      0x00002000
#define LCSR1_BS1                       0x00010000
#define LCSR1_BS2                       0x00020000
#define LCSR1_BS3                       0x00040000
#define LCSR1_BS4                       0x00080000
#define LCSR1_BS5                       0x00100000
#define LCSR1_BS6                       0x00200000
#define LCSR1_IU2                       0x02000000
#define LCSR1_IU3                       0x04000000
#define LCSR1_IU4                       0x08000000
#define LCSR1_IU5                       0x10000000
#define LCSR1_IU6                       0x20000000

//
// LCD Controller Interrupt ID Register (LIIDR)
//
#define LIIDR_IFrameID(n)               ((n))

//
// LCD Controller TMED RGB Seed Register (TRGBR)
//
#define TRGBR_TRS(n)                    ((n))
#define TRGBR_TGS(n)                    ((n) << 8)
#define TRGBR_TBS(n)                    ((n) << 16)

//
// LCD Controller TMED Control Register (TCR)
//
#define TCR_TM2S                        0x00000001
#define TCR_TM1S                        0x00000002
#define TCR_TM2En                       0x00000004
#define TCR_TM1En                       0x00000008
#define TCR_TVBS(n)                     ((n) << 4)
#define TCR_THBS(n)                     ((n) << 8)
#define TCR_TSCS(n)                     ((n) << 12)
#define TCR_TED                         0x00004000

//
// LCD Controller DMA Frame Descriptor Address Registers (FDADRx)
//
#define FDADRx_FDADR(n)                 ((n) & 0xFFFFFFF0)

//
// LCD Controller DMA Frame Source Address Registers (FSADRx)
//
#define FSADRx_FSADR(n)                 ((n) & 0xFFFFFFF8)

//
// LCD Controller DMA Frame ID Registers (FIDRx)
//
#define FIDRx_FIDR(n)                   ((n) & 0xFFFFFFF8)

//
// LCD Controller DMA Command Registers (LDCMDx)
//
#define LDCMDx_Len(n)                   ((n))
#define LDCMDx_EOFInt                   0x00200000
#define LDCMDx_SOFInt                   0x00400000
#define LDCMDx_Palette                  0x04000000

//
// LCD Controller DMA Frame Branch Registers (FBRx)
//
#define FBRx_BRA                        0x00000001
#define FBRx_BINT                       0x00000002
#define FBRx_SrcAddr(n)                 ((n) << 4)


// Masks for UDC Registers

// UDC Control Register (UDCCR)
#define UDCCR_UDE                       ( 0x1U << 0 )       /* UDC enabled */
#define UDCCR_UDA                       ( 0x1U << 1 )       /* READ-ONLY: udc is active */
#define UDCCR_UDR                       ( 0x1U << 2 )       /* Forces the usb out of suspend state */
#define UDCCR_EMCE                      ( 0x1U << 3 )       /* The Endpoint memory config. has an error */
#define UDCCR_SMAC                      ( 0x1U << 4 )       /* Switch Endpoint memory to Active config. */
                                                            /* Active interface and Alternate Interface */
#define UDCCR_AAISN_SHIFT               5                   /* Shift and a mask for the Alternate Interface */
#define UDCCR_AAISN_MASK                ( 0x7U << XLLP_UDC_UDCCR_AAISN_SHIFT )  /* Settings  (0-7) */
#define UDCCR_AIN_SHIFT                 8                   /* Shift and a mask for the Interface */
#define UDCCR_AIN_MASK                  ( 0x7U << XLLP_UDC_UDCCR_AIN_SHIFT )    /* Number    (0-7) */
#define UDCCR_ACN_SHIFT                 11                  /* Shift and a mask for the Configuration */
#define UDCCR_ACN_MASK                  ( 0x3U << XLLP_UDC_UDCCR_ACN_SHIFT )    // Number    (0-3) */
#define UDCCR_DRWF                      ( 0x1U << 16 )      /* Device Remote Wakeup Feature */

// UDC Interrupt Status Register (UDCICR0, UDCICR1)
#define UDCICSR_IRQ_P                   ( 1 )               // Packet Complete Interrupt Request - Endpoint Q
#define UDCICSR_IRQ_E                   ( 2 )               // FIFO Error Interrupt Request - Endpoint Q
#define UDCICSR0_IRQ_0                  (0x1U<<0)
#define UDCICSR0_IRQ_A                  (0x1U<<2)
#define UDCICSR0_IRQ_B                  (0x1U<<4)
#define UDCICSR1_IRQ_Q                  (0x1U<<0)
#define UDCICSR1_IRQ_R                  (0x1U<<2)

#define UDCICSR1_IRRS                   ( 0x1U << 27 )      // Interrupt Request - Reset
#define UDCICSR1_IRSU                   ( 0x1U << 28 )      // Interrupt Request - Suspend
#define UDCICSR1_IRRU                   ( 0x1U << 29 )      // Interrupt Request - Resume
#define UDCICSR1_IRSOF                  ( 0x1U << 30 )      // Interrupt Request - SOF
#define UDCICSR1_IRCC                   ( 0x1U << 31 )      // Interrupt Request - Configuration Change

#define UDCISR1_EVENTS                  ( 0x1FU << 27 )     // Mask to clear all event interrupts

// UDC UP2OCR
#define UP2OCR_SEOS                     ( 0x1U << 24 )      // Single-Ended Output Select
#define UP2OCR_HXOE                     ( 0x1U << 17 )      // Host Port 2 Transceiver Ouput Enable
#define UP2OCR_HXS                      ( 0x1U << 16 )      // Host Port 2 Transceiver Output Select
#define UP2OCR_DPPUE                    ( 0x1U << 4 )       // D+ Pull Up Enable
#define UP2OCR_DMPDE                    ( 0x1U << 3 )       // D- Pull Down Enable
#define UP2OCR_DPPDE                    ( 0x1U << 2 )       // D+ Pull Down Enable

// UDC Endpoint 0 Control/Status Register (UDCCSR0)
#define UDCCSR0_OPC                     ( 0x1U << 0 )       // OUT packet to endpoint zero received
#define UDCCSR0_IPR                     ( 0x1U << 1 )       // Packet has been written to endpoint zero FIFO
#define UDCCSR0_FTF                     ( 0x1U << 2 )       // Flush the Tx FIFO
#define UDCCSR0_SST                     ( 0x1U << 4 )       // UDC sent stall handshake
#define UDCCSR0_FST                     ( 0x1U << 5 )       // Force the UDC to issue a stall handshake
#define UDCCSR0_RNE                     ( 0x1U << 6 )       // There is unread data in the Rx FIFO
#define UDCCSR0_SA                      ( 0x1U << 7 )       // Current packet in FIFO is part of UDC setup command

// UDC Endpoint Control/Status Registers A-X
#define UDCCSR_FS                       ( 0x1U << 0 )       // FIFO needs service
#define UDCCSR_PC                       ( 0x1U << 1 )       // Packet Complete
#define UDCCSR_EFE                      ( 0x1U << 2 )       // Endpoint FIFO error
#define UDCCSR_DME                      ( 0x1U << 3 )       // DMA Enable
#define UDCCSR_SST                      ( 0x1U << 4 )       // Sent STALL
#define UDCCSR_FST                      ( 0x1U << 5 )       // Force STALL
#define UDCCSR_BNE                      ( 0x1U << 6 )       // Buffer not empty/full
#define UDCCSR_SP                       ( 0x1U << 7 )       // Short Packet
#define UDCCSR_FEF                      ( 0x1U << 8 )       // Flash Endpoint FIFO
#define UDCCSR_DPE                      ( 0x1U << 9 )       // Data Packet Error

// UDC Endpoint A-X Configuration Registers
#define UDCCRZ_EE                       ( 0x1U << 0 )       // Endpoint Enable
#define UDCCRZ_DE                       ( 0x1U << 1 )       // Double-buffering Enable
#define UDCCRZ_MPS                      ( 0x1U << 2)        // Maximum Packet Size
#define UDCCRZ_ED                       ( 0x1U << 12 )      // Endpoint Direction
#define UDCCRZ_ET                       ( 0x1U << 13)       // Endoint Type
#define UDCCRZ_EN                       ( 0x1U << 15)       // Endoint Number
#define UDCCRZ_AISN                     ( 0x1U << 19)       // Interface Alternate Settings Number
#define UDCCRZ_IN                       ( 0x1U << 22)       // Interface Number
#define UDCCRZ_CN                       ( 0x1U << 25)       // Configuration Number

#define ED_IN                           1
#define ED_OUT                          0

#define ET_INT                          3
#define ET_BLK                          2
#define ET_ISO                          1

/*
U2D Registers
*/
// U2D Control Register (U2DCR)
#define U2DCR_UDE                       ( 0x1U << 0 )       // UDC enabled
#define U2DCR_UDA                       ( 0x1U << 1 )       // READ-ONLY: udc is active
#define U2DCR_UDR                       ( 0x1U << 2 )       // Forces the usb out of suspend state
#define U2DCR_EMCE                      ( 0x1U << 3 )       // The Endpoint memory config. has an error
#define U2DCR_AAISN_SHIFT               3                   // Shift and a mask for the Alternate Interface
#define U2DCR_AAISN_MASK                ( 0xFU << U2DCR_AAISN_SHIFT )  // Settings  (0-16)
#define U2DCR_AIN_SHIFT                 7                   // Shift and a mask for the Interface
#define U2DCR_AIN_MASK                  ( 0xFU << U2DCR_AIN_SHIFT )    // Number    (0-16)
#define U2DCR_ACN_SHIFT                 11                  // Shift and a mask for the Configuration
#define U2DCR_ACN_MASK                  ( 0xFU << U2DCR_ACN_SHIFT )    // Number    (0-16)
#define U2DCR_DRWF                      ( 0x1U << 16 )      // Device Remote Wakeup Feature
#define U2DCR_SMAC                      ( 0x1U << 17 )      // Switch Endpoint memory to Active config.
                                                            // Active interface and Alternate Interface
#define U2DCR_HS                        ( 0x1U << 18 )
#define U2DCR_CC                        ( 0x1U << 19 )
#define U2DCR_ADD                       ( 0x1U << 20 )      // Application Device Disconnect
#define U2DCR_ABP                       ( 0x1U << 21 )
#define U2DCR_UCLKOVR                   ( 0x1U << 22 )
#define U2DCR_FSTC                      ( 0x7U << 24 )
#define U2DCR_SPEOREN                   ( 0x1U << 27)
#define U2DCR_HSTC                      ( 0x7U << 28 )
#define U2DCR_NDC                       ( 0x1U << 31 )

//U2D Interrupt Control Register (U2DICR,U2DICR2)
#define U2DICR_IEx_SPC                  ( 1U << 0 )         // Short Package Complete
#define U2DICR_IEx_PC                   ( 1U << 1 )         // Package Complete
#define U2DICR_IEx_ERR                  ( 1U << 2 )         // FIFO Error

#define U2DICR_IE0(n)                   ( ((n) & 0x7U) << 0 )       // Interrupt Enable - Endpoint 0 bits
#define U2DICR_IEA(n)                   ( ((n) & 0x7U) << 3 )       // Interrupt Enable - Endpoint A bits
#define U2DICR_IEB(n)                   ( ((n) & 0x7U) << 6 )       // Interrupt Enable - Endpoint B bits
#define U2DICR_IEC(n)                   ( ((n) & 0x7U) << 9 )       // Interrupt Enable - Endpoint C bits
#define U2DICR_IED(n)                   ( ((n) & 0x7U) << 12 )      // Interrupt Enable - Endpoint D bits
#define U2DICR_IEE(n)                   ( ((n) & 0x7U) << 15 )      // Interrupt Enable - Endpoint E bits
#define U2DICR_IEF(n)                   ( ((n) & 0x7U) << 18 )      // Interrupt Enable - Endpoint F bits
#define U2DICR_IEG(n)                   ( ((n) & 0x7U) << 21 )      // Interrupt Enable - Endpoint G bits
#define U2DICR_IE_ALL_X(x)              ( 0x7U << (3*x) )           // Interrupt Enable ALL - Endpoint X
#define U2DICR_IE_NORMAL_X(x)           ( 0x3U << (3*x) )           // Interrupt Enable NORMAL - Endpoint X

#define U2DICR_IEDPE                    ( 0x1U << 25 )      // Interrupt Enable - Data Packet Error
#define U2DICR_IERS                     ( 0x1U << 26 )      // Interrupt Enable - Reset
#define U2DICR_IESU                     ( 0x1U << 27 )      // Interrupt Enable - Suspend
#define U2DICR_IERU                     ( 0x1U << 28 )      // Interrupt Enable - Resume
#define U2DICR_IEUSOF                   ( 0x1U << 29 )      // Interrupt Enable - Macro SOF
#define U2DICR_IESOF                    ( 0x1U << 30 )      // Interrupt Enable - SOF
#define U2DICR_IECC                     ( 0x1U << 31 )      // Interrupt Enable - Configuration Change


// U2D Interrupt Status Register (U2DISR, U2DISR2)
#define U2DISR_IEx_SPC                  ( 1U << 0 )         // Short Package Complete
#define U2DISR_IEx_PC                   ( 1U << 1 )         // Package Complete
#define U2DISR_IEx_ERR                  ( 1U << 2 )         // FIFO Error

#define U2DISR_IE0(n)                   ( ((n) & 0x7U) << 0 )       // Interrupt Enable - Endpoint 0 bits
#define U2DISR_IEA(n)                   ( ((n) & 0x7U) << 3 )       // Interrupt Enable - Endpoint A bits
#define U2DISR_IEB(n)                   ( ((n) & 0x7U) << 6 )       // Interrupt Enable - Endpoint B bits
#define U2DISR_IEC(n)                   ( ((n) & 0x7U) << 9 )       // Interrupt Enable - Endpoint C bits
#define U2DISR_IED(n)                   ( ((n) & 0x7U) << 12 )      // Interrupt Enable - Endpoint D bits
#define U2DISR_IEE(n)                   ( ((n) & 0x7U) << 15 )      // Interrupt Enable - Endpoint E bits
#define U2DISR_IEF(n)                   ( ((n) & 0x7U) << 18 )      // Interrupt Enable - Endpoint F bits
#define U2DISR_IEG(n)                   ( ((n) & 0x7U) << 21 )      // Interrupt Enable - Endpoint G bits
#define U2DISR_IE_ALL_X(x)              ( 0x7U << (3*x) )           // Interrupt Enable ALL - Endpoint X
#define U2DISR_IE_NORMAL_X(x)           ( 0x3U << (3*x) )           // Interrupt Enable NORMAL - Endpoint X
#define U2DISR_IE_ERR_X(x)              ( U2DISR_IEx_ERR << (3*x) ) // Interrupt Enable ERR - Endpoint X

#define U2DISR_IRDPE                    (0x1U << 25 )       // Interrupt Request - Data Packet Error
#define U2DISR_IRRS                     (0x1U << 26 )       // Interrupt Request - Reset
#define U2DISR_IRSU                     (0x1U << 27 )       // Interrupt Request - Suspend
#define U2DISR_IRRU                     (0x1U << 28 )       // Interrupt Request - Resume
#define U2DICR_IRUSOF                   (0x1U << 29 )       // Interrupt Enable - Macro SOF
#define U2DISR_IRSOF                    (0x1U << 30 )       // Interrupt Request - SOF
#define U2DISR_IRCC                     (0x1U << 31 )       // Interrupt Request - Configuration Change


//U2D OTG Control Register(U2DOTGCR) for Monahans LV Only
#define U2DOTGCR_ULE                    (0x1u << 0)         // ULPI Wrapper Enable
#define U2DOTGCR_RTSM                   (0x1u << 1)         // Return to Synchronous Mode(ULPI Mode)
#define U2DOTGCR_SMAF                   (0x1u << 2)         // Serial Mode Alternate Function Select
#define U2DOTGCR_ULAF                   (0x1u << 3)         // ULPI Mode Alternate Function Select
#define U2DOTGCR_UTMID                  (0x1u << 4)         // UTMI Interface Disable
#define U2DOTGCR_CKAF                   (0x1u << 5)         // Carkit Mode Alternate Function Select
#define U2DOTGCR_BHNP                   (0x1u << 28)        // B-device Host Negotiation Protocol Port Support
#define U2DOTGCR_AHNP                   (0x1u << 29)        // A-device Host Negotiation Protocol Port Support
#define U2DOTGCR_AALTHNP                (0x1u << 30)        // A-device Alternate Host Negotiation Protocol Port Support
#define U2DOTGCR_OTGEN                  (0x1u << 31)        // On-the-Go Enable

//U2D OTG Interrupt Control/Enable Register(U2DOTGICR) for Monahans LV Only
#define U2DOTGICR_IFECK                 (0x1u << 0)         // RXCMD Carkit Interrupt Fall Enable
#define U2DOTGICR_IFEVV                 (0x1u << 1)         // RXCMD OTG Vbus Valid Interrupt Fall Enable
#define U2DOTGICR_IFESV                 (0x1u << 2)         // RXCMD OTG Session Valid Interrupt Fall Enable
#define U2DOTGICR_IFESE                 (0x1u << 3)         // RXCMD OTG Session End Interrupt Fall Enable
#define U2DOTGICR_IFEID                 (0x1u << 4)         // RXCMD OTG ID Change Interrupt Fall Enable
#define U2DOTGICR_IFELS0                (0x1u << 5)         // RXCMD Linestate[0] Change Interrupt Fall Enable
#define U2DOTGICR_IFELS1                (0x1u << 6)         // RXCMD Linestate[1] Change Interrupt Fall Enable
#define U2DOTGICR_IRECK                 (0x1u << 8)         // RXCMD Carkit Interrupt Rise Enable
#define U2DOTGICR_IREVV                 (0x1u << 9)         // RXCMD OTG Vbus Valid Interrupt Rise Enable
#define U2DOTGICR_IRESV                 (0x1u << 10)        // RXCMD OTG Session Valid Interrupt Rise Enable
#define U2DOTGICR_IRESE                 (0x1u << 11)        // RXCMD OTG Session End Interrupt Rise Enable
#define U2DOTGICR_IREID                 (0x1u << 12)        // RXCMD OTG ID Change Interrupt Rise Enable
#define U2DOTGICR_IRELS0                (0x1u << 13)        // RXCMD Linestate[0] Change Interrupt Rise Enable
#define U2DOTGICR_IRELS1                (0x1u << 14)        // RXCMD Linestate[1] Change Interrupt Rise Enable
#define U2DOTGICR_IESI                  (0x1u << 16)        // OTG Interrupt Enable
#define U2DOTGICR_IESF                  (0x1u << 17)        // OTG Set Feature Command Received Enable

//U2D OTG ULPI Control Register(U2DOTGUCR) for Monahans LV Only
#define U2DOTGUCR_RUN                   (0x1u << 25)        // Run


//U2D Endpoint 0 Control Status Register(U2DCSR0)
#define U2DCSR0_OPC                     (0x1u << 0)         // Out Packet Complete
#define U2DCSR0_IPR                     (0x1u << 1)         // In Packet Ready
#define U2DCSR0_FTF                     (0x1u << 2)         // Flush Transmit FIFO
#define U2DCSR0_DME                     (0x1u << 3)         // DMA Enable
#define U2DCSR0_SST                     (0x1u << 4)         // Sent Stall
#define U2DCSR0_FST                     (0x1u << 5)         // Force Stall
#define U2DCSR0_RNE                     (0x1u << 6)         // Receive Fifo Not Empty
#define U2DCSR0_SA                      (0x1u << 7)         // Setup Actvie
#define U2DCSR0_IPA                     (0x1u << 8)         // In Packet Adjusted

//U2D Endpoints Control Status Registers(U2DCSRA-U2DCSRP)
#define U2DCSR_FS                       (0x1u <<0)          // FIFO needs service
#define U2DCSR_PC                       (0x1u <<1)          // Packet Complete
#define U2DCSR_TRN                      (0x1u <<2)          // Tx/Rx NAK
#define U2DCSR_DME                      (0x1u <<3)          // DME Enable
#define U2DCSR_SST                      (0x1u <<4)          // Sent Stall
#define U2DCSR_FST                      (0x1u <<5)          // Force Stall
#define U2DCSR_BNEBNF                   (0x1u <<6)          // Buffer NOT Full/Buffer NOT Empty
#define U2DCSR_SP                       (0x1u <<7)          // Short Packet Control/Status(OUT endpoints only)
#define U2DCSR_FEF                      (0x1u <<8)          // Flush Endpoint FIFO
#define U2DCSR_DPE                      (0x1u <<9)          // Data Packet Error(Isochronous Endpoints only)
#define U2DCSR_BFBE                     (0x1u <<10)         // Buffer Full/Buffer Empty

// U2D Endpoint Information Registers(U2DENA-U2DENP)
#define U2DEN_EN(n)                     (((n) & 0xF) )         // Endpoint Number
#define U2DEN_ED(n)                     (((n) & 0x1U) << 4)    // USB Endpoint Direction
#define U2DEN_ET(n)                     (((n) & 0x3U) << 5)    // Endoint Type
#define U2DEN_CN(n)                     (((n) &  0xFU) << 7)   // Configuration Number
#define U2DEN_IN(n)                     (((n) & 0xFU) << 11)   // Interface Number
#define U2DEN_AISN(n)                   (((n) &  0xFU) << 15)  // Interface Alternate Settings Number
#define U2DEN_MPS(n)                    (((n) & 0x7FFU) << 19 )// Maximum Packet Size
#define U2DEN_HBW(n)                    (((n) & 0x3U) << 30)   // High Bandwidth Commands per Micro-frame

//U2D Endpoint Configure register(U2DCRA-U2DCRP)
#define U2DCR_BS(n)                     (((n/4) & 0x3FF) <<1)   // Endpoint Buffer Size
#define U2DCR_EE                        (0x1u << 0)             // Endpoint Enable

//U2D Channel Control/Status Registers(U2DMACSR0-15)
#define U2DMACSR_BUSERRINTR             (0x1u << 0)         // Bus error Interrupt
#define U2DMACSR_STARTINTR              (0x1u << 1)         // Start Interrupt
#define U2DMACSR_ENDINTR                (0x1u << 2)         // End Interrupt
#define U2DMACSR_STOPINTR               (0x1u << 3)         // Stop Interrupt
#define U2DMACSR_RASINTR                (0x1u << 4)         // Request After Channel stopped
#define U2DMACSR_REQPEND                (0x1u << 8)         // Request Pending
#define U2DMACSR_EORINTR                (0x1u << 9)         // End of Recevie
#define U2DMACSR_BUSERRTYPE             (0x3u << 10)        // PX Bus Error Type
#define U2DMACSR_SCEMI                  (0xFu << 13)        // System Bus Split Completion Error Message Index
#define U2DMACSR_SCEMC                  (0x3u << 18)        // System Bus Split Completion Error Message Class
#define U2DMACSR_MASKRUN                (0x1u << 22)        // Mask Run
#define U2DMACSR_RASIRQEN               (0x1u << 23)        // Request After Channel Stopped Interrupt Enable
#define U2DMACSR_EORSTOPEN              (0x1u << 26)        // Stop the channel on an EOR
#define U2DMACSR_EORJMPEN               (0x1u << 27)        // Jump to the Next Descriptor
#define U2DMACSR_EORIRQEN               (0x1u << 28)        // End-of-Receive Interrupt Enabled
#define U2DMACSR_STOPIRQEN              (0x1u << 29)        // Stop Interrupt Enabled
#define U2DMACSR_RUN                    (0x1u << 31)        // Run:start/stop the channel

//U2D DMA Descriptor Adress Register(U2DMADADR0-15)
#define U2DMADADR_STOP                  (0x1u << 0)         // 0-Run channel;1-Stop channel after completely processing
                                                            // this descriptor and before fetching the next descriptor
#define U2DMADADR_DESCRIPA(n)           ((n&0xF) << 4)      // Descriptor Adress contains address of next descriptor

//U2D DMA command
#define U2DMACMD_XFRDIS                 (0x1U << 31)        // Transfer Direction
#define U2DMACMD_STARTIRQEN             (0x1U << 22)        // Start Interrupt Enable
#define U2DMACMD_ENDIRQEN               (0x1U << 21)        // End Interrupt Enable
#define U2DMACMD_PACKCOMP               (0x1U << 13)        // Packet Complete

/*
I2C Registers
*/

/*  bus monitor register */
#define IBMR_SDA                        (1 << 0)            /* reflects the status of SDA pin */
#define IBMR_SCL                        (1 << 1)            /* reflects the status of SCL pin */

/* data buffer regiter mask */
#define IDBR_ADDR                       0xFF;               /*buffer for I2C bus send/receive data */
#define IDBR_MODE                       (1 << 0)

/* Control Register */
#define ICR_START                       (1 << 0)            /* 1:send a Start condition to the I2C when in master mode */
#define ICR_STOP                        (1 << 1)            /* 1:send a Stop condition after next data byte transferred on I2C bus in master mode */
#define ICR_ACKNACK                     (1 << 2)            /* Ack/Nack control: 1:Nack, 0:Ack (negative or positive pulse) */
#define ICR_TB                          (1 << 3)            /* 1:send/receive byte, 0:cleared by I2C unit when done */
#define ICR_MA                          (1 << 4)            /* 1:I2C sends STOP w/out data permission, 0:ICR bit used only */
#define ICR_SCLEA                       (1 << 5)            /* I2C clock output: 1:Enabled, 0:Disabled. ICCR configured before ! */
#define ICR_UIE                         (1 << 6)            /* I2C unit: 1:Enabled, 0:Disabled */
#define ICR_GCD                         (1 << 7)            /* General Call: 1:Disabled, 0:Enabled */
#define ICR_ITEIE                       (1 << 8)            /* 1: IDBR Transmit Empty Interrupt Enable */
#define ICR_DRFIE                       (1 << 9)            /* 1: IDBR Receive Full Interrupt Enable */
#define ICR_BEIE                        (1 << 10)           /* 1: Bus Error Interrupt Enable */
#define ICR_SSDIE                       (1 << 11)           /* 1: Slave Stop Detected Interrupt Enable */
#define ICR_ALDIE                       (1 << 12)           /* 1: Arbitration Loss Detected Interrupt Enable */
#define ICR_SADIE                       (1 << 13)           /* 1: Slave Address Detected Interrupt Enable */
#define ICR_UR                          (1 << 14)           /* 1: I2C unit reset */
#define ICR_FM                          (1 << 15)           /* 1: Fast mode - 400 KBit/sec. operation. Default is 100 KBit/sec */

/* Status Register */
#define ISR_RWM                         (1 << 0)            /* 1: I2C in master receive = slave transmit mode */
#define ISR_ACKNACK                     (1 << 1)            /* 1: I2C received/sent a Nack, 0: Ack */
#define ISR_UB                          (1 << 2)            /* 1: Processor's I2C unit busy */
#define ISR_IBB                         (1 << 3)            /* 1: I2C bus busy. Processor's I2C unit not involved */
#define ISR_SSD                         (1 << 4)            /* 1: Slave Stop detected (when in slave mode: receive or transmit) */
#define ISR_ALD                         (1 << 5)            /* 1: Arbitration Loss Detected */
#define ISR_ITE                         (1 << 6)            /* 1: Transfer finished on I2C bus. If enabled in ICR, interrupt signaled */
#define ISR_IRF                         (1 << 7)            /* 1: IDBR received new byte from I2C bus. If ICR, interrupt signaled */
#define ISR_GCAD                        (1 << 8)            /* 1: I2C unit received a General Call address */
#define ISR_SAD                         (1 << 9)            /* 1: I2C unit detected a 7-bit address matching the general call or ISAR */
#define ISR_BED                         (1 << 10)           /* Bit set by unit when a Bus Error detected */

/* Frequency */

#define CLKCFG_T                        (1u << 0)
#define CLKCFG_F                        (1u << 1)
#define CLKCFG_MASK                     (CLKCFG_T | CLKCFG_F)

#define AICSR_PCIS                      (1u << 5)           /*  */
#define AICSR_PCIE                      (1u << 4)           /*  */
#define AICSR_TCIS                      (1u << 3)           /*  */
#define AICSR_TCIE                      (1u << 2)           /*  */
#define AICSR_FCIS                      (1u << 1)           /*  */
#define AICSR_FCIE                      (1u << 0)           /*  */

#define ACCR_XL(x)                      ((x&0x1F) << 0)     /*Ratio = RunMode/Oscillator*/
#define ACCR_XN(x)                      ((x&0x7) << 8)      /*Ratio = TurboMode/RunMode*/
#define ACCR_PCCE                       (1u << 11)          /*0: No clock for core during Power mode change, 1: Ring Oscillator*/
#define ACCR_DMCFS(x)                   ((x&0x3) << 12)     /*DDR Memory controller Frequency select*/
#define ACCR_HSS(x)                     ((x&0x3) << 14)     /*HSIO Bus-Clock Frequency select*/
#define ACCR_XSPCLK(x)                  ((x&0x3) << 16)     /*Core Frequency select during frequency change*/
#define ACCR_SFLFS(x)                   ((x&0x3) << 18)     /*SRAM controller Frequency*/
#define ACCR_SMCFS(x)                   ((x&0x7) << 23)     /*Static Memory Controller Frequency*/
#define ACCR_D0CS                       (1u << 26)          /*0: Use PLLs as clock source in D0 mode, 1: Use Ring Oscillator*/
#define ACCR_VAUF(x)                    ((x&0x3) << 28)     /*Video Accelerator Frequency*/
#define ACCR_SPDIS                      (1u << 30)          /*System PLL Disable*/
#define ACCR_XPDIS                      (1u << 31)          /*Core PLL Disable*/

#define ACSR_XL(x)                      ((x >> 0)&0x1F)     /*Ratio = RunMode/Oscillator*/
#define ACSR_XN(x)                      ((x >> 8)&0x7)      /*Ratio = TurboMode/RunMode*/
#define ACSR_DMC_S(x)                   ((x >> 12)&0x3)     /*DDR Memory controller Frequency select*/
#define ACSR_HSS_S(x)                   ((x >> 14)&0x3)     /*HSIO Bus-Clock Frequency select*/
#define ACSR_XSPCLK_S(x)                ((x >> 16)&0x3)     /*Core Frequency select during frequency change*/
#define ACSR_SFL_S(x)                   ((x >> 18)&0x3)     /*SRAM controller Frequency*/
#define ACSR_VAUF_S(x)                  ((x >> 21)&0x3)     /*Video Accelerator Frequency*/
#define ACSR_SMC_S(x)                   ((x >> 23)&0x7)     /*Static Memory Controller Frequency*/
#define ACSR_RO_S                       (1u << 26)          /*PLL is using Ring Oscillator (1) or not (0)*/
#define ACSR_SPLCK                      (1u << 28)          /*System PLL is locked and ready to use*/
#define ACSR_XPLCK                      (1u << 29)          /*Core PLL is locked and ready to use*/
#define ACSR_SPDIS                      (1u << 30)          /*System PLL Disable*/
#define ACSR_XPDIS                      (1u << 31)          /*Core PLL Disable*/

#define ACSR_XL_MASK                    (0x1F)
#define ACSR_XN_MASK                    (7 << 8)

#define VAUF_104MHz                     0
#define VAUF_156MHz                     1
#define VAUF_208MHz                     2
#define VAUF_78MHz                      3

#define SMCFS_78M                       0
#define SMCFS_104M                      2
#define SMCFS_208M                      5

#define SFLFS_104M                      0
#define SFLFS_156M                      1
#define SFLFS_208M                      2

#define SFL_S_156M                      1
#define SFL_S_208M                      2
#define SFL_S_312M                      3

#define XSPCLK_156M                     0
#define XSPCLK_NULL                     3

#define HSS_104M                        0
#define HSS_156M                        1

#define HSS_S_104M                      0
#define HSS_S_156M                      1
#define HSS_S_208M                      2
#define HSS_S_312M                      3

#define DMCFS_26M                       0
#define DMCFS_260M                      3

#define XL_TIMES_8                      8
#define XL_TIMES_12                     12
#define XL_TIMES_16                     16
#define XL_TIMES_24                     24

#define XN_TIMES_1                      1
#define XN_TIMES_2                      2
#define XN_TIMES_4                      4

/* OS Timer */
#define OMCR_CRES(n)                    ((n&7) << 0)        /* 0: Disable, 1: 1/32768, 2: 1milisecond, 3: 1s, 4: 1microsecond */

/* RTC */
#define RTSR_AL                         (0x1 << 0)          // RTC Alarm detect
#define RTSR_HZ                         (0x1 << 1)          // HZ rising edge detect
#define RTSR_ALE                        (0x1 << 2)          // RTC Alarm enable
#define RTSR_HZE                        (0x1 << 3)          // HZ enable
#define RTSR_RDAL1                      (0x1 << 4)          // Wristwatch alarm 1 detect
#define RTSR_RDALE1                     (0x1 << 5)          // Wristwatch alarm 1 enable
#define RTSR_RDAL2                      (0x1 << 6)          // Wristwatch alarm 2 detect
#define RTSR_RDALE2                     (0x1 << 7)          // Wristwatch alarm 2 enable
#define RTSR_SWAL1                      (0x1 << 8)          // Stopwatch alarm 1 detect
#define RTSR_SWALE1                     (0x1 << 9)          // Stopwatch alarm 1 enable
#define RTSR_SWAL2                      (0x1 << 10)         // Stopwatch alarm 2 detect
#define RTSR_SWALE2                     (0x1 << 11)         // Stopwatch alarm 2 enable
#define RTSR_SWCE                       (0x1 << 12)         // Stopwatch counter enable
#define RTSR_PIAL                       (0x1 << 13)         // Periodic alarm detect
#define RTSR_PIALE                      (0x1 << 14)         // Periodic alarm enable
#define RTSR_PICE                       (0x1 << 15)         // Periodic interrupt count enable

#define RDCR_WOM(n)                     ((n&7)<<20)         /*Week of month */
#define RDCR_DOW(n)                     ((n&7)<<17)         /* Day of week */
#define RDCR_HOURS(n)                   ((n&0x1F)<<12)      /* 0~23 */
#define RDCR_MINUTES(n)                 ((n&0x3F)<<6)       /* 0~59 */
#define RDCR_SECONDS(n)                 ((n&0x3F)<<0)       /* 0~59 */
#define RDCR_MASK                       0x000FFFFF

#define RYCR_YEAR(n)                    ((n&0xFFF)<<9)      /* 0~4095 */
#define RYCR_MONTH(n)                   ((n&0xF)<<5)        /* 1~12 */
#define RYCR_DOM(n)                     ((n&0x1F)<<0)       /* Day of month */
#define RYCR_MASK                       0x001FFFFF

/* NAND */

#define NDCB0_AUTO_RS                   (1<<25)             /* Auto Read Status */
#define NDCB0_CSEL(n)                   ((n&1)<<24)         /* 0: nCS0, 1: nCS1 */
#define NDCB0_CMD_TYPE(t)               ((t&7)<<21)         /*Command Type */
#define NDCB0_NC                        (1<<20)             /* Is there any next Command */
#define NDCB0_DBC                       (1<<19)             /* Double Byte Command */
#define NDCB0_ADDR_CYC(x)               ((x&0x7)<<16)       /* How many Address Cycles needed */

#define NDCB2_ADDR_MASK                 0xFF
#define NDCB2_PAGE_COUNT(n)             (((n-1)&0x3F) << 8)

#define NDCR_SPARE_EN                   (1u << 31)          /* 0: spare area disable, 1: spare area enable  */
#define NDCR_ECC_EN                     (1u << 30)          /* 0: ECC is disable, 1: ECC is enable  */
#define NDCR_DMA_EN                     (1u << 29)          /* 0: DMA is disable, 1: DMA is enable  */
#define NDCR_ND_RUN                     (1<<28)             /* 0: NAND controller is in stop mode, 1: NAND controller is in run mode */
#define NDCR_DWIDTH_C                   (1u << 27)          /* data bus width of the nand flash controller  */
#define NDCR_DWIDTH_M                   (1u << 26)          /*  data bus width of the nand flash memory */
#define NDCR_PAGE_SZ                    (1u << 24)          /* page size of the flash, 00: 512 bytes, 01: 2048 bytes  */
#define NDCR_NCSX                       (1u << 23)          /* 0: chip select should be asserted during read busy phase, 1: chip select don't care */
#define NDCR_NT_STOP                    (1u << 22)          /* 0: not put the controller in IDLE, 1: put it into IDLE for low power mode entry */
#define NDCR_CLR_PG_CNT                 (1u << 20)          /* 0: page count not cleared, 1: clear page count */
#define NDCR_CLR_ECC                    (1u << 19)          /* 0: no effect, 1: ECC logic is initialized */
#define NDCR_RD_ID_CNT(n)               ((n&7) << 16)       /* read ID byte count, values from 1 to 7 */
#define NDCR_RA_START                   (1u << 15)          /* 0: row address supplied from second address cycle, 1: row address supplied from third address cycle */
#define NDCR_PG_PER_BLK                 (1u << 14)          /* 0: 32 pages per block, 1: 64 pages per block */
#define NDCR_ND_ARB_EN                  (1u << 12)          /* 0: data flash bus arbiter is disable, 1: data flash bus arbiter is enable */
#define NDCR_RDYM                       (1u << 11)          /* 0: ready interrupt is enable, 1: ready interrupt is disable */
#define NDCR_CS0_PAGEDM                 (1u << 10)          /* 0: ND_nCS0 page done interrupt is enable, 1: ND_nCS0 page done interrupt is disable */
#define NDCR_CS1_PAGEDM                 (1u << 9)           /* 0: ND_nCS1 page done interrupt is enable, 1: ND_nCS1 page done interrupt is disable */
#define NDCR_CS0_CMDDM                  (1u << 8)           /* 0: ND_nCS0 command done interrupt is enable, 1: ND_nCS0 command done interrupt is disable */
#define NDCR_CS1_CMDDM                  (1u << 7)           /* 0: ND_nCS1 command done interrupt is enable, 1: ND_nCS1 command done interrupt is disable */
#define NDCR_CS0_BBDM                   (1u << 6)           /* 0: ND_nCS0 bad block detect interrupt is enable, 1: ND_nCS0 bad block detect interrupt is disable */
#define NDCR_CS1_BBDM                   (1u << 5)           /* 0: ND_nCS1 bad block detect interrupt is enable, 1: ND_nCS1 bad block detect interrupt is disable */
#define NDCR_DBERRM                     (1u << 4)           /* 0: double-bit error interrupt is enable, 1: double-bit interrupt is disable */
#define NDCR_SBERRM                     (1u << 3)           /* 0: single-bit error interrupt is enable, 1: single-bit interrupt is disable */
#define NDCR_WRDREQM                    (1u << 2)           /* 0: write data request interrupt is enable, 1: write data request interrupt is disable */
#define NDCR_RDDREQM                    (1u << 1)           /* 0: read data request interrupt is enable, 1: read data request interrupt is dsable */
#define NDCR_WRCMDREQM                  (1u << 0)           /* 0: writer command request interrupt is enable, 1: write command request interrupt is disable */

#define NDSR_FLAG_ALL                   0x00000FFF
#define NDSR_RDY                        (1u << 11)          /* 0: read/busy_input has not transitioned from low to high, 1: ready/busy_input has transitioned from low to high */
#define NDSR_CS0_PAGED                  (1u << 10)          /* 0: current read/write on ND_nCS0 don't reach a page boundary, 1: current read/write on ND_nCS0 reaches a page boundary */
#define NDSR_CS1_PAGED                  (1u << 9)           /* 0: current read/write on ND_nCS1 don't reach a page boundary, 1: current read/write on ND_nCS1 reaches a page boundary */
#define NDSR_CS0_CMDD                   (1u << 8)           /* 0: command on ND_nCS0 not successfully completed, 1: command on ND_nCS0 successfully completed */
#define NDSR_CS1_CMDD                   (1u << 7)           /* 0: command on ND_nCS1 not successfully completed, 1: command on ND_nCS1 successfully completed */
#define NDSR_CS0_BBD                    (1u << 6)           /* 0: no bad block is encountered on ND_nCS0, 1: bad block is encountered on ND_nCS0 */
#define NDSR_CS1_BBD                    (1u << 5)           /* 0: no bad block is encountered on ND_nCS1, 1: bad block is encountered on ND_nCS1 */
#define NDSR_DBERR                      (1u << 4)           /* 0: no double-bit error is encountered for read data streams, 1: double-bit error is encountered for read data streams */
#define NDSR_SBERR                      (1u << 3)           /* 0: no correctable error is encountered for read data streams, 1: correctable error is encountered for read data streams */
#define NDSR_WRDREQ                     (1u << 2)           /* 0: no write to the data buffer is required, 1: current command is a page write and data buffer has not been loaded */
#define NDSR_RDDREQ                     (1u << 1)           /* 0: no read from the data buffer is required, 1: data buffer has read data available */
#define NDSR_WRCMDREQ                   (1u << 0)           /* 0: no write to the command buffer is required, 1: new command needs to be written to the command buffer */

#define NDTR0CS_tCH(t)                  ((t&7)<<19)         /* enable singal hold time */
#define NDTR0CS_tCS(t)                  ((t&7)<<16)         /* enable signal setup time */
#define NDTR0CS_tWH(t)                  ((t&7)<<11)         /* ND_nWE high duration */
#define NDTR0CS_tWP(t)                  ((t&7)<<8)          /* ND_nWE pulse width */
#define NDTR0CS_tRH(t)                  ((t&7)<<3)          /* ND_nRE high duration */
#define NDTR0CS_tRP(t)                  ((t&7)<<0)          /* ND_nRE pulse width */

#define NDTR1CS_tR(t)                   ((t&0xFFFF)<<16)    /* ND_nWE high to ND_nRE low for read */
#define NDTR1CS_tWHR(t)                 ((t&0xF)<<4)        /* ND_nWE high to ND_nRE low for a read status or read id */
#define NDTR1CS_tAR(t)                  ((t&0xF)<<0)        /* ND_ALE low to ND_nRE low delay */

#define CMD_TYPE_READ                   0
#define CMD_TYPE_PROGRAM                1
#define CMD_TYPE_ERASE                  2
#define CMD_TYPE_READ_ID                3
#define CMD_TYPE_READ_STATUS            4
#define CMD_TYPE_RESET                  5

/* Quick Capture Interface */

#define CICR0_SL_CAP_EN                 (1 << 29)           /*Capture Enable for Slave Mode: 0-Disable 1-Enable*/
#define CICR0_ENB                       (1 << 28)           /*Capture Interface Enable: 0-Disable 1-Enable*/
#define CICR0_DIS                       (1 << 27)           /*Capture Interface Disable: 0-has not been enabled 1-has been disabled*/
#define CICR0_SIM(n)                    ((n&7) << 24)       /*Sensor Interface Mode: 0-Master Parallel 1-Slave Parallel*/
#define CICR0_LCD_MODE(n)               ((n&3) << 22)       /*0-LCD Handshaking disabled 1-LCD Base Layer CI Active 2-LCD Overlay 1 Layer CI Active 3-LCD Overlay 2 Layer CI Active*/
#define CICR0_GCU_EN                    (1 << 21)           /*GCU Handshaking: 0-Disabled 1-Enabled*/
#define CICR0_EOFXM                     (1 << 12)           /*End-of-Frame Transfer to  Memory Mask: 0-Generates interrupt 1-don't generate interrupt*/
#define CICR0_BSM                       (1 << 11)           /*Branch Status Mask: 0-generate interrupt after branching 1-don't generate interrupt after branching*/
#define CICR0_FUM                       (1 << 10)           /*Input FIFO Underrun Mask: 0-Interrupt 1-No Interrupt*/
#define CICR0_TOM                       (1 << 9)            /*Time-Out Mask: 0-interrupt 1-No interrupt*/
#define CICR0_EOLM                      (1 << 6)            /*End-of-Line Mask: 0-interrupt 1-No interrupt*/
#define CICR0_QDM                       (1 << 4)            /*Capture Interface Quick Disable Mask: 0-Interrupt 1-No Interrupt*/
#define CICR0_CDM                       (1 << 3)            /*Capture Interface Disable Done Mask: 0-Interrupt 1-No Interrupt*/
#define CICR0_SOFM                      (1 << 2)            /*Capture Interface Start-of-Stream Mask: 0-Interrupt 1-No Interrupt*/
#define CICR0_EOFM                      (1 << 1)            /*Capture Interface End-of-Stream Mask: 0-Interrupt 1-No Interrupt*/
#define CICR0_FOM                       (1 << 0)            /*FIFO Overrun Mask: 0-Interrupt 1-No Interrupt*/

#define CICR1_PPL(n)                    (((n-1)&0xFFF) << 15)/*Pixel per Line for the frame*/
#define CICR1_YCBCRF(n)                 (n << 10)           /*YCbCr Format: 0-reserved 1-Planarized format*/
#define CICR1_RAW_BPP(n)                ((n&3) << 5)        /*Raw Bits per Pixel: 0-8 Bits per Pixel 1-reserved 2-10 Bits per pixel 3-reserved*/
#define CICR1_COLORSP(n)                ((n&3) << 3)        /*Color Space: 0-Raw 1-reserved 2-YCbCr 3-reserved*/
#define CICR1_DW(n)                     ((n&7) << 0)        /*Data Width: 0-reserved 1-reserved 2-8 bits from sensor 3-reserved 4-10 bits from sensor other-reserved*/
#define CICR1_BIT8                      (1 << 8)            /*Mask Bit8*/

#define YCBCRF_PLANAR                   1

#define COLORSP_RAW                     0
#define COLORSP_YUV                     2
#define COLORSP_RGB                     3                   /* Not compatible with Developer Manual!!! */

#define CICR2_BLW(n)                    ((n&0xFF) << 24)    /*Beginning-of-Line Pixel Clock Wait Count*/
#define CICR2_ELW(n)                    ((n&0xFF) << 16)    /*End-of-Line Pixel Clock Wait Count*/
#define CICR2_HSW(n)                    ((n&0x3F) << 10)    /*Horizontal Sync Pulse Width*/
#define CICR2_BFPW(n)                   ((n&0x3F) << 3)     /*Beginning of Frame Pixel Clock Wait Count*/
#define CICR2_FSW(n)                    ((n&7) << 0)        /*Frame Stabilization Wait Count*/

#define CICR3_BFW(n)                    ((n&0xFF) << 24)    /*Beginning-of-Frame Pixel Clock Wait Count*/
#define CICR3_EFW(n)                    ((n&0xFF) << 16)    /*End-of-Frame Pixel Clock Wait Count*/
#define CICR3_VSW(n)                    ((n&0x1F) << 11)    /*Vertical Sync Pulse Width*/
#define CICR3_LPF(n)                    (((n-1)&0x7FF) << 0)/*Line per Frame*/

#define CICR4_YCBCR_DS                  (1 << 27)           /*YCbCr4:2:2->YCbCr4:2:0 Enable: 0-Disable 1-Enable*/
#define CICR4_PCLK_EN                   (1 << 23)           /*Pixel Clock Enable*/
#define CICR4_PCP                       (1 << 22)           /*Pixel Clock Polarity: 0-Rising 1-Falling*/
#define CICR4_HSP                       (1 << 21)           /*Horizontal Sync Polarity: 0-active hight inactive low 1-active low inactive high*/
#define CICR4_VSP                       (1 << 20)           /*Vertical Sync Polarity: 0-active hight inactive low 1-active low inactive high*/
#define CICR4_MCLK_EN                   (1 << 19)           /*MCLK Enable: 0-MCLK not supplied by QCI 1-MCLK supplied by QCI*/
#define CICR4_FR_RATE(n)                ((n&7) << 8)        /*Frame Capture Rate*/
#define CICR4_DIV(n)                    ((n&0xFF) << 0)     /*Clock Divisor*/

#define CICMD_INCTRGADDR                (1 << 30)           /*Increase Target Address*/

#define CIFR0_RESETF                    (1 << 3)            /*Reset Input FIFOs*/
#define CIFR0_FEN2                      (1 << 2)            /*FIFO Enable for Channel 2*/
#define CIFR0_FEN1                      (1 << 1)            /*FIFO Enable for Channel 1*/
#define CIFR0_FEN0                      (1 << 0)            /*FIFO Enable for Channel 0*/

/* Keypad */
#define D0CKENA_KEYPAD                  (1u << 14)          // keypad clock enable

#define KPC_AS                          (1u << 30)          // 1: automatic scan, 0: no effect
#define KPC_ASACT                       (1u << 29)          // 1: automatic scan on activity, 0: no automatic scan on activity
#define KPC_MKRN(x)                     (((x - 1) &0x7) << 26)     // matrix keypad row number
#define KPC_MKCN(x)                     (((x - 1) &0x7) << 23)     // matrix keypad column number
#define KPC_MI                          (1u << 22)          // matrix keypad interrupt
#define KPC_IMKP                        (1u << 21)          // ingnore multiple keypress
#define KPC_MS7                         (1u << 20)          // manual matrix scan line
#define KPC_MS6                         (1u << 19)          // manual matrix scan line
#define KPC_MS5                         (1u << 18)          // manual matrix scan line
#define KPC_MS4                         (1u << 17)          // manual matrix scan line
#define KPC_MS3                         (1u << 16)          // manual matrix scan line
#define KPC_MS2                         (1u << 15)          // manual matrix scan line
#define KPC_MS1                         (1u << 14)          // manual matrix scan line
#define KPC_MS0                         (1u << 13)          // manual matrix scan line
#define KPC_ME                          (1u << 12)          // matrix keypad enable
#define KPC_MIE                         (1u << 11)          // matrix interrupt enable
#define KPC_DK_DEB_SEL                  (1u << 9)           // direct keypad debounce select
#define KPC_DKN(x)                      (((x - 1) &0x7) << 6)      // direct key number
#define KPC_DI                          (1u << 5)           // direct keypad interrupt
#define KPC_RE_ZERO_DEB                 (1u << 4)           // rotary encoder zero debounce interval
#define KPC_REEB                        (1u << 3)           // rotary encoder b enable
#define KPC_REEA                        (1u << 2)           // rotary encoder a enable
#define KPC_DE                          (1u << 1)           // direct keypad enable
#define KPC_DIE                         (1u << 0)           // direct keypad interrupt enable

#define KPKDI_DKDI(x)                   ((x&0xFF) << 8)     // direct key debounce interval
#define KPKDI_MKDI(x)                   ((x&0xFF) << 0)     // matrix key debounce interval

#define KPREC_OFB                       (1u << 31)          // overflow bit for rotary encoder b
#define KPREC_UFB                       (1u << 30)          // underflow bit for rotary encoder b
#define KPREC_COUNTB(x)                 ((x&0xFF) << 16)    // count value for rotary encoder b
#define KPREC_OFA                       (1u << 15)          // overflow bit for rotary encoder a
#define KPREC_UFA                       (1u << 14)          // underflow bit for rotary encoder a
#define KPREC_COUNTA(x)                 ((x&0xFF) << 0)     // coiunt value for rotary encoder 0

#define KPAS_SO                         (1u << 31)          // scan on, 1: scanning and the data is invalid, 0: scan is completed
#define KPAS_MUKP_MASK                  (0x1F << 26)        // multiple keys pressed, 0: no key pressed, 1: single key pressed, xxx: multiple keys pressed
#define KPAS_MUKP(x)                    ((x&0x1F) << 26)    // multiple keys pressed, 0: no key pressed, 1: single key pressed, xxx: multiple keys pressed
#define KPAS_RP_MASK                    (0x70)              // row pressed, 1111: reset value, 0000-0111: key pressed
#define KPAS_CP_MASK                    (0x07)              // column pressed, 1111: reset value, 0000-0111: key pressed
#define KPAS_XP_MASK                    (0x77)              // 1111: reset value, 0000-0111: key pressed
#define KPAS_XP_ERR_MASK                (0x88)              // 1111: reset value, 0000-0111: key pressed

#define KPDK_DKP                        (1u << 31)          // 1: direct key pressed since last read, 0: reset on register read
#define KPDK_DK7                        (1u << 7)           // direct key 7 input
#define KPDK_DK6                        (1u << 6)           // direct key 6 input
#define KPDK_DK5                        (1u << 5)           // direct key 5 input
#define KPDK_DK4                        (1u << 4)           // direct key 4 input
#define KPDK_RB1_DK3                    (1u << 3)           // rotary encoder b / direct key 3 input
#define KPDK_RA1_DK2                    (1u << 2)           // rotary encoder a / direct key 2 input
#define KPDK_RB0_DK1                    (1u << 1)           // rotary encoder b / direct key 1 input
#define KPDK_RA0_DK0                    (1u << 0)           // rotary encoder a / direct key 0 input
#define KPDK_DKx_MASK                   0xFF                // mask for direct key input

/*
 MMC/SD
*/
#define CLKRT_CLKRATE(n)                (n & 7)

// SD bus clock control register
#define SD_STRPCL_STOP_CLOCK            (1u << 0)           // stop MMC_CLK and cleared to 0
#define SD_STRPCL_START_CLOCK           (1u << 1)           // start MMC_CLK and cleared to 0

// SD CMD_DAT register
#define  SD_CMDAT_DATA                  (1u << 2)           // 1-current command sequence includes a data transfer
#define  SD_CMDAT_WRITE                 (1u << 3)           // 1-current command sequence is for a write data transfer
#define  SD_CMDAT_STREAM                (1u << 4)           // 1-Data transfer of curment command sequence is in stream mode
#define  SD_CMDAT_BUSY                  (1u << 5)           // 1-Busy signalling is possbile
#define  SD_CMDAT_INIT                  (1u << 6)           // 1-for initialization, precede command sequence with 80 MMCLKS
#define  SD_CMDAT_DMA                   (1u << 7)           // 1-DMA requests are used to service to FIFOs
#define  SD_CMDAT_4DAT                  (1u << 8)           // 1-Enable 4-bit data transfer
#define  SD_CMDAT_STOP                  (1u << 10)          // 1-Stop data transmission
#define  SD_CMDAT_SDIO_INT              (1u << 11)          // 1-Enables controller to check for an SDIO interrupt from the card
#define  SD_CMDAT_SDIO_SUSPEND          (1u << 12)          // 1-SDIO CMD52, suspend current data transfer
#define  SD_CMDAT_SDIO_RESUME           (1u << 13)          // 1-SDIO CMD52, resume a suspended data transfer

// SD status register
#define  SD_STAT_READ_TIMEOUT           (1u << 0)           // 1-Card read data time out
#define  SD_STAT_RESP_TIMEOUT           (1u << 1)           // 1-card response timed out
#define  SD_STAT_WRITE_CRC              (1u << 2)           // 1-Write data rejected by card due to a CRC error
#define  SD_STAT_READ_CRC               (1u << 3)           // 1- CRC error occured on recevied data
#define  SD_STAT_SPI_ERR_TOKEN          (1u << 4)           // 1-SPI data error token has been recevied
#define  SD_STAT_RESP_CRC               (1u << 5)           // 1-CRC error occured on the response
#define  SD_STAT_CLOCK_ON               (1u << 8)           // 1-MMCLK is enbaled
#define  SD_STAT_FLASH_ERR              (1u << 9)           // 1-Flash programming error occured
#define  SD_STAT_SPI_WRITE_ERR          (1u << 10)          // 1-Wrtie data rejected by card due to a write error
#define  SD_STAT_TRAN_DONE              (1u << 11)          // 1-Data transmission to card has completed
#define  SD_STAT_PRG_DONE               (1u << 12)          // 1-Card has finished programming and is not busy
#define  SD_STAT_END_CMD                (1u << 13)          // 1-Command and response sequence has completed
#define  SD_STAT_SDIO_RDSTALLED         (1u << 14)          // 1-Read data transfer has been stalled in response to RD_WAIT
#define  SD_STAT_SDIO_INT               (1u << 15)          // 1-SDIO interrupt has occurred
#define  SD_STAT_SDIO_SUSPENDACK        (1u << 16)          // 1-SDIO data transfer has been suspended by SDIO card

// SD interrupt mask register
// 0-Enabled 1-Masked
#define  SD_MASK_DATA_TRAN_DONE         (1u << 0)
#define  SD_MASK_PRG_DONE               (1u << 1)
#define  SD_MASK_END_CMD_RES            (1u << 2)
#define  SD_MASK_STOP_CMD               (1u << 3)
#define  SD_MASK_CLK_OFF                (1u << 4)
#define  SD_MASK_RXFIFO_RD_REQ          (1u << 5)
#define  SD_MASK_TXFIFO_WR_REQ          (1u << 6)
#define  SD_MASK_TINT                   (1u << 7)
#define  SD_MASK_DAT_ERR                (1u << 8)
#define  SD_MASK_RES_ERR                (1u << 9)
#define  SD_MASK_SDIO_RD_STALLED        (1u << 10)
#define  SD_MASK_SDIO_INT               (1u << 11)
#define  SD_MASK_SDIO_SUSPEND_ACK       (1u << 12)

// SD interrupt register
#define  SD_REG_DATA_TRAN_DONE          (1u << 0)           // 1-Data transfer has completed or a read data time-out has occured
#define  SD_REG_PRG_DONE                (1u << 1)           // 1-Card has finished programming and is no longer busy
#define  SD_REG_END_CMD_RES             (1u << 2)           // 1-MMC has recevied the response  or a response time-out has occured
#define  SD_REG_STOP_CMD                (1u << 3)           // 1-MMC is ready for the stop transmission command
#define  SD_REG_CLK_OFF                 (1u << 4)           // 1-MMCLK has been turned off due to stop bit in STRP_CLK register
#define  SD_REG_RXFIFO_RD_REQ           (1u << 5)           // 1-Request for data read from RXFIFO
#define  SD_REG_TXFIFO_WR_REQ           (1u << 6)           // 1-Request for data write to TXFIFO
#define  SD_REG_TINT                    (1u << 7)           // 1-Receive data transfer has time-out
#define  SD_REG_DAT_ERR                 (1u << 8)           // 1-Data error occurred during data transmission
#define  SD_REG_RES_ERR                 (1u << 9)           // 1-Error occurred on the response
#define  SD_REG_SDIO_RD_STALLED         (1u << 10)          // 1-Card has stalled a read in response to RD_WAIT
#define  SD_REG_SDIO_INT                (1u << 11)          // 1-SDIO interrupt occured
#define  SD_REG_SDIO_SUSPEND_ACK        (1u << 12)          // 1-SDIO data transfer has been suspended by SDIO card

/*
    SSP
*/

#define SSCR0_MOD(x)                    ((x&1u) << 31)      // 0: normal SSP mode, 1: network mode
#define SSCR0_ACS                       (1u << 30)          // audio clock select: 1: I2S_BITCLK output, 0: I2S_BITCLK input
#define SSCR0_FPCKE                     (1u << 29)          // FIFO packing enable
#define SSCR0_52MM                      (1u << 27)          // for lv only, 0: 13Mbps, 1: 52Mbps
#define SSCR0_FRDC(x)                   (((x-1)&0x7) << 24) // Frame Rate Divider [Slots/Frame (for I2S mode, there are 2 slots per frame)]
#define SSCR0_TIM                       (1u << 23)          // transmit FIFO underrun interrupt mask
#define SSCR0_RIM                       (1u << 22)          // receive FIFO overrun interrupt mask
#define SSCR0_NCS                       (1u << 21)          // network clock select
#define SSCR0_SCR(x)                    ((x&0xFFF) << 8)    // serial clock rate
#define SSCR0_SSE                       (1u << 7)           // synchronous serial port enable
#define SSCR0_ECS                       (1u << 6)           // external clock select
#define SSCR0_FRF(x)                    ((x&0x3) << 4)      // frame format
/*
#define SSCR0_EDSS                      (1u << 20)          // extended data size select
#define SSCR0_DSS(x)                    ((x&0xF) << 0)      // data size select
*/
#define SSCR0_E_DSS(x)                  (((x&0x10) << 16) | (x&0xF) << 0)      // data size select

#define MOD_NORMAL                      0
#define MOD_NETWORK                     1

#define E_DSS_32BIT                     0x1F
#define E_DSS_18BIT                     0x11
#define E_DSS_16BIT                     0x0F
#define E_DSS_08BIT                     0x07

#define FRF_SPI                         0
#define FRF_SSP                         1
#define FRF_PSP                         3

#define SCR_000                         0x000
#define SCR_001                         0x001
#define SCR_00F                         0x00F
#define SCR_07F                         0x07F

#define SSCR1_TTELP                     (1u << 31)          // TXD three-state enable on last phase
#define SSCR1_TTE                       (1u << 30)          // TXD three-state enable
#define SSCR1_EBCEI                     (1u << 29)          // enable bit count error interrupt
#define SSCR1_SCFR                      (1u << 28)          // slave clock free running
#define SSCR1_ECRA                      (1u << 27)          // enable clock request A
#define SSCR1_ECRB                      (1u << 26)          // enable clokc request B
#define SSCR1_SCLKDIR                   (1u << 25)          // SSP serial bit rate clock direction
#define SSCR1_SFRMDIR                   (1u << 24)          // SSP frame direction
#define SSCR1_RWOT                      (1u << 23)          // receiver without transmit
#define SSCR1_TRAIL                     (1u << 22)          // trailing byte
#define SSCR1_TSRE                      (1u << 21)          // transmit DMA service request enable
#define SSCR1_RSRE                      (1u << 20)          // receive DMA service request enable
#define SSCR1_TINTE                     (1u << 19)          // receiver time-out interrupt enable
#define SSCR1_PINTE                     (1u << 18)          // peripheral trailing byte interrupt enable
#define SSCR1_IFS                       (1u << 16)          // invert frame signal
#define SSCR1_STRF                      (1u << 15)          // select FIFO for efwr (test mode bit)
#define SSCR1_EFWR                      (1u << 14)          // enable FIFO write/read (test mode bit)
#define SSCR1_RFT(x)                    ((x&0xF) << 10)     // RXFIFO trigger threshold
#define SSCR1_TFT(x)                    ((x&0xF) << 6)      // TXFIFO trigger threshold
#define SSCR1_SPH(x)                    ((x&1u) << 4)       // motorola SPI sspsclk phase setting
#define SSCR1_SPO(x)                    ((x&1u) << 3)       // motorola SPI sspsclk polatiry setting
#define SSCR1_LBM                       (1u << 2)           // loopback mode (test mode bit)
#define SSCR1_TIE                       (1u << 1)           // transmit FIFO interrupt enable
#define SSCR1_RIE                       (1u << 0)           // receive FIFO interrupt enable

#define SPH_ONE_CLK_AFTER               0
#define SPH_HALF_CLK_AFTER              1
#define SPO_IDLE_LOW                    0
#define SPO_IDLE_HIGH                   1

#define SSPSP_EDMYSTRT(x)               ((x&0x3) << 26)     // extended dummy start
#define SSPSP_FSRT(x)                   ((x&1u) << 25)      // frame sync relative timing bit, [1: Normal I2S ; 0: MSB-justified]
#define SSPSP_SFRMWDTH(x)               ((x&0x3F) << 16)    // serial frame width
#define SSPSP_SFRMDLY(x)                ((x&0x7F) << 9)     // serial frame delay
#define SSPSP_DMYSTRT(x)                ((x&0x3) << 7)      // dummy start
#define SSPSP_STRTDLY(x)                ((x&0x7) << 4)      // start delay
#define SSPSP_ETDS                      (1u << 3)           // end of transfer data state
#define SSPSP_SFRMP(x)                  ((x&1u) << 2)       // serial frame polatiry
#define SSPSP_SCMODE(x)                 ((x&0x3) << 0)      // serial bit-rate clock mode: Drive on Falling or Rising, Sample on Fallingn or Rising, Idle on High or Low
/*
#define SSPSP_EDMYSTOP(x)               ((x&0x7) << 28)     // extended dummy stop
#define SSPSP_DMYSTOP(x)                ((x&0x3) << 23)     // dummy stop
*/
#define SSPSP_E_DMYSTOP(x)              (((x&0x1C) << 26)|((x&0x3) << 23)) // dummy stop

#define SCMODE_FALLING_RISING_LO        0
#define SCMODE_RISING_FALLING_LO        1
#define SCMODE_RISING_FALLING_HI        2
#define SCMODE_FALLING_RISING_HI        3

#define SFRMP_SFRM_ACTIVE_LO            0
#define SFRMP_SFRM_ACTIVE_HI            1
#define SFRMP_SFRM_NORMAL_I2S           0
#define SFRMP_SFRM_MSB_JUSTIFIED        1

#define FSRT_NORMAL_I2S                 1
#define FSRT_SFRM_MSB_JUSTIFIED         0

#define SSxSA_xTSA(x)                   (1u << x)           // time slot active

#define SSACD_SCDx8                     (1u << 7)           // 1: SYSCLK divided by 8, 0: SYSCLK divided by 4
#define SSACD_ACPS(x)                   ((x&0x7) << 4)      // Audio clock PLL select
#define SSACD_SCDB                      (1u << 3)           // 1: SYSCLK divided by 4(if SCDx8 = 0) or 8(if SCDx8 = 1), 0: SYSCLK is not divided
#define SSACD_ACDS(x)                   ((x&0x7) << 0)      // Audio clock divider select

#define SSACR_ACPS_5622                 0x0
#define SSACR_ACPS_11345                0x1
#define SSACR_ACPS_12235                0x2
#define SSACR_ACPS_14857                0x3
#define SSACR_ACPS_32842                0x4
#define SSACR_ACPS_48000                0x5
#define SSACR_ACPS_DITHER               0x6

#define SSACR_ACDS_1                    0x0
#define SSACR_ACDS_2                    0x1
#define SSACR_ACDS_4                    0x2
#define SSACR_ACDS_8                    0x3
#define SSACR_ACDS_16                   0x4
#define SSACR_ACDS_32                   0x5

#define SSSR_TNF                        (1u << 2)           // 0: TXFIFO is full, 1: TXFIFO is not full
#define SSSR_RNE                        (1u << 3)           // 0: RXFIFO is empty, 1: RXFIFO is not empty
#define SSSR_TFL(x)                     ((x&0xF) << 8)      // number of entries in TXFIFO, when is 0x0, TXFIFO is either empty or full
#define SSSR_RFL(x)                     ((x&0xF) << 12)     // number of entries in RXFIFO, when is 0xF, RXFIFO is either empty or full
#define SSSR_BSY                        (1u << 4)           // 0: SSP is idle or disable, 1: SSP is Transmitting or Receiving Frame Data

#define SSTO_TIMEOUT(x)                 (x&0xFFFFFF)

#define SSACDD_NUM(x)                   ((x&0x7FFF) << 16)
#define SSACDD_DEN(x)                   ((x&0xFFF) << 0)

/*
    PIN
*/

#define MFPR_PULL_SEL                   (1 << 15)
#define MFPR_PULL_UP                    (1 << 14)
#define MFPR_PULL_DOWN                  (1 << 13)
#define MFPR_DRIVE_F01mA                (0 << 10)
#define MFPR_DRIVE_F02mA                (1 << 10)
#define MFPR_DRIVE_F03mA                (2 << 10)
#define MFPR_DRIVE_F04mA                (3 << 10)
#define MFPR_DRIVE_S06mA                (4 << 10)
#define MFPR_DRIVE_F06mA                (5 << 10)
#define MFPR_DRIVE_S10mA                (6 << 10)
#define MFPR_DRIVE_F10mA                (7 << 10)
#define MFPR_SLEEP_SEL                  (1 << 9)
#define MFPR_SLEEP_OUTPUT_LO            (0 << 8)
#define MFPR_SLEEP_OUTPUT_HI            (1 << 8)
#define MFPR_SLEEP_OUTPUT               (0 << 7)
#define MFPR_SLEEP_INPUT                (1 << 7)
#define MFPR_EDGE_CLEAR                 (1 << 6)
#define MFPR_EDGE_FALL                  (1 << 5)
#define MFPR_EDGE_RISE                  (1 << 4)

/* PIN function locked by ASCR[RDH] for D3 to D0 state */
#define MFPR_FUNC_D3_to_D0_LOCK         MFPR_SLEEP_SEL
#define MFPR_FUNC_D3_to_D0_AUTO_UNLOCK  0

/* Run time Pull resistor enable or not */
#define MFPR_FUNC_PULL_DIS_at_RUN       0
#define MFPR_FUNC_PULL_EN_at_RUN        MFPR_PULL_SEL

/* Pull resistor setting for Run & Sleep */
#define MFPR_FUNC_PULL_NONE             0
#define MFPR_FUNC_PULL_HI               MFPR_PULL_UP
#define MFPR_FUNC_PULL_LO               MFPR_PULL_DOWN

/* Low Power Mode (LPM) PIN Direction */
#define MFPR_FUNC_LPMIO_INPUT           MFPR_SLEEP_INPUT
#define MFPR_FUNC_LPMIO_OUTPUT_LO       MFPR_SLEEP_OUTPUT | MFPR_SLEEP_OUTPUT_LO
#define MFPR_FUNC_LPMIO_OUTPUT_HI       MFPR_SLEEP_OUTPUT | MFPR_SLEEP_OUTPUT_HI

/* Edge detect */
/* EDGE_FALL & EDGE_RISE: The pad need NOT be an input */
#if 0
/*
    !!! OR 'MFPR_EDGE_CLEAR' !!! because we need to clear the EDGE detect flag at the beginning
    But the result is not exactly what we want!!!
    When we set this flag at PIN initial, event we invoke PIN_ClearEdgeFlag, the Wake Up event will never happen!!!
*/
#define MFPR_FUNC_EDGE_DETECT_NONE      (MFPR_EDGE_CLEAR | 0)
#define MFPR_FUNC_EDGE_DETECT_FALL      (MFPR_EDGE_CLEAR | MFPR_EDGE_FALL)
#define MFPR_FUNC_EDGE_DETECT_RISE      (MFPR_EDGE_CLEAR | MFPR_EDGE_RISE)
#define MFPR_FUNC_EDGE_DETECT_BOTH      (MFPR_EDGE_CLEAR | MFPR_EDGE_RISE | MFPR_EDGE_FALL)
#else
#define MFPR_FUNC_EDGE_DETECT_NONE      (MFPR_EDGE_CLEAR)
#define MFPR_FUNC_EDGE_DETECT_FALL      (MFPR_EDGE_FALL)
#define MFPR_FUNC_EDGE_DETECT_RISE      (MFPR_EDGE_RISE)
#define MFPR_FUNC_EDGE_DETECT_BOTH      (MFPR_EDGE_RISE | MFPR_EDGE_FALL)
#endif

