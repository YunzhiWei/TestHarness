/*****************************************************************************
    Monahans Register Addess Definitions
*****************************************************************************/

/*
 GPIO Registers
*/
.equ            MH_GPLR0        ,     (0x40E00000)        /* GPIO Pin Level register GPIO[31:0]                     */
.equ            MH_GPLR1        ,     (0x40E00004)        /* GPIO Pin Level register GPIO[63:32]                    */
.equ            MH_GPLR2        ,     (0x40E00008)        /* GPIO Pin Level register GPIO[95:64]                    */
.equ            MH_GPLR3        ,     (0x40E00100)        /* GPIO Pin Level register GPIO[127:96]                   */

.equ            MH_GPDR0        ,     (0x40E0000C)        /* GPIO Pin Direction register GPIO[31:0]                 */
.equ            MH_GPDR1        ,     (0x40E00010)        /* GPIO Pin Direction register GPIO[63:32]                */
.equ            MH_GPDR2        ,     (0x40E00014)        /* GPIO Pin Direction register GPIO[95:64]                */
.equ            MH_GPDR3        ,     (0x40E0010C)        /* GPIO Pin Direction register GPIO[127:96]               */

.equ            MH_GPSR0        ,     (0x40E00018)        /* GPIO Pin Output Set register GPIO[31:0]                */
.equ            MH_GPSR1        ,     (0x40E0001C)        /* GPIO Pin Output Set register GPIO[63:32]               */
.equ            MH_GPSR2        ,     (0x40E00020)        /* GPIO Pin Output Set register GPIO[95:64]               */
.equ            MH_GPSR3        ,     (0x40E00118)        /* GPIO Pin Output Set register GPIO[127:96]              */

.equ            MH_GPCR0        ,     (0x40E00024)        /* GPIO Pin Output Clear register GPIO[31:0]              */
.equ            MH_GPCR1        ,     (0x40E00028)        /* GPIO Pin Output Clear register GPIO[63:32]             */
.equ            MH_GPCR2        ,     (0x40E0002C)        /* GPIO pin Output Clear register GPIO[95:64]             */
.equ            MH_GPCR3        ,     (0x40E00124)        /* GPIO Pin Output Clear register GPIO[127:96]            */

.equ            MH_GRER0        ,     (0x40E00030)        /* GPIO Rising-Edge Detect Enable register GPIO[31:0]     */
.equ            MH_GRER1        ,     (0x40E00034)        /* GPIO Rising-Edge Detect Enable register GPIO[63:32]    */
.equ            MH_GRER2        ,     (0x40E00038)        /* GPIO Rising-Edge Detect Enable register GPIO[95:64]    */
.equ            MH_GRER3        ,     (0x40E00130)        /* GPIO Rising-Edge Detect Enable register GPIO[127:96]   */

.equ            MH_GFER0        ,     (0x40E0003C)        /* GPIO Falling-Edge Detect Enable register GPIO[31:0]    */
.equ            MH_GFER1        ,     (0x40E00040)        /* GPIO Falling-Edge Detect Enable register GPIO[63:32]   */
.equ            MH_GFER2        ,     (0x40E00044)        /* GPIO Falling-Edge Detect Enable register GPIO[95:64]   */
.equ            MH_GFER3        ,     (0x40E0013C)        /* GPIO Falling-Edge Detect Enable register GPIO[127:96]  */

.equ            MH_GEDR0        ,     (0x40E00048)        /* GPIO Edge Detect Status register GPIO[31:0]            */
.equ            MH_GEDR1        ,     (0x40E0004C)        /* GPIO Edge Detect Status register GPIO[63:32]           */
.equ            MH_GEDR2        ,     (0x40E00050)        /* GPIO Edge Detect Status register GPIO[95:64]           */
.equ            MH_GEDR3        ,     (0x40E00148)        /* GPIO Edge Detect Status register GPIO[127:96]          */

.equ            MH_GSDR0        ,     (0x40E00400)        /* Bit-wise Set of GPIO Direction register GPDR [31:0]    */
.equ            MH_GSDR1        ,     (0x40E00404)        /* Bit-wise Set of GPIO Direction register GPDR [63:32]   */
.equ            MH_GSDR2        ,     (0x40E00408)        /* Bit-wise Set of GPIO Direction register GPDR [95:64]   */
.equ            MH_GSDR3        ,     (0x40E0040C)        /* Bit-wise Set of GPIO Direction register GPDR [127:96]  */

.equ            MH_GCDR0        ,     (0x40E00420)        /* Bit-wise Clear of GPIO Direction register GPDR [31:0]  */
.equ            MH_GCDR1        ,     (0x40E00424)        /* Bit-wise Clear of GPIO Direction register GPDR [63:32] */
.equ            MH_GCDR2        ,     (0x40E00428)        /* Bit-wise Clear of GPIO Direction register GPDR [95:64] */
.equ            MH_GCDR3        ,     (0x40E0042C)        /* Bit-wise Clear of GPIO Direction register GPDR [127:96]*/

.equ            MH_GSRER0       ,     (0x40E00440)        /* Bit-wise Set of GPIO Rising Edge Detect Enable register GRER [31:0]      */
.equ            MH_GSRER1       ,     (0x40E00444)        /* Bit-wise Set of GPIO Rising Edge Detect Enable register GRER [63:32]     */
.equ            MH_GSRER2       ,     (0x40E00448)        /* Bit-wise Set of GPIO Rising Edge Detect Enable register GRER [95:64]     */
.equ            MH_GSRER3       ,     (0x40E0044C)        /* Bit-wise Set of GPIO Rising Edge Detect Enable register GRER [127:96]    */

.equ            MH_GCRER0       ,     (0x40E00460)        /* Bit-wise Clear of GPIO Rising Edge Detect Enable register GRER [31:0]    */
.equ            MH_GCRER1       ,     (0x40E00464)        /* Bit-wise Clear of GPIO Rising Edge Detect Enable register GRER [63:32]   */
.equ            MH_GCRER2       ,     (0x40E00468)        /* Bit-wise Clear of GPIO Rising Edge Detect Enable register GRER [95:64]   */
.equ            MH_GCRER3       ,     (0x40E0046C)        /* Bit-wise Clear of GPIO Rising Edge Detect Enable register GRER [127:96]  */

.equ            MH_GSFER0       ,     (0x40E00480)        /* Bit-wise Set of GPIO Falling Edge Detect Enable register GRER [31:0]     */
.equ            MH_GSFER1       ,     (0x40E00484)        /* Bit-wise Set of GPIO Falling Edge Detect Enable register GRER [63:32]    */
.equ            MH_GSFER2       ,     (0x40E00488)        /* Bit-wise Set of GPIO Falling Edge Detect Enable register GRER [95:64]    */
.equ            MH_GSFER3       ,     (0x40E0048C)        /* Bit-wise Set of GPIO Falling Edge Detect Enable register GRER [127:96]   */

.equ            MH_GCFER0       ,     (0x40E004A0)        /* Bit-wise Clear of GPIO Falling Edge Detect Enable register GRER [31:0]   */
.equ            MH_GCFER1       ,     (0x40E004A4)        /* Bit-wise Clear of GPIO Falling Edge Detect Enable register GRER [63:32]  */
.equ            MH_GCFER2       ,     (0x40E004A8)        /* Bit-wise Clear of GPIO Falling Edge Detect Enable register GRER [95:64]  */
.equ            MH_GCFER3       ,     (0x40E004AC)        /* Bit-wise Clear of GPIO Falling Edge Detect Enable register GRER [127:96] */

/*
 MFPR Registers
*/
.equ            MH_MFPR_BASE    ,     (0x40E10000)

/*
 Services unit clock control unit
*/
.equ            MH_OSCC         ,     (0x41350000)        /* Oscillator Configuration register */

/*
 Slave clock control unit
*/
.equ            MH_ACCR         ,     (0x41340000)        /* Application Subsystem Clock Configuration register       */
.equ            MH_ACSR         ,     (0x41340004)        /* Application Subsystem Clock Status register              */
.equ            MH_AICSR        ,     (0x41340008)        /* Application Subsystem Interrupt Control/Status register  */
.equ            MH_D0CKENA      ,     (0x4134000C)        /* D0 Mode Clock Enable register A                          */
.equ            MH_D0CKENB      ,     (0x41340010)        /* D0 Mode Clock Enable register B                          */
.equ            MH_AC97DIV      ,     (0x41340014)        /* AC ?бе97 Clock Divisor Value register                     */

/*
 Services unit power management unit
*/
.equ            MH_PMCR         ,     (0x40F50000)        /* Power Management Unit Control register                   */
.equ            MH_PSR          ,     (0x40F50004)        /* Power Management Unit S2 Status register                 */
.equ            MH_PSPR         ,     (0x40F50008)        /* Power Management Unit Scratch Pad register               */
.equ            MH_PCFR         ,     (0x40F5000C)        /* Power Management Unit General Configuration register     */
.equ            MH_PWER         ,     (0x40F50010)        /* Power Manager Wake-Up Enable register                    */
.equ            MH_PWSR         ,     (0x40F50014)        /* Power Manager Wake-Up Status register                    */
.equ            MH_PECR         ,     (0x40F50018)        /* Power Manager EXTWAKEUP[1:0] Control register            */
.equ            MH_PVCR         ,     (0x40F50100)        /* Power Management Unit Voltage Change Control register    */

/*
 Slave power management unit
*/
.equ            MH_ASCR         ,     (0x40F40000)        /* Application Subsystem Power Status/Configuration register     */
.equ            MH_ARSR         ,     (0x40F40004)        /* Application Subsystem Reset Status register                   */
.equ            MH_AD3ER        ,     (0x40F40008)        /* Application Subsystem D3 State Wake-Up Enable register        */
.equ            MH_AD3SR        ,     (0x40F4000C)        /* Application Subsystem D3 State Wake-up Status register        */
.equ            MH_AD2D0ER      ,     (0x40F40010)        /* Application Subsystem D2 to D0 State Wake-Up Enable register  */
.equ            MH_AD2D0SR      ,     (0x40F40014)        /* Application Subsystem D2 to D0 State Wake-Up Status register  */
.equ            MH_AD2D1ER      ,     (0x40F40018)        /* Application Subsystem D2 to D1 State Wake-Up Enable register  */
.equ            MH_AD2D1SR      ,     (0x40F4001C)        /* Application Subsystem D2 to D1 State Wake-Up Status register  */
.equ            MH_AD1D0ER      ,     (0x40F40020)        /* Application Subsystem D1 to D0 State Wake-Up Enable register  */
.equ            MH_AD1D0SR      ,     (0x40F40024)        /* Application Subsystem D1 to D0 State Wake-Up Status register  */
.equ            MH_AD3R         ,     (0x40F40030)        /* Application Subsystem D3 State Configuration register         */
.equ            MH_AD2R         ,     (0x40F40034)        /* Application Subsystem D2 State Configuration register         */
.equ            MH_AD1R         ,     (0x40F40038)        /* Application Subsystem D1 State Configuration register         */

/*
 1-Wire Bus Master Interface
*/
.equ            MH_W1CMDR       ,     (0x41B00000)        /* 1-Wire Command register           */
.equ            MH_W1TRR        ,     (0x41B00004)        /* 1-Wire Transmit/Receive buffer    */
.equ            MH_W1INTR       ,     (0x41B00008)        /* 1-Wire Interrupt register         */
.equ            MH_W1IER        ,     (0x41B0000C)        /* 1-Wire Interrupt Enable register  */
.equ            MH_W1CDR        ,     (0x41B00010)        /* 1-Wire Clock Divisor register     */

