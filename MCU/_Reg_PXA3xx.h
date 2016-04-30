
//*****************************************************************************
//    Monahans Register Addess Definitions
//*****************************************************************************

#define     MH_REG_BASE         0x40000000

//
// GPIO Registers
//
#define     MH_GPLR0            (volatile U32 *)(MH_REG_BASE + 0x00E00000)      // GPIO Pin Level register GPIO[31:0]
#define     MH_GPLR1            (volatile U32 *)(MH_REG_BASE + 0x00E00004)      // GPIO Pin Level register GPIO[63:32]
#define     MH_GPLR2            (volatile U32 *)(MH_REG_BASE + 0x00E00008)      // GPIO Pin Level register GPIO[95:64]
#define     MH_GPLR3            (volatile U32 *)(MH_REG_BASE + 0x00E00100)      // GPIO Pin Level register GPIO[127:96]

#define     MH_GPDR0            (volatile U32 *)(MH_REG_BASE + 0x00E0000C)      // GPIO Pin Direction register GPIO[31:0]
#define     MH_GPDR1            (volatile U32 *)(MH_REG_BASE + 0x00E00010)      // GPIO Pin Direction register GPIO[63:32]
#define     MH_GPDR2            (volatile U32 *)(MH_REG_BASE + 0x00E00014)      // GPIO Pin Direction register GPIO[95:64]
#define     MH_GPDR3            (volatile U32 *)(MH_REG_BASE + 0x00E0010C)      // GPIO Pin Direction register GPIO[127:96]

#define     MH_GPSR0            (volatile U32 *)(MH_REG_BASE + 0x00E00018)      // GPIO Pin Output Set register GPIO[31:0]
#define     MH_GPSR1            (volatile U32 *)(MH_REG_BASE + 0x00E0001C)      // GPIO Pin Output Set register GPIO[63:32]
#define     MH_GPSR2            (volatile U32 *)(MH_REG_BASE + 0x00E00020)      // GPIO Pin Output Set register GPIO[95:64]
#define     MH_GPSR3            (volatile U32 *)(MH_REG_BASE + 0x00E00118)      // GPIO Pin Output Set register GPIO[127:96]

#define     MH_GPCR0            (volatile U32 *)(MH_REG_BASE + 0x00E00024)      // GPIO Pin Output Clear register GPIO[31:0]
#define     MH_GPCR1            (volatile U32 *)(MH_REG_BASE + 0x00E00028)      // GPIO Pin Output Clear register GPIO[63:32]
#define     MH_GPCR2            (volatile U32 *)(MH_REG_BASE + 0x00E0002C)      // GPIO pin Output Clear register GPIO[95:64]
#define     MH_GPCR3            (volatile U32 *)(MH_REG_BASE + 0x00E00124)      // GPIO Pin Output Clear register GPIO[127:96]

#define     MH_GRER0            (volatile U32 *)(MH_REG_BASE + 0x00E00030)      // GPIO Rising-Edge Detect Enable register GPIO[31:0]
#define     MH_GRER1            (volatile U32 *)(MH_REG_BASE + 0x00E00034)      // GPIO Rising-Edge Detect Enable register GPIO[63:32]
#define     MH_GRER2            (volatile U32 *)(MH_REG_BASE + 0x00E00038)      // GPIO Rising-Edge Detect Enable register GPIO[95:64]
#define     MH_GRER3            (volatile U32 *)(MH_REG_BASE + 0x00E00130)      // GPIO Rising-Edge Detect Enable register GPIO[127:96]

#define     MH_GFER0            (volatile U32 *)(MH_REG_BASE + 0x00E0003C)      // GPIO Falling-Edge Detect Enable register GPIO[31:0]
#define     MH_GFER1            (volatile U32 *)(MH_REG_BASE + 0x00E00040)      // GPIO Falling-Edge Detect Enable register GPIO[63:32]
#define     MH_GFER2            (volatile U32 *)(MH_REG_BASE + 0x00E00044)      // GPIO Falling-Edge Detect Enable register GPIO[95:64]
#define     MH_GFER3            (volatile U32 *)(MH_REG_BASE + 0x00E0013C)      // GPIO Falling-Edge Detect Enable register GPIO[127:96]

#define     MH_GEDR0            (volatile U32 *)(MH_REG_BASE + 0x00E00048)      // GPIO Edge Detect Status register GPIO[31:0]
#define     MH_GEDR1            (volatile U32 *)(MH_REG_BASE + 0x00E0004C)      // GPIO Edge Detect Status register GPIO[63:32]
#define     MH_GEDR2            (volatile U32 *)(MH_REG_BASE + 0x00E00050)      // GPIO Edge Detect Status register GPIO[95:64]
#define     MH_GEDR3            (volatile U32 *)(MH_REG_BASE + 0x00E00148)      // GPIO Edge Detect Status register GPIO[127:96]

#define     MH_GSDR0            (volatile U32 *)(MH_REG_BASE + 0x00E00400)      // Bit-wise Set of GPIO Direction register GPDR [31:0]
#define     MH_GSDR1            (volatile U32 *)(MH_REG_BASE + 0x00E00404)      // Bit-wise Set of GPIO Direction register GPDR [63:32]
#define     MH_GSDR2            (volatile U32 *)(MH_REG_BASE + 0x00E00408)      // Bit-wise Set of GPIO Direction register GPDR [95:64]
#define     MH_GSDR3            (volatile U32 *)(MH_REG_BASE + 0x00E0040C)      // Bit-wise Set of GPIO Direction register GPDR [127:96]

#define     MH_GCDR0            (volatile U32 *)(MH_REG_BASE + 0x00E00420)      // Bit-wise Clear of GPIO Direction register GPDR [31:0]
#define     MH_GCDR1            (volatile U32 *)(MH_REG_BASE + 0x00E00424)      // Bit-wise Clear of GPIO Direction register GPDR [63:32]
#define     MH_GCDR2            (volatile U32 *)(MH_REG_BASE + 0x00E00428)      // Bit-wise Clear of GPIO Direction register GPDR [95:64]
#define     MH_GCDR3            (volatile U32 *)(MH_REG_BASE + 0x00E0042C)      // Bit-wise Clear of GPIO Direction register GPDR [127:96]

#define     MH_GSRER0           (volatile U32 *)(MH_REG_BASE + 0x00E00440)      // Bit-wise Set of GPIO Rising Edge Detect Enable register GRER [31:0]
#define     MH_GSRER1           (volatile U32 *)(MH_REG_BASE + 0x00E00444)      // Bit-wise Set of GPIO Rising Edge Detect Enable register GRER [63:32]
#define     MH_GSRER2           (volatile U32 *)(MH_REG_BASE + 0x00E00448)      // Bit-wise Set of GPIO Rising Edge Detect Enable register GRER [95:64]
#define     MH_GSRER3           (volatile U32 *)(MH_REG_BASE + 0x00E0044C)      // Bit-wise Set of GPIO Rising Edge Detect Enable register GRER [127:96]

#define     MH_GCRER0           (volatile U32 *)(MH_REG_BASE + 0x00E00460)      // Bit-wise Clear of GPIO Rising Edge Detect Enable register GRER [31:0]
#define     MH_GCRER1           (volatile U32 *)(MH_REG_BASE + 0x00E00464)      // Bit-wise Clear of GPIO Rising Edge Detect Enable register GRER [63:32]
#define     MH_GCRER2           (volatile U32 *)(MH_REG_BASE + 0x00E00468)      // Bit-wise Clear of GPIO Rising Edge Detect Enable register GRER [95:64]
#define     MH_GCRER3           (volatile U32 *)(MH_REG_BASE + 0x00E0046C)      // Bit-wise Clear of GPIO Rising Edge Detect Enable register GRER [127:96]

#define     MH_GSFER0           (volatile U32 *)(MH_REG_BASE + 0x00E00480)      // Bit-wise Set of GPIO Falling Edge Detect Enable register GRER [31:0]
#define     MH_GSFER1           (volatile U32 *)(MH_REG_BASE + 0x00E00484)      // Bit-wise Set of GPIO Falling Edge Detect Enable register GRER [63:32]
#define     MH_GSFER2           (volatile U32 *)(MH_REG_BASE + 0x00E00488)      // Bit-wise Set of GPIO Falling Edge Detect Enable register GRER [95:64]
#define     MH_GSFER3           (volatile U32 *)(MH_REG_BASE + 0x00E0048C)      // Bit-wise Set of GPIO Falling Edge Detect Enable register GRER [127:96]

#define     MH_GCFER0           (volatile U32 *)(MH_REG_BASE + 0x00E004A0)      // Bit-wise Clear of GPIO Falling Edge Detect Enable register GRER [31:0]
#define     MH_GCFER1           (volatile U32 *)(MH_REG_BASE + 0x00E004A4)      // Bit-wise Clear of GPIO Falling Edge Detect Enable register GRER [63:32]
#define     MH_GCFER2           (volatile U32 *)(MH_REG_BASE + 0x00E004A8)      // Bit-wise Clear of GPIO Falling Edge Detect Enable register GRER [95:64]
#define     MH_GCFER3           (volatile U32 *)(MH_REG_BASE + 0x00E004AC)      // Bit-wise Clear of GPIO Falling Edge Detect Enable register GRER [127:96]

//
// Services unit clock control unit
//
#define     MH_OSCC             (volatile U32 *)(MH_REG_BASE + 0x01350000)      // Oscillator Configuration register

//
// Slave clock control unit
//
#define     MH_ACCR             (volatile U32 *)(MH_REG_BASE + 0x01340000)      // Application Subsystem Clock Configuration register
#define     MH_ACSR             (volatile U32 *)(MH_REG_BASE + 0x01340004)      // Application Subsystem Clock Status register
#define     MH_AICSR            (volatile U32 *)(MH_REG_BASE + 0x01340008)      // Application Subsystem Interrupt Control/Status register
#define     MH_D0CKENA          (volatile U32 *)(MH_REG_BASE + 0x0134000C)      // D0 Mode Clock Enable register A
#define     MH_D0CKENB          (volatile U32 *)(MH_REG_BASE + 0x01340010)      // D0 Mode Clock Enable register B
#define     MH_AC97DIV          (volatile U32 *)(MH_REG_BASE + 0x01340014)      // AC ?бе97 Clock Divisor Value register

//
// Services unit power management unit
//
#define     MH_PMCR             (volatile U32 *)(MH_REG_BASE + 0x00F50000)      // Power Management Unit Control register
#define     MH_PSR              (volatile U32 *)(MH_REG_BASE + 0x00F50004)      // Power Management Unit S2 Status register
#define     MH_PSPR             (volatile U32 *)(MH_REG_BASE + 0x00F50008)      // Power Management Unit Scratch Pad register
#define     MH_PCFR             (volatile U32 *)(MH_REG_BASE + 0x00F5000C)      // Power Management Unit General Configuration register
#define     MH_PWER             (volatile U32 *)(MH_REG_BASE + 0x00F50010)      // Power Manager Wake-Up Enable register
#define     MH_PWSR             (volatile U32 *)(MH_REG_BASE + 0x00F50014)      // Power Manager Wake-Up Status register
#define     MH_PECR             (volatile U32 *)(MH_REG_BASE + 0x00F50018)      // Power Manager EXTWAKEUP[1:0] Control register
#define     MH_PVCR             (volatile U32 *)(MH_REG_BASE + 0x00F50100)      // Power Management Unit Voltage Change Control register

#define     PWSR_EERTC          (1u << 31)                                      // S2 or S3 wakeup from RTC
#define     PWSR_WEF            (1u << 2)                                       // S2 or S3 wakeup from EXT_WAKEUP<0> due to FALLING -edge detect
#define     PWSR_WER            (1u << 0)                                       // S2 or S3 wakeup from EXT_WAKEUP<0> due to RISING  -edge detect

//
// Slave power management unit
//
#define     MH_ASCR             (volatile U32 *)(MH_REG_BASE + 0x00F40000)      // Application Subsystem Power Status/Configuration register
#define     MH_ARSR             (volatile U32 *)(MH_REG_BASE + 0x00F40004)      // Application Subsystem Reset Status register
#define     MH_AD3ER            (volatile U32 *)(MH_REG_BASE + 0x00F40008)      // Application Subsystem D3 State Wake-Up Enable register
#define     MH_AD3SR            (volatile U32 *)(MH_REG_BASE + 0x00F4000C)      // Application Subsystem D3 State Wake-up Status register
#define     MH_AD2D0ER          (volatile U32 *)(MH_REG_BASE + 0x00F40010)      // Application Subsystem D2 to D0 State Wake-Up Enable register
#define     MH_AD2D0SR          (volatile U32 *)(MH_REG_BASE + 0x00F40014)      // Application Subsystem D2 to D0 State Wake-Up Status register
#define     MH_AD2D1ER          (volatile U32 *)(MH_REG_BASE + 0x00F40018)      // Application Subsystem D2 to D1 State Wake-Up Enable register
#define     MH_AD2D1SR          (volatile U32 *)(MH_REG_BASE + 0x00F4001C)      // Application Subsystem D2 to D1 State Wake-Up Status register
#define     MH_AD1D0ER          (volatile U32 *)(MH_REG_BASE + 0x00F40020)      // Application Subsystem D1 to D0 State Wake-Up Enable register
#define     MH_AD1D0SR          (volatile U32 *)(MH_REG_BASE + 0x00F40024)      // Application Subsystem D1 to D0 State Wake-Up Status register
#define     MH_AD3R             (volatile U32 *)(MH_REG_BASE + 0x00F40030)      // Application Subsystem D3 State Configuration register
#define     MH_AD2R             (volatile U32 *)(MH_REG_BASE + 0x00F40034)      // Application Subsystem D2 State Configuration register
#define     MH_AD1R             (volatile U32 *)(MH_REG_BASE + 0x00F40038)      // Application Subsystem D1 State Configuration register

//
// 1-Wire Bus Master Interface
//
#define     MH_W1CMDR           (volatile U32 *)(MH_REG_BASE + 0x01B00000)      // 1-Wire Command register
#define     MH_W1TRR            (volatile U32 *)(MH_REG_BASE + 0x01B00004)      // 1-Wire Transmit/Receive buffer
#define     MH_W1INTR           (volatile U32 *)(MH_REG_BASE + 0x01B00008)      // 1-Wire Interrupt register
#define     MH_W1IER            (volatile U32 *)(MH_REG_BASE + 0x01B0000C)      // 1-Wire Interrupt Enable register
#define     MH_W1CDR            (volatile U32 *)(MH_REG_BASE + 0x01B00010)      // 1-Wire Clock Divisor register

//
// DMA Controller
//
#define     MH_DCSR0            (volatile U32 *)(MH_REG_BASE + 0x00000000)      // DMA Control / Status register for channel 0
#define     MH_DCSR1            (volatile U32 *)(MH_REG_BASE + 0x00000004)      // DMA Control / Status register for channel 1
#define     MH_DCSR2            (volatile U32 *)(MH_REG_BASE + 0x00000008)      // DMA Control / Status register for channel 2
#define     MH_DCSR3            (volatile U32 *)(MH_REG_BASE + 0x0000000C)      // DMA Control / Status register for channel 3
#define     MH_DCSR4            (volatile U32 *)(MH_REG_BASE + 0x00000010)      // DMA Control / Status register for channel 4
#define     MH_DCSR5            (volatile U32 *)(MH_REG_BASE + 0x00000014)      // DMA Control / Status register for channel 5
#define     MH_DCSR6            (volatile U32 *)(MH_REG_BASE + 0x00000018)      // DMA Control / Status register for channel 6
#define     MH_DCSR7            (volatile U32 *)(MH_REG_BASE + 0x0000001C)      // DMA Control / Status register for channel 7
#define     MH_DCSR8            (volatile U32 *)(MH_REG_BASE + 0x00000020)      // DMA Control / Status register for channel 8
#define     MH_DCSR9            (volatile U32 *)(MH_REG_BASE + 0x00000024)      // DMA Control / Status register for channel 9
#define     MH_DCSR10           (volatile U32 *)(MH_REG_BASE + 0x00000028)      // DMA Control / Status register for channel 10
#define     MH_DCSR11           (volatile U32 *)(MH_REG_BASE + 0x0000002C)      // DMA Control / Status register for channel 11
#define     MH_DCSR12           (volatile U32 *)(MH_REG_BASE + 0x00000030)      // DMA Control / Status register for channel 12
#define     MH_DCSR13           (volatile U32 *)(MH_REG_BASE + 0x00000034)      // DMA Control / Status register for channel 13
#define     MH_DCSR14           (volatile U32 *)(MH_REG_BASE + 0x00000038)      // DMA Control / Status register for channel 14
#define     MH_DCSR15           (volatile U32 *)(MH_REG_BASE + 0x0000003C)      // DMA Control / Status register for channel 15
#define     MH_DCSR16           (volatile U32 *)(MH_REG_BASE + 0x00000040)      // DMA Control / Status register for channel 16
#define     MH_DCSR17           (volatile U32 *)(MH_REG_BASE + 0x00000044)      // DMA Control / Status register for channel 17
#define     MH_DCSR18           (volatile U32 *)(MH_REG_BASE + 0x00000048)      // DMA Control / Status register for channel 18
#define     MH_DCSR19           (volatile U32 *)(MH_REG_BASE + 0x0000004C)      // DMA Control / Status register for channel 19
#define     MH_DCSR20           (volatile U32 *)(MH_REG_BASE + 0x00000050)      // DMA Control / Status register for channel 20
#define     MH_DCSR21           (volatile U32 *)(MH_REG_BASE + 0x00000054)      // DMA Control / Status register for channel 21
#define     MH_DCSR22           (volatile U32 *)(MH_REG_BASE + 0x00000058)      // DMA Control / Status register for channel 22
#define     MH_DCSR23           (volatile U32 *)(MH_REG_BASE + 0x0000005C)      // DMA Control / Status register for channel 23
#define     MH_DCSR24           (volatile U32 *)(MH_REG_BASE + 0x00000060)      // DMA Control / Status register for channel 24
#define     MH_DCSR25           (volatile U32 *)(MH_REG_BASE + 0x00000064)      // DMA Control / Status register for channel 25
#define     MH_DCSR26           (volatile U32 *)(MH_REG_BASE + 0x00000068)      // DMA Control / Status register for channel 26
#define     MH_DCSR27           (volatile U32 *)(MH_REG_BASE + 0x0000006C)      // DMA Control / Status register for channel 27
#define     MH_DCSR28           (volatile U32 *)(MH_REG_BASE + 0x00000070)      // DMA Control / Status register for channel 28
#define     MH_DCSR29           (volatile U32 *)(MH_REG_BASE + 0x00000074)      // DMA Control / Status register for channel 29
#define     MH_DCSR30           (volatile U32 *)(MH_REG_BASE + 0x00000078)      // DMA Control / Status register for channel 30
#define     MH_DCSR31           (volatile U32 *)(MH_REG_BASE + 0x0000007C)      // DMA Control / Status register for channel 31

#define     MH_DALGN            (volatile U32 *)(MH_REG_BASE + 0x000000A0)      // DMA alignment register
#define     MH_DPCSR            (volatile U32 *)(MH_REG_BASE + 0x000000A4)      // DMA Programmed IO control status register
#define     MH_DRQSR0           (volatile U32 *)(MH_REG_BASE + 0x000000E0)      // DMA DREQ Status register
#define     MH_DINT             (volatile U32 *)(MH_REG_BASE + 0x000000F0)      // DMA Interrupt register

