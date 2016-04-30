
/*
    Platform Name
*/

#define PLATFORM_NAME_S68P              "S68P"
#define PLATFORM_TYPE                   PLATFORM_NAME_S68P

/*
    Memory Map
*/

#include "_MemoryBase_PXA3xx.h"
#include "MemorySize.h"
#include "_MemoryMap_EXE_at_SDRAM.h"

/*
    Processor Type
*/

#define PROCESSOR_TYPE_PXA300

#include "_Reg_PXA3xx.h"
#include "_RegBit_PXA3xx.h"
#include "_StructType_PXA3XX.h"

/*
    PIN MFPR: PINs setting is in start.s
*/

/*
    PMIC
*/

#include "_DA9034_Reg.h"

#define DA9034_LDO1_VOLTAGE1            (DA9034_LDO1_1V8)
#define DA9034_LDO1_VOLTAGE2            (DA9034_LDO1_1V8)
#define DA9034_LDO2_VOLTAGE1            (DA9034_LDO2_1V4)
#define DA9034_LDO2_VOLTAGE2            (DA9034_LDO2_1V1)
#define DA9034_LDO3_VOLTAGE             (DA9034_LDO3_2V8)
#define DA9034_LDO4_VOLTAGE             (DA9034_LDO4_1V8)
#define DA9034_LDO6_VOLTAGE             (DA9034_LDO6_2V65)
#define DA9034_LDO7_VOLTAGE             (DA9034_LDO7_2V8)
#define DA9034_LDO8_VOLTAGE             (DA9034_LDO8_2V8)
#define DA9034_LDO9_VOLTAGE             (DA9034_LDO9_2V85)
#define DA9034_LDO10_VOLTAGE            (DA9034_LDO10_2V85)
#define DA9034_LDO11_VOLTAGE            (DA9034_LDO11_1V8)
#define DA9034_LDO12_VOLTAGE            (DA9034_LDO12_2V85)
#define DA9034_LDO13_VOLTAGE            (DA9034_LDO13_2V9)
#define DA9034_LDO14_VOLTAGE            (DA9034_LDO14_2V9)
#define DA9034_LDO15_VOLTAGE            (DA9034_LDO15_2V9)

#define DA9034_BUCK1_VOLTAGE1           (DA9034_BUCK1_1V4)
#define DA9034_BUCK1_VOLTAGE2           (DA9034_BUCK1_1V1)
#define DA9034_BUCK2_VOLTAGE            (LDO11_10_BUCK2_SEL_1V8)

#define DA9034_POWER_ENABLE_SET1        0
#define DA9034_POWER_ENABLE_SET2        (APPS_OVER2_LDO13_ENABLE | APPS_OVER2_LDO12_ENABLE | APPS_OVER2_LDO11_ENABLE | APPS_OVER2_LDO10_ENABLE | APPS_OVER2_LDO9_ENABLE | APPS_OVER2_LDO7_ENABLE | APPS_OVER2_LDO6_ENABLE)
#define DA9034_POWER_ENABLE_SET3        (APPS_OVER3_BUCK2_ENABLE | APPS_OVER3_RF_GP_ENABLE | APPS_OVER3_LDO15_ENABLE | APPS_OVER3_LDO14_ENABLE | APPS_OVER3_LDO1_ENABLE | APPS_OVER3_LDO3_ENABLE | APPS_OVER3_LDO4_ENABLE | APPS_OVER3_LDO5_ENABLE)

#define DA9034_POWER_ENABLE_nSLEEP1     (LDO_nSLEEP_1_LDO9_nSLEEP_ENABLE | LDO_nSLEEP_1_LDO7_nSLEEP_ENABLE)
#define DA9034_POWER_ENABLE_nSLEEP2     (LDO_nSLEEP_2_LDO5_nSLEEP_ENABLE | LDO_nSLEEP_2_LDO4_nSLEEP_ENABLE)

/*
    Clock
*/
#define REG_CKENA_SETTING               (CKENA_CAM|CKENA_NAND|CKENA_MMC3|CKENA_DMC|CKENA_SMC|CKENA_SRAM|CKENA_BTROM|CKENA_MMC0|CKENA_MMC1|CKENA_KEYP|CKENA_UDC|CKENA_UART2|CKENA_UART1|CKENA_UART3|CKENA_SSP1|CKENA_SSP2|CKENA_SSP3|CKENA_SSP4|CKENA_SET_ALWAYS)
#define REG_CKENB_SETTING               (CKENB_PWM01|CKENB_PWM23|CKENB_I2C|CKENB_GPIO|CKENB_HSIO2|CKENB_GCU|CKENB_SET_ALWAYS)

/*
    NAND Flash
*/

#define NAND_MICRON1GB

#ifdef NAND_MICRON1GB

#define NAND_CMD_READ_CYCLE             4
#define NAND_CMD_WRITE_CYCLE            4
#define NAND_CMD_ERASE_CYCLE            2