/*
 DMA Controller
*/
.equ            MH_DCSR0        ,     (0x40000000)        /* DMA Control / Status register for channel 0                                           */
.equ            MH_DCSR1        ,     (0x40000004)        /* DMA Control / Status register for channel 1                                           */
.equ            MH_DCSR2        ,     (0x40000008)        /* DMA Control / Status register for channel 2                                           */
.equ            MH_DCSR3        ,     (0x4000000C)        /* DMA Control / Status register for channel 3                                           */
.equ            MH_DCSR4        ,     (0x40000010)        /* DMA Control / Status register for channel 4                                           */
.equ            MH_DCSR5        ,     (0x40000014)        /* DMA Control / Status register for channel 5                                           */
.equ            MH_DCSR6        ,     (0x40000018)        /* DMA Control / Status register for channel 6                                           */
.equ            MH_DCSR7        ,     (0x4000001C)        /* DMA Control / Status register for channel 7                                           */
.equ            MH_DCSR8        ,     (0x40000020)        /* DMA Control / Status register for channel 8                                           */
.equ            MH_DCSR9        ,     (0x40000024)        /* DMA Control / Status register for channel 9                                           */
.equ            MH_DCSR10       ,     (0x40000028)        /* DMA Control / Status register for channel 10                                          */
.equ            MH_DCSR11       ,     (0x4000002C)        /* DMA Control / Status register for channel 11                                          */
.equ            MH_DCSR12       ,     (0x40000030)        /* DMA Control / Status register for channel 12                                          */
.equ            MH_DCSR13       ,     (0x40000034)        /* DMA Control / Status register for channel 13                                          */
.equ            MH_DCSR14       ,     (0x40000038)        /* DMA Control / Status register for channel 14                                          */
.equ            MH_DCSR15       ,     (0x4000003C)        /* DMA Control / Status register for channel 15                                          */
.equ            MH_DCSR16       ,     (0x40000040)        /* DMA Control / Status register for channel 16                                          */
.equ            MH_DCSR17       ,     (0x40000044)        /* DMA Control / Status register for channel 17                                          */
.equ            MH_DCSR18       ,     (0x40000048)        /* DMA Control / Status register for channel 18                                          */
.equ            MH_DCSR19       ,     (0x4000004C)        /* DMA Control / Status register for channel 19                                          */
.equ            MH_DCSR20       ,     (0x40000050)        /* DMA Control / Status register for channel 20                                          */
.equ            MH_DCSR21       ,     (0x40000054)        /* DMA Control / Status register for channel 21                                          */
.equ            MH_DCSR22       ,     (0x40000058)        /* DMA Control / Status register for channel 22                                          */
.equ            MH_DCSR23       ,     (0x4000005C)        /* DMA Control / Status register for channel 23                                          */
.equ            MH_DCSR24       ,     (0x40000060)        /* DMA Control / Status register for channel 24                                          */
.equ            MH_DCSR25       ,     (0x40000064)        /* DMA Control / Status register for channel 25                                          */
.equ            MH_DCSR26       ,     (0x40000068)        /* DMA Control / Status register for channel 26                                          */
.equ            MH_DCSR27       ,     (0x4000006C)        /* DMA Control / Status register for channel 27                                          */
.equ            MH_DCSR28       ,     (0x40000070)        /* DMA Control / Status register for channel 28                                          */
.equ            MH_DCSR29       ,     (0x40000074)        /* DMA Control / Status register for channel 29                                          */
.equ            MH_DCSR30       ,     (0x40000078)        /* DMA Control / Status register for channel 30                                          */
.equ            MH_DCSR31       ,     (0x4000007C)        /* DMA Control / Status register for channel 31                                          */
.equ            MH_DALGN        ,     (0x400000A0)        /* DMA alignment register                                                                */
.equ            MH_DPCSR        ,     (0x400000A4)        /* DMA Programmed IO control status register                                             */
.equ            MH_DRQSR0       ,     (0x400000E0)        /* DMA DREQ Status register                                                              */
.equ            MH_DINT         ,     (0x400000F0)        /* DMA Interrupt register                                                                */
.equ            MH_DRCMR0       ,     (0x40000100)        /* Request to Channel Map register for DREQ                                              */
.equ            MH_DRCMR2       ,     (0x40000108)        /* Request to Channel Map register for SSP4 receive request                              */
.equ            MH_DRCMR3       ,     (0x4000010C)        /* Request to Channel Map register for SSP4 transmit request                             */
.equ            MH_DRCMR4       ,     (0x40000110)        /* Request to Channel Map register for UART2 receive request                             */
.equ            MH_DRCMR5       ,     (0x40000114)        /* Request to Channel Map register for UART2 transmit request.                           */
.equ            MH_DRCMR6       ,     (0x40000118)        /* Request to Channel Map register for UART1 receive request                             */
.equ            MH_DRCMR7       ,     (0x4000011C)        /* Request to Channel Map register for UART1 transmit request                            */
.equ            MH_DRCMR8       ,     (0x40000120)        /* Request to Channel Map register for AC97 microphone request                           */
.equ            MH_DRCMR9       ,     (0x40000124)        /* Request to Channel Map register for AC97 modem receive request                        */
.equ            MH_DRCMR10      ,     (0x40000128)        /* Request to Channel Map register for AC97 modem transmit request                       */
.equ            MH_DRCMR11      ,     (0x4000012C)        /* Request to Channel Map register for AC97 audio receive request                        */
.equ            MH_DRCMR12      ,     (0x40000130)        /* Request to Channel Map register for AC97 audio transmit request                       */
.equ            MH_DRCMR13      ,     (0x40000134)        /* Request to Channel Map register for SSP1 receive request                              */
.equ            MH_DRCMR14      ,     (0x40000138)        /* Request to Channel Map register for SSP1 transmit request                             */
.equ            MH_DRCMR15      ,     (0x4000013C)        /* Request to Channel Map register for SSP2 receive request                              */
.equ            MH_DRCMR16      ,     (0x40000140)        /* Request to Channel Map register for SSP2 transmit request                             */
.equ            MH_DRCMR19      ,     (0x4000014C)        /* Request to Channel Map register for UART3 receive request                             */
.equ            MH_DRCMR20      ,     (0x40000150)        /* Request to Channel Map register for UART3 transmit request                            */
.equ            MH_DRCMR21      ,     (0x40000154)        /* Request to Channel Map register for MMC/SDIO 1 receive request                        */
.equ            MH_DRCMR22      ,     (0x40000158)        /* Request to Channel Map register for MMC/SDIO 1 transmit request                       */
.equ            MH_DRCMR24      ,     (0x40000160)        /* Request to Channel Map register for USB endpoint 0 request                            */
.equ            MH_DRCMR25      ,     (0x40000164)        /* Request to Channel Map register for USB endpoint A request                            */
.equ            MH_DRCMR26      ,     (0x40000168)        /* Request to Channel Map register for USB endpoint B request                            */
.equ            MH_DRCMR27      ,     (0x4000016C)        /* Request to Channel Map register for USB endpoint C request                            */
.equ            MH_DRCMR28      ,     (0x40000170)        /* Request to Channel Map register for USB endpoint D request                            */
.equ            MH_DRCMR29      ,     (0x40000174)        /* Request to Channel Map register for USB endpoint E request                            */
.equ            MH_DRCMR30      ,     (0x40000178)        /* Request to Channel Map register for USB endpoint F request                            */
.equ            MH_DRCMR31      ,     (0x4000017C)        /* Request to Channel Map register for USB endpoint G request                            */
.equ            MH_DRCMR32      ,     (0x40000180)        /* Request to Channel Map register for USB endpoint H request                            */
.equ            MH_DRCMR33      ,     (0x40000184)        /* Request to Channel Map register for USB endpoint I request                            */
.equ            MH_DRCMR34      ,     (0x40000188)        /* Request to Channel Map register for USB endpoint J request                            */
.equ            MH_DRCMR35      ,     (0x4000018C)        /* Request to Channel Map register for USB endpoint K request                            */
.equ            MH_DRCMR36      ,     (0x40000190)        /* Request to Channel Map register for USB endpoint L request                            */
.equ            MH_DRCMR37      ,     (0x40000194)        /* Request to Channel Map register for USB endpoint M request                            */
.equ            MH_DRCMR38      ,     (0x40000198)        /* Request to Channel Map register for USB endpoint N request                            */
.equ            MH_DRCMR39      ,     (0x4000019C)        /* Request to Channel Map register for USB endpoint P request                            */
.equ            MH_DRCMR40      ,     (0x400001A0)        /* Request to Channel Map register for USB endpoint Q request                            */
.equ            MH_DRCMR41      ,     (0x400001A4)        /* Request to Channel Map register for USB endpoint R request                            */
.equ            MH_DRCMR42      ,     (0x400001A8)        /* Request to Channel Map register for USB endpoint S request                            */
.equ            MH_DRCMR43      ,     (0x400001AC)        /* Request to Channel Map register for USB endpoint T request                            */
.equ            MH_DRCMR44      ,     (0x400001B0)        /* Request to Channel Map register for USB endpoint U request                            */
.equ            MH_DRCMR45      ,     (0x400001B4)        /* Request to Channel Map register for USB endpoint V request                            */
.equ            MH_DRCMR46      ,     (0x400001B8)        /* Request to Channel Map register for USB endpoint W request                            */
.equ            MH_DRCMR47      ,     (0x400001BC)        /* Request to Channel Map register for USB endpoint X request                            */
.equ            MH_DRCMR48      ,     (0x400001C0)        /* Request to Channel Map register for MSL receive request 1                             */
.equ            MH_DRCMR49      ,     (0x400001C4)        /* Request to Channel Map register for MSL transmit request 1                            */
.equ            MH_DRCMR50      ,     (0x400001C8)        /* Request to Channel Map register for MSL receive request 2                             */
.equ            MH_DRCMR51      ,     (0x400001CC)        /* Request to Channel Map register for MSL transmit request 2                            */
.equ            MH_DRCMR52      ,     (0x400001D0)        /* Request to Channel Map register for MSL receive request 3                             */
.equ            MH_DRCMR53      ,     (0x400001D4)        /* Request to Channel Map register for MSL transmit request 3                            */
.equ            MH_DRCMR54      ,     (0x400001D8)        /* Request to Channel Map register for MSL receive request 4                             */
.equ            MH_DRCMR55      ,     (0x400001DC)        /* Request to Channel Map register for MSL transmit request 4                            */
.equ            MH_DRCMR56      ,     (0x400001E0)        /* Request to Channel Map register for MSL receive request 5                             */
.equ            MH_DRCMR57      ,     (0x400001E4)        /* Request to Channel Map register for MSL transmit request 5                            */
.equ            MH_DRCMR58      ,     (0x400001E8)        /* Request to Channel Map register for MSL receive request 6                             */
.equ            MH_DRCMR59      ,     (0x400001EC)        /* Request to Channel Map register for MSL transmit request 6                            */
.equ            MH_DRCMR60      ,     (0x400001F0)        /* Request to Channel Map register for MSL receive request 7                             */
.equ            MH_DRCMR61      ,     (0x400001F4)        /* Request to Channel Map register for MSL transmit request 7                            */
.equ            MH_DRCMR62      ,     (0x400001F8)        /* Request to Channel Map register for USIM 1 receive request                            */
.equ            MH_DRCMR63      ,     (0x400001FC)        /* Request to Channel Map register for USIM 1 transmit request                           */
.equ            MH_DDADR0       ,     (0x40000200)        /* DMA Descriptor Address register channel 0                                             */
.equ            MH_DSADR0       ,     (0x40000204)        /* DMA Source Address register channel 0                                                 */
.equ            MH_DTADR0       ,     (0x40000208)        /* DMA Target Address register channel 0                                                 */
.equ            MH_DCMD0        ,     (0x4000020C)        /* DMA Command Address register channel 0                                                */
.equ            MH_DDADR1       ,     (0x40000210)        /* DMA Descriptor Address register channel 1                                             */
.equ            MH_DSADR1       ,     (0x40000214)        /* DMA Source Address register channel 1                                                 */
.equ            MH_DTADR1       ,     (0x40000218)        /* DMA Target Address register channel 1                                                 */
.equ            MH_DCMD1        ,     (0x4000021C)        /* DMA Command Address register channel 1                                                */
.equ            MH_DDADR2       ,     (0x40000220)        /* DMA Descriptor Address register channel 2                                             */
.equ            MH_DSADR2       ,     (0x40000224)        /* DMA Source Address register channel 2                                                 */
.equ            MH_DTADR2       ,     (0x40000228)        /* DMA Target Address register channel 2                                                 */
.equ            MH_DCMD2        ,     (0x4000022C)        /* DMA Command Address register channel 2                                                */
.equ            MH_DDADR3       ,     (0x40000230)        /* DMA Descriptor Address register channel 3                                             */
.equ            MH_DSADR3       ,     (0x40000234)        /* DMA Source Address register channel 3                                                 */
.equ            MH_DTADR3       ,     (0x40000238)        /* DMA Target Address register channel 3                                                 */
.equ            MH_DCMD3        ,     (0x4000023C)        /* DMA Command Address register channel 3                                                */
.equ            MH_DDADR4       ,     (0x40000240)        /* DMA Descriptor Address register channel 4                                             */
.equ            MH_DSADR4       ,     (0x40000244)        /* DMA Source Address register channel 4                                                 */
.equ            MH_DTADR4       ,     (0x40000248)        /* DMA Target Address register channel 4                                                 */
.equ            MH_DCMD4        ,     (0x4000024C)        /* DMA Command Address register channel 4                                                */
.equ            MH_DDADR5       ,     (0x40000250)        /* DMA Descriptor Address register channel 5                                             */
.equ            MH_DSADR5       ,     (0x40000254)        /* DMA Source Address register channel 5                                                 */
.equ            MH_DTADR5       ,     (0x40000258)        /* DMA Target Address register channel 5                                                 */
.equ            MH_DCMD5        ,     (0x4000025C)        /* DMA Command Address register channel 5                                                */
.equ            MH_DDADR6       ,     (0x40000260)        /* DMA Descriptor Address register channel 6                                             */
.equ            MH_DSADR6       ,     (0x40000264)        /* DMA Source Address register channel 6                                                 */
.equ            MH_DTADR6       ,     (0x40000268)        /* DMA Target Address register channel 6                                                 */
.equ            MH_DCMD6        ,     (0x4000026C)        /* DMA Command Address register channel 6                                                */
.equ            MH_DDADR7       ,     (0x40000270)        /* DMA Descriptor Address register channel 7                                             */
.equ            MH_DSADR7       ,     (0x40000274)        /* DMA Source Address register channel 7                                                 */
.equ            MH_DTADR7       ,     (0x40000278)        /* DMA Target Address register channel 7                                                 */
.equ            MH_DCMD7        ,     (0x4000027C)        /* DMA Command Address register channel 7                                                */
.equ            MH_DDADR8       ,     (0x40000280)        /* DMA Descriptor Address register channel 8                                             */
.equ            MH_DSADR8       ,     (0x40000284)        /* DMA Source Address register channel 8                                                 */
.equ            MH_DTADR8       ,     (0x40000288)        /* DMA Target Address register channel 8                                                 */
.equ            MH_DCMD8        ,     (0x4000028C)        /* DMA Command Address register channel 8                                                */
.equ            MH_DDADR9       ,     (0x40000290)        /* DMA Descriptor Address register channel 9                                             */
.equ            MH_DSADR9       ,     (0x40000294)        /* DMA Source Address register channel 9                                                 */
.equ            MH_DTADR9       ,     (0x40000298)        /* DMA Target Address register channel 9                                                 */
.equ            MH_DCMD9        ,     (0x4000029C)        /* DMA Command Address register channel 9                                                */
.equ            MH_DDADR10      ,     (0x400002A0)        /* DMA Descriptor Address register channel 10                                            */
.equ            MH_DSADR10      ,     (0x400002A4)        /* DMA Source Address register channel 10                                                */
.equ            MH_DTADR10      ,     (0x400002A8)        /* DMA Target Address register channel 10                                                */
.equ            MH_DCMD10       ,     (0x400002AC)        /* DMA Command Address register channel 10                                               */
.equ            MH_DDADR11      ,     (0x400002B0)        /* DMA Descriptor Address register channel 11                                            */
.equ            MH_DSADR11      ,     (0x400002B4)        /* DMA Source Address register channel 11                                                */
.equ            MH_DTADR11      ,     (0x400002B8)        /* DMA Target Address register channel 11                                                */
.equ            MH_DCMD11       ,     (0x400002BC)        /* DMA Command Address register channel 11                                               */
.equ            MH_DDADR12      ,     (0x400002C0)        /* DMA Descriptor Address register channel 12                                            */
.equ            MH_DSADR12      ,     (0x400002C4)        /* DMA Source Address register channel 12                                                */
.equ            MH_DTADR12      ,     (0x400002C8)        /* DMA Target Address register channel 12                                                */
.equ            MH_DCMD12       ,     (0x400002CC)        /* DMA Command Address register channel 12                                               */
.equ            MH_DDADR13      ,     (0x400002D0)        /* DMA Descriptor Address register channel 13                                            */
.equ            MH_DSADR13      ,     (0x400002D4)        /* DMA Source Address register channel 13                                                */
.equ            MH_DTADR13      ,     (0x400002D8)        /* DMA Target Address register channel 13                                                */
.equ            MH_DCMD13       ,     (0x400002DC)        /* DMA Command Address register channel 13                                               */
.equ            MH_DDADR14      ,     (0x400002E0)        /* DMA Descriptor Address register channel 14                                            */
.equ            MH_DSADR14      ,     (0x400002E4)        /* DMA Source Address register channel 14                                                */
.equ            MH_DTADR14      ,     (0x400002E8)        /* DMA Target Address register channel 14                                                */
.equ            MH_DCMD14       ,     (0x400002EC)        /* DMA Command Address register channel 14                                               */
.equ            MH_DDADR15      ,     (0x400002F0)        /* DMA Descriptor Address register channel 15                                            */
.equ            MH_DSADR15      ,     (0x400002F4)        /* DMA Source Address register channel 15                                                */
.equ            MH_DTADR15      ,     (0x400002F8)        /* DMA Target Address register channel 15                                                */
.equ            MH_DCMD15       ,     (0x400002FC)        /* DMA Command Address register channel 15                                               */
.equ            MH_DDADR16      ,     (0x40000300)        /* DMA Descriptor Address register channel 16                                            */
.equ            MH_DSADR16      ,     (0x40000304)        /* DMA Source Address register channel 16                                                */
.equ            MH_DTADR16      ,     (0x40000308)        /* DMA Target Address register channel 16                                                */
.equ            MH_DCMD16       ,     (0x4000030C)        /* DMA Command Address register channel 16                                               */
.equ            MH_DDADR17      ,     (0x40000310)        /* DMA Descriptor Address register channel 17                                            */
.equ            MH_DSADR17      ,     (0x40000314)        /* DMA Source Address register channel 17                                                */
.equ            MH_DTADR17      ,     (0x40000318)        /* DMA Target Address register channel 17                                                */
.equ            MH_DCMD17       ,     (0x4000031C)        /* DMA Command Address register channel 17                                               */
.equ            MH_DDADR18      ,     (0x40000320)        /* DMA Descriptor Address register channel 18                                            */
.equ            MH_DSADR18      ,     (0x40000324)        /* DMA Source Address register channel 18                                                */
.equ            MH_DTADR18      ,     (0x40000328)        /* DMA Target Address register channel 18                                                */
.equ            MH_DCMD18       ,     (0x4000032C)        /* DMA Command Address register channel 18                                               */
.equ            MH_DDADR19      ,     (0x40000330)        /* DMA Descriptor Address register channel 19                                            */
.equ            MH_DSADR19      ,     (0x40000334)        /* DMA Source Address register channel 19                                                */
.equ            MH_DTADR19      ,     (0x40000338)        /* DMA Target Address register channel 19                                                */
.equ            MH_DCMD19       ,     (0x4000033C)        /* DMA Command Address register channel 19                                               */
.equ            MH_DDADR20      ,     (0x40000340)        /* DMA Descriptor Address register channel 20                                            */
.equ            MH_DSADR20      ,     (0x40000344)        /* DMA Source Address register channel 20                                                */
.equ            MH_DTADR20      ,     (0x40000348)        /* DMA Target Address register channel 20                                                */
.equ            MH_DCMD20       ,     (0x4000034C)        /* DMA Command Address register channel 20                                               */
.equ            MH_DDADR21      ,     (0x40000350)        /* DMA Descriptor Address register channel 21                                            */
.equ            MH_DSADR21      ,     (0x40000354)        /* DMA Source Address register channel 21                                                */
.equ            MH_DTADR21      ,     (0x40000358)        /* DMA Target Address register channel 21                                                */
.equ            MH_DCMD21       ,     (0x4000035C)        /* DMA Command Address register channel 21                                               */
.equ            MH_DDADR22      ,     (0x40000360)        /* DMA Descriptor Address register channel 22                                            */
.equ            MH_DSADR22      ,     (0x40000364)        /* DMA Source Address register channel 22                                                */
.equ            MH_DTADR22      ,     (0x40000368)        /* DMA Target Address register channel 22                                                */
.equ            MH_DCMD22       ,     (0x4000036C)        /* DMA Command Address register channel 22                                               */
.equ            MH_DDADR23      ,     (0x40000370)        /* DMA Descriptor Address register channel 23                                            */
.equ            MH_DSADR23      ,     (0x40000374)        /* DMA Source Address register channel 23                                                */
.equ            MH_DTADR23      ,     (0x40000378)        /* DMA Target Address register channel 23                                                */
.equ            MH_DCMD23       ,     (0x4000037C)        /* DMA Command Address register channel 23                                               */
.equ            MH_DDADR24      ,     (0x40000380)        /* DMA Descriptor Address register channel 24                                            */
.equ            MH_DSADR24      ,     (0x40000384)        /* DMA Source Address register channel 24                                                */
.equ            MH_DTADR24      ,     (0x40000388)        /* DMA Target Address register channel 24                                                */
.equ            MH_DCMD24       ,     (0x4000038C)        /* DMA Command Address register channel 24                                               */
.equ            MH_DDADR25      ,     (0x40000390)        /* DMA Descriptor Address register channel 25                                            */
.equ            MH_DSADR25      ,     (0x40000394)        /* DMA Source Address register channel 25                                                */
.equ            MH_DTADR25      ,     (0x40000398)        /* DMA Target Address register channel 25                                                */
.equ            MH_DCMD25       ,     (0x4000039C)        /* DMA Command Address register channel 25                                               */
.equ            MH_DDADR26      ,     (0x400003A0)        /* DMA Descriptor Address register channel 26                                            */
.equ            MH_DSADR26      ,     (0x400003A4)        /* DMA Source Address register channel 26                                                */
.equ            MH_DTADR26      ,     (0x400003A8)        /* DMA Target Address register channel 26                                                */
.equ            MH_DCMD26       ,     (0x400003AC)        /* DMA Command Address register channel 26                                               */
.equ            MH_DDADR27      ,     (0x400003B0)        /* DMA Descriptor Address register channel 27                                            */
.equ            MH_DSADR27      ,     (0x400003B4)        /* DMA Source Address register channel 27                                                */
.equ            MH_DTADR27      ,     (0x400003B8)        /* DMA Target Address register channel 27                                                */
.equ            MH_DCMD27       ,     (0x400003BC)        /* DMA Command Address register channel 27                                               */
.equ            MH_DDADR28      ,     (0x400003C0)        /* DMA Descriptor Address register channel 28                                            */
.equ            MH_DSADR28      ,     (0x400003C4)        /* DMA Source Address register channel 28                                                */
.equ            MH_DTADR28      ,     (0x400003C8)        /* DMA Target Address register channel 28                                                */
.equ            MH_DCMD28       ,     (0x400003CC)        /* DMA Command Address register channel 28                                               */
.equ            MH_DDADR29      ,     (0x400003D0)        /* DMA Descriptor Address register channel 29                                            */
.equ            MH_DSADR29      ,     (0x400003D4)        /* DMA Source Address register channel 29                                                */
.equ            MH_DTADR29      ,     (0x400003D8)        /* DMA Target Address register channel 29                                                */
.equ            MH_DCMD29       ,     (0x400003DC)        /* DMA Command Address register channel 29                                               */
.equ            MH_DDADR30      ,     (0x400003E0)        /* DMA Descriptor Address register channel 30                                            */
.equ            MH_DSADR30      ,     (0x400003E4)        /* DMA Source Address register channel 30                                                */
.equ            MH_DTADR30      ,     (0x400003E8)        /* DMA Target Address register channel 30                                                */
.equ            MH_DCMD30       ,     (0x400003EC)        /* DMA Command Address register channel 30                                               */
.equ            MH_DDADR31      ,     (0x400003F0)        /* DMA Descriptor Address register channel 31                                            */
.equ            MH_DSADR31      ,     (0x400003F4)        /* DMA Source Address register channel 31                                                */
.equ            MH_DTADR31      ,     (0x400003F8)        /* DMA Target Address register channel 31                                                */
.equ            MH_DCMD31       ,     (0x400003FC)        /* DMA Command Address register channel 31                                               */
.equ            MH_DRCMR66      ,     (0x40001108)        /* Request to Channel Map register for SSP3 receive request                              */
.equ            MH_DRCMR67      ,     (0x4000110C)        /* Request to Channel Map register for SSP3 transmit request                             */
.equ            MH_DRCMR91      ,     (0x4000116C)        /* Request to Channel Map register for USIM 2 receive request                            */
.equ            MH_DRCMR92      ,     (0x40001170)        /* Request to Channel Map register for USIM 2 transmit request                           */
.equ            MH_DRCMR93      ,     (0x40001174)        /* Request to Channel Map register for MMC/SDIO 2 receive                                */
.equ            MH_DRCMR94      ,     (0x40001178)        /* Request to Channel Map register for MMC/SDIO 2 transmit request                       */
.equ            MH_DRCMR95      ,     (0x4000117C)        /* Request to Channel Map register for AC97 surround transmit request                    */
.equ            MH_DRCMR96      ,     (0x40001180)        /* Request to Channel Map register for AC97 centre/LFE transmit request                  */
.equ            MH_DRCMR97      ,     (0x40001184)        /* Request to Channel Map register for NAND interface data transmit & receive request    */
.equ            MH_DRCMR99      ,     (0x4000118C)        /* Request to Channel Map register for NAND interface command transmit request           */