#define     MH_DRCMR0           (volatile U32 *)(MH_REG_BASE + 0x00000100)      // Request to Channel Map register for DREQ
#define     MH_DRCMR2           (volatile U32 *)(MH_REG_BASE + 0x00000108)      // Request to Channel Map register for SSP4 receive request
#define     MH_DRCMR3           (volatile U32 *)(MH_REG_BASE + 0x0000010C)      // Request to Channel Map register for SSP4 transmit request
#define     MH_DRCMR4           (volatile U32 *)(MH_REG_BASE + 0x00000110)      // Request to Channel Map register for UART2 receive request
#define     MH_DRCMR5           (volatile U32 *)(MH_REG_BASE + 0x00000114)      // Request to Channel Map register for UART2 transmit request.
#define     MH_DRCMR6           (volatile U32 *)(MH_REG_BASE + 0x00000118)      // Request to Channel Map register for UART1 receive request
#define     MH_DRCMR7           (volatile U32 *)(MH_REG_BASE + 0x0000011C)      // Request to Channel Map register for UART1 transmit request
#define     MH_DRCMR8           (volatile U32 *)(MH_REG_BASE + 0x00000120)      // Request to Channel Map register for AC97 microphone request
#define     MH_DRCMR9           (volatile U32 *)(MH_REG_BASE + 0x00000124)      // Request to Channel Map register for AC97 modem receive request
#define     MH_DRCMR10          (volatile U32 *)(MH_REG_BASE + 0x00000128)      // Request to Channel Map register for AC97 modem transmit request
#define     MH_DRCMR11          (volatile U32 *)(MH_REG_BASE + 0x0000012C)      // Request to Channel Map register for AC97 audio receive request
#define     MH_DRCMR12          (volatile U32 *)(MH_REG_BASE + 0x00000130)      // Request to Channel Map register for AC97 audio transmit request
#define     MH_DRCMR13          (volatile U32 *)(MH_REG_BASE + 0x00000134)      // Request to Channel Map register for SSP1 receive request
#define     MH_DRCMR14          (volatile U32 *)(MH_REG_BASE + 0x00000138)      // Request to Channel Map register for SSP1 transmit request
#define     MH_DRCMR15          (volatile U32 *)(MH_REG_BASE + 0x0000013C)      // Request to Channel Map register for SSP2 receive request
#define     MH_DRCMR16          (volatile U32 *)(MH_REG_BASE + 0x00000140)      // Request to Channel Map register for SSP2 transmit request
#define     MH_DRCMR19          (volatile U32 *)(MH_REG_BASE + 0x0000014C)      // Request to Channel Map register for UART3 receive request
#define     MH_DRCMR20          (volatile U32 *)(MH_REG_BASE + 0x00000150)      // Request to Channel Map register for UART3 transmit request
#define     MH_DRCMR21          (volatile U32 *)(MH_REG_BASE + 0x00000154)      // Request to Channel Map register for MMC/SDIO 1 receive request
#define     MH_DRCMR22          (volatile U32 *)(MH_REG_BASE + 0x00000158)      // Request to Channel Map register for MMC/SDIO 1 transmit request
#define     MH_DRCMR24          (volatile U32 *)(MH_REG_BASE + 0x00000160)      // Request to Channel Map register for USB endpoint 0 request
#define     MH_DRCMR25          (volatile U32 *)(MH_REG_BASE + 0x00000164)      // Request to Channel Map register for USB endpoint A request
#define     MH_DRCMR26          (volatile U32 *)(MH_REG_BASE + 0x00000168)      // Request to Channel Map register for USB endpoint B request
#define     MH_DRCMR27          (volatile U32 *)(MH_REG_BASE + 0x0000016C)      // Request to Channel Map register for USB endpoint C request
#define     MH_DRCMR28          (volatile U32 *)(MH_REG_BASE + 0x00000170)      // Request to Channel Map register for USB endpoint D request
#define     MH_DRCMR29          (volatile U32 *)(MH_REG_BASE + 0x00000174)      // Request to Channel Map register for USB endpoint E request
#define     MH_DRCMR30          (volatile U32 *)(MH_REG_BASE + 0x00000178)      // Request to Channel Map register for USB endpoint F request
#define     MH_DRCMR31          (volatile U32 *)(MH_REG_BASE + 0x0000017C)      // Request to Channel Map register for USB endpoint G request
#define     MH_DRCMR32          (volatile U32 *)(MH_REG_BASE + 0x00000180)      // Request to Channel Map register for USB endpoint H request
#define     MH_DRCMR33          (volatile U32 *)(MH_REG_BASE + 0x00000184)      // Request to Channel Map register for USB endpoint I request
#define     MH_DRCMR34          (volatile U32 *)(MH_REG_BASE + 0x00000188)      // Request to Channel Map register for USB endpoint J request
#define     MH_DRCMR35          (volatile U32 *)(MH_REG_BASE + 0x0000018C)      // Request to Channel Map register for USB endpoint K request
#define     MH_DRCMR36          (volatile U32 *)(MH_REG_BASE + 0x00000190)      // Request to Channel Map register for USB endpoint L request
#define     MH_DRCMR37          (volatile U32 *)(MH_REG_BASE + 0x00000194)      // Request to Channel Map register for USB endpoint M request
#define     MH_DRCMR38          (volatile U32 *)(MH_REG_BASE + 0x00000198)      // Request to Channel Map register for USB endpoint N request
#define     MH_DRCMR39          (volatile U32 *)(MH_REG_BASE + 0x0000019C)      // Request to Channel Map register for USB endpoint P request
#define     MH_DRCMR40          (volatile U32 *)(MH_REG_BASE + 0x000001A0)      // Request to Channel Map register for USB endpoint Q request
#define     MH_DRCMR41          (volatile U32 *)(MH_REG_BASE + 0x000001A4)      // Request to Channel Map register for USB endpoint R request
#define     MH_DRCMR42          (volatile U32 *)(MH_REG_BASE + 0x000001A8)      // Request to Channel Map register for USB endpoint S request
#define     MH_DRCMR43          (volatile U32 *)(MH_REG_BASE + 0x000001AC)      // Request to Channel Map register for USB endpoint T request
#define     MH_DRCMR44          (volatile U32 *)(MH_REG_BASE + 0x000001B0)      // Request to Channel Map register for USB endpoint U request
#define     MH_DRCMR45          (volatile U32 *)(MH_REG_BASE + 0x000001B4)      // Request to Channel Map register for USB endpoint V request
#define     MH_DRCMR46          (volatile U32 *)(MH_REG_BASE + 0x000001B8)      // Request to Channel Map register for USB endpoint W request
#define     MH_DRCMR47          (volatile U32 *)(MH_REG_BASE + 0x000001BC)      // Request to Channel Map register for USB endpoint X request
#define     MH_DRCMR48          (volatile U32 *)(MH_REG_BASE + 0x000001C0)      // Request to Channel Map register for MSL receive request 1
#define     MH_DRCMR49          (volatile U32 *)(MH_REG_BASE + 0x000001C4)      // Request to Channel Map register for MSL transmit request 1
#define     MH_DRCMR50          (volatile U32 *)(MH_REG_BASE + 0x000001C8)      // Request to Channel Map register for MSL receive request 2
#define     MH_DRCMR51          (volatile U32 *)(MH_REG_BASE + 0x000001CC)      // Request to Channel Map register for MSL transmit request 2
#define     MH_DRCMR52          (volatile U32 *)(MH_REG_BASE + 0x000001D0)      // Request to Channel Map register for MSL receive request 3
#define     MH_DRCMR53          (volatile U32 *)(MH_REG_BASE + 0x000001D4)      // Request to Channel Map register for MSL transmit request 3
#define     MH_DRCMR54          (volatile U32 *)(MH_REG_BASE + 0x000001D8)      // Request to Channel Map register for MSL receive request 4
#define     MH_DRCMR55          (volatile U32 *)(MH_REG_BASE + 0x000001DC)      // Request to Channel Map register for MSL transmit request 4
#define     MH_DRCMR56          (volatile U32 *)(MH_REG_BASE + 0x000001E0)      // Request to Channel Map register for MSL receive request 5
#define     MH_DRCMR57          (volatile U32 *)(MH_REG_BASE + 0x000001E4)      // Request to Channel Map register for MSL transmit request 5
#define     MH_DRCMR58          (volatile U32 *)(MH_REG_BASE + 0x000001E8)      // Request to Channel Map register for MSL receive request 6
#define     MH_DRCMR59          (volatile U32 *)(MH_REG_BASE + 0x000001EC)      // Request to Channel Map register for MSL transmit request 6
#define     MH_DRCMR60          (volatile U32 *)(MH_REG_BASE + 0x000001F0)      // Request to Channel Map register for MSL receive request 7
#define     MH_DRCMR61          (volatile U32 *)(MH_REG_BASE + 0x000001F4)      // Request to Channel Map register for MSL transmit request 7
#define     MH_DRCMR62          (volatile U32 *)(MH_REG_BASE + 0x000001F8)      // Request to Channel Map register for USIM 1 receive request
#define     MH_DRCMR63          (volatile U32 *)(MH_REG_BASE + 0x000001FC)      // Request to Channel Map register for USIM 1 transmit request

#define     MH_DDADR0           (volatile U32 *)(MH_REG_BASE + 0x00000200)      // DMA Descriptor Address register channel 0
#define     MH_DSADR0           (volatile U32 *)(MH_REG_BASE + 0x00000204)      // DMA Source Address register channel 0
#define     MH_DTADR0           (volatile U32 *)(MH_REG_BASE + 0x00000208)      // DMA Target Address register channel 0
#define     MH_DCMD0            (volatile U32 *)(MH_REG_BASE + 0x0000020C)      // DMA Command Address register channel 0
#define     MH_DDADR1           (volatile U32 *)(MH_REG_BASE + 0x00000210)      // DMA Descriptor Address register channel 1
#define     MH_DSADR1           (volatile U32 *)(MH_REG_BASE + 0x00000214)      // DMA Source Address register channel 1
#define     MH_DTADR1           (volatile U32 *)(MH_REG_BASE + 0x00000218)      // DMA Target Address register channel 1
#define     MH_DCMD1            (volatile U32 *)(MH_REG_BASE + 0x0000021C)      // DMA Command Address register channel 1
#define     MH_DDADR2           (volatile U32 *)(MH_REG_BASE + 0x00000220)      // DMA Descriptor Address register channel 2
#define     MH_DSADR2           (volatile U32 *)(MH_REG_BASE + 0x00000224)      // DMA Source Address register channel 2
#define     MH_DTADR2           (volatile U32 *)(MH_REG_BASE + 0x00000228)      // DMA Target Address register channel 2
#define     MH_DCMD2            (volatile U32 *)(MH_REG_BASE + 0x0000022C)      // DMA Command Address register channel 2
#define     MH_DDADR3           (volatile U32 *)(MH_REG_BASE + 0x00000230)      // DMA Descriptor Address register channel 3
#define     MH_DSADR3           (volatile U32 *)(MH_REG_BASE + 0x00000234)      // DMA Source Address register channel 3
#define     MH_DTADR3           (volatile U32 *)(MH_REG_BASE + 0x00000238)      // DMA Target Address register channel 3
#define     MH_DCMD3            (volatile U32 *)(MH_REG_BASE + 0x0000023C)      // DMA Command Address register channel 3
#define     MH_DDADR4           (volatile U32 *)(MH_REG_BASE + 0x00000240)      // DMA Descriptor Address register channel 4
#define     MH_DSADR4           (volatile U32 *)(MH_REG_BASE + 0x00000244)      // DMA Source Address register channel 4
#define     MH_DTADR4           (volatile U32 *)(MH_REG_BASE + 0x00000248)      // DMA Target Address register channel 4
#define     MH_DCMD4            (volatile U32 *)(MH_REG_BASE + 0x0000024C)      // DMA Command Address register channel 4
#define     MH_DDADR5           (volatile U32 *)(MH_REG_BASE + 0x00000250)      // DMA Descriptor Address register channel 5
#define     MH_DSADR5           (volatile U32 *)(MH_REG_BASE + 0x00000254)      // DMA Source Address register channel 5
#define     MH_DTADR5           (volatile U32 *)(MH_REG_BASE + 0x00000258)      // DMA Target Address register channel 5
#define     MH_DCMD5            (volatile U32 *)(MH_REG_BASE + 0x0000025C)      // DMA Command Address register channel 5
#define     MH_DDADR6           (volatile U32 *)(MH_REG_BASE + 0x00000260)      // DMA Descriptor Address register channel 6
#define     MH_DSADR6           (volatile U32 *)(MH_REG_BASE + 0x00000264)      // DMA Source Address register channel 6
#define     MH_DTADR6           (volatile U32 *)(MH_REG_BASE + 0x00000268)      // DMA Target Address register channel 6
#define     MH_DCMD6            (volatile U32 *)(MH_REG_BASE + 0x0000026C)      // DMA Command Address register channel 6
#define     MH_DDADR7           (volatile U32 *)(MH_REG_BASE + 0x00000270)      // DMA Descriptor Address register channel 7
#define     MH_DSADR7           (volatile U32 *)(MH_REG_BASE + 0x00000274)      // DMA Source Address register channel 7
#define     MH_DTADR7           (volatile U32 *)(MH_REG_BASE + 0x00000278)      // DMA Target Address register channel 7
#define     MH_DCMD7            (volatile U32 *)(MH_REG_BASE + 0x0000027C)      // DMA Command Address register channel 7
#define     MH_DDADR8           (volatile U32 *)(MH_REG_BASE + 0x00000280)      // DMA Descriptor Address register channel 8
#define     MH_DSADR8           (volatile U32 *)(MH_REG_BASE + 0x00000284)      // DMA Source Address register channel 8
#define     MH_DTADR8           (volatile U32 *)(MH_REG_BASE + 0x00000288)      // DMA Target Address register channel 8
#define     MH_DCMD8            (volatile U32 *)(MH_REG_BASE + 0x0000028C)      // DMA Command Address register channel 8
#define     MH_DDADR9           (volatile U32 *)(MH_REG_BASE + 0x00000290)      // DMA Descriptor Address register channel 9
#define     MH_DSADR9           (volatile U32 *)(MH_REG_BASE + 0x00000294)      // DMA Source Address register channel 9
#define     MH_DTADR9           (volatile U32 *)(MH_REG_BASE + 0x00000298)      // DMA Target Address register channel 9
#define     MH_DCMD9            (volatile U32 *)(MH_REG_BASE + 0x0000029C)      // DMA Command Address register channel 9
#define     MH_DDADR10          (volatile U32 *)(MH_REG_BASE + 0x000002A0)      // DMA Descriptor Address register channel 10
#define     MH_DSADR10          (volatile U32 *)(MH_REG_BASE + 0x000002A4)      // DMA Source Address register channel 10
#define     MH_DTADR10          (volatile U32 *)(MH_REG_BASE + 0x000002A8)      // DMA Target Address register channel 10
#define     MH_DCMD10           (volatile U32 *)(MH_REG_BASE + 0x000002AC)      // DMA Command Address register channel 10
#define     MH_DDADR11          (volatile U32 *)(MH_REG_BASE + 0x000002B0)      // DMA Descriptor Address register channel 11
#define     MH_DSADR11          (volatile U32 *)(MH_REG_BASE + 0x000002B4)      // DMA Source Address register channel 11
#define     MH_DTADR11          (volatile U32 *)(MH_REG_BASE + 0x000002B8)      // DMA Target Address register channel 11
#define     MH_DCMD11           (volatile U32 *)(MH_REG_BASE + 0x000002BC)      // DMA Command Address register channel 11
#define     MH_DDADR12          (volatile U32 *)(MH_REG_BASE + 0x000002C0)      // DMA Descriptor Address register channel 12
#define     MH_DSADR12          (volatile U32 *)(MH_REG_BASE + 0x000002C4)      // DMA Source Address register channel 12
#define     MH_DTADR12          (volatile U32 *)(MH_REG_BASE + 0x000002C8)      // DMA Target Address register channel 12
#define     MH_DCMD12           (volatile U32 *)(MH_REG_BASE + 0x000002CC)      // DMA Command Address register channel 12
#define     MH_DDADR13          (volatile U32 *)(MH_REG_BASE + 0x000002D0)      // DMA Descriptor Address register channel 13
#define     MH_DSADR13          (volatile U32 *)(MH_REG_BASE + 0x000002D4)      // DMA Source Address register channel 13
#define     MH_DTADR13          (volatile U32 *)(MH_REG_BASE + 0x000002D8)      // DMA Target Address register channel 13
#define     MH_DCMD13           (volatile U32 *)(MH_REG_BASE + 0x000002DC)      // DMA Command Address register channel 13
#define     MH_DDADR14          (volatile U32 *)(MH_REG_BASE + 0x000002E0)      // DMA Descriptor Address register channel 14
#define     MH_DSADR14          (volatile U32 *)(MH_REG_BASE + 0x000002E4)      // DMA Source Address register channel 14
#define     MH_DTADR14          (volatile U32 *)(MH_REG_BASE + 0x000002E8)      // DMA Target Address register channel 14
#define     MH_DCMD14           (volatile U32 *)(MH_REG_BASE + 0x000002EC)      // DMA Command Address register channel 14
#define     MH_DDADR15          (volatile U32 *)(MH_REG_BASE + 0x000002F0)      // DMA Descriptor Address register channel 15
#define     MH_DSADR15          (volatile U32 *)(MH_REG_BASE + 0x000002F4)      // DMA Source Address register channel 15
#define     MH_DTADR15          (volatile U32 *)(MH_REG_BASE + 0x000002F8)      // DMA Target Address register channel 15
#define     MH_DCMD15           (volatile U32 *)(MH_REG_BASE + 0x000002FC)      // DMA Command Address register channel 15
#define     MH_DDADR16          (volatile U32 *)(MH_REG_BASE + 0x00000300)      // DMA Descriptor Address register channel 16
#define     MH_DSADR16          (volatile U32 *)(MH_REG_BASE + 0x00000304)      // DMA Source Address register channel 16
#define     MH_DTADR16          (volatile U32 *)(MH_REG_BASE + 0x00000308)      // DMA Target Address register channel 16
#define     MH_DCMD16           (volatile U32 *)(MH_REG_BASE + 0x0000030C)      // DMA Command Address register channel 16
#define     MH_DDADR17          (volatile U32 *)(MH_REG_BASE + 0x00000310)      // DMA Descriptor Address register channel 17
#define     MH_DSADR17          (volatile U32 *)(MH_REG_BASE + 0x00000314)      // DMA Source Address register channel 17
#define     MH_DTADR17          (volatile U32 *)(MH_REG_BASE + 0x00000318)      // DMA Target Address register channel 17
#define     MH_DCMD17           (volatile U32 *)(MH_REG_BASE + 0x0000031C)      // DMA Command Address register channel 17
#define     MH_DDADR18          (volatile U32 *)(MH_REG_BASE + 0x00000320)      // DMA Descriptor Address register channel 18
#define     MH_DSADR18          (volatile U32 *)(MH_REG_BASE + 0x00000324)      // DMA Source Address register channel 18
#define     MH_DTADR18          (volatile U32 *)(MH_REG_BASE + 0x00000328)      // DMA Target Address register channel 18
#define     MH_DCMD18           (volatile U32 *)(MH_REG_BASE + 0x0000032C)      // DMA Command Address register channel 18
#define     MH_DDADR19          (volatile U32 *)(MH_REG_BASE + 0x00000330)      // DMA Descriptor Address register channel 19
#define     MH_DSADR19          (volatile U32 *)(MH_REG_BASE + 0x00000334)      // DMA Source Address register channel 19
#define     MH_DTADR19          (volatile U32 *)(MH_REG_BASE + 0x00000338)      // DMA Target Address register channel 19
#define     MH_DCMD19           (volatile U32 *)(MH_REG_BASE + 0x0000033C)      // DMA Command Address register channel 19
#define     MH_DDADR20          (volatile U32 *)(MH_REG_BASE + 0x00000340)      // DMA Descriptor Address register channel 20
#define     MH_DSADR20          (volatile U32 *)(MH_REG_BASE + 0x00000344)      // DMA Source Address register channel 20
#define     MH_DTADR20          (volatile U32 *)(MH_REG_BASE + 0x00000348)      // DMA Target Address register channel 20
#define     MH_DCMD20           (volatile U32 *)(MH_REG_BASE + 0x0000034C)      // DMA Command Address register channel 20
#define     MH_DDADR21          (volatile U32 *)(MH_REG_BASE + 0x00000350)      // DMA Descriptor Address register channel 21
#define     MH_DSADR21          (volatile U32 *)(MH_REG_BASE + 0x00000354)      // DMA Source Address register channel 21
#define     MH_DTADR21          (volatile U32 *)(MH_REG_BASE + 0x00000358)      // DMA Target Address register channel 21
#define     MH_DCMD21           (volatile U32 *)(MH_REG_BASE + 0x0000035C)      // DMA Command Address register channel 21
#define     MH_DDADR22          (volatile U32 *)(MH_REG_BASE + 0x00000360)      // DMA Descriptor Address register channel 22
#define     MH_DSADR22          (volatile U32 *)(MH_REG_BASE + 0x00000364)      // DMA Source Address register channel 22
#define     MH_DTADR22          (volatile U32 *)(MH_REG_BASE + 0x00000368)      // DMA Target Address register channel 22
#define     MH_DCMD22           (volatile U32 *)(MH_REG_BASE + 0x0000036C)      // DMA Command Address register channel 22
#define     MH_DDADR23          (volatile U32 *)(MH_REG_BASE + 0x00000370)      // DMA Descriptor Address register channel 23
#define     MH_DSADR23          (volatile U32 *)(MH_REG_BASE + 0x00000374)      // DMA Source Address register channel 23
#define     MH_DTADR23          (volatile U32 *)(MH_REG_BASE + 0x00000378)      // DMA Target Address register channel 23
#define     MH_DCMD23           (volatile U32 *)(MH_REG_BASE + 0x0000037C)      // DMA Command Address register channel 23
#define     MH_DDADR24          (volatile U32 *)(MH_REG_BASE + 0x00000380)      // DMA Descriptor Address register channel 24
#define     MH_DSADR24          (volatile U32 *)(MH_REG_BASE + 0x00000384)      // DMA Source Address register channel 24
#define     MH_DTADR24          (volatile U32 *)(MH_REG_BASE + 0x00000388)      // DMA Target Address register channel 24
#define     MH_DCMD24           (volatile U32 *)(MH_REG_BASE + 0x0000038C)      // DMA Command Address register channel 24
#define     MH_DDADR25          (volatile U32 *)(MH_REG_BASE + 0x00000390)      // DMA Descriptor Address register channel 25
#define     MH_DSADR25          (volatile U32 *)(MH_REG_BASE + 0x00000394)      // DMA Source Address register channel 25
#define     MH_DTADR25          (volatile U32 *)(MH_REG_BASE + 0x00000398)      // DMA Target Address register channel 25
#define     MH_DCMD25           (volatile U32 *)(MH_REG_BASE + 0x0000039C)      // DMA Command Address register channel 25
#define     MH_DDADR26          (volatile U32 *)(MH_REG_BASE + 0x000003A0)      // DMA Descriptor Address register channel 26
#define     MH_DSADR26          (volatile U32 *)(MH_REG_BASE + 0x000003A4)      // DMA Source Address register channel 26
#define     MH_DTADR26          (volatile U32 *)(MH_REG_BASE + 0x000003A8)      // DMA Target Address register channel 26
#define     MH_DCMD26           (volatile U32 *)(MH_REG_BASE + 0x000003AC)      // DMA Command Address register channel 26
#define     MH_DDADR27          (volatile U32 *)(MH_REG_BASE + 0x000003B0)      // DMA Descriptor Address register channel 27
#define     MH_DSADR27          (volatile U32 *)(MH_REG_BASE + 0x000003B4)      // DMA Source Address register channel 27
#define     MH_DTADR27          (volatile U32 *)(MH_REG_BASE + 0x000003B8)      // DMA Target Address register channel 27
#define     MH_DCMD27           (volatile U32 *)(MH_REG_BASE + 0x000003BC)      // DMA Command Address register channel 27
#define     MH_DDADR28          (volatile U32 *)(MH_REG_BASE + 0x000003C0)      // DMA Descriptor Address register channel 28
#define     MH_DSADR28          (volatile U32 *)(MH_REG_BASE + 0x000003C4)      // DMA Source Address register channel 28
#define     MH_DTADR28          (volatile U32 *)(MH_REG_BASE + 0x000003C8)      // DMA Target Address register channel 28
#define     MH_DCMD28           (volatile U32 *)(MH_REG_BASE + 0x000003CC)      // DMA Command Address register channel 28
#define     MH_DDADR29          (volatile U32 *)(MH_REG_BASE + 0x000003D0)      // DMA Descriptor Address register channel 29
#define     MH_DSADR29          (volatile U32 *)(MH_REG_BASE + 0x000003D4)      // DMA Source Address register channel 29
#define     MH_DTADR29          (volatile U32 *)(MH_REG_BASE + 0x000003D8)      // DMA Target Address register channel 29
#define     MH_DCMD29           (volatile U32 *)(MH_REG_BASE + 0x000003DC)      // DMA Command Address register channel 29
#define     MH_DDADR30          (volatile U32 *)(MH_REG_BASE + 0x000003E0)      // DMA Descriptor Address register channel 30
#define     MH_DSADR30          (volatile U32 *)(MH_REG_BASE + 0x000003E4)      // DMA Source Address register channel 30
#define     MH_DTADR30          (volatile U32 *)(MH_REG_BASE + 0x000003E8)      // DMA Target Address register channel 30
#define     MH_DCMD30           (volatile U32 *)(MH_REG_BASE + 0x000003EC)      // DMA Command Address register channel 30
#define     MH_DDADR31          (volatile U32 *)(MH_REG_BASE + 0x000003F0)      // DMA Descriptor Address register channel 31
#define     MH_DSADR31          (volatile U32 *)(MH_REG_BASE + 0x000003F4)      // DMA Source Address register channel 31
#define     MH_DTADR31          (volatile U32 *)(MH_REG_BASE + 0x000003F8)      // DMA Target Address register channel 31
#define     MH_DCMD31           (volatile U32 *)(MH_REG_BASE + 0x000003FC)      // DMA Command Address register channel 31
#define     MH_DRCMR66          (volatile U32 *)(MH_REG_BASE + 0x00001108)      // Request to Channel Map register for SSP3 receive request
#define     MH_DRCMR67          (volatile U32 *)(MH_REG_BASE + 0x0000110C)      // Request to Channel Map register for SSP3 transmit request
#define     MH_DRCMR91          (volatile U32 *)(MH_REG_BASE + 0x0000116C)      // Request to Channel Map register for USIM 2 receive request
#define     MH_DRCMR92          (volatile U32 *)(MH_REG_BASE + 0x00001170)      // Request to Channel Map register for USIM 2 transmit request
#define     MH_DRCMR93          (volatile U32 *)(MH_REG_BASE + 0x00001174)      // Request to Channel Map register for MMC/SDIO 2 receive
#define     MH_DRCMR94          (volatile U32 *)(MH_REG_BASE + 0x00001178)      // Request to Channel Map register for MMC/SDIO 2 transmit request
#define     MH_DRCMR95          (volatile U32 *)(MH_REG_BASE + 0x0000117C)      // Request to Channel Map register for AC97 surround transmit request
#define     MH_DRCMR96          (volatile U32 *)(MH_REG_BASE + 0x00001180)      // Request to Channel Map register for AC97 centre/LFE transmit request
#define     MH_DRCMR97          (volatile U32 *)(MH_REG_BASE + 0x00001184)      // Request to Channel Map register for NAND interface data transmit & receive request
#define     MH_DRCMR99          (volatile U32 *)(MH_REG_BASE + 0x0000118C)      // Request to Channel Map register for NAND interface command transmit request