#define NAND_SPAREAREA_SIZE             64
#define NAND_SECTOR_SIZE                (2 * 1024)
#define NAND_BLOCK_SIZE                 (64 * NAND_SECTOR_SIZE)
#define NAND_TOTAL_SIZE                 (1024 * NAND_BLOCK_SIZE)

#define NAND_BADBLOCK_NUMBER_MAX        20

#define DEFAULT_NDTR0CS0_VALUE          NDTR0CS_tCH(2) | NDTR0CS_tCS(4) | NDTR0CS_tWH(3) | NDTR0CS_tWP(4) | NDTR0CS_tRH(3) | NDTR0CS_tRP(4)
#define DEFAULT_NDTR1CS0_VALUE          NDTR1CS_tR(0x0F3D) | NDTR1CS_tWHR(0xD) |NDTR1CS_tAR(0x2)

#endif

#ifdef NAND_MICRON2GB

#define NAND_CMD_READ_CYCLE             5
#define NAND_CMD_WRITE_CYCLE            5
#define NAND_CMD_ERASE_CYCLE            3

#define NAND_SPAREAREA_SIZE             64
#define NAND_SECTOR_SIZE                (2 * 1024)
#define NAND_BLOCK_SIZE                 (64 * NAND_SECTOR_SIZE)
#define NAND_TOTAL_SIZE                 (2048 * NAND_BLOCK_SIZE)

#define NAND_BADBLOCK_NUMBER_MAX        40

#define DEFAULT_NDTR0CS0_VALUE          NDTR0CS_tCH(2) | NDTR0CS_tCS(6) | NDTR0CS_tWH(3) | NDTR0CS_tWP(4) | NDTR0CS_tRH(3) | NDTR0CS_tRP(4)
#define DEFAULT_NDTR1CS0_VALUE          NDTR1CS_tR(0x0F3D) | NDTR1CS_tWHR(0xD) |NDTR1CS_tAR(0x2)

#endif

/*
    PMIC
*/

#define SYS_PMIC_TYPE_DA9034

/*
    UART Port
*/

#define UART_ID_DBG                     UART_ID_3
#define UART_ID_MENU                    UART_ID_3
#define UART_ID_XMDM                    UART_ID_3

#define UART_ID_MODEM                   UART_ID_1

/*
    PIN
*/

#define PIN_PMIC_INT                    18

/*
    GPIO
*/

// Output
#define GPIO_CHG_CURRENT                ( 1u << (0   - 0 * 32) )
#define GPIO_FLIGHT_EN                  ( 1u << (5   - 0 * 32) )
#define GPIO_USBWS_CTRL_A               ( 1u << (29  - 0 * 32) )

#define GPIO_PANEL_BK_LIGHT             ( 1u << (24  - 0 * 32) )
#define GPIO_PANEL_RESET                ( 1u << (76  - 2 * 32) )
#define GPIO_PANEL_SPI_CLK              ( 1u << (81  - 2 * 32) )
#define GPIO_PANEL_SPI_SI               ( 1u << (89  - 2 * 32) )
#define GPIO_PANEL_SPI_CS               ( 1u << (127 - 3 * 32) )

#define GPIO_SPK_SD                     ( 1u << (38  - 1 * 32) )

#define GPIO_FM2010_RST                 ( 1u << (34  - 1 * 32) )
#define GPIO_FM2010_PWD                 ( 1u << (108 - 3 * 32) )
#define GPIO_FM2010_IRQ_ANA             ( 1u << (33  - 1 * 32) )

#define GPIO_AP_RST_BB                  ( 1u << (125 - 3 * 32) )
#define GPIO_BB_ON                      ( 1u << (4   - 0 * 32) )
#define GPIO_AP_ACTIVE                  ( 1u << (87  - 2 * 32) )
#define GPIO_RF_ATE                     ( 1u << (36  - 1 * 32) )

// Input
#define GPIO_PMIC_INT                   ( 1u << (18  - 0 * 32) )
#define GPIO_CHARGE_DOK                 ( 1u << (6   - 0 * 32) )
#define GPIO_CHARGE_CHG                 ( 1u << (103 - 3 * 32) )

// For Test
#define GPIO_101                        ( 1u << (101 - 3 * 32) )
#define GPIO_102                        ( 1u << (102 - 3 * 32) )

// FOR MODEM TEST
#define GPIO_FFUART_RTS                 ( 1u << (37 - 1 * 32) )

// Output Low

#define REG_GPCR0_VAL                   (GPIO_PANEL_BK_LIGHT | GPIO_USBWS_CTRL_A | GPIO_FLIGHT_EN | GPIO_CHG_CURRENT | GPIO_BB_ON)
#define REG_GPCR1_VAL                   (GPIO_RF_ATE)
#define REG_GPCR2_VAL                   (GPIO_PANEL_SPI_CLK | GPIO_PANEL_SPI_SI | GPIO_PANEL_RESET)
#define REG_GPCR3_VAL                   (GPIO_PANEL_SPI_CS | GPIO_AP_RST_BB)