/*
 Interrupt Controller
*/
.equ            MH_ICIP         ,     (0x40D00000)        /* CP6, CR0 Interrupt Controller IRQ Pending register                                    */
.equ            MH_ICMR         ,     (0x40D00004)        /* CP6, CR1 Interrupt Controller Mask register                                           */
.equ            MH_ICLR         ,     (0x40D00008)        /* CP6, CR2 Interrupt Controller Level register                                          */
.equ            MH_ICFP         ,     (0x40D0000C)        /* CP6, CR3 Interrupt Controller FIQ Pending register                                    */
.equ            MH_ICPR         ,     (0x40D00010)        /* CP6, CR4 Interrupt Controller Pending register                                        */
.equ            MH_ICCR         ,     (0x40D00014)        /* Interrupt Controller Control register                                                 */
.equ            MH_ICHP         ,     (0x40D00018)        /* CP6, CR5 Interrupt Controller Highest Priority register                               */
.equ            MH_IPR0         ,     (0x40D0001C)        /* Interrupt Priority registers for interrupts 0                                         */
.equ            MH_IPR1         ,     (0x40D00020)        /* Interrupt Priority registers for interrupts 1                                         */
.equ            MH_IPR2         ,     (0x40D00024)        /* Interrupt Priority registers for interrupts 2                                         */
.equ            MH_IPR3         ,     (0x40D00028)        /* Interrupt Priority registers for interrupts 3                                         */
.equ            MH_IPR4         ,     (0x40D0002C)        /* Interrupt Priority registers for interrupts 4                                         */
.equ            MH_IPR5         ,     (0x40D00030)        /* Interrupt Priority registers for interrupts 5                                         */
.equ            MH_IPR6         ,     (0x40D00034)        /* Interrupt Priority registers for interrupts 6                                         */
.equ            MH_IPR7         ,     (0x40D00038)        /* Interrupt Priority registers for interrupts 7                                         */
.equ            MH_IPR8         ,     (0x40D0003C)        /* Interrupt Priority registers for interrupts 8                                         */
.equ            MH_IPR9         ,     (0x40D00040)        /* Interrupt Priority registers for interrupts 9                                         */
.equ            MH_IPR10        ,     (0x40D00044)        /* Interrupt Priority registers for interrupts 10                                        */
.equ            MH_IPR11        ,     (0x40D00048)        /* Interrupt Priority registers for interrupts 11                                        */
.equ            MH_IPR12        ,     (0x40D0004C)        /* Interrupt Priority registers for interrupts 12                                        */
.equ            MH_IPR13        ,     (0x40D00050)        /* Interrupt Priority registers for interrupts 13                                        */
.equ            MH_IPR14        ,     (0x40D00054)        /* Interrupt Priority registers for interrupts 14                                        */
.equ            MH_IPR15        ,     (0x40D00058)        /* Interrupt Priority registers for interrupts 15                                        */
.equ            MH_IPR16        ,     (0x40D0005C)        /* Interrupt Priority registers for interrupts 16                                        */
.equ            MH_IPR17        ,     (0x40D00060)        /* Interrupt Priority registers for interrupts 17                                        */
.equ            MH_IPR18        ,     (0x40D00064)        /* Interrupt Priority registers for interrupts 18                                        */
.equ            MH_IPR19        ,     (0x40D00068)        /* Interrupt Priority registers for interrupts 19                                        */
.equ            MH_IPR20        ,     (0x40D0006C)        /* Interrupt Priority registers for interrupts 20                                        */
.equ            MH_IPR21        ,     (0x40D00070)        /* Interrupt Priority registers for interrupts 21                                        */
.equ            MH_IPR22        ,     (0x40D00074)        /* Interrupt Priority registers for interrupts 22                                        */
.equ            MH_IPR23        ,     (0x40D00078)        /* Interrupt Priority registers for interrupts 23                                        */
.equ            MH_IPR24        ,     (0x40D0007C)        /* Interrupt Priority registers for interrupts 24                                        */
.equ            MH_IPR25        ,     (0x40D00080)        /* Interrupt Priority registers for interrupts 25                                        */
.equ            MH_IPR26        ,     (0x40D00084)        /* Interrupt Priority registers for interrupts 26                                        */
.equ            MH_IPR27        ,     (0x40D00088)        /* Interrupt Priority registers for interrupts 27                                        */
.equ            MH_IPR28        ,     (0x40D0008C)        /* Interrupt Priority registers for interrupts 28                                        */
.equ            MH_IPR29        ,     (0x40D00090)        /* Interrupt Priority registers for interrupts 29                                        */
.equ            MH_IPR30        ,     (0x40D00094)        /* Interrupt Priority registers for interrupts 30                                        */
.equ            MH_IPR31        ,     (0x40D00098)        /* Interrupt Priority registers for interrupts 31                                        */
.equ            MH_ICIP2        ,     (0x40D0009C)        /* CP6, CR6 Interrupt Controller IRQ Pending register 2                                  */
.equ            MH_ICMR2        ,     (0x40D000A0)        /* CP6, CR7 Interrupt Controller Mask register 2                                         */
.equ            MH_ICLR2        ,     (0x40D000A4)        /* CP6, CR8 Interrupt Controller Level register 2                                        */
.equ            MH_ICFP2        ,     (0x40D000A8)        /* CP6, CR9 Interrupt Controller FIQ Pending register 2                                  */
.equ            MH_ICPR2        ,     (0x40D000AC)        /* CP6, CR10 Interrupt Controller Pending register 2                                     */
.equ            MH_IPR32        ,     (0x40D000B0)        /* Interrupt Priority registers for priorities 32                                        */
.equ            MH_IPR33        ,     (0x40D000B4)        /* Interrupt Priority registers for priorities 33                                        */
.equ            MH_IPR34        ,     (0x40D000B8)        /* Interrupt Priority registers for priorities 34                                        */
.equ            MH_IPR35        ,     (0x40D000BC)        /* Interrupt Priority registers for priorities 35                                        */
.equ            MH_IPR36        ,     (0x40D000C0)        /* Interrupt Priority registers for priorities 36                                        */
.equ            MH_IPR37        ,     (0x40D000C4)        /* Interrupt Priority registers for priorities 37                                        */
.equ            MH_IPR38        ,     (0x40D000C8)        /* Interrupt Priority registers for priorities 38                                        */
.equ            MH_IPR39        ,     (0x40D000CC)        /* Interrupt Priority registers for priorities 39                                        */
.equ            MH_IPR40        ,     (0x40D000D0)        /* Interrupt Priority registers for priorities 40                                        */
.equ            MH_IPR41        ,     (0x40D000D4)        /* Interrupt Priority registers for priorities 41                                        */
.equ            MH_IPR42        ,     (0x40D000D8)        /* Interrupt Priority registers for priorities 42                                        */
.equ            MH_IPR43        ,     (0x40D000DC)        /* Interrupt Priority registers for priorities 43                                        */
.equ            MH_IPR44        ,     (0x40D000E0)        /* Interrupt Priority registers for priorities 44                                        */
.equ            MH_IPR45        ,     (0x40D000E4)        /* Interrupt Priority registers for priorities 45                                        */
.equ            MH_IPR46        ,     (0x40D000E8)        /* Interrupt Priority registers for priorities 46                                        */
.equ            MH_IPR47        ,     (0x40D000EC)        /* Interrupt Priority registers for priorities 47                                        */
.equ            MH_IPR48        ,     (0x40D000F0)        /* Interrupt Priority registers for priorities 48                                        */
.equ            MH_IPR49        ,     (0x40D000F4)        /* Interrupt Priority registers for priorities 49                                        */
.equ            MH_IPR50        ,     (0x40D000F8)        /* Interrupt Priority registers for priorities 50                                        */
.equ            MH_IPR51        ,     (0x40D000FC)        /* Interrupt Priority registers for priorities 51                                        */
.equ            MH_IPR52        ,     (0x40D00100)        /* Interrupt Priority registers for priorities 52                                        */