//
// Interrupt Controller
//
#define     MH_ICIP             (volatile U32 *)(MH_REG_BASE + 0x00D00000)      // CP6, CR0 Interrupt Controller IRQ Pending register
#define     MH_ICMR             (volatile U32 *)(MH_REG_BASE + 0x00D00004)      // CP6, CR1 Interrupt Controller Mask register
#define     MH_ICLR             (volatile U32 *)(MH_REG_BASE + 0x00D00008)      // CP6, CR2 Interrupt Controller Level register
#define     MH_ICFP             (volatile U32 *)(MH_REG_BASE + 0x00D0000C)      // CP6, CR3 Interrupt Controller FIQ Pending register
#define     MH_ICPR             (volatile U32 *)(MH_REG_BASE + 0x00D00010)      // CP6, CR4 Interrupt Controller Pending register
#define     MH_ICCR             (volatile U32 *)(MH_REG_BASE + 0x00D00014)      // Interrupt Controller Control register
#define     MH_ICHP             (volatile U32 *)(MH_REG_BASE + 0x00D00018)      // CP6, CR5 Interrupt Controller Highest Priority register

#define     MH_IPR0             (volatile U32 *)(MH_REG_BASE + 0x00D0001C)      // Interrupt Priority registers for interrupts 0
#define     MH_IPR1             (volatile U32 *)(MH_REG_BASE + 0x00D00020)      // Interrupt Priority registers for interrupts 1
#define     MH_IPR2             (volatile U32 *)(MH_REG_BASE + 0x00D00024)      // Interrupt Priority registers for interrupts 2
#define     MH_IPR3             (volatile U32 *)(MH_REG_BASE + 0x00D00028)      // Interrupt Priority registers for interrupts 3
#define     MH_IPR4             (volatile U32 *)(MH_REG_BASE + 0x00D0002C)      // Interrupt Priority registers for interrupts 4
#define     MH_IPR5             (volatile U32 *)(MH_REG_BASE + 0x00D00030)      // Interrupt Priority registers for interrupts 5
#define     MH_IPR6             (volatile U32 *)(MH_REG_BASE + 0x00D00034)      // Interrupt Priority registers for interrupts 6
#define     MH_IPR7             (volatile U32 *)(MH_REG_BASE + 0x00D00038)      // Interrupt Priority registers for interrupts 7
#define     MH_IPR8             (volatile U32 *)(MH_REG_BASE + 0x00D0003C)      // Interrupt Priority registers for interrupts 8
#define     MH_IPR9             (volatile U32 *)(MH_REG_BASE + 0x00D00040)      // Interrupt Priority registers for interrupts 9
#define     MH_IPR10            (volatile U32 *)(MH_REG_BASE + 0x00D00044)      // Interrupt Priority registers for interrupts 10
#define     MH_IPR11            (volatile U32 *)(MH_REG_BASE + 0x00D00048)      // Interrupt Priority registers for interrupts 11
#define     MH_IPR12            (volatile U32 *)(MH_REG_BASE + 0x00D0004C)      // Interrupt Priority registers for interrupts 12
#define     MH_IPR13            (volatile U32 *)(MH_REG_BASE + 0x00D00050)      // Interrupt Priority registers for interrupts 13
#define     MH_IPR14            (volatile U32 *)(MH_REG_BASE + 0x00D00054)      // Interrupt Priority registers for interrupts 14
#define     MH_IPR15            (volatile U32 *)(MH_REG_BASE + 0x00D00058)      // Interrupt Priority registers for interrupts 15
#define     MH_IPR16            (volatile U32 *)(MH_REG_BASE + 0x00D0005C)      // Interrupt Priority registers for interrupts 16
#define     MH_IPR17            (volatile U32 *)(MH_REG_BASE + 0x00D00060)      // Interrupt Priority registers for interrupts 17
#define     MH_IPR18            (volatile U32 *)(MH_REG_BASE + 0x00D00064)      // Interrupt Priority registers for interrupts 18
#define     MH_IPR19            (volatile U32 *)(MH_REG_BASE + 0x00D00068)      // Interrupt Priority registers for interrupts 19
#define     MH_IPR20            (volatile U32 *)(MH_REG_BASE + 0x00D0006C)      // Interrupt Priority registers for interrupts 20
#define     MH_IPR21            (volatile U32 *)(MH_REG_BASE + 0x00D00070)      // Interrupt Priority registers for interrupts 21
#define     MH_IPR22            (volatile U32 *)(MH_REG_BASE + 0x00D00074)      // Interrupt Priority registers for interrupts 22
#define     MH_IPR23            (volatile U32 *)(MH_REG_BASE + 0x00D00078)      // Interrupt Priority registers for interrupts 23
#define     MH_IPR24            (volatile U32 *)(MH_REG_BASE + 0x00D0007C)      // Interrupt Priority registers for interrupts 24
#define     MH_IPR25            (volatile U32 *)(MH_REG_BASE + 0x00D00080)      // Interrupt Priority registers for interrupts 25
#define     MH_IPR26            (volatile U32 *)(MH_REG_BASE + 0x00D00084)      // Interrupt Priority registers for interrupts 26
#define     MH_IPR27            (volatile U32 *)(MH_REG_BASE + 0x00D00088)      // Interrupt Priority registers for interrupts 27
#define     MH_IPR28            (volatile U32 *)(MH_REG_BASE + 0x00D0008C)      // Interrupt Priority registers for interrupts 28
#define     MH_IPR29            (volatile U32 *)(MH_REG_BASE + 0x00D00090)      // Interrupt Priority registers for interrupts 29
#define     MH_IPR30            (volatile U32 *)(MH_REG_BASE + 0x00D00094)      // Interrupt Priority registers for interrupts 30
#define     MH_IPR31            (volatile U32 *)(MH_REG_BASE + 0x00D00098)      // Interrupt Priority registers for interrupts 31

#define     MH_ICIP2            (volatile U32 *)(MH_REG_BASE + 0x00D0009C)      // CP6, CR6 Interrupt Controller IRQ Pending register 2
#define     MH_ICMR2            (volatile U32 *)(MH_REG_BASE + 0x00D000A0)      // CP6, CR7 Interrupt Controller Mask register 2
#define     MH_ICLR2            (volatile U32 *)(MH_REG_BASE + 0x00D000A4)      // CP6, CR8 Interrupt Controller Level register 2
#define     MH_ICFP2            (volatile U32 *)(MH_REG_BASE + 0x00D000A8)      // CP6, CR9 Interrupt Controller FIQ Pending register 2
#define     MH_ICPR2            (volatile U32 *)(MH_REG_BASE + 0x00D000AC)      // CP6, CR10 Interrupt Controller Pending register 2
#define     MH_IPR32            (volatile U32 *)(MH_REG_BASE + 0x00D000B0)      // Interrupt Priority registers for priorities 32
#define     MH_IPR33            (volatile U32 *)(MH_REG_BASE + 0x00D000B4)      // Interrupt Priority registers for priorities 33
#define     MH_IPR34            (volatile U32 *)(MH_REG_BASE + 0x00D000B8)      // Interrupt Priority registers for priorities 34
#define     MH_IPR35            (volatile U32 *)(MH_REG_BASE + 0x00D000BC)      // Interrupt Priority registers for priorities 35
#define     MH_IPR36            (volatile U32 *)(MH_REG_BASE + 0x00D000C0)      // Interrupt Priority registers for priorities 36
#define     MH_IPR37            (volatile U32 *)(MH_REG_BASE + 0x00D000C4)      // Interrupt Priority registers for priorities 37
#define     MH_IPR38            (volatile U32 *)(MH_REG_BASE + 0x00D000C8)      // Interrupt Priority registers for priorities 38
#define     MH_IPR39            (volatile U32 *)(MH_REG_BASE + 0x00D000CC)      // Interrupt Priority registers for priorities 39
#define     MH_IPR40            (volatile U32 *)(MH_REG_BASE + 0x00D000D0)      // Interrupt Priority registers for priorities 40
#define     MH_IPR41            (volatile U32 *)(MH_REG_BASE + 0x00D000D4)      // Interrupt Priority registers for priorities 41
#define     MH_IPR42            (volatile U32 *)(MH_REG_BASE + 0x00D000D8)      // Interrupt Priority registers for priorities 42
#define     MH_IPR43            (volatile U32 *)(MH_REG_BASE + 0x00D000DC)      // Interrupt Priority registers for priorities 43
#define     MH_IPR44            (volatile U32 *)(MH_REG_BASE + 0x00D000E0)      // Interrupt Priority registers for priorities 44
#define     MH_IPR45            (volatile U32 *)(MH_REG_BASE + 0x00D000E4)      // Interrupt Priority registers for priorities 45
#define     MH_IPR46            (volatile U32 *)(MH_REG_BASE + 0x00D000E8)      // Interrupt Priority registers for priorities 46
#define     MH_IPR47            (volatile U32 *)(MH_REG_BASE + 0x00D000EC)      // Interrupt Priority registers for priorities 47
#define     MH_IPR48            (volatile U32 *)(MH_REG_BASE + 0x00D000F0)      // Interrupt Priority registers for priorities 48
#define     MH_IPR49            (volatile U32 *)(MH_REG_BASE + 0x00D000F4)      // Interrupt Priority registers for priorities 49
#define     MH_IPR50            (volatile U32 *)(MH_REG_BASE + 0x00D000F8)      // Interrupt Priority registers for priorities 50
#define     MH_IPR51            (volatile U32 *)(MH_REG_BASE + 0x00D000FC)      // Interrupt Priority registers for priorities 51
#define     MH_IPR52            (volatile U32 *)(MH_REG_BASE + 0x00D00100)      // Interrupt Priority registers for priorities 52

//
// Real-Time Clock (RTC)
//
#define     MH_RCNR             (volatile U32 *)(MH_REG_BASE + 0x00900000)      // RTC Counter register
#define     MH_RTAR             (volatile U32 *)(MH_REG_BASE + 0x00900004)      // RTC Alarm register
#define     MH_RTSR             (volatile U32 *)(MH_REG_BASE + 0x00900008)      // RTC Status register
#define     MH_RTTR             (volatile U32 *)(MH_REG_BASE + 0x0090000C)      // RTC Timer Trim register
#define     MH_RDCR             (volatile U32 *)(MH_REG_BASE + 0x00900010)      // RTC Day Counter register
#define     MH_RYCR             (volatile U32 *)(MH_REG_BASE + 0x00900014)      // RTC Year Counter register
#define     MH_RDAR1            (volatile U32 *)(MH_REG_BASE + 0x00900018)      // Wristwatch Day Alarm register 1
#define     MH_RYAR1            (volatile U32 *)(MH_REG_BASE + 0x0090001C)      // Wristwatch Year Alarm register 1
#define     MH_RDAR2            (volatile U32 *)(MH_REG_BASE + 0x00900020)      // Wristwatch Day Alarm register 2
#define     MH_RYAR2            (volatile U32 *)(MH_REG_BASE + 0x00900024)      // Wristwatch Year Alarm register 2
#define     MH_SWCR             (volatile U32 *)(MH_REG_BASE + 0x00900028)      // Stopwatch Counter register
#define     MH_SWAR1            (volatile U32 *)(MH_REG_BASE + 0x0090002C)      // Stopwatch Alarm register 1
#define     MH_SWAR2            (volatile U32 *)(MH_REG_BASE + 0x00900030)      // Stopwatch Alarm register 2
#define     MH_RTCPICR          (volatile U32 *)(MH_REG_BASE + 0x00900034)      // Periodic Interrupt Counter register
#define     MH_PIAR             (volatile U32 *)(MH_REG_BASE + 0x00900038)      // Periodic Interrupt Alarm register

//
// Operating System Timers
//
#define     MH_OSMR0            (volatile U32 *)(MH_REG_BASE + 0x00A00000)      // OS Timer Match 0 register
#define     MH_OSMR1            (volatile U32 *)(MH_REG_BASE + 0x00A00004)      // OS Timer Match 1 register
#define     MH_OSMR2            (volatile U32 *)(MH_REG_BASE + 0x00A00008)      // OS Timer Match 2 register
#define     MH_OSMR3            (volatile U32 *)(MH_REG_BASE + 0x00A0000C)      // OS Timer Match 3 register
#define     MH_OSMR4            (volatile U32 *)(MH_REG_BASE + 0x00A00080)      // OS Timer Match register 4
#define     MH_OSMR5            (volatile U32 *)(MH_REG_BASE + 0x00A00084)      // OS Timer Match register 5
#define     MH_OSMR6            (volatile U32 *)(MH_REG_BASE + 0x00A00088)      // OS Timer Match register 6
#define     MH_OSMR7            (volatile U32 *)(MH_REG_BASE + 0x00A0008C)      // OS Timer Match register 7
#define     MH_OSMR8            (volatile U32 *)(MH_REG_BASE + 0x00A00090)      // OS Timer Match register 8
#define     MH_OSMR9            (volatile U32 *)(MH_REG_BASE + 0x00A00094)      // OS Timer Match register 9
#define     MH_OSMR10           (volatile U32 *)(MH_REG_BASE + 0x00A00098)      // OS Timer Match register 10
#define     MH_OSMR11           (volatile U32 *)(MH_REG_BASE + 0x00A0009C)      // OS Timer Match register 11

#define     MH_OSCR0            (volatile U32 *)(MH_REG_BASE + 0x00A00010)      // OS Timer Counter register 0
#define     MH_OSSR             (volatile U32 *)(MH_REG_BASE + 0x00A00014)      // OS Timer Status register (used for all counters)
#define     MH_OWER             (volatile U32 *)(MH_REG_BASE + 0x00A00018)      // OS Timer Watchdog Enable register
#define     MH_OIER             (volatile U32 *)(MH_REG_BASE + 0x00A0001C)      // OS Timer Interrupt Enable register (used for all counters)
#define     MH_OSNR             (volatile U32 *)(MH_REG_BASE + 0x00A00020)      // OS Timer Snapshot register

#define     MH_OSCR4            (volatile U32 *)(MH_REG_BASE + 0x00A00040)      // OS Timer Counter register 4
#define     MH_OSCR5            (volatile U32 *)(MH_REG_BASE + 0x00A00044)      // OS Timer Counter register 5
#define     MH_OSCR6            (volatile U32 *)(MH_REG_BASE + 0x00A00048)      // OS Timer Counter register 6
#define     MH_OSCR7            (volatile U32 *)(MH_REG_BASE + 0x00A0004C)      // OS Timer Counter register 7
#define     MH_OSCR8            (volatile U32 *)(MH_REG_BASE + 0x00A00050)      // OS Timer Counter register 8
#define     MH_OSCR9            (volatile U32 *)(MH_REG_BASE + 0x00A00054)      // OS Timer Counter register 9
#define     MH_OSCR10           (volatile U32 *)(MH_REG_BASE + 0x00A00058)      // OS Timer Counter register 10
#define     MH_OSCR11           (volatile U32 *)(MH_REG_BASE + 0x00A0005C)      // OS Timer Counter register 11

#define     MH_OMCR4            (volatile U32 *)(MH_REG_BASE + 0x00A000C0)      // OS Match Control register 4
#define     MH_OMCR5            (volatile U32 *)(MH_REG_BASE + 0x00A000C4)      // OS Match Control register 5
#define     MH_OMCR6            (volatile U32 *)(MH_REG_BASE + 0x00A000C8)      // OS Match Control register 6
#define     MH_OMCR7            (volatile U32 *)(MH_REG_BASE + 0x00A000CC)      // OS Match Control register 7
#define     MH_OMCR8            (volatile U32 *)(MH_REG_BASE + 0x00A000D0)      // OS Match Control register 8
#define     MH_OMCR9            (volatile U32 *)(MH_REG_BASE + 0x00A000D4)      // OS Match Control register 9
#define     MH_OMCR10           (volatile U32 *)(MH_REG_BASE + 0x00A000D8)      // OS Match Control register 10
#define     MH_OMCR11           (volatile U32 *)(MH_REG_BASE + 0x00A000DC)      // OS Match Control register 11

//
// Performance Monitoring and Debug
//
#define     MH_PML_ESEL_0       (volatile U32 *)(MH_REG_BASE + 0x0600FF00)      // Event Select registers 0
#define     MH_PML_ESEL_1       (volatile U32 *)(MH_REG_BASE + 0x0600FF04)      // Event Select registers 1
#define     MH_PML_ESEL_2       (volatile U32 *)(MH_REG_BASE + 0x0600FF08)      // Event Select registers 2
#define     MH_PML_ESEL_3       (volatile U32 *)(MH_REG_BASE + 0x0600FF0C)      // Event Select registers 3
#define     MH_PML_ESEL_4       (volatile U32 *)(MH_REG_BASE + 0x0600FF10)      // Event Select registers 4
#define     MH_PML_ESEL_5       (volatile U32 *)(MH_REG_BASE + 0x0600FF14)      // Event Select registers 5
#define     MH_PML_ESEL_6       (volatile U32 *)(MH_REG_BASE + 0x0600FF18)      // Event Select registers 6
#define     MH_PML_ESEL_7       (volatile U32 *)(MH_REG_BASE + 0x0600FF1C)      // Event Select registers 7
#define     MH_MDUXSCALEBP      (volatile U32 *)(MH_REG_BASE + 0x0600FF40)      // MDU Intel XScale? Snapshot register
#define     MH_MDU2DGEVENT      (volatile U32 *)(MH_REG_BASE + 0x0600FF54)      // MDU 2DG Stop register

//
// System Bus Arbiters
//
#define     MH_ARBCNTRL1        (volatile U32 *)(MH_REG_BASE + 0x0600FE00)      // system bus #1 Bus Arbiter Control register
#define     MH_ARBCNTRL2        (volatile U32 *)(MH_REG_BASE + 0x0600FE80)      // system bus #2 Bus Arbiter Control register