// Output High

#define REG_GPSR0_VAL                   (0)
#define REG_GPSR1_VAL                   (GPIO_SPK_SD | GPIO_FM2010_RST | GPIO_FM2010_IRQ_ANA)
#define REG_GPSR2_VAL                   (GPIO_AP_ACTIVE)
#define REG_GPSR3_VAL                   (GPIO_FM2010_PWD)

// Rasing interrupt enable
#define REG_GSRER0_VAL                  (0)
#define REG_GSRER1_VAL                  0
#define REG_GSRER2_VAL                  0
#define REG_GSRER3_VAL                  0

// Falling interrupt enable
#define REG_GSFER0_VAL                  (GPIO_PMIC_INT)
#define REG_GSFER1_VAL                  0
#define REG_GSFER2_VAL                  0
#define REG_GSFER3_VAL                  (0)

/*
    MMC/SD
*/

#define MMC_CONTROLLER_ID               0

/*
    Keypad
*/

#define KEYPAD_ROW_NUMBER               8
#define KEYPAD_COL_NUMBER               8
#define KEYPAD_DIR_NUMBER               3

#define KP_SCANCODE_0_UP                ((1 << 0) << 0)
#define KP_SCANCODE_0_DOWN              ((1 << 1) << 0)
#define KP_SCANCODE_0_CAM1              ((1 << 2) << 0)
#define KP_SCANCODE_0_CAM2              ((1 << 3) << 0)

#define USER_SEL_GOTO_MOBM              (KP_SCANCODE_0_CAM1 | KP_SCANCODE_0_CAM2)
#define USER_SEL_GOTO_HWT               (0xFFFFFFFF - 0)
#define USER_SEL_GOTO_EBOOT1            (0xFFFFFFFF - 1)
#define USER_SEL_GOTO_EBOOT2            (0xFFFFFFFF - 2)
#define USER_SEL_GOTO_ULDR              (0xFFFFFFFF - 3)
#define USER_SEL_GOTO_CLEANBOOT         (KP_SCANCODE_0_UP | KP_SCANCODE_0_DOWN)
#define USER_SEL_GOTO_KITL              (0xFFFFFFFF - 4)

/*
    Display
*/

#define DISP_BK_CONTROL(p)              GPIO_PanelBackLight(p)

#define OVERLAY2_MODE_YUV
//#define OVERLAY2_MODE_RGB

#define DISPLAY_RESOLUSION_QVGA_PORTRAIT

#ifdef DISPLAY_RESOLUSION_QVGA_PORTRAIT
#define LCD_WIDTH                       240
#define LCD_HEIGHT                      320

#define LCCR1_BLW_BEGIN_OF_LINE_WAIT    2
#define LCCR1_ELW_END_OF_LINE_WAIT      2
#define LCCR1_HSW_LSYNC_PULSE_WIDTH     1

#define LCCR2_BFW_BEGIN_OF_FRAME_WAIT   2
#define LCCR2_EFW_END_OF_FRAME_WAIT     2
#define LCCR2_VSW_FSYNC_PULSE_WIDTH     1

#define LCCR3_PCP_PIXEL_CLK_POLARITY    PCP_PIXEL_CLK_DATA_ON_RISING
#define LCCR3_HSP_HORI_SYNC_POLARITY    HSP_HSYNC_ACTIVE_LOW
#define LCCR3_VSP_VERT_SYNC_POLARITY    VSP_VSYNC_ACTIVE_LOW

#define LCCR3_BPP_BIT_PER_PIXEL         BPP_16BIT_PER_PIXEL

#define LCCR3_PCD_PIXEL_CLK_DIVIDE      14
#define LCCR4_PCD_DIV_FORMULA_SEL       PCD_DIV_FORMULA0
#endif

#define LCD_OUTPUT_BPP                  16
#define LCD_OUTPUT_PIXEL_SIZE           (LCD_OUTPUT_BPP/8)

#define OVERLAY1_WIDTH                  160
#define OVERLAY1_HEIGHT                 120
#define LCD_OL1_BPP                     32

#define OVERLAY2_WIDTH                  160
#define OVERLAY2_HEIGHT                 120
#define LCD_OL2_BPP                     16

#if (LCCR3_BPP_BIT_PER_PIXEL ==         BPP_16BIT_PER_PIXEL)
#define FB_BASE_BPP                     16
#define PAL_BASE_ITEM_NUM               0
#endif

#ifdef OVERLAY2_MODE_RGB
#define CIF_PIC_COLOR_BPP_RGB           16
#endif

/*
    SSP
*/
#define SSP_AUDIO_PLAY                  SSP_ID_2
#define SSP_AUDIO_RECORD                SSP_ID_3