/*
 Real-Time Clock (RTC)
*/
.equ            MH_RCNR         ,     (0x40900000)        /* RTC Counter register                  */
.equ            MH_RTAR         ,     (0x40900004)        /* RTC Alarm register                    */
.equ            MH_RTSR         ,     (0x40900008)        /* RTC Status register                   */
.equ            MH_RTTR         ,     (0x4090000C)        /* RTC Timer Trim register               */
.equ            MH_RDCR         ,     (0x40900010)        /* RTC Day Counter register              */
.equ            MH_RYCR         ,     (0x40900014)        /* RTC Year Counter register             */
.equ            MH_RDAR1        ,     (0x40900018)        /* Wristwatch Day Alarm register 1       */
.equ            MH_RYAR1        ,     (0x4090001C)        /* Wristwatch Year Alarm register 1      */
.equ            MH_RDAR2        ,     (0x40900020)        /* Wristwatch Day Alarm register 2       */
.equ            MH_RYAR2        ,     (0x40900024)        /* Wristwatch Year Alarm register 2      */
.equ            MH_SWCR         ,     (0x40900028)        /* Stopwatch Counter register            */
.equ            MH_SWAR1        ,     (0x4090002C)        /* Stopwatch Alarm register 1            */
.equ            MH_SWAR2        ,     (0x40900030)        /* Stopwatch Alarm register 2            */
.equ            MH_RTCPICR      ,     (0x40900034)        /* Periodic Interrupt Counter register   */
.equ            MH_PIAR         ,     (0x40900038)        /* Periodic Interrupt Alarm register     */

/*
 Operating System Timers
*/
.equ            MH_OSMR0        ,     (0x40A00000)        /* OS Timer Match 0 register                                        */
.equ            MH_OSMR1        ,     (0x40A00004)        /* OS Timer Match 1 register                                        */
.equ            MH_OSMR2        ,     (0x40A00008)        /* OS Timer Match 2 register                                        */
.equ            MH_OSMR3        ,     (0x40A0000C)        /* OS Timer Match 3 register                                        */
.equ            MH_OSCR0        ,     (0x40A00010)        /* OS Timer Counter register 0                                      */
.equ            MH_OSSR         ,     (0x40A00014)        /* OS Timer Status register (used for all counters)                 */
.equ            MH_OWER         ,     (0x40A00018)        /* OS Timer Watchdog Enable register                                */
.equ            MH_OIER         ,     (0x40A0001C)        /* OS Timer Interrupt Enable register (used for all counters)       */
.equ            MH_OSNR         ,     (0x40A00020)        /* OS Timer Snapshot register                                       */
.equ            MH_OSCR4        ,     (0x40A00040)        /* OS Timer Counter register 4                                      */
.equ            MH_OSCR5        ,     (0x40A00044)        /* OS Timer Counter register 5                                      */
.equ            MH_OSCR6        ,     (0x40A00048)        /* OS Timer Counter register 6                                      */
.equ            MH_OSCR7        ,     (0x40A0004C)        /* OS Timer Counter register 7                                      */
.equ            MH_OSCR8        ,     (0x40A00050)        /* OS Timer Counter register 8                                      */
.equ            MH_OSCR9        ,     (0x40A00054)        /* OS Timer Counter register 9                                      */
.equ            MH_OSCR10       ,     (0x40A00058)        /* OS Timer Counter register 10                                     */
.equ            MH_OSCR11       ,     (0x40A0005C)        /* OS Timer Counter register 11                                     */
.equ            MH_OSMR4        ,     (0x40A00080)        /* OS Timer Match register 4                                        */
.equ            MH_OSMR5        ,     (0x40A00084)        /* OS Timer Match register 5                                        */
.equ            MH_OSMR6        ,     (0x40A00088)        /* OS Timer Match register 6                                        */
.equ            MH_OSMR7        ,     (0x40A0008C)        /* OS Timer Match register 7                                        */
.equ            MH_OSMR8        ,     (0x40A00090)        /* OS Timer Match register 8                                        */
.equ            MH_OSMR9        ,     (0x40A00094)        /* OS Timer Match register 9                                        */
.equ            MH_OSMR10       ,     (0x40A00098)        /* OS Timer Match register 10                                       */
.equ            MH_OSMR11       ,     (0x40A0009C)        /* OS Timer Match register 11                                       */
.equ            MH_OMCR4        ,     (0x40A000C0)        /* OS Match Control register 4                                      */
.equ            MH_OMCR5        ,     (0x40A000C4)        /* OS Match Control register 5                                      */
.equ            MH_OMCR6        ,     (0x40A000C8)        /* OS Match Control register 6                                      */
.equ            MH_OMCR7        ,     (0x40A000CC)        /* OS Match Control register 7                                      */
.equ            MH_OMCR8        ,     (0x40A000D0)        /* OS Match Control register 8                                      */
.equ            MH_OMCR9        ,     (0x40A000D4)        /* OS Match Control register 9                                      */
.equ            MH_OMCR10       ,     (0x40A000D8)        /* OS Match Control register 10                                     */
.equ            MH_OMCR11       ,     (0x40A000DC)        /* OS Match Control register 11                                     */

/*
 Performance Monitoring and Debug
*/
.equ            MH_PML_ESEL_0   ,     (0x4600FF00)        /* Event Select registers 0              */
.equ            MH_PML_ESEL_1   ,     (0x4600FF04)        /* Event Select registers 1              */
.equ            MH_PML_ESEL_2   ,     (0x4600FF08)        /* Event Select registers 2              */
.equ            MH_PML_ESEL_3   ,     (0x4600FF0C)        /* Event Select registers 3              */
.equ            MH_PML_ESEL_4   ,     (0x4600FF10)        /* Event Select registers 4              */
.equ            MH_PML_ESEL_5   ,     (0x4600FF14)        /* Event Select registers 5              */
.equ            MH_PML_ESEL_6   ,     (0x4600FF18)        /* Event Select registers 6              */
.equ            MH_PML_ESEL_7   ,     (0x4600FF1C)        /* Event Select registers 7              */
.equ            MH_MDUXSCALEBP  ,     (0x4600FF40)        /* MDU Intel XScale? Snapshot register   */
.equ            MH_MDU2DGEVENT  ,     (0x4600FF54)        /* MDU 2DG Stop register                 */

/*
 System Bus Arbiters
*/
.equ            MH_ARBCNTRL1    ,     (0x4600FE00)        /* system bus #1 Bus Arbiter Control register  */
.equ            MH_ARBCNTRL2    ,     (0x4600FE80)        /* system bus #2 Bus Arbiter Control register  */

/*
 External Memory Controller
*/
.equ            MH_MDCNFG       ,     (0x48100000)        /* SDRAM Configuration register                            */
.equ            MH_MDREFR       ,     (0x48100004)        /* SDRAM Refresh Control register                          */
.equ            MH_MDMRS        ,     (0x48100040)        /* SDRAM Mode Register Set Configuration register          */
.equ            MH_DDRHCAL      ,     (0x48100060)        /* DDR Hardware Calibration register                       */
.equ            MH_DDRWCAL      ,     (0x48100068)        /* DDR Write Strobe Calibration register                   */
.equ            MH_DMCIER       ,     (0x48100070)        /* Dynamic Memory Controller Interrupt Enable register     */
.equ            MH_DMCISR       ,     (0x48100078)        /* Dynamic Memory Controller Interrupt Status register     */
.equ            MH_DDRDLS       ,     (0x48100080)        /* Delay Line Status register                              */
.equ            MH_EMPI         ,     (0x48100090)        /* EMPI Control register                                   */
.equ            MH_RCOMP        ,     (0x48100100)        /* Rcomp Control register                                  */
.equ            MH_PADMA        ,     (0x48100110)        /* PADMA Strength and Slew Settings register               */
.equ            MH_PADMDMSB     ,     (0x48100114)        /* PADMDMSB Strength and Slew Settings register            */
.equ            MH_PADMDLSB     ,     (0x48100118)        /* PADMDLSB Strength and Slew Settings register            */
.equ            MH_PADSDRAM     ,     (0x4810011C)        /* PADSDRAM Strength and Slew Settings register            */
.equ            MH_PADSDCLK     ,     (0x48100120)        /* PADSDCLK Strength and Slew Settings register            */
.equ            MH_PADSDCS      ,     (0x48100124)        /* PADSDCS Strength and Slew Settings register             */
.equ            MH_PADSMEM      ,     (0x48100128)        /* PADSMEM Strength and Slew Settings register             */
.equ            MH_PADSCLK      ,     (0x4810012C)        /* PADSCLK Strength and Slew Settings register             */
.equ            MH_CMA          ,     (0x48100FFC)        /* Controller Miscellaneous Access Register                */

/*
 Static Memory Controller
*/
.equ            MH_MSC0         ,     (0x4A000008)        /* Static Memory Control register 0                                             */
.equ            MH_MSC1         ,     (0x4A00000C)        /* Static Memory Control register 1                                             */
.equ            MH_MECR         ,     (0x4A000014)        /* Expansion Memory (Compact Flash) Configuration register                      */
.equ            MH_SXCNFG       ,     (0x4A00001C)        /* Synchronous Static Memory Control register                                   */
.equ            MH_MCMEM0       ,     (0x4A000028)        /* Expansion Memory Common Memory Space Timing Configuration                    */
.equ            MH_MCATT0       ,     (0x4A000030)        /* Expansion Memory Attribute Space Timing Configuration                        */
.equ            MH_MCIO0        ,     (0x4A000038)        /* Expansion Memory I/O Space Timing Configuration                              */
.equ            MH_MEMCLKCFG    ,     (0x4A000068)        /* Clock Configuration                                                          */
.equ            MH_CSADRCFG0    ,     (0x4A000080)        /* Address Configuration register for Chip Select 0                             */
.equ            MH_CSADRCFG1    ,     (0x4A000084)        /* Address Configuration register for Chip Select 1                             */
.equ            MH_CSADRCFG2    ,     (0x4A000088)        /* Address Configuration register for Chip Select 2                             */
.equ            MH_CSADRCFG3    ,     (0x4A00008C)        /* Address Configuration register for Chip Select 3                             */
.equ            MH_CSADRCFGP    ,     (0x4A000090)        /* Address Configuration register for PC Card Interface                         */
.equ            MH_CSMSADRCFG   ,     (0x4A0000A0)        /* CS and EMPI Bus Mode Configuration register                                  */
.equ            MH_CLKRETDEL    ,     (0x4A0000B0)        /* Delay line and mux selects for return data latching for synchronous flash    */
.equ            MH_ADVRETDEL    ,     (0x4A0000B4)        /* Delay line and mux selects for return data latching for synchronous flash    */

/*
 Data Flash Controller Register Summary
*/
.equ            MH_NDCR         ,     (0x43100000)        /* Data Flash Control register                                         */
.equ            MH_NDTR0CS0     ,     (0x43100004)        /* Data Controller Timing Parameter 0 register for NDnCS0              */
.equ            MH_NDTR1CS0     ,     (0x4310000C)        /* Data Controller Timing Parameter 1 register for NDnCS0              */
.equ            MH_NDSR         ,     (0x43100014)        /* Data Controller Status register                                     */
.equ            MH_NDPCR        ,     (0x43100018)        /* Data Controller Page Count register                                 */
.equ            MH_NDBDR0       ,     (0x4310001C)        /* Data Controller Bad Block register 0                                */
.equ            MH_NDBDR1       ,     (0x43100020)        /* Data Controller Bad Block register 1                                */
.equ            MH_NDDB         ,     (0x43100040)        /* Data Controller Data Buffer                                         */
.equ            MH_NDCB0        ,     (0x43100048)        /* Data Controller Command Buffer 0                                    */
.equ            MH_NDCB1        ,     (0x4310004C)        /* Data Controller Command Buffer 1                                    */
.equ            MH_NDCB2        ,     (0x43100050)        /* Data Controller Command Buffer 2                                    */