//
// External Memory Controller
//
#define     MH_MDCNFG           (volatile U32 *)(MH_REG_BASE + 0x08100000)      // SDRAM Configuration register
#define     MH_MDREFR           (volatile U32 *)(MH_REG_BASE + 0x08100004)      // SDRAM Refresh Control register
#define     MH_MDMRS            (volatile U32 *)(MH_REG_BASE + 0x08100040)      // SDRAM Mode Register Set Configuration register
#define     MH_DDRHCAL          (volatile U32 *)(MH_REG_BASE + 0x08100060)      // DDR Hardware Calibration register
#define     MH_DDRWCAL          (volatile U32 *)(MH_REG_BASE + 0x08100068)      // DDR Write Strobe Calibration register
#define     MH_DMCIER           (volatile U32 *)(MH_REG_BASE + 0x08100070)      // Dynamic Memory Controller Interrupt Enable register
#define     MH_DMCISR           (volatile U32 *)(MH_REG_BASE + 0x08100078)      // Dynamic Memory Controller Interrupt Status register
#define     MH_DDRDLS           (volatile U32 *)(MH_REG_BASE + 0x08100080)      // Delay Line Status register
#define     MH_EMPI             (volatile U32 *)(MH_REG_BASE + 0x08100090)      // EMPI Control register
#define     MH_RCOMP            (volatile U32 *)(MH_REG_BASE + 0x08100100)      // Rcomp Control register
#define     MH_PADMA            (volatile U32 *)(MH_REG_BASE + 0x08100110)      // PADMA Strength and Slew Settings register
#define     MH_PADMDMSB         (volatile U32 *)(MH_REG_BASE + 0x08100114)      // PADMDMSB Strength and Slew Settings register
#define     MH_PADMDLSB         (volatile U32 *)(MH_REG_BASE + 0x08100118)      // PADMDLSB Strength and Slew Settings register
#define     MH_PADSDRAM         (volatile U32 *)(MH_REG_BASE + 0x0810011C)      // PADSDRAM Strength and Slew Settings register
#define     MH_PADSDCLK         (volatile U32 *)(MH_REG_BASE + 0x08100120)      // PADSDCLK Strength and Slew Settings register
#define     MH_PADSDCS          (volatile U32 *)(MH_REG_BASE + 0x08100124)      // PADSDCS Strength and Slew Settings register
#define     MH_PADSMEM          (volatile U32 *)(MH_REG_BASE + 0x08100128)      // PADSMEM Strength and Slew Settings register
#define     MH_PADSCLK          (volatile U32 *)(MH_REG_BASE + 0x0810012C)      // PADSCLK Strength and Slew Settings register

#define     DDRHCAL_HCEN        (1u << 31)                                      // Phase detector is enable
#define     MDCNFG_HWFREQ       (1u << 29)                                      // Frequency change peding

//
// Static Memory Controller
//
#define     MH_MSC0             (volatile U32 *)(MH_REG_BASE + 0x0A000008)      // Static Memory Control register 0
#define     MH_MSC1             (volatile U32 *)(MH_REG_BASE + 0x0A00000C)      // Static Memory Control register 1
#define     MH_MECR             (volatile U32 *)(MH_REG_BASE + 0x0A000014)      // Expansion Memory (Compact Flash) Configuration register
#define     MH_SXCNFG           (volatile U32 *)(MH_REG_BASE + 0x0A00001C)      // Synchronous Static Memory Control register
#define     MH_MCMEM0           (volatile U32 *)(MH_REG_BASE + 0x0A000028)      // Expansion Memory Common Memory Space Timing Configuration
#define     MH_MCATT0           (volatile U32 *)(MH_REG_BASE + 0x0A000030)      // Expansion Memory Attribute Space Timing Configuration
#define     MH_MCIO0            (volatile U32 *)(MH_REG_BASE + 0x0A000038)      // Expansion Memory I/O Space Timing Configuration
#define     MH_MEMCLKCFG        (volatile U32 *)(MH_REG_BASE + 0x0A000068)      // Clock Configuration
#define     MH_CSADRCFG0        (volatile U32 *)(MH_REG_BASE + 0x0A000080)      // Address Configuration register for Chip Select 0
#define     MH_CSADRCFG1        (volatile U32 *)(MH_REG_BASE + 0x0A000084)      // Address Configuration register for Chip Select 1
#define     MH_CSADRCFG2        (volatile U32 *)(MH_REG_BASE + 0x0A000088)      // Address Configuration register for Chip Select 2
#define     MH_CSADRCFG3        (volatile U32 *)(MH_REG_BASE + 0x0A00008C)      // Address Configuration register for Chip Select 3
#define     MH_CSADRCFGP        (volatile U32 *)(MH_REG_BASE + 0x0A000090)      // Address Configuration register for PC Card Interface
#define     MH_CSMSADRCFG       (volatile U32 *)(MH_REG_BASE + 0x0A0000A0)      // CS and EMPI Bus Mode Configuration register
#define     MH_CLKRETDEL        (volatile U32 *)(MH_REG_BASE + 0x0A0000B0)      // Delay line and mux selects for return data latching for synchronous flash
#define     MH_ADVRETDEL        (volatile U32 *)(MH_REG_BASE + 0x0A0000B4)      // Delay line and mux selects for return data latching for synchronous flash

//
// Data Flash Controller Register Summary
//
#define     MH_NDCR             (volatile U32 *)(MH_REG_BASE + 0x03100000)      // Data Flash Control register
#define     MH_NDTR0CS0         (volatile U32 *)(MH_REG_BASE + 0x03100004)      // Data Controller Timing Parameter 0 register for NDnCS0
#define     MH_NDTR1CS0         (volatile U32 *)(MH_REG_BASE + 0x0310000C)      // Data Controller Timing Parameter 1 register for NDnCS0
#define     MH_NDSR             (volatile U32 *)(MH_REG_BASE + 0x03100014)      // Data Controller Status register
#define     MH_NDPCR            (volatile U32 *)(MH_REG_BASE + 0x03100018)      // Data Controller Page Count register
#define     MH_NDBDR0           (volatile U32 *)(MH_REG_BASE + 0x0310001C)      // Data Controller Bad Block register 0
#define     MH_NDBDR1           (volatile U32 *)(MH_REG_BASE + 0x03100020)      // Data Controller Bad Block register 1
#define     MH_NDDB             (volatile U32 *)(MH_REG_BASE + 0x03100040)      // Data Controller Data Buffer
#define     MH_NDCB0            (volatile U32 *)(MH_REG_BASE + 0x03100048)      // Data Controller Command Buffer 0
#define     MH_NDCB1            (volatile U32 *)(MH_REG_BASE + 0x0310004C)      // Data Controller Command Buffer 1
#define     MH_NDCB2            (volatile U32 *)(MH_REG_BASE + 0x03100050)      // Data Controller Command Buffer 2

//
// MMC/SD/SDIO Controller Register Summary
//
#define     MH_MMC1_BASE        (volatile U32 *)(MH_REG_BASE + 0x01100000)
#define     MH_MMCSTRPCL1       (volatile U32 *)(MH_REG_BASE + 0x01100000)      // Control to start and stop MMC/SD/SDIO clock
#define     MH_MMCSTAT1         (volatile U32 *)(MH_REG_BASE + 0x01100004)      // MMC/SD/SDIO status register (read only)
#define     MH_MMCCLKRT1        (volatile U32 *)(MH_REG_BASE + 0x01100008)      // MMC/SD/SDIO clock rate
#define     MH_MMCSPI1          (volatile U32 *)(MH_REG_BASE + 0x0110000c)      // SPI mode control bits
#define     MH_MMCCMDAT1        (volatile U32 *)(MH_REG_BASE + 0x01100010)      // Command/response/data sequence control
#define     MH_MMCRESTO1        (volatile U32 *)(MH_REG_BASE + 0x01100014)      // Expected response time out
#define     MH_MMCRDTO1         (volatile U32 *)(MH_REG_BASE + 0x01100018)      // Expected data read time out
#define     MH_MMCBLKLEN1       (volatile U32 *)(MH_REG_BASE + 0x0110001c)      // Block length of data transaction
#define     MH_MMCNUMBLK1       (volatile U32 *)(MH_REG_BASE + 0x01100020)      // Number of blocks, for block mode
#define     MH_MMCPRTBUF1       (volatile U32 *)(MH_REG_BASE + 0x01100024)      // Partial MMCTXFIFO FIFO written
#define     MH_MMCIMASK1        (volatile U32 *)(MH_REG_BASE + 0x01100028)      // Interrupt Mask
#define     MH_MMCIREG1         (volatile U32 *)(MH_REG_BASE + 0x0110002c)      // Interrupt Register (read only)
#define     MH_MMCCMD1          (volatile U32 *)(MH_REG_BASE + 0x01100030)      // Index of current command
#define     MH_MMCARGH1         (volatile U32 *)(MH_REG_BASE + 0x01100034)      // MSW part of the current command argument
#define     MH_MMCARGL1         (volatile U32 *)(MH_REG_BASE + 0x01100038)      // LSW part of the current command argument
#define     MH_MMCRES1          (volatile U32 *)(MH_REG_BASE + 0x0110003c)      // Response FIFO (read only)
#define     MH_MMCRXFIFO1       (volatile U32 *)(MH_REG_BASE + 0x01100040)      // Receive FIFO (read only)
#define     MH_MMCTXFIFO1       (volatile U32 *)(MH_REG_BASE + 0x01100044)      // Transmit FIFO (write only)
#define     MH_MMCRDWAIT1       (volatile U32 *)(MH_REG_BASE + 0x01100048)      // SDIO RDWAIT, stall read data transfer
#define     MH_MMCBLKSREM1      (volatile U32 *)(MH_REG_BASE + 0x0110004C)      // Blocks Remaining

#define     MH_MMC2_BASE        (volatile U32 *)(MH_REG_BASE + 0x02000000)
#define     MH_MMCSTRPCL2       (volatile U32 *)(MH_REG_BASE + 0x02000000)      // Control to start and stop MMC/SD/SDIO clock
#define     MH_MMCSTAT2         (volatile U32 *)(MH_REG_BASE + 0x02000004)      // MMC/SD/SDIO status register (read only)
#define     MH_MMCCLKRT2        (volatile U32 *)(MH_REG_BASE + 0x02000008)      // MMC/SD/SDIO clock rate
#define     MH_MMCSPI2          (volatile U32 *)(MH_REG_BASE + 0x0200000c)      // SPI mode control bits
#define     MH_MMCCMDAT2        (volatile U32 *)(MH_REG_BASE + 0x02000010)      // Command/response/data sequence control
#define     MH_MMCRESTO2        (volatile U32 *)(MH_REG_BASE + 0x02000014)      // Expected response time out
#define     MH_MMCRDTO2         (volatile U32 *)(MH_REG_BASE + 0x02000018)      // Expected data read time out
#define     MH_MMCBLKLEN2       (volatile U32 *)(MH_REG_BASE + 0x0200001c)      // Block length of data transaction
#define     MH_MMCNUMBLK2       (volatile U32 *)(MH_REG_BASE + 0x02000020)      // Number of blocks, for block mode
#define     MH_MMCPRTBUF2       (volatile U32 *)(MH_REG_BASE + 0x02000024)      // Partial MMCTXFIFO FIFO written
#define     MH_MMCIMASK2        (volatile U32 *)(MH_REG_BASE + 0x02000028)      // Interrupt Mask
#define     MH_MMCIREG2         (volatile U32 *)(MH_REG_BASE + 0x0200002c)      // Interrupt Register (read only)
#define     MH_MMCCMD2          (volatile U32 *)(MH_REG_BASE + 0x02000030)      // Index of current command
#define     MH_MMCARGH2         (volatile U32 *)(MH_REG_BASE + 0x02000034)      // MSW part of the current command argument
#define     MH_MMCARGL2         (volatile U32 *)(MH_REG_BASE + 0x02000038)      // LSW part of the current command argument
#define     MH_MMCRES2          (volatile U32 *)(MH_REG_BASE + 0x0200003c)      // Response FIFO (read only)
#define     MH_MMCRXFIFO2       (volatile U32 *)(MH_REG_BASE + 0x02000040)      // Receive FIFO (read only)
#define     MH_MMCTXFIFO2       (volatile U32 *)(MH_REG_BASE + 0x02000044)      // Transmit FIFO (write only)
#define     MH_MMCRDWAIT2       (volatile U32 *)(MH_REG_BASE + 0x02000048)      // SDIO RDWAIT, stall read data transfer
#define     MH_MMCBLKSREM2      (volatile U32 *)(MH_REG_BASE + 0x0200004C)      // Blocks Remaining

#define     MH_MMC3_BASE        (volatile U32 *)(MH_REG_BASE + 0x02500000)
#define     MH_MMCSTRPCL3       (volatile U32 *)(MH_REG_BASE + 0x02500000)      // Control to start and stop MMC/SD/SDIO clock
#define     MH_MMCSTAT3         (volatile U32 *)(MH_REG_BASE + 0x02500004)      // MMC/SD/SDIO status register (read only)
#define     MH_MMCCLKRT3        (volatile U32 *)(MH_REG_BASE + 0x02500008)      // MMC/SD/SDIO clock rate
#define     MH_MMCSPI3          (volatile U32 *)(MH_REG_BASE + 0x0250000c)      // SPI mode control bits
#define     MH_MMCCMDAT3        (volatile U32 *)(MH_REG_BASE + 0x02500010)      // Command/response/data sequence control
#define     MH_MMCRESTO3        (volatile U32 *)(MH_REG_BASE + 0x02500014)      // Expected response time out
#define     MH_MMCRDTO3         (volatile U32 *)(MH_REG_BASE + 0x02500018)      // Expected data read time out
#define     MH_MMCBLKLEN3       (volatile U32 *)(MH_REG_BASE + 0x0250001c)      // Block length of data transaction
#define     MH_MMCNUMBLK3       (volatile U32 *)(MH_REG_BASE + 0x02500020)      // Number of blocks, for block mode
#define     MH_MMCPRTBUF3       (volatile U32 *)(MH_REG_BASE + 0x02500024)      // Partial MMCTXFIFO FIFO written
#define     MH_MMCIMASK3        (volatile U32 *)(MH_REG_BASE + 0x02500028)      // Interrupt Mask
#define     MH_MMCIREG3         (volatile U32 *)(MH_REG_BASE + 0x0250002c)      // Interrupt Register (read only)
#define     MH_MMCCMD3          (volatile U32 *)(MH_REG_BASE + 0x02500030)      // Index of current command
#define     MH_MMCARGH3         (volatile U32 *)(MH_REG_BASE + 0x02500034)      // MSW part of the current command argument
#define     MH_MMCARGL3         (volatile U32 *)(MH_REG_BASE + 0x02500038)      // LSW part of the current command argument
#define     MH_MMCRES3          (volatile U32 *)(MH_REG_BASE + 0x0250003c)      // Response FIFO (read only)
#define     MH_MMCRXFIFO3       (volatile U32 *)(MH_REG_BASE + 0x02500040)      // Receive FIFO (read only)
#define     MH_MMCTXFIFO3       (volatile U32 *)(MH_REG_BASE + 0x02500044)      // Transmit FIFO (write only)
#define     MH_MMCRDWAIT3       (volatile U32 *)(MH_REG_BASE + 0x02500048)      // SDIO RDWAIT, stall read data transfer
#define     MH_MMCBLKSREM3      (volatile U32 *)(MH_REG_BASE + 0x0250004C)      // Blocks Remaining

//
// LCD Controller Register Summary
//
#define     MH_LCCR0            (volatile U32 *)(MH_REG_BASE + 0x04000000)      // LCD Controller Control register 0
#define     MH_LCCR1            (volatile U32 *)(MH_REG_BASE + 0x04000004)      // LCD Controller Control register 1
#define     MH_LCCR2            (volatile U32 *)(MH_REG_BASE + 0x04000008)      // LCD Controller Control register 2
#define     MH_LCCR3            (volatile U32 *)(MH_REG_BASE + 0x0400000C)      // LCD Controller Control register 3
#define     MH_LCCR4            (volatile U32 *)(MH_REG_BASE + 0x04000010)      // LCD Controller Control register 4
#define     MH_LCCR5            (volatile U32 *)(MH_REG_BASE + 0x04000014)      // LCD Controller Control register 5
#define     MH_LCCR6            (volatile U32 *)(MH_REG_BASE + 0x04000018)      // LCD Controller Control register 6
#define     MH_FBR0             (volatile U32 *)(MH_REG_BASE + 0x04000020)      // DMA Channel 0 Frame Branch register
#define     MH_FBR1             (volatile U32 *)(MH_REG_BASE + 0x04000024)      // DMA Channel 1 Frame Branch register
#define     MH_FBR2             (volatile U32 *)(MH_REG_BASE + 0x04000028)      // DMA Channel 2 Frame Branch register
#define     MH_FBR3             (volatile U32 *)(MH_REG_BASE + 0x0400002C)      // DMA Channel 3 Frame Branch register
#define     MH_FBR4             (volatile U32 *)(MH_REG_BASE + 0x04000030)      // DMA Channel 4 Frame Branch register
#define     MH_LCSR1            (volatile U32 *)(MH_REG_BASE + 0x04000034)      // LCD Controller Status register 1
#define     MH_LCSR0            (volatile U32 *)(MH_REG_BASE + 0x04000038)      // LCD Controller Status register 0
#define     MH_LIIDR            (volatile U32 *)(MH_REG_BASE + 0x0400003C)      // LCD Controller Interrupt ID register
#define     MH_TRGBR            (volatile U32 *)(MH_REG_BASE + 0x04000040)      // TMED RGB Seed register
#define     MH_TCR              (volatile U32 *)(MH_REG_BASE + 0x04000044)      // TMED Control register
#define     MH_OVL1C1           (volatile U32 *)(MH_REG_BASE + 0x04000050)      // Overlay 1 Control register 1
#define     MH_OVL1C2           (volatile U32 *)(MH_REG_BASE + 0x04000060)      // Overlay 1 Control register 2
#define     MH_OVL2C1           (volatile U32 *)(MH_REG_BASE + 0x04000070)      // Overlay 2 Control register 1
#define     MH_OVL2C2           (volatile U32 *)(MH_REG_BASE + 0x04000080)      // Overlay 2 Control register 2
#define     MH_CCR              (volatile U32 *)(MH_REG_BASE + 0x04000090)      // Cursor Control register
#define     MH_CMDCR            (volatile U32 *)(MH_REG_BASE + 0x04000100)      // Command Control register
#define     MH_PRSR             (volatile U32 *)(MH_REG_BASE + 0x04000104)      // Panel Read Status register
#define     MH_FBR5             (volatile U32 *)(MH_REG_BASE + 0x04000110)      // DMA Channel 5 Frame Branch register
#define     MH_FBR6             (volatile U32 *)(MH_REG_BASE + 0x04000114)      // DMA Channel 6 Frame Branch register
#define     MH_FDADR0           (volatile U32 *)(MH_REG_BASE + 0x04000200)      // DMA Channel 0 Frame Descriptor Address register
#define     MH_FSADR0           (volatile U32 *)(MH_REG_BASE + 0x04000204)      // DMA Channel 0 Frame Source Address register
#define     MH_FIDR0            (volatile U32 *)(MH_REG_BASE + 0x04000208)      // DMA Channel 0 Frame ID register
#define     MH_LDCMD0           (volatile U32 *)(MH_REG_BASE + 0x0400020C)      // LCD DMA Channel 0 Command register
#define     MH_FDADR1           (volatile U32 *)(MH_REG_BASE + 0x04000210)      // DMA Channel 1 Frame Descriptor Address register
#define     MH_FSADR1           (volatile U32 *)(MH_REG_BASE + 0x04000214)      // DMA Channel 1 Frame Source Address register
#define     MH_FIDR1            (volatile U32 *)(MH_REG_BASE + 0x04000218)      // DMA Channel 1 Frame ID register
#define     MH_LDCMD1           (volatile U32 *)(MH_REG_BASE + 0x0400021C)      // LCD DMA Channel 1 Command register
#define     MH_FDADR2           (volatile U32 *)(MH_REG_BASE + 0x04000220)      // DMA Channel 2 Frame Descriptor Address register
#define     MH_FSADR2           (volatile U32 *)(MH_REG_BASE + 0x04000224)      // DMA Channel 2 Frame Source Address register
#define     MH_FIDR2            (volatile U32 *)(MH_REG_BASE + 0x04000228)      // DMA Channel 2 Frame ID register
#define     MH_LDCMD2           (volatile U32 *)(MH_REG_BASE + 0x0400022C)      // LCD DMA Channel 2 Command register
#define     MH_FDADR3           (volatile U32 *)(MH_REG_BASE + 0x04000230)      // DMA Channel 3 Frame Descriptor Address register
#define     MH_FSADR3           (volatile U32 *)(MH_REG_BASE + 0x04000234)      // DMA Channel 3 Frame Source Address register
#define     MH_FIDR3            (volatile U32 *)(MH_REG_BASE + 0x04000238)      // DMA Channel 3 Frame ID register
#define     MH_LDCMD3           (volatile U32 *)(MH_REG_BASE + 0x0400023C)      // LCD DMA Channel 3 Command register
#define     MH_FDADR4           (volatile U32 *)(MH_REG_BASE + 0x04000240)      // DMA Channel 4 Frame Descriptor Address register
#define     MH_FSADR4           (volatile U32 *)(MH_REG_BASE + 0x04000244)      // DMA Channel 4 Frame Source Address register
#define     MH_FIDR4            (volatile U32 *)(MH_REG_BASE + 0x04000248)      // DMA Channel 4 Frame ID register
#define     MH_LDCMD4           (volatile U32 *)(MH_REG_BASE + 0x0400024C)      // LCD DMA Channel 4 Command register
#define     MH_FDADR5           (volatile U32 *)(MH_REG_BASE + 0x04000250)      // DMA Channel 5 Frame Descriptor Address register
#define     MH_FSADR5           (volatile U32 *)(MH_REG_BASE + 0x04000254)      // DMA Channel 5 Frame Source Address register
#define     MH_FIDR5            (volatile U32 *)(MH_REG_BASE + 0x04000258)      // DMA Channel 5 Frame ID register
#define     MH_LDCMD5           (volatile U32 *)(MH_REG_BASE + 0x0400025C)      // LCD DMA Channel 5 Command register
#define     MH_FDADR6           (volatile U32 *)(MH_REG_BASE + 0x04000260)      // DMA Channel 6 Frame Descriptor Address register
#define     MH_FSADR6           (volatile U32 *)(MH_REG_BASE + 0x04000264)      // DMA Channel 6 Frame Source Address register
#define     MH_FIDR6            (volatile U32 *)(MH_REG_BASE + 0x04000268)      // DMA Channel 6 Frame ID register
#define     MH_LDCMD6           (volatile U32 *)(MH_REG_BASE + 0x0400026C)      // LCD DMA Channel 6 Command register
#define     MH_LCDBSCNTR        (volatile U32 *)(MH_REG_BASE + 0x08000054)      // LCD Buffer Strength Control register