/*
 Internal Memory Address Map
*/
.equ            MH_IMPMCR       ,     (0x58000000)        /* IM Power Management Control register */

/*
 MMC/SD/SDIO Controller Register Summary
*/
.equ            MH_MMCSTRPCL1   ,     (0x41100000)        /* Control to start and stop MMC/SD/SDIO clock                  */
.equ            MH_MMCSTAT1     ,     (0x41100004)        /* MMC/SD/SDIO status register (read only)                      */
.equ            MH_MMCCLKRT1    ,     (0x41100008)        /* MMC/SD/SDIO clock rate                                       */
.equ            MH_MMCSPI1      ,     (0x4110000c)        /* SPI mode control bits                                        */
.equ            MH_MMCCMDAT1    ,     (0x41100010)        /* Command/response/data sequence control                       */
.equ            MH_MMCRESTO1    ,     (0x41100014)        /* Expected response time out                                   */
.equ            MH_MMCRDTO1     ,     (0x41100018)        /* Expected data read time out                                  */
.equ            MH_MMCBLKLEN1   ,     (0x4110001c)        /* Block length of data transaction                             */
.equ            MH_MMCNUMBLK1   ,     (0x41100020)        /* Number of blocks, for block mode                             */
.equ            MH_MMCPRTBUF1   ,     (0x41100024)        /* Partial MMCTXFIFO FIFO written                               */
.equ            MH_MMCIMASK1    ,     (0x41100028)        /* Interrupt Mask                                               */
.equ            MH_MMCIREG1     ,     (0x4110002c)        /* Interrupt Register (read only)                               */
.equ            MH_MMCCMD1      ,     (0x41100030)        /* Index of current command                                     */
.equ            MH_MMCARGH1     ,     (0x41100034)        /* MSW part of the current command argument                     */
.equ            MH_MMCARGL1     ,     (0x41100038)        /* LSW part of the current command argument                     */
.equ            MH_MMCRES1      ,     (0x4110003c)        /* Response FIFO (read only)                                    */
.equ            MH_MMCRXFIFO1   ,     (0x41100040)        /* Receive FIFO (read only)                                     */
.equ            MH_MMCTXFIFO1   ,     (0x41100044)        /* Transmit FIFO (write only)                                   */
.equ            MH_MMCRDWAIT1   ,     (0x41100048)        /* SDIO RDWAIT, stall read data transfer                        */
.equ            MH_MMCBLKSREM1  ,     (0x4110004C)        /* Blocks Remaining                                             */
.equ            MH_MMCSTRPCL2   ,     (0x42000000)        /* Control to start and stop MMC/SD/SDIO clock                  */
.equ            MH_MMCSTAT2     ,     (0x42000004)        /* MMC/SD/SDIO status register (read only)                      */
.equ            MH_MMCCLKRT2    ,     (0x42000008)        /* MMC/SD/SDIO clock rate                                       */
.equ            MH_MMCSPI2      ,     (0x4200000c)        /* SPI mode control bits                                        */
.equ            MH_MMCCMDAT2    ,     (0x42000010)        /* Command/response/data sequence control                       */
.equ            MH_MMCRESTO2    ,     (0x42000014)        /* Expected response time out                                   */
.equ            MH_MMCRDTO2     ,     (0x42000018)        /* Expected data read time out                                  */
.equ            MH_MMCBLKLEN2   ,     (0x4200001c)        /* Block length of data transaction                             */
.equ            MH_MMCNUMBLK2   ,     (0x42000020)        /* Number of blocks, for block mode                             */
.equ            MH_MMCPRTBUF2   ,     (0x42000024)        /* Partial MMCTXFIFO FIFO written                               */
.equ            MH_MMCIMASK2    ,     (0x42000028)        /* Interrupt Mask                                               */
.equ            MH_MMCIREG2     ,     (0x4200002c)        /* Interrupt Register (read only)                               */
.equ            MH_MMCCMD2      ,     (0x42000030)        /* Index of current command                                     */
.equ            MH_MMCARGH2     ,     (0x42000034)        /* MSW part of the current command argument                     */
.equ            MH_MMCARGL2     ,     (0x42000038)        /* LSW part of the current command argument                     */
.equ            MH_MMCRES2      ,     (0x4200003c)        /* Response FIFO (read only)                                    */
.equ            MH_MMCRXFIFO2   ,     (0x42000040)        /* Receive FIFO (read only)                                     */
.equ            MH_MMCTXFIFO2   ,     (0x42000044)        /* Transmit FIFO (write only)                                   */
.equ            MH_MMCRDWAIT2   ,     (0x42000048)        /* SDIO RDWAIT, stall read data transfer                        */
.equ            MH_MMCBLKSREM2  ,     (0x4200004C)        /* Blocks Remaining                                             */

/*
 LCD Controller Register Summary
*/
.equ            MH_LCCR0        ,     (0x44000000)        /* LCD Controller Control register 0           */
.equ            MH_LCCR1        ,     (0x44000004)        /* LCD Controller Control register 1           */
.equ            MH_LCCR2        ,     (0x44000008)        /* LCD Controller Control register 2           */
.equ            MH_LCCR3        ,     (0x4400000C)        /* LCD Controller Control register 3           */
.equ            MH_LCCR4        ,     (0x44000010)        /* LCD Controller Control register 4           */
.equ            MH_LCCR5        ,     (0x44000014)        /* LCD Controller Control register 5           */
.equ            MH_LCCR6        ,     (0x44000018)        /* LCD Controller Control register 6           */

.equ            MH_FBR0         ,     (0x44000020)        /* DMA Channel 0 Frame Branch register                          */
.equ            MH_FBR1         ,     (0x44000024)        /* DMA Channel 1 Frame Branch register                          */
.equ            MH_FBR2         ,     (0x44000028)        /* DMA Channel 2 Frame Branch register                          */
.equ            MH_FBR3         ,     (0x4400002C)        /* DMA Channel 3 Frame Branch register                          */
.equ            MH_FBR4         ,     (0x44000030)        /* DMA Channel 4 Frame Branch register                          */
.equ            MH_LCSR1        ,     (0x44000034)        /* LCD Controller Status register 1                             */
.equ            MH_LCSR0        ,     (0x44000038)        /* LCD Controller Status register 0                             */
.equ            MH_LIIDR        ,     (0x4400003C)        /* LCD Controller Interrupt ID register                         */
.equ            MH_TRGBR        ,     (0x44000040)        /* TMED RGB Seed register                                       */
.equ            MH_TCR          ,     (0x44000044)        /* TMED Control register                                        */
.equ            MH_OVL1C1       ,     (0x44000050)        /* Overlay 1 Control register 1                                 */
.equ            MH_OVL1C2       ,     (0x44000060)        /* Overlay 1 Control register 2                                 */
.equ            MH_OVL2C1       ,     (0x44000070)        /* Overlay 2 Control register 1                                 */
.equ            MH_OVL2C2       ,     (0x44000080)        /* Overlay 2 Control register 2                                 */
.equ            MH_CCR          ,     (0x44000090)        /* Cursor Control register                                      */
.equ            MH_CMDCR        ,     (0x44000100)        /* Command Control register                                     */
.equ            MH_PRSR         ,     (0x44000104)        /* Panel Read Status register                                   */
.equ            MH_FBR5         ,     (0x44000110)        /* DMA Channel 5 Frame Branch register                          */
.equ            MH_FBR6         ,     (0x44000114)        /* DMA Channel 6 Frame Branch register                          */
.equ            MH_FDADR0       ,     (0x44000200)        /* DMA Channel 0 Frame Descriptor Address register              */
.equ            MH_FSADR0       ,     (0x44000204)        /* DMA Channel 0 Frame Source Address register                  */
.equ            MH_FIDR0        ,     (0x44000208)        /* DMA Channel 0 Frame ID register                              */
.equ            MH_LDCMD0       ,     (0x4400020C)        /* LCD DMA Channel 0 Command register                           */
.equ            MH_FDADR1       ,     (0x44000210)        /* DMA Channel 1 Frame Descriptor Address register              */
.equ            MH_FSADR1       ,     (0x44000214)        /* DMA Channel 1 Frame Source Address register                  */
.equ            MH_FIDR1        ,     (0x44000218)        /* DMA Channel 1 Frame ID register                              */
.equ            MH_LDCMD1       ,     (0x4400021C)        /* LCD DMA Channel 1 Command register                           */
.equ            MH_FDADR2       ,     (0x44000220)        /* DMA Channel 2 Frame Descriptor Address register              */
.equ            MH_FSADR2       ,     (0x44000224)        /* DMA Channel 2 Frame Source Address register                  */
.equ            MH_FIDR2        ,     (0x44000228)        /* DMA Channel 2 Frame ID register                              */
.equ            MH_LDCMD2       ,     (0x4400022C)        /* LCD DMA Channel 2 Command register                           */
.equ            MH_FDADR3       ,     (0x44000230)        /* DMA Channel 3 Frame Descriptor Address register              */
.equ            MH_FSADR3       ,     (0x44000234)        /* DMA Channel 3 Frame Source Address register                  */
.equ            MH_FIDR3        ,     (0x44000238)        /* DMA Channel 3 Frame ID register                              */
.equ            MH_LDCMD3       ,     (0x4400023C)        /* LCD DMA Channel 3 Command register                           */
.equ            MH_FDADR4       ,     (0x44000240)        /* DMA Channel 4 Frame Descriptor Address register              */
.equ            MH_FSADR4       ,     (0x44000244)        /* DMA Channel 4 Frame Source Address register                  */
.equ            MH_FIDR4        ,     (0x44000248)        /* DMA Channel 4 Frame ID register                              */
.equ            MH_LDCMD4       ,     (0x4400024C)        /* LCD DMA Channel 4 Command register                           */
.equ            MH_FDADR5       ,     (0x44000250)        /* DMA Channel 5 Frame Descriptor Address register              */
.equ            MH_FSADR5       ,     (0x44000254)        /* DMA Channel 5 Frame Source Address register                  */
.equ            MH_FIDR5        ,     (0x44000258)        /* DMA Channel 5 Frame ID register                              */
.equ            MH_LDCMD5       ,     (0x4400025C)        /* LCD DMA Channel 5 Command register                           */
.equ            MH_FDADR6       ,     (0x44000260)        /* DMA Channel 6 Frame Descriptor Address register              */
.equ            MH_FSADR6       ,     (0x44000264)        /* DMA Channel 6 Frame Source Address register                  */
.equ            MH_FIDR6        ,     (0x44000268)        /* DMA Channel 6 Frame ID register                              */
.equ            MH_LDCMD6       ,     (0x4400026C)        /* LCD DMA Channel 6 Command register                           */

.equ            MH_LCDBSCNTR    ,     (0x48000054)        /* LCD Buffer Strength Control register */

/*
  Mini-LCD Controller Register Summary
*/
.equ            MH_MLCCR0       ,     (0x46000000)        /* Mini-LCD Controller Control register 0  */
.equ            MH_MLCCR1       ,     (0x46000004)        /* Mini-LCD Controller Control register 1  */
.equ            MH_MLCCR2       ,     (0x46000008)        /* Mini-LCD Controller Control register 2  */
.equ            MH_MLSADD       ,     (0x4600000C)        /* Mini-LCD SRAM Address register          */
.equ            MH_MLFRMCNT     ,     (0x46000010)        /* Mini-LCD Frame Count register           */

/*
  Quick Capture Interface Register Summary
*/
.equ            MH_CICR0        ,     (0x50000000)        /* Quick Capture Interface Control register 0                            */
.equ            MH_CICR1        ,     (0x50000004)        /* Quick Capture Interface Control register 1                            */
.equ            MH_CICR2        ,     (0x50000008)        /* Quick Capture Interface Control register 2                            */
.equ            MH_CICR3        ,     (0x5000000C)        /* Quick Capture Interface Control register 3                            */
.equ            MH_CICR4        ,     (0x50000010)        /* Quick Capture Interface Control register 4                            */
.equ            MH_CISR         ,     (0x50000014)        /* Quick Capture Interface Status register                               */
.equ            MH_CITOR        ,     (0x5000001C)        /* Quick Capture Interface Time-Out register                             */
.equ            MH_CIBR0        ,     (0x50000028)        /* Quick Capture Interface Channel 0 Receive Buffer                      */
.equ            MH_CIBR1        ,     (0x50000030)        /* Quick Capture Interface Channel 1 Receive Buffer                      */
.equ            MH_CIBR2        ,     (0x50000038)        /* Quick Capture Interface Channel 2 Receive Buffer                      */
.equ            MH_CIBR3        ,     (0x50000040)        /* Quick Capture Interface Channel 3 Receive Buffer                      */
.equ            MH_CIPSS        ,     (0x50000064)        /* Quick Capture Interface Pixel Substitution Status register            */
.equ            MH_CIPBUF       ,     (0x50000068)        /* Quick Capture Interface Pixel Substitution Buffer                     */
.equ            MH_CIHST        ,     (0x5000006C)        /* Quick Capture Interface Histogram Configuration                       */
.equ            MH_CISUM        ,     (0x50000070)        /* Quick Capture Interface Histogram Summation register                  */
.equ            MH_CICCR        ,     (0x50000074)        /* Quick Capture Interface Compander Configuration                       */
.equ            MH_CISSC        ,     (0x5000007C)        /* Quick Capture Interface Spatial Scaling Configuration                 */
.equ            MH_CICMR        ,     (0x50000090)        /* Quick Capture Interface Color Management register                     */
.equ            MH_CICMC0       ,     (0x50000094)        /* Quick Capture Interface Color Management Coefficients 0               */
.equ            MH_CICMC1       ,     (0x50000098)        /* Quick Capture Interface Color Management Coefficients 1               */
.equ            MH_CICMC2       ,     (0x5000009C)        /* Quick Capture Interface Color Management Coefficients 2               */
.equ            MH_CIFR0        ,     (0x500000B0)        /* Quick Capture Interface FIFO Control register 0                       */
.equ            MH_CIFR1        ,     (0x500000B4)        /* Quick Capture Interface FIFO Control register 1                       */
.equ            MH_CIFSR        ,     (0x500000C0)        /* Quick Capture Interface FIFO Status register                          */
.equ            MH_CIDADR0      ,     (0x50000240)        /* Quick Capture Interface DMA Descriptor Address Channel 0 register     */
.equ            MH_CIDADR1      ,     (0x50000250)        /* Quick Capture Interface DMA Descriptor Address Channel 1 register     */
.equ            MH_CIDADR2      ,     (0x50000260)        /* Quick Capture Interface DMA Descriptor Address Channel 2 register     */
.equ            MH_CIDADR3      ,     (0x50000270)        /* Quick Capture Interface DMA Descriptor Address Channel 3 register     */
.equ            MH_CISADR0      ,     (0x50000244)        /* Quick Capture Interface DMA Source Address Channel 0 register         */
.equ            MH_CISADR1      ,     (0x50000254)        /* Quick Capture Interface DMA Source Address Channel 1 register         */
.equ            MH_CISADR2      ,     (0x50000264)        /* Quick Capture Interface DMA Source Address Channel 2 register         */
.equ            MH_CISADR3      ,     (0x50000274)        /* Quick Capture Interface DMA Source Address Channel 3 register         */
.equ            MH_CITADR0      ,     (0x50000248)        /* Quick Capture Interface DMA Target Address Channel 0 register         */
.equ            MH_CITADR1      ,     (0x50000258)        /* Quick Capture Interface DMA Target Address Channel 1 register         */
.equ            MH_CITADR2      ,     (0x50000268)        /* Quick Capture Interface DMA Target Address Channel 2 register         */
.equ            MH_CITADR3      ,     (0x50000278)        /* Quick Capture Interface DMA Target Address Channel 3 register         */
.equ            MH_CICMD0       ,     (0x5000024C)        /* Quick Capture Interface DMA Command Channel 0 register                */
.equ            MH_CICMD1       ,     (0x5000025C)        /* Quick Capture Interface DMA Command Channel 1 register                */
.equ            MH_CICMD2       ,     (0x5000026C)        /* Quick Capture Interface DMA Command Channel 2 register                */
.equ            MH_CICMD3       ,     (0x5000027C)        /* Quick Capture Interface DMA Command Channel 3 register                */
.equ            MH_CIDBR0       ,     (0x50000220)        /* Quick Capture Interface DMA Branch Channel 0 register                 */
.equ            MH_CIDBR1       ,     (0x50000224)        /* Quick Capture Interface DMA Branch Channel 1 register                 */
.equ            MH_CIDBR2       ,     (0x50000228)        /* Quick Capture Interface DMA Branch Channel 2 register                 */
.equ            MH_CIDBR3       ,     (0x5000022C)        /* Quick Capture Interface DMA Branch Channel 3 register                 */
.equ            MH_CIDCSR0      ,     (0x50000200)        /* Quick Capture Interface DMA Controller/Status Channel 0 register      */
.equ            MH_CIDCSR1      ,     (0x50000204)        /* Quick Capture Interface DMA Controller/Status Channel 1 register      */
.equ            MH_CIDCSR2      ,     (0x50000208)        /* Quick Capture Interface DMA Controller/Status Channel 2 register      */
.equ            MH_CIDCSR3      ,     (0x5000020C)        /* Quick Capture Interface DMA Controller/Status Channel 3 register      */

/*
  Keypad Controller Register Summary
*/
.equ            MH_KPC          ,     (0x41500000)        /* Keypad Control register                                    */
.equ            MH_KPDK         ,     (0x41500008)        /* Keypad Direct Key register                                 */
.equ            MH_KPREC        ,     (0x41500010)        /* Keypad Rotary Encoder Count register                       */
.equ            MH_KPMK         ,     (0x41500018)        /* Keypad Matrix Key register                                 */
.equ            MH_KPAS         ,     (0x41500020)        /* Keypad Automatic Scan register                             */
.equ            MH_KPASMKP0     ,     (0x41500028)        /* Keypad Automatic Scan Multiple keypress register 0         */
.equ            MH_KPASMKP1     ,     (0x41500030)        /* Keypad Automatic Scan Multiple keypress register 1         */
.equ            MH_KPASMKP2     ,     (0x41500038)        /* Keypad Automatic Scan Multiple keypress register 2         */
.equ            MH_KPASMKP3     ,     (0x41500040)        /* Keypad Automatic Scan Multiple keypress register 3         */
.equ            MH_KPKDI        ,     (0x41500048)        /* Keypad Key Debounce Interval register                      */

/*
  ADC and Touch Screen Interface Register Summary
*/
.equ            MH_ADCD         ,     (0x41C00000)        /* Analog-to-Digital Converter Data register        */
.equ            MH_ADCS         ,     (0x41C00004)        /* Analog-to-Digital Converter Setup register       */
.equ            MH_ADCE         ,     (0x41C00008)        /* Analog-to-Digital Converter Enable register      */
.equ            MH_ADCP         ,     (0x41C0000C)        /* Analog-to-Digital Converter Pressure register    */

/*
  UDC Register Summary
*/
.equ            MH_UDCCR        ,     (0x40600000)        /* UDC Control register                                       */
.equ            MH_UDCICR0      ,     (0x40600004)        /* UDC Interrupt Control register 0                           */
.equ            MH_UDCCIR1      ,     (0x40600008)        /* UDC Interrupt Control register 1                           */
.equ            MH_UDCISR0      ,     (0x4060000C)        /* UDC Interrupt Status register 0                            */
.equ            MH_UDCSIR1      ,     (0x40600010)        /* UDC Interrupt Status register 1                            */
.equ            MH_UDCFNR       ,     (0x40600014)        /* UDC Frame Number register                                  */
.equ            MH_UDCOTGICR    ,     (0x40600018)        /* UDC OTG Interrupt Control register                         */
.equ            MH_UDCOTGISR    ,     (0x4060001C)        /* UDC OTG Interrupt Status register                          */
.equ            MH_UP2OCR       ,     (0x40600020)        /* USB Port 2 Output Control register                         */
.equ            MH_UP3OCR       ,     (0x40600024)        /* USB Port 3 Output Control register                         */
.equ            MH_UDCCSR0      ,     (0x40600100)        /* UDC Control/Status register - Endpoint 0                   */
.equ            MH_UDCCSRA      ,     (0x40600104)        /* UDC Control/Status register - Endpoint A                   */
.equ            MH_UDCCSRB      ,     (0x40600108)        /* UDC Control/Status register - Endpoint B                   */
.equ            MH_UDCCSRC      ,     (0x4060010C)        /* UDC Control/Status register - Endpoint C                   */
.equ            MH_UDCCSRD      ,     (0x40600110)        /* UDC Control/Status register - Endpoint D                   */
.equ            MH_UDCCSRE      ,     (0x40600114)        /* UDC Control/Status register - Endpoint E                   */
.equ            MH_UDCCSRF      ,     (0x40600118)        /* UDC Control/Status register - Endpoint F                   */
.equ            MH_UDCCSRG      ,     (0x4060011C)        /* UDC Control/Status register - Endpoint G                   */
.equ            MH_UDCCSRH      ,     (0x40600120)        /* UDC Control/Status register - Endpoint H                   */
.equ            MH_UDCCSRI      ,     (0x40600124)        /* UDC Control/Status register - Endpoint I                   */
.equ            MH_UDCCSRJ      ,     (0x40600128)        /* UDC Control/Status register - Endpoint J                   */
.equ            MH_UDCCSRK      ,     (0x4060012C)        /* UDC Control/Status register - Endpoint K                   */
.equ            MH_UDCCSRL      ,     (0x40600130)        /* UDC Control/Status register - Endpoint L                   */
.equ            MH_UDCCSRM      ,     (0x40600134)        /* UDC Control/Status register - Endpoint M                   */
.equ            MH_UDCCSRN      ,     (0x40600138)        /* UDC Control/Status register - Endpoint N                   */
.equ            MH_UDCCSRP      ,     (0x4060013C)        /* UDC Control/Status register - Endpoint P                   */
.equ            MH_UDCCSRQ      ,     (0x40600140)        /* UDC Control/Status register - Endpoint Q                   */
.equ            MH_UDCCSRR      ,     (0x40600144)        /* UDC Control/Status register - Endpoint R                   */
.equ            MH_UDCCSRS      ,     (0x40600148)        /* UDC Control/Status register - Endpoint S                   */
.equ            MH_UDCCSRT      ,     (0x4060014C)        /* UDC Control/Status register - Endpoint T                   */
.equ            MH_UDCCSRU      ,     (0x40600150)        /* UDC Control/Status register - Endpoint U                   */
.equ            MH_UDCCSRV      ,     (0x40600154)        /* UDC Control/Status register - Endpoint V                   */
.equ            MH_UDCCSRW      ,     (0x40600158)        /* UDC Control/Status register - Endpoint W                   */
.equ            MH_UDCCSRX      ,     (0x4060015C)        /* UDC Control/Status register - Endpoint X                   */
.equ            MH_UDCBCR0      ,     (0x40600200)        /* UDC Byte Count register - Endpoint 0                       */
.equ            MH_UDCBCRA      ,     (0x40600204)        /* UDC Byte Count register - Endpoint A                       */
.equ            MH_UDCBCRB      ,     (0x40600208)        /* UDC Byte Count register - Endpoint B                       */
.equ            MH_UDCBCRC      ,     (0x4060020C)        /* UDC Byte Count register - Endpoint C                       */
.equ            MH_UDCBCRD      ,     (0x40600210)        /* UDC Byte Count register - Endpoint D                       */
.equ            MH_UDCBCRE      ,     (0x40600214)        /* UDC Byte Count register - Endpoint E                       */
.equ            MH_UDCBCRF      ,     (0x40600218)        /* UDC Byte Count register - Endpoint F                       */
.equ            MH_UDCBCRG      ,     (0x4060021C)        /* UDC Byte Count register - Endpoint G                       */
.equ            MH_UDCBCRH      ,     (0x40600220)        /* UDC Byte Count register - Endpoint H                       */
.equ            MH_UDCBCRI      ,     (0x40600224)        /* UDC Byte Count register - Endpoint I                       */
.equ            MH_UDCBCRJ      ,     (0x40600228)        /* UDC Byte Count register - Endpoint J                       */
.equ            MH_UDCBCRK      ,     (0x4060022C)        /* UDC Byte Count register - Endpoint K                       */
.equ            MH_UDCBCRL      ,     (0x40600230)        /* UDC Byte Count register - Endpoint L                       */
.equ            MH_UDCBCRM      ,     (0x40600234)        /* UDC Byte Count register - Endpoint M                       */
.equ            MH_UDCBCRN      ,     (0x40600238)        /* UDC Byte Count register - Endpoint N                       */
.equ            MH_UDCBCRP      ,     (0x4060023C)        /* UDC Byte Count register - Endpoint P                       */
.equ            MH_UDCBCRQ      ,     (0x40600240)        /* UDC Byte Count register - Endpoint Q                       */
.equ            MH_UDCBCRR      ,     (0x40600244)        /* UDC Byte Count register - Endpoint R                       */
.equ            MH_UDCBCRS      ,     (0x40600248)        /* UDC Byte Count register - Endpoint S                       */
.equ            MH_UDCBCRT      ,     (0x4060024C)        /* UDC Byte Count register - Endpoint T                       */
.equ            MH_UDCBCRU      ,     (0x40600250)        /* UDC Byte Count register - Endpoint U                       */
.equ            MH_UDCBCRV      ,     (0x40600254)        /* UDC Byte Count register - Endpoint V                       */
.equ            MH_UDCBCRW      ,     (0x40600258)        /* UDC Byte Count register - Endpoint W                       */
.equ            MH_UDCBCRX      ,     (0x4060025C)        /* UDC Byte Count register - Endpoint X                       */
.equ            MH_UDCDR0       ,     (0x40600300)        /* UDC Data register - Endpoint 0                             */
.equ            MH_UDCDRA       ,     (0x40600304)        /* UDC Data register - Endpoint A                             */
.equ            MH_UDCDRB       ,     (0x40600308)        /* UDC Data register - Endpoint B                             */
.equ            MH_UDCDRC       ,     (0x4060030C)        /* UDC Data register - Endpoint C                             */
.equ            MH_UDCDRD       ,     (0x40600310)        /* UDC Data register - Endpoint D                             */
.equ            MH_UDCDRE       ,     (0x40600314)        /* UDC Data register - Endpoint E                             */
.equ            MH_UDCDRF       ,     (0x40600318)        /* UDC Data register - Endpoint F                             */
.equ            MH_UDCDRG       ,     (0x4060031C)        /* UDC Data register - Endpoint G                             */
.equ            MH_UDCDRH       ,     (0x40600320)        /* UDC Data register - Endpoint H                             */
.equ            MH_UDCDRI       ,     (0x40600324)        /* UDC Data register - Endpoint I                             */
.equ            MH_UDCDRJ       ,     (0x40600328)        /* UDC Data register - Endpoint J                             */
.equ            MH_UDCDRK       ,     (0x4060032C)        /* UDC Data register - Endpoint K                             */
.equ            MH_UDCDRL       ,     (0x40600330)        /* UDC Data register - Endpoint L                             */
.equ            MH_UDCDRM       ,     (0x40600334)        /* UDC Data register - Endpoint M                             */
.equ            MH_UDCDRN       ,     (0x40600338)        /* UDC Data register - Endpoint N                             */
.equ            MH_UDCDRP       ,     (0x4060033C)        /* UDC Data register - Endpoint P                             */
.equ            MH_UDCDRQ       ,     (0x40600340)        /* UDC Data register - Endpoint Q                             */
.equ            MH_UDCDRR       ,     (0x40600344)        /* UDC Data register - Endpoint R                             */
.equ            MH_UDCDRS       ,     (0x40600348)        /* UDC Data register - Endpoint S                             */
.equ            MH_UDCDRT       ,     (0x4060034C)        /* UDC Data register - Endpoint T                             */
.equ            MH_UDCDRU       ,     (0x40600350)        /* UDC Data register - Endpoint U                             */
.equ            MH_UDCDRV       ,     (0x40600354)        /* UDC Data register - Endpoint V                             */
.equ            MH_UDCDRW       ,     (0x40600358)        /* UDC Data register - Endpoint W                             */
.equ            MH_UDCDRX       ,     (0x4060035C)        /* UDC Data register - Endpoint X                             */
.equ            MH_UDCCRA       ,     (0x40600404)        /* UDC Configuration register - Endpoint A                    */
.equ            MH_UDCCRB       ,     (0x40600408)        /* UDC Configuration register - Endpoint B                    */
.equ            MH_UDCCRC       ,     (0x4060040C)        /* UDC Configuration register - Endpoint C                    */
.equ            MH_UDCCRD       ,     (0x40600410)        /* UDC Configuration register - Endpoint D                    */
.equ            MH_UDCCRE       ,     (0x40600414)        /* UDC Configuration register - Endpoint E                    */
.equ            MH_UDCCRF       ,     (0x40600418)        /* UDC Configuration register - Endpoint F                    */
.equ            MH_UDCCRG       ,     (0x4060041C)        /* UDC Configuration register - Endpoint G                    */
.equ            MH_UDCCRH       ,     (0x40600420)        /* UDC Configuration register - Endpoint H                    */
.equ            MH_UDCCRI       ,     (0x40600424)        /* UDC Configuration register - Endpoint I                    */
.equ            MH_UDCCRJ       ,     (0x40600428)        /* UDC Configuration register - Endpoint J                    */
.equ            MH_UDCCRK       ,     (0x4060042C)        /* UDC Configuration register - Endpoint K                    */
.equ            MH_UDCCRL       ,     (0x40600430)        /* UDC Configuration register - Endpoint L                    */
.equ            MH_UDCCRM       ,     (0x40600434)        /* UDC Configuration register - Endpoint M                    */
.equ            MH_UDCCRN       ,     (0x40600438)        /* UDC Configuration register - Endpoint N                    */
.equ            MH_UDCCRP       ,     (0x4060043C)        /* UDC Configuration register - Endpoint P                    */
.equ            MH_UDCCRQ       ,     (0x40600440)        /* UDC Configuration register - Endpoint Q                    */
.equ            MH_UDCCRR       ,     (0x40600444)        /* UDC Configuration register - Endpoint R                    */
.equ            MH_UDCCRS       ,     (0x40600448)        /* UDC Configuration register - Endpoint S                    */
.equ            MH_UDCCRT       ,     (0x4060044C)        /* UDC Configuration register - Endpoint T                    */
.equ            MH_UDCCRU       ,     (0x40600450)        /* UDC Configuration register - Endpoint U                    */
.equ            MH_UDCCRV       ,     (0x40600454)        /* UDC Configuration register - Endpoint V                    */
.equ            MH_UDCCRW       ,     (0x40600458)        /* UDC Configuration register - Endpoint W                    */
.equ            MH_UDCCRX       ,     (0x4060045C)        /* UDC Configuration register - Endpoint X                    */