//
// Mini-LCD Controller Register Summary
//
#define     MH_MLCCR0           (volatile U32 *)(MH_REG_BASE + 0x06000000)      // Mini-LCD Controller Control register 0
#define     MH_MLCCR1           (volatile U32 *)(MH_REG_BASE + 0x06000004)      // Mini-LCD Controller Control register 1
#define     MH_MLCCR2           (volatile U32 *)(MH_REG_BASE + 0x06000008)      // Mini-LCD Controller Control register 2
#define     MH_MLSADD           (volatile U32 *)(MH_REG_BASE + 0x0600000C)      // Mini-LCD SRAM Address register
#define     MH_MLFRMCNT         (volatile U32 *)(MH_REG_BASE + 0x06000010)      // Mini-LCD Frame Count register

//
// Keypad Controller Register Summary
//
#define     MH_KPC              (volatile U32 *)(MH_REG_BASE + 0x01500000)      // Keypad Control register
#define     MH_KPDK             (volatile U32 *)(MH_REG_BASE + 0x01500008)      // Keypad Direct Key register
#define     MH_KPREC            (volatile U32 *)(MH_REG_BASE + 0x01500010)      // Keypad Rotary Encoder Count register
#define     MH_KPMK             (volatile U32 *)(MH_REG_BASE + 0x01500018)      // Keypad Matrix Key register
#define     MH_KPAS             (volatile U32 *)(MH_REG_BASE + 0x01500020)      // Keypad Automatic Scan register
#define     MH_KPASMKP0         (volatile U32 *)(MH_REG_BASE + 0x01500028)      // Keypad Automatic Scan Multiple keypress register 0
#define     MH_KPASMKP1         (volatile U32 *)(MH_REG_BASE + 0x01500030)      // Keypad Automatic Scan Multiple keypress register 1
#define     MH_KPASMKP2         (volatile U32 *)(MH_REG_BASE + 0x01500038)      // Keypad Automatic Scan Multiple keypress register 2
#define     MH_KPASMKP3         (volatile U32 *)(MH_REG_BASE + 0x01500040)      // Keypad Automatic Scan Multiple keypress register 3
#define     MH_KPKDI            (volatile U32 *)(MH_REG_BASE + 0x01500048)      // Keypad Key Debounce Interval register

//
// ADC and Touch Screen Interface Register Summary
//
#define     MH_ADCD             (volatile U32 *)(MH_REG_BASE + 0x01C00000)      // Analog-to-Digital Converter Data register
#define     MH_ADCS             (volatile U32 *)(MH_REG_BASE + 0x01C00004)      // Analog-to-Digital Converter Setup register
#define     MH_ADCE             (volatile U32 *)(MH_REG_BASE + 0x01C00008)      // Analog-to-Digital Converter Enable register
#define     MH_ADCP             (volatile U32 *)(MH_REG_BASE + 0x01C0000C)      // Analog-to-Digital Converter Pressure register

//
// UDC Register Summary
//
#define     MH_UDCCR            (volatile U32 *)(MH_REG_BASE + 0x00600000)      // UDC Control register
#define     MH_UDCICR0          (volatile U32 *)(MH_REG_BASE + 0x00600004)      // UDC Interrupt Control register 0
#define     MH_UDCICR1          (volatile U32 *)(MH_REG_BASE + 0x00600008)      // UDC Interrupt Control register 1
#define     MH_UDCISR0          (volatile U32 *)(MH_REG_BASE + 0x0060000C)      // UDC Interrupt Status register 0
#define     MH_UDCISR1          (volatile U32 *)(MH_REG_BASE + 0x00600010)      // UDC Interrupt Status register 1
#define     MH_UDCFNR           (volatile U32 *)(MH_REG_BASE + 0x00600014)      // UDC Frame Number register
#define     MH_UDCOTGICR        (volatile U32 *)(MH_REG_BASE + 0x00600018)      // UDC OTG Interrupt Control register
#define     MH_UDCOTGISR        (volatile U32 *)(MH_REG_BASE + 0x0060001C)      // UDC OTG Interrupt Status register
#define     MH_UP2OCR           (volatile U32 *)(MH_REG_BASE + 0x00600020)      // USB Port 2 Output Control register
#define     MH_UP3OCR           (volatile U32 *)(MH_REG_BASE + 0x00600024)      // USB Port 3 Output Control register
#define     MH_UDCCSR0          (volatile U32 *)(MH_REG_BASE + 0x00600100)      // UDC Control/Status register - Endpoint 0
#define     MH_UDCCSRA          (volatile U32 *)(MH_REG_BASE + 0x00600104)      // UDC Control/Status register - Endpoint A
#define     MH_UDCCSRB          (volatile U32 *)(MH_REG_BASE + 0x00600108)      // UDC Control/Status register - Endpoint B
#define     MH_UDCCSRC          (volatile U32 *)(MH_REG_BASE + 0x0060010C)      // UDC Control/Status register - Endpoint C
#define     MH_UDCCSRD          (volatile U32 *)(MH_REG_BASE + 0x00600110)      // UDC Control/Status register - Endpoint D
#define     MH_UDCCSRE          (volatile U32 *)(MH_REG_BASE + 0x00600114)      // UDC Control/Status register - Endpoint E
#define     MH_UDCCSRF          (volatile U32 *)(MH_REG_BASE + 0x00600118)      // UDC Control/Status register - Endpoint F
#define     MH_UDCCSRG          (volatile U32 *)(MH_REG_BASE + 0x0060011C)      // UDC Control/Status register - Endpoint G
#define     MH_UDCCSRH          (volatile U32 *)(MH_REG_BASE + 0x00600120)      // UDC Control/Status register - Endpoint H
#define     MH_UDCCSRI          (volatile U32 *)(MH_REG_BASE + 0x00600124)      // UDC Control/Status register - Endpoint I
#define     MH_UDCCSRJ          (volatile U32 *)(MH_REG_BASE + 0x00600128)      // UDC Control/Status register - Endpoint J
#define     MH_UDCCSRK          (volatile U32 *)(MH_REG_BASE + 0x0060012C)      // UDC Control/Status register - Endpoint K
#define     MH_UDCCSRL          (volatile U32 *)(MH_REG_BASE + 0x00600130)      // UDC Control/Status register - Endpoint L
#define     MH_UDCCSRM          (volatile U32 *)(MH_REG_BASE + 0x00600134)      // UDC Control/Status register - Endpoint M
#define     MH_UDCCSRN          (volatile U32 *)(MH_REG_BASE + 0x00600138)      // UDC Control/Status register - Endpoint N
#define     MH_UDCCSRP          (volatile U32 *)(MH_REG_BASE + 0x0060013C)      // UDC Control/Status register - Endpoint P
#define     MH_UDCCSRQ          (volatile U32 *)(MH_REG_BASE + 0x00600140)      // UDC Control/Status register - Endpoint Q
#define     MH_UDCCSRR          (volatile U32 *)(MH_REG_BASE + 0x00600144)      // UDC Control/Status register - Endpoint R
#define     MH_UDCCSRS          (volatile U32 *)(MH_REG_BASE + 0x00600148)      // UDC Control/Status register - Endpoint S
#define     MH_UDCCSRT          (volatile U32 *)(MH_REG_BASE + 0x0060014C)      // UDC Control/Status register - Endpoint T
#define     MH_UDCCSRU          (volatile U32 *)(MH_REG_BASE + 0x00600150)      // UDC Control/Status register - Endpoint U
#define     MH_UDCCSRV          (volatile U32 *)(MH_REG_BASE + 0x00600154)      // UDC Control/Status register - Endpoint V
#define     MH_UDCCSRW          (volatile U32 *)(MH_REG_BASE + 0x00600158)      // UDC Control/Status register - Endpoint W
#define     MH_UDCCSRX          (volatile U32 *)(MH_REG_BASE + 0x0060015C)      // UDC Control/Status register - Endpoint X
#define     MH_UDCBCR0          (volatile U32 *)(MH_REG_BASE + 0x00600200)      // UDC Byte Count register - Endpoint 0
#define     MH_UDCBCRA          (volatile U32 *)(MH_REG_BASE + 0x00600204)      // UDC Byte Count register - Endpoint A
#define     MH_UDCBCRB          (volatile U32 *)(MH_REG_BASE + 0x00600208)      // UDC Byte Count register - Endpoint B
#define     MH_UDCBCRC          (volatile U32 *)(MH_REG_BASE + 0x0060020C)      // UDC Byte Count register - Endpoint C
#define     MH_UDCBCRD          (volatile U32 *)(MH_REG_BASE + 0x00600210)      // UDC Byte Count register - Endpoint D
#define     MH_UDCBCRE          (volatile U32 *)(MH_REG_BASE + 0x00600214)      // UDC Byte Count register - Endpoint E
#define     MH_UDCBCRF          (volatile U32 *)(MH_REG_BASE + 0x00600218)      // UDC Byte Count register - Endpoint F
#define     MH_UDCBCRG          (volatile U32 *)(MH_REG_BASE + 0x0060021C)      // UDC Byte Count register - Endpoint G
#define     MH_UDCBCRH          (volatile U32 *)(MH_REG_BASE + 0x00600220)      // UDC Byte Count register - Endpoint H
#define     MH_UDCBCRI          (volatile U32 *)(MH_REG_BASE + 0x00600224)      // UDC Byte Count register - Endpoint I
#define     MH_UDCBCRJ          (volatile U32 *)(MH_REG_BASE + 0x00600228)      // UDC Byte Count register - Endpoint J
#define     MH_UDCBCRK          (volatile U32 *)(MH_REG_BASE + 0x0060022C)      // UDC Byte Count register - Endpoint K
#define     MH_UDCBCRL          (volatile U32 *)(MH_REG_BASE + 0x00600230)      // UDC Byte Count register - Endpoint L
#define     MH_UDCBCRM          (volatile U32 *)(MH_REG_BASE + 0x00600234)      // UDC Byte Count register - Endpoint M
#define     MH_UDCBCRN          (volatile U32 *)(MH_REG_BASE + 0x00600238)      // UDC Byte Count register - Endpoint N
#define     MH_UDCBCRP          (volatile U32 *)(MH_REG_BASE + 0x0060023C)      // UDC Byte Count register - Endpoint P
#define     MH_UDCBCRQ          (volatile U32 *)(MH_REG_BASE + 0x00600240)      // UDC Byte Count register - Endpoint Q
#define     MH_UDCBCRR          (volatile U32 *)(MH_REG_BASE + 0x00600244)      // UDC Byte Count register - Endpoint R
#define     MH_UDCBCRS          (volatile U32 *)(MH_REG_BASE + 0x00600248)      // UDC Byte Count register - Endpoint S
#define     MH_UDCBCRT          (volatile U32 *)(MH_REG_BASE + 0x0060024C)      // UDC Byte Count register - Endpoint T
#define     MH_UDCBCRU          (volatile U32 *)(MH_REG_BASE + 0x00600250)      // UDC Byte Count register - Endpoint U
#define     MH_UDCBCRV          (volatile U32 *)(MH_REG_BASE + 0x00600254)      // UDC Byte Count register - Endpoint V
#define     MH_UDCBCRW          (volatile U32 *)(MH_REG_BASE + 0x00600258)      // UDC Byte Count register - Endpoint W
#define     MH_UDCBCRX          (volatile U32 *)(MH_REG_BASE + 0x0060025C)      // UDC Byte Count register - Endpoint X
#define     MH_UDCDR0           (volatile U32 *)(MH_REG_BASE + 0x00600300)      // UDC Data register - Endpoint 0
#define     MH_UDCDRA           (volatile U32 *)(MH_REG_BASE + 0x00600304)      // UDC Data register - Endpoint A
#define     MH_UDCDRB           (volatile U32 *)(MH_REG_BASE + 0x00600308)      // UDC Data register - Endpoint B
#define     MH_UDCDRC           (volatile U32 *)(MH_REG_BASE + 0x0060030C)      // UDC Data register - Endpoint C
#define     MH_UDCDRD           (volatile U32 *)(MH_REG_BASE + 0x00600310)      // UDC Data register - Endpoint D
#define     MH_UDCDRE           (volatile U32 *)(MH_REG_BASE + 0x00600314)      // UDC Data register - Endpoint E
#define     MH_UDCDRF           (volatile U32 *)(MH_REG_BASE + 0x00600318)      // UDC Data register - Endpoint F
#define     MH_UDCDRG           (volatile U32 *)(MH_REG_BASE + 0x0060031C)      // UDC Data register - Endpoint G
#define     MH_UDCDRH           (volatile U32 *)(MH_REG_BASE + 0x00600320)      // UDC Data register - Endpoint H
#define     MH_UDCDRI           (volatile U32 *)(MH_REG_BASE + 0x00600324)      // UDC Data register - Endpoint I
#define     MH_UDCDRJ           (volatile U32 *)(MH_REG_BASE + 0x00600328)      // UDC Data register - Endpoint J
#define     MH_UDCDRK           (volatile U32 *)(MH_REG_BASE + 0x0060032C)      // UDC Data register - Endpoint K
#define     MH_UDCDRL           (volatile U32 *)(MH_REG_BASE + 0x00600330)      // UDC Data register - Endpoint L
#define     MH_UDCDRM           (volatile U32 *)(MH_REG_BASE + 0x00600334)      // UDC Data register - Endpoint M
#define     MH_UDCDRN           (volatile U32 *)(MH_REG_BASE + 0x00600338)      // UDC Data register - Endpoint N
#define     MH_UDCDRP           (volatile U32 *)(MH_REG_BASE + 0x0060033C)      // UDC Data register - Endpoint P
#define     MH_UDCDRQ           (volatile U32 *)(MH_REG_BASE + 0x00600340)      // UDC Data register - Endpoint Q
#define     MH_UDCDRR           (volatile U32 *)(MH_REG_BASE + 0x00600344)      // UDC Data register - Endpoint R
#define     MH_UDCDRS           (volatile U32 *)(MH_REG_BASE + 0x00600348)      // UDC Data register - Endpoint S
#define     MH_UDCDRT           (volatile U32 *)(MH_REG_BASE + 0x0060034C)      // UDC Data register - Endpoint T
#define     MH_UDCDRU           (volatile U32 *)(MH_REG_BASE + 0x00600350)      // UDC Data register - Endpoint U
#define     MH_UDCDRV           (volatile U32 *)(MH_REG_BASE + 0x00600354)      // UDC Data register - Endpoint V
#define     MH_UDCDRW           (volatile U32 *)(MH_REG_BASE + 0x00600358)      // UDC Data register - Endpoint W
#define     MH_UDCDRX           (volatile U32 *)(MH_REG_BASE + 0x0060035C)      // UDC Data register - Endpoint X
#define     MH_UDCCR0           (volatile U32 *)(MH_REG_BASE + 0x00600400)      // Not exist at all
#define     MH_UDCCRA           (volatile U32 *)(MH_REG_BASE + 0x00600404)      // UDC Configuration register - Endpoint A
#define     MH_UDCCRB           (volatile U32 *)(MH_REG_BASE + 0x00600408)      // UDC Configuration register - Endpoint B
#define     MH_UDCCRC           (volatile U32 *)(MH_REG_BASE + 0x0060040C)      // UDC Configuration register - Endpoint C
#define     MH_UDCCRD           (volatile U32 *)(MH_REG_BASE + 0x00600410)      // UDC Configuration register - Endpoint D
#define     MH_UDCCRE           (volatile U32 *)(MH_REG_BASE + 0x00600414)      // UDC Configuration register - Endpoint E
#define     MH_UDCCRF           (volatile U32 *)(MH_REG_BASE + 0x00600418)      // UDC Configuration register - Endpoint F
#define     MH_UDCCRG           (volatile U32 *)(MH_REG_BASE + 0x0060041C)      // UDC Configuration register - Endpoint G
#define     MH_UDCCRH           (volatile U32 *)(MH_REG_BASE + 0x00600420)      // UDC Configuration register - Endpoint H
#define     MH_UDCCRI           (volatile U32 *)(MH_REG_BASE + 0x00600424)      // UDC Configuration register - Endpoint I
#define     MH_UDCCRJ           (volatile U32 *)(MH_REG_BASE + 0x00600428)      // UDC Configuration register - Endpoint J
#define     MH_UDCCRK           (volatile U32 *)(MH_REG_BASE + 0x0060042C)      // UDC Configuration register - Endpoint K
#define     MH_UDCCRL           (volatile U32 *)(MH_REG_BASE + 0x00600430)      // UDC Configuration register - Endpoint L
#define     MH_UDCCRM           (volatile U32 *)(MH_REG_BASE + 0x00600434)      // UDC Configuration register - Endpoint M
#define     MH_UDCCRN           (volatile U32 *)(MH_REG_BASE + 0x00600438)      // UDC Configuration register - Endpoint N
#define     MH_UDCCRP           (volatile U32 *)(MH_REG_BASE + 0x0060043C)      // UDC Configuration register - Endpoint P
#define     MH_UDCCRQ           (volatile U32 *)(MH_REG_BASE + 0x00600440)      // UDC Configuration register - Endpoint Q
#define     MH_UDCCRR           (volatile U32 *)(MH_REG_BASE + 0x00600444)      // UDC Configuration register - Endpoint R
#define     MH_UDCCRS           (volatile U32 *)(MH_REG_BASE + 0x00600448)      // UDC Configuration register - Endpoint S
#define     MH_UDCCRT           (volatile U32 *)(MH_REG_BASE + 0x0060044C)      // UDC Configuration register - Endpoint T
#define     MH_UDCCRU           (volatile U32 *)(MH_REG_BASE + 0x00600450)      // UDC Configuration register - Endpoint U
#define     MH_UDCCRV           (volatile U32 *)(MH_REG_BASE + 0x00600454)      // UDC Configuration register - Endpoint V
#define     MH_UDCCRW           (volatile U32 *)(MH_REG_BASE + 0x00600458)      // UDC Configuration register - Endpoint W
#define     MH_UDCCRX           (volatile U32 *)(MH_REG_BASE + 0x0060045C)      // UDC Configuration register - Endpoint X

//
// USB 2.0 Client controller Register Addressses
//
#define   MH_U2DCR              (volatile U32 *)(MH_REG_BASE + 0x14100000)      // U2D Control register
#define   MH_U2DICR             (volatile U32 *)(MH_REG_BASE + 0x14100004)      // U2D Interrupt Control register
#define   MH_U2DICR2            (volatile U32 *)(MH_REG_BASE + 0x14100008)      // U2D Interrupt Control register(Endpoints H-P)
#define   MH_U2DISR             (volatile U32 *)(MH_REG_BASE + 0x1410000C)      // U2D Interrupt Status register
#define   MH_U2DISR2            (volatile U32 *)(MH_REG_BASE + 0x14100010)      // U2D Interrupt Status register(Endpoints H-P)
#define   MH_U2DFNR             (volatile U32 *)(MH_REG_BASE + 0x14100014)      // U2D Frame Number register
#define   MH_U2DOTGCR           (volatile U32 *)(MH_REG_BASE + 0x14100020)      // U2D OTG Control register
#define   MH_U2DOTGICR          (volatile U32 *)(MH_REG_BASE + 0x14100024)      // U2D OTG Interrupt Control/Enable register
#define   MH_U2DOTGISR          (volatile U32 *)(MH_REG_BASE + 0x14100028)      // U2D OTG Interrupt Status register
#define   MH_U2DOTGUSR          (volatile U32 *)(MH_REG_BASE + 0x1410002C)      // U2D OTG ULPI Status register
#define   MH_U2DOTGUCR          (volatile U32 *)(MH_REG_BASE + 0x14100030)      // U2D OTG ULPI Control register
#define   MH_U2DP3CR            (volatile U32 *)(MH_REG_BASE + 0x14100034)      // U2D Host Port3 Control register