/*
  USB Host controller Register Addresses
*/
.equ            MH_UHCREV       ,     (0x4C000000)        /* UHC HCI Spec Revision                                      */
.equ            MH_UHCHCON      ,     (0x4C000004)        /* UHC Host Control register                                  */
.equ            MH_UHCCOMS      ,     (0x4C000008)        /* UHC Command Status                                         */
.equ            MH_UHCINTS      ,     (0x4C00000C)        /* UHC Interrupt Status                                       */
.equ            MH_UHCINTE      ,     (0x4C000010)        /* UHC Interrupt Enable register                              */
.equ            MH_UHCINTD      ,     (0x4C000014)        /* UHC Interrupt Disable register                             */
.equ            MH_UHCHCCA      ,     (0x4C000018)        /* UHC Host Controller Communication Area                     */
.equ            MH_UHCPCED      ,     (0x4C00001C)        /* UHC Period Current Endpoint Descriptor                     */
.equ            MH_UHCCHED      ,     (0x4C000020)        /* UHC Control Head Endpoint Descriptor register              */
.equ            MH_UHCCCED      ,     (0x4C000024)        /* UHC Control Current Endpoint Descriptor register           */
.equ            MH_UHCBHED      ,     (0x4C000028)        /* UHC Bulk Head Endpoint Descriptor register                 */
.equ            MH_UHCBCED      ,     (0x4C00002C)        /* UHC Bulk Current Endpoint Descriptor register              */
.equ            MH_UHCDHEAD     ,     (0x4C000030)        /* UHC Done Head register                                     */
.equ            MH_UHCFMI       ,     (0x4C000034)        /* UHC Frame Interval register                                */
.equ            MH_UHCFMR       ,     (0x4C000038)        /* UHC Frame Remaining register                               */
.equ            MH_UHCFMN       ,     (0x4C00003C)        /* UHC Frame Number register                                  */
.equ            MH_UHCPERS      ,     (0x4C000040)        /* UHC Periodic Start register                                */
.equ            MH_UHCLST       ,     (0x4C000044)        /* UHC Low-Speed Threshold register                           */
.equ            MH_UHCRHDA      ,     (0x4C000048)        /* UHC Root Hub Descriptor A register                         */
.equ            MH_UHCRHDB      ,     (0x4C00004C)        /* UHC Root Hub Descriptor B register                         */
.equ            MH_UHCRHS       ,     (0x4C000050)        /* UHC Root Hub Status register                               */
.equ            MH_UHCRHPS1     ,     (0x4C000054)        /* UHC Root Hub Port 1 Status register                        */
.equ            MH_UHCRHPS2     ,     (0x4C000058)        /* UHC Root Hub Port 2 Status register                        */
.equ            MH_UHCRHPS3     ,     (0x4C00005C)        /* UHC Root Hub Port 3 Status register                        */
.equ            MH_UHCSTAT      ,     (0x4C000060)        /* UHC Status register                                        */
.equ            MH_UHCHR        ,     (0x4C000064)        /* UHC Reset register                                         */
.equ            MH_UHCHIE       ,     (0x4C000068)        /* UHC Interrupt Enable register                              */
.equ            MH_UHCHIT       ,     (0x4C00006C)        /* UHC Interrupt Test register                                */

/*
 MSL Interface Register Summary
*/
.equ            MH_BBFIFO1      ,     (0x41400004)        /* Channel 1 Receive/Transmit FIFO register                   */
.equ            MH_BBFIFO2      ,     (0x41400008)        /* Channel 2 Receive/Transmit FIFO register                   */
.equ            MH_BBFIFO3      ,     (0x4140000C)        /* Channel 3 Receive/Transmit FIFO register                   */
.equ            MH_BBFIFO4      ,     (0x41400010)        /* Channel 4 Receive/Transmit FIFO register                   */
.equ            MH_BBFIFO5      ,     (0x41400014)        /* Channel 5 Receive/Transmit FIFO register                   */
.equ            MH_BBFIFO6      ,     (0x41400018)        /* Channel 6 Receive/Transmit FIFO register                   */
.equ            MH_BBFIFO7      ,     (0x4140001C)        /* Channel 7 Receive/Transmit FIFO register                   */
.equ            MH_BBCFG1       ,     (0x41400044)        /* Channel 1 Configuration register                           */
.equ            MH_BBCFG2       ,     (0x41400048)        /* Channel 2 Configuration register                           */
.equ            MH_BBCFG3       ,     (0x4140004C)        /* Channel 3 Configuration register                           */
.equ            MH_BBCFG4       ,     (0x41400050)        /* Channel 4 Configuration register                           */
.equ            MH_BBCFG5       ,     (0x41400054)        /* Channel 5 Configuration register                           */
.equ            MH_BBCFG6       ,     (0x41400058)        /* Channel 6 Configuration register                           */
.equ            MH_BBCFG7       ,     (0x4140005C)        /* Channel 7 Configuration register                           */
.equ            MH_BBSTAT1      ,     (0x41400084)        /* Channel 1 Status register                                  */
.equ            MH_BBSTAT2      ,     (0x41400088)        /* Channel 2 Status register                                  */
.equ            MH_BBSTAT3      ,     (0x4140008C)        /* Channel 3 Status register                                  */
.equ            MH_BBSTAT4      ,     (0x41400090)        /* Channel 4 Status register                                  */
.equ            MH_BBSTAT5      ,     (0x41400094)        /* Channel 5 Status register                                  */
.equ            MH_BBSTAT6      ,     (0x41400098)        /* Channel 6 Status register                                  */
.equ            MH_BBSTAT7      ,     (0x4140009C)        /* Channel 7 Status register                                  */
.equ            MH_BBEOM1       ,     (0x414000C4)        /* Channel 1 EOM register                                     */
.equ            MH_BBEOM2       ,     (0x414000C8)        /* Channel 2 EOM register                                     */
.equ            MH_BBEOM3       ,     (0x414000CC)        /* Channel 3 EOM register                                     */
.equ            MH_BBEOM4       ,     (0x414000D0)        /* Channel 4 EOM register                                     */
.equ            MH_BBEOM5       ,     (0x414000D4)        /* Channel 5 EOM register                                     */
.equ            MH_BBEOM6       ,     (0x414000D8)        /* Channel 6 EOM register                                     */
.equ            MH_BBEOM7       ,     (0x414000DC)        /* Channel 7 EOM register                                     */
.equ            MH_BBIID        ,     (0x41400108)        /* Interrupt ID register                                      */
.equ            MH_BBFREQ       ,     (0x41400110)        /* TX Frequency Select register                               */
.equ            MH_BBWAIT       ,     (0x41400114)        /* Wait Count register                                        */
.equ            MH_BBCST        ,     (0x41400118)        /* Clock Stop Time register                                   */
.equ            MH_BBVGIL       ,     (0x4140011C)        /* Virtual GPIO Input Pin Level register                      */
.equ            MH_BBVGOL       ,     (0x41400120)        /* Virtual GPIO Output Pin Level register                     */
.equ            MH_BBVGSR       ,     (0x41400124)        /* Virtual GPIO Output Pin Set register                       */
.equ            MH_BBVGCR       ,     (0x41400128)        /* Virtual GPIO Output Pin Clear register                     */
.equ            MH_BBVGRE       ,     (0x4140012C)        /* Virtual GPIO Rising Edge Detect register                   */
.equ            MH_BBVGFE       ,     (0x41400130)        /* Virtual GPIO Falling Edge Detect register                  */
.equ            MH_BBVGED       ,     (0x41400134)        /* Virtual GPIO Edge Detect Status register                   */
.equ            MH_BBVGVI       ,     (0x41400138)        /* Virtual GPIO Value Interrupt register                      */
.equ            MH_BBWAKE       ,     (0x41400140)        /* Wake-Up register                                           */
.equ            MH_BBITFC       ,     (0x41400144)        /* Interface Width register                                   */
.equ            MH_BBWST        ,     (0x41400148)        /* Wait Sample Time register                                  */

/*
  SSP Register Summary
*/
.equ            MH_SSCR01       ,     (0x41000000)        /* SSP1 Control register 0                                    */
.equ            MH_SSCR11       ,     (0x41000004)        /* SSP1 Control register 1                                    */
.equ            MH_SSSR1        ,     (0x41000008)        /* SSP1 Status register                                       */
.equ            MH_SSITR1       ,     (0x4100000C)        /* SSP1 Interrupt Test register                               */
.equ            MH_SSDR1        ,     (0x41000010)        /* SSP1 Data Write Register/SSP1 Data Read register           */
.equ            MH_SSTO1        ,     (0x41000028)        /* SSP1 Time Out register                                     */
.equ            MH_SSPSP1       ,     (0x4100002C)        /* SSP1 Programmable Serial Protocol register                 */
.equ            MH_SSTSA1       ,     (0x41000030)        /* SSP1 TX Time Slot Active register                          */
.equ            MH_SSRSA1       ,     (0x41000034)        /* SSP1 RX Time Slot Active register                          */
.equ            MH_SSTSS1       ,     (0x41000038)        /* SSP1 Time Slot Status register                             */
.equ            MH_SSACD1       ,     (0x4100003C)        /* SSP1 Audio Clock Divider register                          */
.equ            MH_SSACDD1      ,     (0x41000040)        /* SSP1 Audio Clock Dither Divider register                   */
.equ            MH_SSCR02       ,     (0x41700000)        /* SSP2 Control register 0                                    */
.equ            MH_SSCR12       ,     (0x41700004)        /* SSP2 Control register 1                                    */
.equ            MH_SSSR2        ,     (0x41700008)        /* SSP2 Status register                                       */
.equ            MH_SSITR2       ,     (0x4170000C)        /* SSP2 Interrupt Test register                               */
.equ            MH_SSDR2        ,     (0x41700010)        /* SSP2 Data Write Register/SSP2 Data Read register           */
.equ            MH_SSTO2        ,     (0x41700028)        /* SSP2 Time Out register                                     */
.equ            MH_SSPSP2       ,     (0x4170002C)        /* SSP2 Programmable Serial Protocol register                 */
.equ            MH_SSTSA2       ,     (0x41700030)        /* SSP2 TX Time Slot Active register                          */
.equ            MH_SSRSA2       ,     (0x41700034)        /* SSP2 RX Time Slot Active register                          */
.equ            MH_SSTSS2       ,     (0x41700038)        /* SSP2 Time Slot Status register                             */
.equ            MH_SSACD2       ,     (0x4170003C)        /* SSP2 Audio Clock Divider register                          */
.equ            MH_SSACDD2      ,     (0x41700040)        /* SSP2 Audio Clock Dither Divider register                   */
.equ            MH_SSCR03       ,     (0x41900000)        /* SSP3 Control register 0                                    */
.equ            MH_SSCR13       ,     (0x41900004)        /* SSP3 Control register 1                                    */
.equ            MH_SSSR3        ,     (0x41900008)        /* SSP3 Status register                                       */
.equ            MH_SSITR3       ,     (0x4190000C)        /* SSP3 Interrupt Test register                               */
.equ            MH_SSDR3        ,     (0x41900010)        /* SSP3 Data Write Register/SSP3 Data Read register           */
.equ            MH_SSTO3        ,     (0x41900028)        /* SSP3 Time Out register                                     */
.equ            MH_SSPSP3       ,     (0x4190002C)        /* SSP3 Programmable Serial Protocol register                 */
.equ            MH_SSTSA3       ,     (0x41900030)        /* SSP3 TX Time Slot Active register                          */
.equ            MH_SSRSA3       ,     (0x41900034)        /* SSP3 RX Time Slot Active register                          */
.equ            MH_SSTSS3       ,     (0x41900038)        /* SSP3 Time Slot Status register                             */
.equ            MH_SSACD3       ,     (0x4190003C)        /* SSP3 Audio Clock Divider register                          */
.equ            MH_SSACDD3      ,     (0x41900040)        /* SSP3 Audio Clock Dither Divider register                   */
.equ            MH_SSCR04       ,     (0x41A00000)        /* SSP4 Control register 0                                    */
.equ            MH_SSCR14       ,     (0x41A00004)        /* SSP4 Control register 1                                    */
.equ            MH_SSSR4        ,     (0x41A00008)        /* SSP4 Status register                                       */
.equ            MH_SSITR4       ,     (0x41A0000C)        /* SSP4 Interrupt Test register                               */
.equ            MH_SSDR4        ,     (0x41A00010)        /* SSP4 Data Write Register/SSP4 Data Read register           */
.equ            MH_SSTO4        ,     (0x41A00028)        /* SSP4 Time Out register                                     */
.equ            MH_SSPSP4       ,     (0x41A0002C)        /* SSP4 Programmable Serial Protocol register                 */
.equ            MH_SSTSA4       ,     (0x41A00030)        /* SSP4 TX Time Slot Active register                          */
.equ            MH_SSRSA4       ,     (0x41A00034)        /* SSP4 RX Time Slot Active register                          */
.equ            MH_SSTSS4       ,     (0x41A00038)        /* SSP4 Time Slot Status register                             */
.equ            MH_SSACD4       ,     (0x41A0003C)        /* SSP4 Audio Clock Divider register                          */
.equ            MH_SSACDD4      ,     (0x41A00040)        /* SSP4 Audio Clock Dither Divider register                   */