#define   MH_U2DCSRx            (volatile U32 *)(MH_REG_BASE + 0x14100100)      // U2D Control/Status register - Endpoint
#define   MH_U2DCSR0            (volatile U32 *)(MH_REG_BASE + 0x14100100)      // U2D Control/Status register - Endpoint 0
#define   MH_U2DCSRA            (volatile U32 *)(MH_REG_BASE + 0x14100104)      // U2D Control/Status register - Endpoint A
#define   MH_U2DCSRB            (volatile U32 *)(MH_REG_BASE + 0x14100108)      // U2D Control/Status register - Endpoint B
#define   MH_U2DCSRC            (volatile U32 *)(MH_REG_BASE + 0x1410010C)      // U2D Control/Status register - Endpoint C
#define   MH_U2DCSRD            (volatile U32 *)(MH_REG_BASE + 0x14100110)      // U2D Control/Status register - Endpoint D
#define   MH_U2DCSRE            (volatile U32 *)(MH_REG_BASE + 0x14100114)      // U2D Control/Status register - Endpoint E
#define   MH_U2DCSRF            (volatile U32 *)(MH_REG_BASE + 0x14100118)      // U2D Control/Status register - Endpoint F
#define   MH_U2DCSRG            (volatile U32 *)(MH_REG_BASE + 0x1410011C)      // U2D Control/Status register - Endpoint G
#define   MH_U2DCSRH            (volatile U32 *)(MH_REG_BASE + 0x14100120)      // U2D Control/Status register - Endpoint H
#define   MH_U2DCSRI            (volatile U32 *)(MH_REG_BASE + 0x14100124)      // U2D Control/Status register - Endpoint I
#define   MH_U2DCSRJ            (volatile U32 *)(MH_REG_BASE + 0x14100128)      // U2D Control/Status register - Endpoint J
#define   MH_U2DCSRK            (volatile U32 *)(MH_REG_BASE + 0x1410012C)      // U2D Control/Status register - Endpoint K
#define   MH_U2DCSRL            (volatile U32 *)(MH_REG_BASE + 0x14100130)      // U2D Control/Status register - Endpoint L
#define   MH_U2DCSRM            (volatile U32 *)(MH_REG_BASE + 0x14100134)      // U2D Control/Status register - Endpoint M
#define   MH_U2DCSRN            (volatile U32 *)(MH_REG_BASE + 0x14100138)      // U2D Control/Status register - Endpoint N
#define   MH_U2DCSRP            (volatile U32 *)(MH_REG_BASE + 0x1410013C)      // U2D Control/Status register - Endpoint P

#define   MH_U2DBCRx            (volatile U32 *)(MH_REG_BASE + 0x14100200)      // U2D Byte Count register - Endpoint
#define   MH_U2DBCR0            (volatile U32 *)(MH_REG_BASE + 0x14100200)      // U2D Byte Count register - Endpoint 0
#define   MH_U2DBCRA            (volatile U32 *)(MH_REG_BASE + 0x14100204)      // U2D Byte Count register - Endpoint A
#define   MH_U2DBCRB            (volatile U32 *)(MH_REG_BASE + 0x14100208)      // U2D Byte Count register - Endpoint B
#define   MH_U2DBCRC            (volatile U32 *)(MH_REG_BASE + 0x1410020C)      // U2D Byte Count register - Endpoint C
#define   MH_U2DBCRD            (volatile U32 *)(MH_REG_BASE + 0x14100210)      // U2D Byte Count register - Endpoint D
#define   MH_U2DBCRE            (volatile U32 *)(MH_REG_BASE + 0x14100214)      // U2D Byte Count register - Endpoint E
#define   MH_U2DBCRF            (volatile U32 *)(MH_REG_BASE + 0x14100218)      // U2D Byte Count register - Endpoint F
#define   MH_U2DBCRG            (volatile U32 *)(MH_REG_BASE + 0x1410021C)      // U2D Byte Count register - Endpoint G

#define   MH_U2DDR0             (volatile U32 *)(MH_REG_BASE + 0x14100300)      // U2D Data register - Endpoint 0

#define   MH_U2DCRx             (volatile U32 *)(MH_REG_BASE + 0x14100400)      // U2D Configuration register, this defination is just for software program
                                                                                //- !!! Endpoint 0 is not valid !!!
#define   MH_U2DCRA             (volatile U32 *)(MH_REG_BASE + 0x14100404)      // U2D Configuration register - Endpoint A
#define   MH_U2DCRB             (volatile U32 *)(MH_REG_BASE + 0x14100408)      // U2D Configuration register - Endpoint B
#define   MH_U2DCRC             (volatile U32 *)(MH_REG_BASE + 0x1410040C)      // U2D Configuration register - Endpoint C
#define   MH_U2DCRD             (volatile U32 *)(MH_REG_BASE + 0x14100410)      // U2D Configuration register - Endpoint D
#define   MH_U2DCRE             (volatile U32 *)(MH_REG_BASE + 0x14100414)      // U2D Configuration register - Endpoint E
#define   MH_U2DCRF             (volatile U32 *)(MH_REG_BASE + 0x14100418)      // U2D Configuration register - Endpoint F
#define   MH_U2DCRG             (volatile U32 *)(MH_REG_BASE + 0x1410041C)      // U2D Configuration register - Endpoint G
#define   MH_U2DCRH             (volatile U32 *)(MH_REG_BASE + 0x14100420)      // U2D Configuration register - Endpoint H
#define   MH_U2DCRI             (volatile U32 *)(MH_REG_BASE + 0x14100424)      // U2D Configuration register - Endpoint I
#define   MH_U2DCRJ             (volatile U32 *)(MH_REG_BASE + 0x14100428)      // U2D Configuration register - Endpoint J
#define   MH_U2DCRK             (volatile U32 *)(MH_REG_BASE + 0x1410042C)      // U2D Configuration register - Endpoint K
#define   MH_U2DCRL             (volatile U32 *)(MH_REG_BASE + 0x14100430)      // U2D Configuration register - Endpoint L
#define   MH_U2DCRM             (volatile U32 *)(MH_REG_BASE + 0x14100434)      // U2D Configuration register - Endpoint M
#define   MH_U2DCRN             (volatile U32 *)(MH_REG_BASE + 0x14100438)      // U2D Configuration register - Endpoint N
#define   MH_U2DCRP             (volatile U32 *)(MH_REG_BASE + 0x1410043C)      // U2D Configuration register - Endpoint P

#define   MH_U2DSCA             (volatile U32 *)(MH_REG_BASE + 0x14100500)      // U2D Setup Command Address

#define   MH_U2DENx             (volatile U32 *)(MH_REG_BASE + 0x14100504)      // U2D Endpoint Information register - Endpoint
#define   MH_U2DNE0             (volatile U32 *)(MH_REG_BASE + 0x14100504)      // U2D Endpoint Information register - Endpoint 0
#define   MH_U2DNEA             (volatile U32 *)(MH_REG_BASE + 0x14100508)      // U2D Endpoint Information register - Endpoint A
#define   MH_U2DNEB             (volatile U32 *)(MH_REG_BASE + 0x1410050C)      // U2D Endpoint Information register - Endpoint B
#define   MH_U2DNEC             (volatile U32 *)(MH_REG_BASE + 0x14100510)      // U2D Endpoint Information register - Endpoint C
#define   MH_U2DNED             (volatile U32 *)(MH_REG_BASE + 0x14100514)      // U2D Endpoint Information register - Endpoint D
#define   MH_U2DNEE             (volatile U32 *)(MH_REG_BASE + 0x14100518)      // U2D Endpoint Information register - Endpoint E
#define   MH_U2DNEF             (volatile U32 *)(MH_REG_BASE + 0x1410051C)      // U2D Endpoint Information register - Endpoint F
#define   MH_U2DNEG             (volatile U32 *)(MH_REG_BASE + 0x14100520)      // U2D Endpoint Information register - Endpoint G
#define   MH_U2DNEH             (volatile U32 *)(MH_REG_BASE + 0x14100524)      // U2D Endpoint Information register - Endpoint H
#define   MH_U2DNEI             (volatile U32 *)(MH_REG_BASE + 0x14100528)      // U2D Endpoint Information register - Endpoint I
#define   MH_U2DNEJ             (volatile U32 *)(MH_REG_BASE + 0x1410052C)      // U2D Endpoint Information register - Endpoint J
#define   MH_U2DNEK             (volatile U32 *)(MH_REG_BASE + 0x14100530)      // U2D Endpoint Information register - Endpoint K
#define   MH_U2DNEL             (volatile U32 *)(MH_REG_BASE + 0x14100534)      // U2D Endpoint Information register - Endpoint L
#define   MH_U2DNEM             (volatile U32 *)(MH_REG_BASE + 0x14100538)      // U2D Endpoint Information register - Endpoint M
#define   MH_U2DNEN             (volatile U32 *)(MH_REG_BASE + 0x1410053C)      // U2D Endpoint Information register - Endpoint N
#define   MH_U2DNEP             (volatile U32 *)(MH_REG_BASE + 0x14100540)      // U2D Endpoint Information register - Endpoint P

#define   MH_U2DMACSRx          (volatile U32 *)(MH_REG_BASE + 0x14101000)      // U2D Control/Status register for channel
#define   MH_U2DMACSR0          (volatile U32 *)(MH_REG_BASE + 0x14101000)      // U2D Control/Status register for channel 0
#define   MH_U2DMACSR1          (volatile U32 *)(MH_REG_BASE + 0x14101004)      // U2D Control/Status register for channel 1
#define   MH_U2DMACSR2          (volatile U32 *)(MH_REG_BASE + 0x14101008)      // U2D Control/Status register for channel 2
#define   MH_U2DMACSR3          (volatile U32 *)(MH_REG_BASE + 0x1410100C)      // U2D Control/Status register for channel 3
#define   MH_U2DMACSR4          (volatile U32 *)(MH_REG_BASE + 0x14101010)      // U2D Control/Status register for channel 4
#define   MH_U2DMACSR5          (volatile U32 *)(MH_REG_BASE + 0x14101014)      // U2D Control/Status register for channel 5
#define   MH_U2DMACSR6          (volatile U32 *)(MH_REG_BASE + 0x14101018)      // U2D Control/Status register for channel 6
#define   MH_U2DMACSR7          (volatile U32 *)(MH_REG_BASE + 0x1410101C)      // U2D Control/Status register for channel 7
#define   MH_U2DMACSR8          (volatile U32 *)(MH_REG_BASE + 0x14101020)      // U2D Control/Status register for channel 8
#define   MH_U2DMACSR9          (volatile U32 *)(MH_REG_BASE + 0x14101024)      // U2D Control/Status register for channel 9
#define   MH_U2DMACSR10         (volatile U32 *)(MH_REG_BASE + 0x14101028)      // U2D Control/Status register for channel 10
#define   MH_U2DMACSR11         (volatile U32 *)(MH_REG_BASE + 0x1410102C)      // U2D Control/Status register for channel 11
#define   MH_U2DMACSR12         (volatile U32 *)(MH_REG_BASE + 0x14101030)      // U2D Control/Status register for channel 12
#define   MH_U2DMACSR13         (volatile U32 *)(MH_REG_BASE + 0x14101034)      // U2D Control/Status register for channel 13
#define   MH_U2DMACSR14         (volatile U32 *)(MH_REG_BASE + 0x14101038)      // U2D Control/Status register for channel 14
#define   MH_U2DMACSR15         (volatile U32 *)(MH_REG_BASE + 0x1410103C)      // U2D Control/Status register for channel 15

#define   MH_U2DMACR            (volatile U32 *)(MH_REG_BASE + 0x14101080)      // U2D Control register
#define   MH_U2DMAINT           (volatile U32 *)(MH_REG_BASE + 0x141010F0)      // U2D Interrupt register

#define   MH_U2DMABR0           (volatile U32 *)(MH_REG_BASE + 0x14101100)      // U2D Branch register for channel 0
#define   MH_U2DMABR1           (volatile U32 *)(MH_REG_BASE + 0x14101104)      // U2D Branch register for channel 1
#define   MH_U2DMABR2           (volatile U32 *)(MH_REG_BASE + 0x14101108)      // U2D Branch register for channel 2
#define   MH_U2DMABR3           (volatile U32 *)(MH_REG_BASE + 0x1410110C)      // U2D Branch register for channel 3
#define   MH_U2DMABR4           (volatile U32 *)(MH_REG_BASE + 0x14101110)      // U2D Branch register for channel 4
#define   MH_U2DMABR5           (volatile U32 *)(MH_REG_BASE + 0x14101114)      // U2D Branch register for channel 5
#define   MH_U2DMABR6           (volatile U32 *)(MH_REG_BASE + 0x14101118)      // U2D Branch register for channel 6
#define   MH_U2DMABR7           (volatile U32 *)(MH_REG_BASE + 0x1410111C)      // U2D Branch register for channel 7
#define   MH_U2DMABR8           (volatile U32 *)(MH_REG_BASE + 0x14101120)      // U2D Branch register for channel 8
#define   MH_U2DMABR9           (volatile U32 *)(MH_REG_BASE + 0x14101124)      // U2D Branch register for channel 9
#define   MH_U2DMABR10          (volatile U32 *)(MH_REG_BASE + 0x14101128)      // U2D Branch register for channel 10
#define   MH_U2DMABR11          (volatile U32 *)(MH_REG_BASE + 0x1410112C)      // U2D Branch register for channel 11
#define   MH_U2DMABR12          (volatile U32 *)(MH_REG_BASE + 0x14101130)      // U2D Branch register for channel 12
#define   MH_U2DMABR13          (volatile U32 *)(MH_REG_BASE + 0x14101134)      // U2D Branch register for channel 13
#define   MH_U2DMABR14          (volatile U32 *)(MH_REG_BASE + 0x14101138)      // U2D Branch register for channel 14
#define   MH_U2DMABR15          (volatile U32 *)(MH_REG_BASE + 0x1410113C)      // U2D Branch register for channel 15

#define   MH_U2DDMAADDR         (volatile U2D_DMA_REGs_t *)(MH_REG_BASE + 0x14101200)      // U2D DMA Address register
#define   MH_U2DMADADR0         (volatile U32 *)(MH_REG_BASE + 0x14101200)      // U2D Descriptor Address register channel 0
#define   MH_U2DMASADR0         (volatile U32 *)(MH_REG_BASE + 0x14101204)      // U2D Source Address register channel 0
#define   MH_U2DMATADR0         (volatile U32 *)(MH_REG_BASE + 0x14101208)      // U2D Target Address register channel 0
#define   MH_U2DMACMD0          (volatile U32 *)(MH_REG_BASE + 0x1410120C)      // U2D Command Address register channel 0
#define   MH_U2DMADADR1         (volatile U32 *)(MH_REG_BASE + 0x14101210)      // U2D Descriptor Address register channel 1
#define   MH_U2DMASADR1         (volatile U32 *)(MH_REG_BASE + 0x14101214)      // U2D Source Address register channel 1
#define   MH_U2DMATADR1         (volatile U32 *)(MH_REG_BASE + 0x14101218)      // U2D Target Address register channel 1
#define   MH_U2DMACMD1          (volatile U32 *)(MH_REG_BASE + 0x1410121C)      // U2D Command Address register channel 1
#define   MH_U2DMADADR2         (volatile U32 *)(MH_REG_BASE + 0x14101220)      // U2D Descriptor Address register channel 2
#define   MH_U2DMASADR2         (volatile U32 *)(MH_REG_BASE + 0x14101224)      // U2D Source Address register channel 2
#define   MH_U2DMATADR2         (volatile U32 *)(MH_REG_BASE + 0x14101228)      // U2D Target Address register channel 2
#define   MH_U2DMACMD2          (volatile U32 *)(MH_REG_BASE + 0x1410122C)      // U2D Command Address register channel 2
#define   MH_U2DMADADR3         (volatile U32 *)(MH_REG_BASE + 0x14101230)      // U2D Descriptor Address register channel 3
#define   MH_U2DMASADR3         (volatile U32 *)(MH_REG_BASE + 0x14101234)      // U2D Source Address register channel 3
#define   MH_U2DMATADR3         (volatile U32 *)(MH_REG_BASE + 0x14101238)      // U2D Target Address register channel 3
#define   MH_U2DMACMD3          (volatile U32 *)(MH_REG_BASE + 0x1410123C)      // U2D Command Address register channel 3
#define   MH_U2DMADADR4         (volatile U32 *)(MH_REG_BASE + 0x14101240)      // U2D Descriptor Address register channel 4
#define   MH_U2DMASADR4         (volatile U32 *)(MH_REG_BASE + 0x14101244)      // U2D Source Address register channel 4
#define   MH_U2DMATADR4         (volatile U32 *)(MH_REG_BASE + 0x14101248)      // U2D Target Address register channel 4
#define   MH_U2DMACMD4          (volatile U32 *)(MH_REG_BASE + 0x1410124C)      // U2D Command Address register channel 4
#define   MH_U2DMADADR5         (volatile U32 *)(MH_REG_BASE + 0x14101250)      // U2D Descriptor Address register channel 5
#define   MH_U2DMASADR5         (volatile U32 *)(MH_REG_BASE + 0x14101254)      // U2D Source Address register channel 5
#define   MH_U2DMATADR5         (volatile U32 *)(MH_REG_BASE + 0x14101258)      // U2D Target Address register channel 5
#define   MH_U2DMACMD5          (volatile U32 *)(MH_REG_BASE + 0x1410125C)      // U2D Command Address register channel 5
#define   MH_U2DMADADR6         (volatile U32 *)(MH_REG_BASE + 0x14101260)      // U2D Descriptor Address register channel 6
#define   MH_U2DMASADR6         (volatile U32 *)(MH_REG_BASE + 0x14101264)      // U2D Source Address register channel 6
#define   MH_U2DMATADR6         (volatile U32 *)(MH_REG_BASE + 0x14101268)      // U2D Target Address register channel 6
#define   MH_U2DMACMD6          (volatile U32 *)(MH_REG_BASE + 0x1410126C)      // U2D Command Address register channel 6
#define   MH_U2DMADADR7         (volatile U32 *)(MH_REG_BASE + 0x14101270)      // U2D Descriptor Address register channel 7
#define   MH_U2DMASADR7         (volatile U32 *)(MH_REG_BASE + 0x14101274)      // U2D Source Address register channel 7
#define   MH_U2DMATADR7         (volatile U32 *)(MH_REG_BASE + 0x14101278)      // U2D Target Address register channel 7
#define   MH_U2DMACMD7          (volatile U32 *)(MH_REG_BASE + 0x1410127C)      // U2D Command Address register channel 7
#define   MH_U2DMADADR8         (volatile U32 *)(MH_REG_BASE + 0x14101280)      // U2D Descriptor Address register channel 8
#define   MH_U2DMASADR8         (volatile U32 *)(MH_REG_BASE + 0x14101284)      // U2D Source Address register channel 8
#define   MH_U2DMATADR8         (volatile U32 *)(MH_REG_BASE + 0x14101288)      // U2D Target Address register channel 8
#define   MH_U2DMACMD8          (volatile U32 *)(MH_REG_BASE + 0x1410128C)      // U2D Command Address register channel 8
#define   MH_U2DMADADR9         (volatile U32 *)(MH_REG_BASE + 0x14101290)      // U2D Descriptor Address register channel 9
#define   MH_U2DMASADR9         (volatile U32 *)(MH_REG_BASE + 0x14101294)      // U2D Source Address register channel 9
#define   MH_U2DMATADR9         (volatile U32 *)(MH_REG_BASE + 0x14101298)      // U2D Target Address register channel 9
#define   MH_U2DMACMD9          (volatile U32 *)(MH_REG_BASE + 0x1410129C)      // U2D Command Address register channel 9
#define   MH_U2DMADADR10        (volatile U32 *)(MH_REG_BASE + 0x141012A0)      // U2D Descriptor Address register channel 10
#define   MH_U2DMASADR10        (volatile U32 *)(MH_REG_BASE + 0x141012A4)      // U2D Source Address register channel 10
#define   MH_U2DMATADR10        (volatile U32 *)(MH_REG_BASE + 0x141012A8)      // U2D Target Address register channel 10
#define   MH_U2DMACMD10         (volatile U32 *)(MH_REG_BASE + 0x141012AC)      // U2D Command Address register channel 10
#define   MH_U2DMADADR11        (volatile U32 *)(MH_REG_BASE + 0x141012B0)      // U2D Descriptor Address register channel 11
#define   MH_U2DMASADR11        (volatile U32 *)(MH_REG_BASE + 0x141012B4)      // U2D Source Address register channel 11
#define   MH_U2DMATADR11        (volatile U32 *)(MH_REG_BASE + 0x141012B8)      // U2D Target Address register channel 11
#define   MH_U2DMACMD11         (volatile U32 *)(MH_REG_BASE + 0x141012BC)      // U2D Command Address register channel 11
#define   MH_U2DMADADR12        (volatile U32 *)(MH_REG_BASE + 0x141012C0)      // U2D Descriptor Address register channel 12
#define   MH_U2DMASADR12        (volatile U32 *)(MH_REG_BASE + 0x141012C4)      // U2D Source Address register channel 12
#define   MH_U2DMATADR12        (volatile U32 *)(MH_REG_BASE + 0x141012C8)      // U2D Target Address register channel 12
#define   MH_U2DMACMD12         (volatile U32 *)(MH_REG_BASE + 0x141012CC)      // U2D Command Address register channel 12
#define   MH_U2DMADADR13        (volatile U32 *)(MH_REG_BASE + 0x141012D0)      // U2D Descriptor Address register channel 13
#define   MH_U2DMASADR13        (volatile U32 *)(MH_REG_BASE + 0x141012D4)      // U2D Source Address register channel 13
#define   MH_U2DMATADR13        (volatile U32 *)(MH_REG_BASE + 0x141012D8)      // U2D Target Address register channel 13
#define   MH_U2DMACMD13         (volatile U32 *)(MH_REG_BASE + 0x141012DC)      // U2D Command Address register channel 13
#define   MH_U2DMADADR14        (volatile U32 *)(MH_REG_BASE + 0x141012E0)      // U2D Descriptor Address register channel 14
#define   MH_U2DMASADR14        (volatile U32 *)(MH_REG_BASE + 0x141012E4)      // U2D Source Address register channel 14
#define   MH_U2DMATADR14        (volatile U32 *)(MH_REG_BASE + 0x141012E8)      // U2D Target Address register channel 14
#define   MH_U2DMACMD14         (volatile U32 *)(MH_REG_BASE + 0x141012EC)      // U2D Command Address register channel 14
#define   MH_U2DMADADR15        (volatile U32 *)(MH_REG_BASE + 0x141012F0)      // U2D Descriptor Address register channel 15
#define   MH_U2DMASADR15        (volatile U32 *)(MH_REG_BASE + 0x141012F4)      // U2D Source Address register channel 15
#define   MH_U2DMATADR15        (volatile U32 *)(MH_REG_BASE + 0x141012F8)      // U2D Target Address register channel 15
#define   MH_U2DMACMD15         (volatile U32 *)(MH_REG_BASE + 0x141012FC)      // U2D Command Address register channel 15

//
// USB Host controller Register Addresses
//
#define     MH_UHCREV           (volatile U32 *)(MH_REG_BASE + 0x0C000000)      // UHC HCI Spec Revision
#define     MH_UHCHCON          (volatile U32 *)(MH_REG_BASE + 0x0C000004)      // UHC Host Control register
#define     MH_UHCCOMS          (volatile U32 *)(MH_REG_BASE + 0x0C000008)      // UHC Command Status
#define     MH_UHCINTS          (volatile U32 *)(MH_REG_BASE + 0x0C00000C)      // UHC Interrupt Status
#define     MH_UHCINTE          (volatile U32 *)(MH_REG_BASE + 0x0C000010)      // UHC Interrupt Enable register
#define     MH_UHCINTD          (volatile U32 *)(MH_REG_BASE + 0x0C000014)      // UHC Interrupt Disable register
#define     MH_UHCHCCA          (volatile U32 *)(MH_REG_BASE + 0x0C000018)      // UHC Host Controller Communication Area
#define     MH_UHCPCED          (volatile U32 *)(MH_REG_BASE + 0x0C00001C)      // UHC Period Current Endpoint Descriptor
#define     MH_UHCCHED          (volatile U32 *)(MH_REG_BASE + 0x0C000020)      // UHC Control Head Endpoint Descriptor register
#define     MH_UHCCCED          (volatile U32 *)(MH_REG_BASE + 0x0C000024)      // UHC Control Current Endpoint Descriptor register
#define     MH_UHCBHED          (volatile U32 *)(MH_REG_BASE + 0x0C000028)      // UHC Bulk Head Endpoint Descriptor register
#define     MH_UHCBCED          (volatile U32 *)(MH_REG_BASE + 0x0C00002C)      // UHC Bulk Current Endpoint Descriptor register
#define     MH_UHCDHEAD         (volatile U32 *)(MH_REG_BASE + 0x0C000030)      // UHC Done Head register
#define     MH_UHCFMI           (volatile U32 *)(MH_REG_BASE + 0x0C000034)      // UHC Frame Interval register
#define     MH_UHCFMR           (volatile U32 *)(MH_REG_BASE + 0x0C000038)      // UHC Frame Remaining register
#define     MH_UHCFMN           (volatile U32 *)(MH_REG_BASE + 0x0C00003C)      // UHC Frame Number register
#define     MH_UHCPERS          (volatile U32 *)(MH_REG_BASE + 0x0C000040)      // UHC Periodic Start register
#define     MH_UHCLST           (volatile U32 *)(MH_REG_BASE + 0x0C000044)      // UHC Low-Speed Threshold register
#define     MH_UHCRHDA          (volatile U32 *)(MH_REG_BASE + 0x0C000048)      // UHC Root Hub Descriptor A register
#define     MH_UHCRHDB          (volatile U32 *)(MH_REG_BASE + 0x0C00004C)      // UHC Root Hub Descriptor B register
#define     MH_UHCRHS           (volatile U32 *)(MH_REG_BASE + 0x0C000050)      // UHC Root Hub Status register
#define     MH_UHCRHPS1         (volatile U32 *)(MH_REG_BASE + 0x0C000054)      // UHC Root Hub Port 1 Status register
#define     MH_UHCRHPS2         (volatile U32 *)(MH_REG_BASE + 0x0C000058)      // UHC Root Hub Port 2 Status register
#define     MH_UHCRHPS3         (volatile U32 *)(MH_REG_BASE + 0x0C00005C)      // UHC Root Hub Port 3 Status register
#define     MH_UHCSTAT          (volatile U32 *)(MH_REG_BASE + 0x0C000060)      // UHC Status register
#define     MH_UHCHR            (volatile U32 *)(MH_REG_BASE + 0x0C000064)      // UHC Reset register
#define     MH_UHCHIE           (volatile U32 *)(MH_REG_BASE + 0x0C000068)      // UHC Interrupt Enable register
#define     MH_UHCHIT           (volatile U32 *)(MH_REG_BASE + 0x0C00006C)      // UHC Interrupt Test register

//
// MSL Interface Register Summary
//
#define     MH_BBFIFO1          (volatile U32 *)(MH_REG_BASE + 0x01400004)      // Channel 1 Receive/Transmit FIFO register
#define     MH_BBFIFO2          (volatile U32 *)(MH_REG_BASE + 0x01400008)      // Channel 2 Receive/Transmit FIFO register
#define     MH_BBFIFO3          (volatile U32 *)(MH_REG_BASE + 0x0140000C)      // Channel 3 Receive/Transmit FIFO register
#define     MH_BBFIFO4          (volatile U32 *)(MH_REG_BASE + 0x01400010)      // Channel 4 Receive/Transmit FIFO register
#define     MH_BBFIFO5          (volatile U32 *)(MH_REG_BASE + 0x01400014)      // Channel 5 Receive/Transmit FIFO register
#define     MH_BBFIFO6          (volatile U32 *)(MH_REG_BASE + 0x01400018)      // Channel 6 Receive/Transmit FIFO register
#define     MH_BBFIFO7          (volatile U32 *)(MH_REG_BASE + 0x0140001C)      // Channel 7 Receive/Transmit FIFO register
#define     MH_BBCFG1           (volatile U32 *)(MH_REG_BASE + 0x01400044)      // Channel 1 Configuration register
#define     MH_BBCFG2           (volatile U32 *)(MH_REG_BASE + 0x01400048)      // Channel 2 Configuration register
#define     MH_BBCFG3           (volatile U32 *)(MH_REG_BASE + 0x0140004C)      // Channel 3 Configuration register
#define     MH_BBCFG4           (volatile U32 *)(MH_REG_BASE + 0x01400050)      // Channel 4 Configuration register
#define     MH_BBCFG5           (volatile U32 *)(MH_REG_BASE + 0x01400054)      // Channel 5 Configuration register
#define     MH_BBCFG6           (volatile U32 *)(MH_REG_BASE + 0x01400058)      // Channel 6 Configuration register
#define     MH_BBCFG7           (volatile U32 *)(MH_REG_BASE + 0x0140005C)      // Channel 7 Configuration register
#define     MH_BBSTAT1          (volatile U32 *)(MH_REG_BASE + 0x01400084)      // Channel 1 Status register
#define     MH_BBSTAT2          (volatile U32 *)(MH_REG_BASE + 0x01400088)      // Channel 2 Status register
#define     MH_BBSTAT3          (volatile U32 *)(MH_REG_BASE + 0x0140008C)      // Channel 3 Status register
#define     MH_BBSTAT4          (volatile U32 *)(MH_REG_BASE + 0x01400090)      // Channel 4 Status register
#define     MH_BBSTAT5          (volatile U32 *)(MH_REG_BASE + 0x01400094)      // Channel 5 Status register
#define     MH_BBSTAT6          (volatile U32 *)(MH_REG_BASE + 0x01400098)      // Channel 6 Status register
#define     MH_BBSTAT7          (volatile U32 *)(MH_REG_BASE + 0x0140009C)      // Channel 7 Status register
#define     MH_BBEOM1           (volatile U32 *)(MH_REG_BASE + 0x014000C4)      // Channel 1 EOM register
#define     MH_BBEOM2           (volatile U32 *)(MH_REG_BASE + 0x014000C8)      // Channel 2 EOM register
#define     MH_BBEOM3           (volatile U32 *)(MH_REG_BASE + 0x014000CC)      // Channel 3 EOM register
#define     MH_BBEOM4           (volatile U32 *)(MH_REG_BASE + 0x014000D0)      // Channel 4 EOM register
#define     MH_BBEOM5           (volatile U32 *)(MH_REG_BASE + 0x014000D4)      // Channel 5 EOM register
#define     MH_BBEOM6           (volatile U32 *)(MH_REG_BASE + 0x014000D8)      // Channel 6 EOM register
#define     MH_BBEOM7           (volatile U32 *)(MH_REG_BASE + 0x014000DC)      // Channel 7 EOM register
#define     MH_BBIID            (volatile U32 *)(MH_REG_BASE + 0x01400108)      // Interrupt ID register
#define     MH_BBFREQ           (volatile U32 *)(MH_REG_BASE + 0x01400110)      // TX Frequency Select register
#define     MH_BBWAIT           (volatile U32 *)(MH_REG_BASE + 0x01400114)      // Wait Count register
#define     MH_BBCST            (volatile U32 *)(MH_REG_BASE + 0x01400118)      // Clock Stop Time register
#define     MH_BBVGIL           (volatile U32 *)(MH_REG_BASE + 0x0140011C)      // Virtual GPIO Input Pin Level register
#define     MH_BBVGOL           (volatile U32 *)(MH_REG_BASE + 0x01400120)      // Virtual GPIO Output Pin Level register
#define     MH_BBVGSR           (volatile U32 *)(MH_REG_BASE + 0x01400124)      // Virtual GPIO Output Pin Set register
#define     MH_BBVGCR           (volatile U32 *)(MH_REG_BASE + 0x01400128)      // Virtual GPIO Output Pin Clear register
#define     MH_BBVGRE           (volatile U32 *)(MH_REG_BASE + 0x0140012C)      // Virtual GPIO Rising Edge Detect register
#define     MH_BBVGFE           (volatile U32 *)(MH_REG_BASE + 0x01400130)      // Virtual GPIO Falling Edge Detect register
#define     MH_BBVGED           (volatile U32 *)(MH_REG_BASE + 0x01400134)      // Virtual GPIO Edge Detect Status register
#define     MH_BBVGVI           (volatile U32 *)(MH_REG_BASE + 0x01400138)      // Virtual GPIO Value Interrupt register
#define     MH_BBWAKE           (volatile U32 *)(MH_REG_BASE + 0x01400140)      // Wake-Up register
#define     MH_BBITFC           (volatile U32 *)(MH_REG_BASE + 0x01400144)      // Interface Width register
#define     MH_BBWST            (volatile U32 *)(MH_REG_BASE + 0x01400148)      // Wait Sample Time register

//
// SSP Register Summary
//
#define     MH_SSP1_BASE        (MH_REG_BASE + 0x01000000)
#define     MH_SSCR01           (volatile U32 *)(MH_SSP1_BASE + 0x00)           // SSP1 Control register 0
#define     MH_SSCR11           (volatile U32 *)(MH_SSP1_BASE + 0x04)           // SSP1 Control register 1
#define     MH_SSSR1            (volatile U32 *)(MH_SSP1_BASE + 0x08)           // SSP1 Status register
#define     MH_SSITR1           (volatile U32 *)(MH_SSP1_BASE + 0x0C)           // SSP1 Interrupt Test register
#define     MH_SSDR1            (volatile U32 *)(MH_SSP1_BASE + 0x10)           // SSP1 Data Write Register/SSP1 Data Read register
#define     MH_SSTO1            (volatile U32 *)(MH_SSP1_BASE + 0x28)           // SSP1 Time Out register
#define     MH_SSPSP1           (volatile U32 *)(MH_SSP1_BASE + 0x2C)           // SSP1 Programmable Serial Protocol register
#define     MH_SSTSA1           (volatile U32 *)(MH_SSP1_BASE + 0x30)           // SSP1 TX Time Slot Active register
#define     MH_SSRSA1           (volatile U32 *)(MH_SSP1_BASE + 0x34)           // SSP1 RX Time Slot Active register
#define     MH_SSTSS1           (volatile U32 *)(MH_SSP1_BASE + 0x38)           // SSP1 Time Slot Status register
#define     MH_SSACD1           (volatile U32 *)(MH_SSP1_BASE + 0x3C)           // SSP1 Audio Clock Divider register
#define     MH_SSACDD1          (volatile U32 *)(MH_SSP1_BASE + 0x40)           // SSP1 Audio Clock Dither Divider register

#define     MH_SSP2_BASE        (MH_REG_BASE + 0x01700000)
#define     MH_SSCR02           (volatile U32 *)(MH_SSP2_BASE + 0x00)           // SSP2 Control register 0
#define     MH_SSCR12           (volatile U32 *)(MH_SSP2_BASE + 0x04)           // SSP2 Control register 1
#define     MH_SSSR2            (volatile U32 *)(MH_SSP2_BASE + 0x08)           // SSP2 Status register
#define     MH_SSITR2           (volatile U32 *)(MH_SSP2_BASE + 0x0C)           // SSP2 Interrupt Test register
#define     MH_SSDR2            (volatile U32 *)(MH_SSP2_BASE + 0x10)           // SSP2 Data Write Register/SSP2 Data Read register
#define     MH_SSTO2            (volatile U32 *)(MH_SSP2_BASE + 0x28)           // SSP2 Time Out register
#define     MH_SSPSP2           (volatile U32 *)(MH_SSP2_BASE + 0x2C)           // SSP2 Programmable Serial Protocol register
#define     MH_SSTSA2           (volatile U32 *)(MH_SSP2_BASE + 0x30)           // SSP2 TX Time Slot Active register
#define     MH_SSRSA2           (volatile U32 *)(MH_SSP2_BASE + 0x34)           // SSP2 RX Time Slot Active register
#define     MH_SSTSS2           (volatile U32 *)(MH_SSP2_BASE + 0x38)           // SSP2 Time Slot Status register
#define     MH_SSACD2           (volatile U32 *)(MH_SSP2_BASE + 0x3C)           // SSP2 Audio Clock Divider register
#define     MH_SSACDD2          (volatile U32 *)(MH_SSP2_BASE + 0x40)           // SSP2 Audio Clock Dither Divider register

#define     MH_SSP3_BASE        (MH_REG_BASE + 0x01900000)
#define     MH_SSCR03           (volatile U32 *)(MH_SSP3_BASE + 0x00)           // SSP3 Control register 0
#define     MH_SSCR13           (volatile U32 *)(MH_SSP3_BASE + 0x04)           // SSP3 Control register 1
#define     MH_SSSR3            (volatile U32 *)(MH_SSP3_BASE + 0x08)           // SSP3 Status register
#define     MH_SSITR3           (volatile U32 *)(MH_SSP3_BASE + 0x0C)           // SSP3 Interrupt Test register
#define     MH_SSDR3            (volatile U32 *)(MH_SSP3_BASE + 0x10)           // SSP3 Data Write Register/SSP3 Data Read register
#define     MH_SSTO3            (volatile U32 *)(MH_SSP3_BASE + 0x28)           // SSP3 Time Out register
#define     MH_SSPSP3           (volatile U32 *)(MH_SSP3_BASE + 0x2C)           // SSP3 Programmable Serial Protocol register
#define     MH_SSTSA3           (volatile U32 *)(MH_SSP3_BASE + 0x30)           // SSP3 TX Time Slot Active register
#define     MH_SSRSA3           (volatile U32 *)(MH_SSP3_BASE + 0x34)           // SSP3 RX Time Slot Active register
#define     MH_SSTSS3           (volatile U32 *)(MH_SSP3_BASE + 0x38)           // SSP3 Time Slot Status register
#define     MH_SSACD3           (volatile U32 *)(MH_SSP3_BASE + 0x3C)           // SSP3 Audio Clock Divider register
#define     MH_SSACDD3          (volatile U32 *)(MH_SSP3_BASE + 0x40)           // SSP3 Audio Clock Dither Divider register

#define     MH_SSP4_BASE        (MH_REG_BASE + 0x01A00000)
#define     MH_SSCR04           (volatile U32 *)(MH_SSP4_BASE + 0x00)           // SSP4 Control register 0
#define     MH_SSCR14           (volatile U32 *)(MH_SSP4_BASE + 0x04)           // SSP4 Control register 1
#define     MH_SSSR4            (volatile U32 *)(MH_SSP4_BASE + 0x08)           // SSP4 Status register
#define     MH_SSITR4           (volatile U32 *)(MH_SSP4_BASE + 0x0C)           // SSP4 Interrupt Test register
#define     MH_SSDR4            (volatile U32 *)(MH_SSP4_BASE + 0x10)           // SSP4 Data Write Register/SSP4 Data Read register
#define     MH_SSTO4            (volatile U32 *)(MH_SSP4_BASE + 0x28)           // SSP4 Time Out register
#define     MH_SSPSP4           (volatile U32 *)(MH_SSP4_BASE + 0x2C)           // SSP4 Programmable Serial Protocol register
#define     MH_SSTSA4           (volatile U32 *)(MH_SSP4_BASE + 0x30)           // SSP4 TX Time Slot Active register
#define     MH_SSRSA4           (volatile U32 *)(MH_SSP4_BASE + 0x34)           // SSP4 RX Time Slot Active register
#define     MH_SSTSS4           (volatile U32 *)(MH_SSP4_BASE + 0x38)           // SSP4 Time Slot Status register
#define     MH_SSACD4           (volatile U32 *)(MH_SSP4_BASE + 0x3C)           // SSP4 Audio Clock Divider register
#define     MH_SSACDD4          (volatile U32 *)(MH_SSP4_BASE + 0x40)           // SSP4 Audio Clock Dither Divider register

//
// AC97 Controller Unit
//
#define     MH_POCR             (volatile U32 *)(MH_REG_BASE + 0x00500000)      // PCM Out Control register
#define     MH_PCMICR           (volatile U32 *)(MH_REG_BASE + 0x00500004)      // PCM In Control register
#define     MH_MCCR             (volatile U32 *)(MH_REG_BASE + 0x00500008)      // Mic In Control register
#define     MH_GCR              (volatile U32 *)(MH_REG_BASE + 0x0050000C)      // Global Control register
#define     MH_POSR             (volatile U32 *)(MH_REG_BASE + 0x00500010)      // PCM Out Status register
#define     MH_PCMISR           (volatile U32 *)(MH_REG_BASE + 0x00500014)      // PCM In Status register
#define     MH_MCSR             (volatile U32 *)(MH_REG_BASE + 0x00500018)      // Mic In Status register
#define     MH_GSR              (volatile U32 *)(MH_REG_BASE + 0x0050001C)      // Global Status register
#define     MH_CAR              (volatile U32 *)(MH_REG_BASE + 0x00500020)      // CODEC Access register
#define     MH_PCSCR            (volatile U32 *)(MH_REG_BASE + 0x00500024)      // PCM Surround Out Control register
#define     MH_PCSSR            (volatile U32 *)(MH_REG_BASE + 0x00500028)      // PCM Surround Out Status register
#define     MH_PCSDR            (volatile U32 *)(MH_REG_BASE + 0x0050002C)      // PCM Surround Out Data register
#define     MH_PCCLCR           (volatile U32 *)(MH_REG_BASE + 0x00500030)      // PCM Center/LFE Out Control register
#define     MH_PCCLSR           (volatile U32 *)(MH_REG_BASE + 0x00500034)      // PCM Center/LFE Out Status register
#define     MH_PCCLDR           (volatile U32 *)(MH_REG_BASE + 0x00500038)      // PCM Center/LFE Out Data register
#define     MH_PCDR             (volatile U32 *)(MH_REG_BASE + 0x00500040)      // PCM FIFO Data register
#define     MH_MCDR             (volatile U32 *)(MH_REG_BASE + 0x00500060)      // Mic-in FIFO Data register
#define     MH_MOCR             (volatile U32 *)(MH_REG_BASE + 0x00500100)      // Modem Out Control register
#define     MH_MICR             (volatile U32 *)(MH_REG_BASE + 0x00500108)      // Modem In Control register
#define     MH_MOSR             (volatile U32 *)(MH_REG_BASE + 0x00500110)      // Modem Out Status register
#define     MH_MISR             (volatile U32 *)(MH_REG_BASE + 0x00500118)      // Modem In Status register
#define     MH_MODR             (volatile U32 *)(MH_REG_BASE + 0x00500140)      // Modem FIFO Data register

//
// UART Register Summary
//
#define     MH_UART1_BASE       (volatile U32 *)(MH_REG_BASE + 0x00100000)
#define     MH_FFRBR            (volatile U32 *)(MH_REG_BASE + 0x00100000)      // Receive Buffer register
#define     MH_FFTHR            (volatile U32 *)(MH_REG_BASE + 0x00100000)      // Transmit Holding register
#define     MH_FFIER            (volatile U32 *)(MH_REG_BASE + 0x00100004)      // Interrupt Enable register
#define     MH_FFIIR            (volatile U32 *)(MH_REG_BASE + 0x00100008)      // Interrupt ID register
#define     MH_FFFCR            (volatile U32 *)(MH_REG_BASE + 0x00100008)      // FIFO Control register
#define     MH_FFLCR            (volatile U32 *)(MH_REG_BASE + 0x0010000C)      // Line Control register
#define     MH_FFMCR            (volatile U32 *)(MH_REG_BASE + 0x00100010)      // Modem Control register
#define     MH_FFLSR            (volatile U32 *)(MH_REG_BASE + 0x00100014)      // Line Status register
#define     MH_FFMSR            (volatile U32 *)(MH_REG_BASE + 0x00100018)      // Modem Status register
#define     MH_FFSPR            (volatile U32 *)(MH_REG_BASE + 0x0010001C)      // Scratch Pad register
#define     MH_FFDLL            (volatile U32 *)(MH_REG_BASE + 0x00100000)      // Divisor Latch register, low byte
#define     MH_FFDLH            (volatile U32 *)(MH_REG_BASE + 0x00100004)      // Divisor Latch register, high byte
#define     MH_FFISR            (volatile U32 *)(MH_REG_BASE + 0x00100020)      // Serial Infrared Select register
#define     MH_FFFOR            (volatile U32 *)(MH_REG_BASE + 0x00100024)      // FIFO Occupancy register
#define     MH_FFABR            (volatile U32 *)(MH_REG_BASE + 0x00100028)      // Autobaud Control register
#define     MH_FFACR            (volatile U32 *)(MH_REG_BASE + 0x0010002C)      // Autobaud Count register