/*
 AC97 Controller Unit
*/
.equ            MH_POCR         ,     (0x40500000)        /* PCM Out Control register                                   */
.equ            MH_PCMICR       ,     (0x40500004)        /* PCM In Control register                                    */
.equ            MH_MCCR         ,     (0x40500008)        /* Mic In Control register                                    */
.equ            MH_GCR          ,     (0x4050000C)        /* Global Control register                                    */
.equ            MH_POSR         ,     (0x40500010)        /* PCM Out Status register                                    */
.equ            MH_PCMISR       ,     (0x40500014)        /* PCM In Status register                                     */
.equ            MH_MCSR         ,     (0x40500018)        /* Mic In Status register                                     */
.equ            MH_GSR          ,     (0x4050001C)        /* Global Status register                                     */
.equ            MH_CAR          ,     (0x40500020)        /* CODEC Access register                                      */
.equ            MH_PCSCR        ,     (0x40500024)        /* PCM Surround Out Control register                          */
.equ            MH_PCSSR        ,     (0x40500028)        /* PCM Surround Out Status register                           */
.equ            MH_PCSDR        ,     (0x4050002C)        /* PCM Surround Out Data register                             */
.equ            MH_PCCLCR       ,     (0x40500030)        /* PCM Center/LFE Out Control register                        */
.equ            MH_PCCLSR       ,     (0x40500034)        /* PCM Center/LFE Out Status register                         */
.equ            MH_PCCLDR       ,     (0x40500038)        /* PCM Center/LFE Out Data register                           */
.equ            MH_PCDR         ,     (0x40500040)        /* PCM FIFO Data register                                     */
.equ            MH_MCDR         ,     (0x40500060)        /* Mic-in FIFO Data register                                  */
.equ            MH_MOCR         ,     (0x40500100)        /* Modem Out Control register                                 */
.equ            MH_MICR         ,     (0x40500108)        /* Modem In Control register                                  */
.equ            MH_MOSR         ,     (0x40500110)        /* Modem Out Status register                                  */
.equ            MH_MISR         ,     (0x40500118)        /* Modem In Status register                                   */
.equ            MH_MODR         ,     (0x40500140)        /* Modem FIFO Data register                                   */

/*
 UART Register Summary
*/
.equ            MH_FFRBR        ,     (0x40100000)        /* Receive Buffer register                                    */
.equ            MH_FFTHR        ,     (0x40100000)        /* Transmit Holding register                                  */
.equ            MH_FFIER        ,     (0x40100004)        /* Interrupt Enable register                                  */
.equ            MH_FFIIR        ,     (0x40100008)        /* Interrupt ID register                                      */
.equ            MH_FFFCR        ,     (0x40100008)        /* FIFO Control register                                      */
.equ            MH_FFLCR        ,     (0x4010000C)        /* Line Control register                                      */
.equ            MH_FFMCR        ,     (0x40100010)        /* Modem Control register                                     */
.equ            MH_FFLSR        ,     (0x40100014)        /* Line Status register                                       */
.equ            MH_FFMSR        ,     (0x40100018)        /* Modem Status register                                      */
.equ            MH_FFSPR        ,     (0x4010001C)        /* Scratch Pad register                                       */
.equ            MH_FFDLL        ,     (0x40100000)        /* Divisor Latch register, low byte                           */
.equ            MH_FFDLH        ,     (0x40100004)        /* Divisor Latch register, high byte                          */
.equ            MH_FFISR        ,     (0x40100020)        /* Serial Infrared Select register                            */
.equ            MH_FFFOR        ,     (0x40100024)        /* FIFO Occupancy register                                    */
.equ            MH_FFABR        ,     (0x40100028)        /* Autobaud Control register                                  */
.equ            MH_FFACR        ,     (0x4010002C)        /* Autobaud Count register                                    */
.equ            MH_BTRBR        ,     (0x40200000)        /* Receive Buffer register                                    */
.equ            MH_BTTHR        ,     (0x40200000)        /* Transmit Holding register                                  */
.equ            MH_BTIER        ,     (0x40200004)        /* Interrupt Enable register                                  */
.equ            MH_BTIIR        ,     (0x40200008)        /* Interrupt ID register                                      */
.equ            MH_BTFCR        ,     (0x40200008)        /* FIFO Control register                                      */
.equ            MH_BTLCR        ,     (0x4020000C)        /* Line Control register                                      */
.equ            MH_BTMCR        ,     (0x40200010)        /* Modem Control register                                     */
.equ            MH_BTLSR        ,     (0x40200014)        /* Line Status register                                       */
.equ            MH_BTMSR        ,     (0x40200018)        /* Modem Status register                                      */
.equ            MH_BTSPR        ,     (0x4020001C)        /* Scratch Pad register                                       */
.equ            MH_BTDLL        ,     (0x40200000)        /* Divisor Latch register, low byte                           */
.equ            MH_BTDLH        ,     (0x40200004)        /* Divisor Latch register, high byte                          */
.equ            MH_BTISR        ,     (0x40200020)        /* Serial Infrared Select register                            */
.equ            MH_BTFOR        ,     (0x40200024)        /* FIFO Occupancy register                                    */
.equ            MH_BTABR        ,     (0x40200028)        /* Autobaud Control register                                  */
.equ            MH_BTACR        ,     (0x4020002C)        /* Autobaud Count register                                    */
.equ            MH_STRBR        ,     (0x40700000)        /* Receive Buffer register                                    */
.equ            MH_STTHR        ,     (0x40700000)        /* Transmit Holding register                                  */
.equ            MH_STIER        ,     (0x40700004)        /* Interrupt Enable register                                  */
.equ            MH_STIIR        ,     (0x40700008)        /* Interrupt ID register                                      */
.equ            MH_STFCR        ,     (0x40700008)        /* FIFO Control register                                      */
.equ            MH_STLCR        ,     (0x4070000C)        /* Line Control register                                      */
.equ            MH_STMCR        ,     (0x40700010)        /* Modem Control register                                     */
.equ            MH_STLSR        ,     (0x40700014)        /* Line Status register                                       */
.equ            MH_STMSR        ,     (0x40700018)        /* Modem Status register                                      */
.equ            MH_STSPR        ,     (0x4070001C)        /* Scratch Pad register                                       */
.equ            MH_STDLL        ,     (0x40700000)        /* Divisor Latch register, low byte                           */
.equ            MH_STDLH        ,     (0x40700004)        /* Divisor Latch register, high byte                          */
.equ            MH_STISR        ,     (0x40700020)        /* Serial Infrared Select register                            */
.equ            MH_STFOR        ,     (0x40700024)        /* FIFO Occupancy register                                    */
.equ            MH_STABR        ,     (0x40700028)        /* Autobaud Control register                                  */
.equ            MH_STACR        ,     (0x4070002C)        /* Autobaud Count register                                    */

/*
 CIR Register Addresses
*/
.equ            MH_CIRPW        ,     (0x41D00000)        /* CIR Pulse Width Comparator register                        */
.equ            MH_CIRMP        ,     (0x41D00004)        /* CIR Modulation Period Comparator register                  */
.equ            MH_CIRN0        ,     (0x41D00008)        /* CIR N0 Symbol Length register                              */
.equ            MH_CIRN1        ,     (0x41D0000C)        /* CIR N1 Symbol Length register                              */
.equ            MH_CIRS0        ,     (0x41D00010)        /* CIR S0 Symbol Length register                              */
.equ            MH_CIRS1        ,     (0x41D00014)        /* CIR S1 Symbol Length register                              */
.equ            MH_CIRBUFF      ,     (0x41D00018)        /* CIR Buffer register                                        */
.equ            MH_CIRNS        ,     (0x41D0001C)        /* CIR Number of Symbols register                             */
.equ            MH_CIRCR        ,     (0x41D00020)        /* CIR Control register                                       */
.equ            MH_CIRIR        ,     (0x41D00024)        /* CIR Interrupt register                                     */

/*
 PWM Control Registers
*/
.equ            MH_PWMCR0       ,     (0x40B00000)        /* PWM 0 Control register                          */
.equ            MH_PWMDCR0      ,     (0x40B00004)        /* PWM 0 Duty Cycle register                       */
.equ            MH_PWMPCR0      ,     (0x40B00008)        /* PWM 0 Period register                           */
.equ            MH_PWMCR2       ,     (0x40B00010)        /* PWM 2 Control register                          */
.equ            MH_PWMDCR2      ,     (0x40B00014)        /* PWM 2 Duty Cycle register                       */
.equ            MH_PWMPCR2      ,     (0x40B00018)        /* PWM 2 Period register                           */
.equ            MH_PWMCR1       ,     (0x40C00000)        /* PWM 1 Control register                          */
.equ            MH_PWMDCR1      ,     (0x40C00004)        /* PWM 1 Duty Cycle register                       */
.equ            MH_PWMPCR1      ,     (0x40C00008)        /* PWM 1 Period register                           */
.equ            MH_PWMCR3       ,     (0x40C00010)        /* PWM 3 Control register                          */
.equ            MH_PWMDCR3      ,     (0x40C00014)        /* PWM 3 Duty Cycle register                       */
.equ            MH_PWMPCR3      ,     (0x40C00018)        /* PWM 3 Period register                           */

/*
 USIM Controller Register Summary
*/
.equ            MH_Base1        ,     (0x41600000)        /* USIM Controller 1                                 */
.equ            MH_RBR1         ,     (0x41600000)        /* USIM Receive Buffer register                      */
.equ            MH_THR1         ,     (0x41600004)        /* USIM Transmit Holding register                    */
.equ            MH_IER1         ,     (0x41600008)        /* USIM Interrupt Enable register                    */
.equ            MH_IIR1         ,     (0x4160000C)        /* USIM Interrupt Identification register            */
.equ            MH_FCR1         ,     (0x41600010)        /* USIM FIFO Control register                        */
.equ            MH_FSR1         ,     (0x41600014)        /* USIM FIFO Status register                         */
.equ            MH_ECR1         ,     (0x41600018)        /* USIM Error Control register                       */
.equ            MH_LCR1         ,     (0x4160001C)        /* USIM Line Control register                        */
.equ            MH_USCCR1       ,     (0x41600020)        /* USIM SmartCard Control register                   */
.equ            MH_LSR1         ,     (0x41600024)        /* USIM Line Status register                         */
.equ            MH_EGTR1        ,     (0x41600028)        /* USIM Extra Guard Time register                    */
.equ            MH_BGTR1        ,     (0x4160002C)        /* USIM Block Guard Time register                    */
.equ            MH_TOR1         ,     (0x41600030)        /* USIM Time-Out register                            */
.equ            MH_CLKR1        ,     (0x41600034)        /* USIM Clock register                               */
.equ            MH_DLR1         ,     (0x41600038)        /* USIM Divisor Latch register                       */
.equ            MH_FLR1         ,     (0x4160003C)        /* USIM Factor Latch register                        */
.equ            MH_CWTR1        ,     (0x41600040)        /* USIM Character Waiting Time register              */
.equ            MH_BWTR1        ,     (0x41600044)        /* USIM Block Waiting Time register                  */
.equ            MH_Base2        ,     (0x42100000)        /* USIM Controller 2                                 */
.equ            MH_RBR2         ,     (0x42100000)        /* USIM Receive Buffer register                      */
.equ            MH_THR2         ,     (0x42100004)        /* USIM Transmit Holding register                    */
.equ            MH_IER2         ,     (0x42100008)        /* USIM Interrupt Enable register                    */
.equ            MH_IIR2         ,     (0x4210000C)        /* USIM Interrupt Identification register            */
.equ            MH_FCR2         ,     (0x42100010)        /* USIM FIFO Control register                        */
.equ            MH_FSR2         ,     (0x42100014)        /* USIM FIFO Status register                         */
.equ            MH_ECR2         ,     (0x42100018)        /* USIM Error Control register                       */
.equ            MH_LCR2         ,     (0x4210001C)        /* USIM Line Control register                        */
.equ            MH_USCCR2       ,     (0x42100020)        /* USIM SmartCard Control register                   */
.equ            MH_LSR2         ,     (0x42100024)        /* USIM Line Status register                         */
.equ            MH_EGTR2        ,     (0x42100028)        /* USIM Extra Guard Time register                    */
.equ            MH_BGTR2        ,     (0x4210002C)        /* USIM Block Guard Time register                    */
.equ            MH_TOR2         ,     (0x42100030)        /* USIM Time-Out register                            */
.equ            MH_CLKR2        ,     (0x42100034)        /* USIM Clock register                               */
.equ            MH_DLR2         ,     (0x42100038)        /* USIM Divisor Latch register                       */
.equ            MH_FLR2         ,     (0x4210003C)        /* USIM Factor Latch register                        */
.equ            MH_CWTR2        ,     (0x42100040)        /* USIM Character Waiting Time register              */
.equ            MH_BWTR2        ,     (0x42100044)        /* USIM Block Waiting Time register                  */

/*
 Standard I2C Register Addresses
*/
.equ            MH_IBMR         ,     (0x40301680)        /* Bus Monitor register            */
.equ            MH_IDBR         ,     (0x40301688)        /* Data Buffer register            */
.equ            MH_ICR          ,     (0x40301690)        /* Control register                */
.equ            MH_ISR          ,     (0x40301698)        /* Status register                 */
.equ            MH_ISAR         ,     (0x403016A0)        /* Slave Address register          */

#      .end