#define     MH_UART2_BASE       (volatile U32 *)(MH_REG_BASE + 0x00200000)
#define     MH_BTRBR            (volatile U32 *)(MH_REG_BASE + 0x00200000)      // Receive Buffer register
#define     MH_BTTHR            (volatile U32 *)(MH_REG_BASE + 0x00200000)      // Transmit Holding register
#define     MH_BTIER            (volatile U32 *)(MH_REG_BASE + 0x00200004)      // Interrupt Enable register
#define     MH_BTIIR            (volatile U32 *)(MH_REG_BASE + 0x00200008)      // Interrupt ID register
#define     MH_BTFCR            (volatile U32 *)(MH_REG_BASE + 0x00200008)      // FIFO Control register
#define     MH_BTLCR            (volatile U32 *)(MH_REG_BASE + 0x0020000C)      // Line Control register
#define     MH_BTMCR            (volatile U32 *)(MH_REG_BASE + 0x00200010)      // Modem Control register
#define     MH_BTLSR            (volatile U32 *)(MH_REG_BASE + 0x00200014)      // Line Status register
#define     MH_BTMSR            (volatile U32 *)(MH_REG_BASE + 0x00200018)      // Modem Status register
#define     MH_BTSPR            (volatile U32 *)(MH_REG_BASE + 0x0020001C)      // Scratch Pad register
#define     MH_BTDLL            (volatile U32 *)(MH_REG_BASE + 0x00200000)      // Divisor Latch register, low byte
#define     MH_BTDLH            (volatile U32 *)(MH_REG_BASE + 0x00200004)      // Divisor Latch register, high byte
#define     MH_BTISR            (volatile U32 *)(MH_REG_BASE + 0x00200020)      // Serial Infrared Select register
#define     MH_BTFOR            (volatile U32 *)(MH_REG_BASE + 0x00200024)      // FIFO Occupancy register
#define     MH_BTABR            (volatile U32 *)(MH_REG_BASE + 0x00200028)      // Autobaud Control register
#define     MH_BTACR            (volatile U32 *)(MH_REG_BASE + 0x0020002C)      // Autobaud Count register

#define     MH_UART3_BASE       (volatile U32 *)(MH_REG_BASE + 0x00700000)
#define     MH_STRBR            (volatile U32 *)(MH_REG_BASE + 0x00700000)      // Receive Buffer register
#define     MH_STTHR            (volatile U32 *)(MH_REG_BASE + 0x00700000)      // Transmit Holding register
#define     MH_STIER            (volatile U32 *)(MH_REG_BASE + 0x00700004)      // Interrupt Enable register
#define     MH_STIIR            (volatile U32 *)(MH_REG_BASE + 0x00700008)      // Interrupt ID register
#define     MH_STFCR            (volatile U32 *)(MH_REG_BASE + 0x00700008)      // FIFO Control register
#define     MH_STLCR            (volatile U32 *)(MH_REG_BASE + 0x0070000C)      // Line Control register
#define     MH_STMCR            (volatile U32 *)(MH_REG_BASE + 0x00700010)      // Modem Control register
#define     MH_STLSR            (volatile U32 *)(MH_REG_BASE + 0x00700014)      // Line Status register
#define     MH_STMSR            (volatile U32 *)(MH_REG_BASE + 0x00700018)      // Modem Status register
#define     MH_STSPR            (volatile U32 *)(MH_REG_BASE + 0x0070001C)      // Scratch Pad register
#define     MH_STDLL            (volatile U32 *)(MH_REG_BASE + 0x00700000)      // Divisor Latch register, low byte
#define     MH_STDLH            (volatile U32 *)(MH_REG_BASE + 0x00700004)      // Divisor Latch register, high byte
#define     MH_STISR            (volatile U32 *)(MH_REG_BASE + 0x00700020)      // Serial Infrared Select register
#define     MH_STFOR            (volatile U32 *)(MH_REG_BASE + 0x00700024)      // FIFO Occupancy register
#define     MH_STABR            (volatile U32 *)(MH_REG_BASE + 0x00700028)      // Autobaud Control register
#define     MH_STACR            (volatile U32 *)(MH_REG_BASE + 0x0070002C)      // Autobaud Count register

//
// CIR Register Addresses
//
#define     MH_CIRPW            (volatile U32 *)(MH_REG_BASE + 0x01D00000)      // CIR Pulse Width Comparator register
#define     MH_CIRMP            (volatile U32 *)(MH_REG_BASE + 0x01D00004)      // CIR Modulation Period Comparator register
#define     MH_CIRN0            (volatile U32 *)(MH_REG_BASE + 0x01D00008)      // CIR N0 Symbol Length register
#define     MH_CIRN1            (volatile U32 *)(MH_REG_BASE + 0x01D0000C)      // CIR N1 Symbol Length register
#define     MH_CIRS0            (volatile U32 *)(MH_REG_BASE + 0x01D00010)      // CIR S0 Symbol Length register
#define     MH_CIRS1            (volatile U32 *)(MH_REG_BASE + 0x01D00014)      // CIR S1 Symbol Length register
#define     MH_CIRBUFF          (volatile U32 *)(MH_REG_BASE + 0x01D00018)      // CIR Buffer register
#define     MH_CIRNS            (volatile U32 *)(MH_REG_BASE + 0x01D0001C)      // CIR Number of Symbols register
#define     MH_CIRCR            (volatile U32 *)(MH_REG_BASE + 0x01D00020)      // CIR Control register
#define     MH_CIRIR            (volatile U32 *)(MH_REG_BASE + 0x01D00024)      // CIR Interrupt register

//
// PWM Control Registers
//
#define     MH_PWMCR0           (volatile U32 *)(MH_REG_BASE + 0x00B00000)      // PWM 0 Control register
#define     MH_PWMDCR0          (volatile U32 *)(MH_REG_BASE + 0x00B00004)      // PWM 0 Duty Cycle register
#define     MH_PWMPCR0          (volatile U32 *)(MH_REG_BASE + 0x00B00008)      // PWM 0 Period register
#define     MH_PWMCR2           (volatile U32 *)(MH_REG_BASE + 0x00B00010)      // PWM 2 Control register
#define     MH_PWMDCR2          (volatile U32 *)(MH_REG_BASE + 0x00B00014)      // PWM 2 Duty Cycle register
#define     MH_PWMPCR2          (volatile U32 *)(MH_REG_BASE + 0x00B00018)      // PWM 2 Period register
#define     MH_PWMCR1           (volatile U32 *)(MH_REG_BASE + 0x00C00000)      // PWM 1 Control register
#define     MH_PWMDCR1          (volatile U32 *)(MH_REG_BASE + 0x00C00004)      // PWM 1 Duty Cycle register
#define     MH_PWMPCR1          (volatile U32 *)(MH_REG_BASE + 0x00C00008)      // PWM 1 Period register
#define     MH_PWMCR3           (volatile U32 *)(MH_REG_BASE + 0x00C00010)      // PWM 3 Control register
#define     MH_PWMDCR3          (volatile U32 *)(MH_REG_BASE + 0x00C00014)      // PWM 3 Duty Cycle register
#define     MH_PWMPCR3          (volatile U32 *)(MH_REG_BASE + 0x00C00018)      // PWM 3 Period register

//
// USIM Controller Register Summary
//
#define     MH_BASE1            (volatile U32 *)(MH_REG_BASE + 0x01600000)      // USIM Controller 1
#define     MH_RBR1             (volatile U32 *)(MH_REG_BASE + 0x01600000)      // USIM Receive Buffer register
#define     MH_THR1             (volatile U32 *)(MH_REG_BASE + 0x01600004)      // USIM Transmit Holding register
#define     MH_IER1             (volatile U32 *)(MH_REG_BASE + 0x01600008)      // USIM Interrupt Enable register
#define     MH_IIR1             (volatile U32 *)(MH_REG_BASE + 0x0160000C)      // USIM Interrupt Identification register
#define     MH_FCR1             (volatile U32 *)(MH_REG_BASE + 0x01600010)      // USIM FIFO Control register
#define     MH_FSR1             (volatile U32 *)(MH_REG_BASE + 0x01600014)      // USIM FIFO Status register
#define     MH_ECR1             (volatile U32 *)(MH_REG_BASE + 0x01600018)      // USIM Error Control register
#define     MH_LCR1             (volatile U32 *)(MH_REG_BASE + 0x0160001C)      // USIM Line Control register
#define     MH_USCCR1           (volatile U32 *)(MH_REG_BASE + 0x01600020)      // USIM SmartCard Control register
#define     MH_LSR1             (volatile U32 *)(MH_REG_BASE + 0x01600024)      // USIM Line Status register
#define     MH_EGTR1            (volatile U32 *)(MH_REG_BASE + 0x01600028)      // USIM Extra Guard Time register
#define     MH_BGTR1            (volatile U32 *)(MH_REG_BASE + 0x0160002C)      // USIM Block Guard Time register
#define     MH_TOR1             (volatile U32 *)(MH_REG_BASE + 0x01600030)      // USIM Time-Out register
#define     MH_CLKR1            (volatile U32 *)(MH_REG_BASE + 0x01600034)      // USIM Clock register
#define     MH_DLR1             (volatile U32 *)(MH_REG_BASE + 0x01600038)      // USIM Divisor Latch register
#define     MH_FLR1             (volatile U32 *)(MH_REG_BASE + 0x0160003C)      // USIM Factor Latch register
#define     MH_CWTR1            (volatile U32 *)(MH_REG_BASE + 0x01600040)      // USIM Character Waiting Time register
#define     MH_BWTR1            (volatile U32 *)(MH_REG_BASE + 0x01600044)      // USIM Block Waiting Time register
#define     MH_BASE2            (volatile U32 *)(MH_REG_BASE + 0x02100000)      // USIM Controller 2
#define     MH_RBR2             (volatile U32 *)(MH_REG_BASE + 0x02100000)      // USIM Receive Buffer register
#define     MH_THR2             (volatile U32 *)(MH_REG_BASE + 0x02100004)      // USIM Transmit Holding register
#define     MH_IER2             (volatile U32 *)(MH_REG_BASE + 0x02100008)      // USIM Interrupt Enable register
#define     MH_IIR2             (volatile U32 *)(MH_REG_BASE + 0x0210000C)      // USIM Interrupt Identification register
#define     MH_FCR2             (volatile U32 *)(MH_REG_BASE + 0x02100010)      // USIM FIFO Control register
#define     MH_FSR2             (volatile U32 *)(MH_REG_BASE + 0x02100014)      // USIM FIFO Status register
#define     MH_ECR2             (volatile U32 *)(MH_REG_BASE + 0x02100018)      // USIM Error Control register
#define     MH_LCR2             (volatile U32 *)(MH_REG_BASE + 0x0210001C)      // USIM Line Control register
#define     MH_USCCR2           (volatile U32 *)(MH_REG_BASE + 0x02100020)      // USIM SmartCard Control register
#define     MH_LSR2             (volatile U32 *)(MH_REG_BASE + 0x02100024)      // USIM Line Status register
#define     MH_EGTR2            (volatile U32 *)(MH_REG_BASE + 0x02100028)      // USIM Extra Guard Time register
#define     MH_BGTR2            (volatile U32 *)(MH_REG_BASE + 0x0210002C)      // USIM Block Guard Time register
#define     MH_TOR2             (volatile U32 *)(MH_REG_BASE + 0x02100030)      // USIM Time-Out register
#define     MH_CLKR2            (volatile U32 *)(MH_REG_BASE + 0x02100034)      // USIM Clock register
#define     MH_DLR2             (volatile U32 *)(MH_REG_BASE + 0x02100038)      // USIM Divisor Latch register
#define     MH_FLR2             (volatile U32 *)(MH_REG_BASE + 0x0210003C)      // USIM Factor Latch register
#define     MH_CWTR2            (volatile U32 *)(MH_REG_BASE + 0x02100040)      // USIM Character Waiting Time register
#define     MH_BWTR2            (volatile U32 *)(MH_REG_BASE + 0x02100044)      // USIM Block Waiting Time register

//
// Standard I2C Register Addresses
//
#define     MH_IBMR             (volatile U32 *)(MH_REG_BASE + 0x00301680)      // Bus Monitor register
#define     MH_IDBR             (volatile U32 *)(MH_REG_BASE + 0x00301688)      // Data Buffer register
#define     MH_ICR              (volatile U32 *)(MH_REG_BASE + 0x00301690)      // Control register
#define     MH_ISR              (volatile U32 *)(MH_REG_BASE + 0x00301698)      // Status register
#define     MH_ISAR             (volatile U32 *)(MH_REG_BASE + 0x003016A0)      // Slave Address register

//
// PWR I2C Register Addresses
//
#define     MH_PWRIBMR          (volatile U32 *)(MH_REG_BASE + 0x00F500C0)      // Bus Monitor register
#define     MH_PWRIDBR          (volatile U32 *)(MH_REG_BASE + 0x00F500C4)      // Data Buffer register
#define     MH_PWRICR           (volatile U32 *)(MH_REG_BASE + 0x00F500C8)      // Control register
#define     MH_PWRISR           (volatile U32 *)(MH_REG_BASE + 0x00F500CC)      // Status register
#define     MH_PWRISAR          (volatile U32 *)(MH_REG_BASE + 0x00F500D0)      // Slave Address register

//
// Internal Memory Address Map
//
#define     MH_IMPMCR           (volatile U32 *)(MH_REG_BASE + 0x18000000)      // IM Power Management Control register

//
// Quick Capture Interface Register Summary
//
#define     MH_CICR0            (volatile U32 *)(MH_REG_BASE + 0x10000000)      // Quick Capture Interface Control register 0
#define     MH_CICR1            (volatile U32 *)(MH_REG_BASE + 0x10000004)      // Quick Capture Interface Control register 1
#define     MH_CICR2            (volatile U32 *)(MH_REG_BASE + 0x10000008)      // Quick Capture Interface Control register 2
#define     MH_CICR3            (volatile U32 *)(MH_REG_BASE + 0x1000000C)      // Quick Capture Interface Control register 3
#define     MH_CICR4            (volatile U32 *)(MH_REG_BASE + 0x10000010)      // Quick Capture Interface Control register 4
#define     MH_CISR             (volatile U32 *)(MH_REG_BASE + 0x10000014)      // Quick Capture Interface Status register
#define     MH_CITOR            (volatile U32 *)(MH_REG_BASE + 0x1000001C)      // Quick Capture Interface Time-Out register
#define     MH_CIBR0            (volatile U32 *)(MH_REG_BASE + 0x10000028)      // Quick Capture Interface Channel 0 Receive Buffer
#define     MH_CIBR1            (volatile U32 *)(MH_REG_BASE + 0x10000030)      // Quick Capture Interface Channel 1 Receive Buffer
#define     MH_CIBR2            (volatile U32 *)(MH_REG_BASE + 0x10000038)      // Quick Capture Interface Channel 2 Receive Buffer
#define     MH_CIBR3            (volatile U32 *)(MH_REG_BASE + 0x10000040)      // Quick Capture Interface Channel 3 Receive Buffer
#define     MH_CIPSS            (volatile U32 *)(MH_REG_BASE + 0x10000064)      // Quick Capture Interface Pixel Substitution Status register
#define     MH_CIPBUF           (volatile U32 *)(MH_REG_BASE + 0x10000068)      // Quick Capture Interface Pixel Substitution Buffer
#define     MH_CIHST            (volatile U32 *)(MH_REG_BASE + 0x1000006C)      // Quick Capture Interface Histogram Configuration
#define     MH_CISUM            (volatile U32 *)(MH_REG_BASE + 0x10000070)      // Quick Capture Interface Histogram Summation register
#define     MH_CICCR            (volatile U32 *)(MH_REG_BASE + 0x10000074)      // Quick Capture Interface Compander Configuration
#define     MH_CISSC            (volatile U32 *)(MH_REG_BASE + 0x1000007C)      // Quick Capture Interface Spatial Scaling Configuration
#define     MH_CICMR            (volatile U32 *)(MH_REG_BASE + 0x10000090)      // Quick Capture Interface Color Management register
#define     MH_CICMC0           (volatile U32 *)(MH_REG_BASE + 0x10000094)      // Quick Capture Interface Color Management Coefficients 0
#define     MH_CICMC1           (volatile U32 *)(MH_REG_BASE + 0x10000098)      // Quick Capture Interface Color Management Coefficients 1
#define     MH_CICMC2           (volatile U32 *)(MH_REG_BASE + 0x1000009C)      // Quick Capture Interface Color Management Coefficients 2
#define     MH_CIFR0            (volatile U32 *)(MH_REG_BASE + 0x100000B0)      // Quick Capture Interface FIFO Control register 0
#define     MH_CIFR1            (volatile U32 *)(MH_REG_BASE + 0x100000B4)      // Quick Capture Interface FIFO Control register 1
#define     MH_CIFSR            (volatile U32 *)(MH_REG_BASE + 0x100000C0)      // Quick Capture Interface FIFO Status register
#define     MH_CIDADR0          (volatile U32 *)(MH_REG_BASE + 0x10000240)      // Quick Capture Interface DMA Descriptor Address Channel 0 register
#define     MH_CIDADR1          (volatile U32 *)(MH_REG_BASE + 0x10000250)      // Quick Capture Interface DMA Descriptor Address Channel 1 register
#define     MH_CIDADR2          (volatile U32 *)(MH_REG_BASE + 0x10000260)      // Quick Capture Interface DMA Descriptor Address Channel 2 register
#define     MH_CIDADR3          (volatile U32 *)(MH_REG_BASE + 0x10000270)      // Quick Capture Interface DMA Descriptor Address Channel 3 register
#define     MH_CISADR0          (volatile U32 *)(MH_REG_BASE + 0x10000244)      // Quick Capture Interface DMA Source Address Channel 0 register
#define     MH_CISADR1          (volatile U32 *)(MH_REG_BASE + 0x10000254)      // Quick Capture Interface DMA Source Address Channel 1 register
#define     MH_CISADR2          (volatile U32 *)(MH_REG_BASE + 0x10000264)      // Quick Capture Interface DMA Source Address Channel 2 register
#define     MH_CISADR3          (volatile U32 *)(MH_REG_BASE + 0x10000274)      // Quick Capture Interface DMA Source Address Channel 3 register
#define     MH_CITADR0          (volatile U32 *)(MH_REG_BASE + 0x10000248)      // Quick Capture Interface DMA Target Address Channel 0 register
#define     MH_CITADR1          (volatile U32 *)(MH_REG_BASE + 0x10000258)      // Quick Capture Interface DMA Target Address Channel 1 register
#define     MH_CITADR2          (volatile U32 *)(MH_REG_BASE + 0x10000268)      // Quick Capture Interface DMA Target Address Channel 2 register
#define     MH_CITADR3          (volatile U32 *)(MH_REG_BASE + 0x10000278)      // Quick Capture Interface DMA Target Address Channel 3 register
#define     MH_CICMD0           (volatile U32 *)(MH_REG_BASE + 0x1000024C)      // Quick Capture Interface DMA Command Channel 0 register
#define     MH_CICMD1           (volatile U32 *)(MH_REG_BASE + 0x1000025C)      // Quick Capture Interface DMA Command Channel 1 register
#define     MH_CICMD2           (volatile U32 *)(MH_REG_BASE + 0x1000026C)      // Quick Capture Interface DMA Command Channel 2 register
#define     MH_CICMD3           (volatile U32 *)(MH_REG_BASE + 0x1000027C)      // Quick Capture Interface DMA Command Channel 3 register
#define     MH_CIDBR0           (volatile U32 *)(MH_REG_BASE + 0x10000220)      // Quick Capture Interface DMA Branch Channel 0 register
#define     MH_CIDBR1           (volatile U32 *)(MH_REG_BASE + 0x10000224)      // Quick Capture Interface DMA Branch Channel 1 register
#define     MH_CIDBR2           (volatile U32 *)(MH_REG_BASE + 0x10000228)      // Quick Capture Interface DMA Branch Channel 2 register
#define     MH_CIDBR3           (volatile U32 *)(MH_REG_BASE + 0x1000022C)      // Quick Capture Interface DMA Branch Channel 3 register
#define     MH_CIDCSR0          (volatile U32 *)(MH_REG_BASE + 0x10000200)      // Quick Capture Interface DMA Controller/Status Channel 0 register
#define     MH_CIDCSR1          (volatile U32 *)(MH_REG_BASE + 0x10000204)      // Quick Capture Interface DMA Controller/Status Channel 1 register
#define     MH_CIDCSR2          (volatile U32 *)(MH_REG_BASE + 0x10000208)      // Quick Capture Interface DMA Controller/Status Channel 2 register
#define     MH_CIDCSR3          (volatile U32 *)(MH_REG_BASE + 0x1000020C)      // Quick Capture Interface DMA Controller/Status Channel 3 register

//
// PIN --- MFPR
//

#define     MH_MFPR_BASE        (MH_REG_BASE + 0x00E10000)

#define     MH_MFPR_GPIO77      (volatile U32 *)(MH_MFPR_BASE + 0x04D4)
#define     MH_MFPR_GPIO78      (volatile U32 *)(MH_MFPR_BASE + 0x04D8)

