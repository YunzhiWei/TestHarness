
#define CHARGER_DISABLE                 0                   // '1' - disable Charge; '0' - enable Charge

/*
    Platform Name
*/

#define PLATFORM_NAME_GRYPHUS           "Gryphus"
#define PLATFORM_TYPE                   PLATFORM_NAME_GRYPHUS

/*
    Memory Map
*/

#include "_MemoryBase_PXA3xx.h"
#include "MemorySize.h"
#include "_MemoryMap_EXE_at_SDRAM.h"

/*
    Processor Type
*/

#define PROCESSOR_TYPE_PXA310

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
#define DA9034_LDO11_VOLTAGE            (DA9034_LDO11_3V)
#define DA9034_LDO12_VOLTAGE            (DA9034_LDO12_2V9)
#define DA9034_LDO13_VOLTAGE            (DA9034_LDO13_2V9)
#define DA9034_LDO14_VOLTAGE            (0)
#define DA9034_LDO15_VOLTAGE            (DA9034_LDO15_2V9)

#define DA9034_BUCK1_VOLTAGE1           (DA9034_BUCK1_1V375)
#define DA9034_BUCK1_VOLTAGE2           (DA9034_BUCK1_1V1)
#define DA9034_BUCK2_VOLTAGE            (LDO11_10_BUCK2_SEL_1V8)

#define DA9034_POWER_ENABLE_SET1        (OVER1_BUCK1_ENABLE | OVER1_LDO2_ENABLE | OVER1_SEL_LDO_DRIVE)
#define DA9034_POWER_ENABLE_SET2        (APPS_OVER2_LDO11_ENABLE | APPS_OVER2_LDO9_ENABLE | APPS_OVER2_LDO7_ENABLE)
#define DA9034_POWER_ENABLE_SET3        (APPS_OVER3_BUCK2_ENABLE | APPS_OVER3_RF_GP_ENABLE | APPS_OVER3_LDO1_ENABLE | APPS_OVER3_LDO3_ENABLE | APPS_OVER3_LDO4_ENABLE | APPS_OVER3_LDO5_ENABLE)

#define DA9034_POWER_ENABLE_nSLEEP1     (LDO_nSLEEP_1_LDO9_nSLEEP_ENABLE | LDO_nSLEEP_1_LDO7_nSLEEP_ENABLE)
#define DA9034_POWER_ENABLE_nSLEEP2     (LDO_nSLEEP_2_LDO5_nSLEEP_ENABLE | LDO_nSLEEP_2_LDO4_nSLEEP_ENABLE)

/*
    Clock
*/
#define REG_CKENA_SETTING               (CKENA_CAM|CKENA_NAND|CKENA_U2D|CKENA_DMC|CKENA_SMC|CKENA_SRAM|CKENA_BTROM|CKENA_MMC0|CKENA_KEYP|CKENA_UART1|CKENA_UART3|CKENA_SSP2|CKENA_SSP3|CKENA_SSP4|CKENA_SET_ALWAYS)
#define REG_CKENB_SETTING               (CKENB_I2C|CKENB_GPIO|CKENB_HSIO2|CKENB_GCU|CKENB_SET_ALWAYS)

/*
    NAND Flash
*/

#define NAND_MICRON2GB

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

#define PIN_PMIC_INT                    127

/*
    GPIO
*/

// Output

#define GPIO_DF_WP                      ( 1u << (1   - 0 * 32) )
#define GPIO_ULPI_RESET                 ( 1u << (2   - 0 * 32) )
#define GPIO_CHGB_EN                    ( 1u << (23  - 0 * 32) )

#define GPIO_CIF_RST                    ( 1u << (53  - 1 * 32) )
#define GPIO_CIF_SD                     ( 1u << (76  - 2 * 32) )

#define GPIO_LCM_RST                    ( 1u << (71  - 2 * 32) )

#define GPIO_MODEM_ONKEY                ( 1u << (80  - 2 * 32) )
#define GPIO_MODEM_DSR                  ( 1u << (81  - 2 * 32) )
#define GPIO_MODEM_DTR                  ( 1u << (83  - 2 * 32) )
#define GPIO_MODEM_RTS                  ( 1u << (84  - 2 * 32) )

#define GPIO_MODEM_RST                  ( 1u << (89  - 2 * 32) )
#define GPIO_MP3_OP_ON                  ( 1u << (90  - 2 * 32) )

#define GPIO_FM_RST                     ( 1u << (99  - 3 * 32) )
#define GPIO_WIFI_SD                    ( 1u << (101 - 3 * 32) )
#define GPIO_WIFI_RST                   ( 1u << (102 - 3 * 32) )
#define GPIO_BT_RST                     ( 1u << (106 - 3 * 32) )

// Input

#define GPIO_CHARGEB_STATUS             ( 1u << (10  - 0 * 32) )
#define GPIO_ACOK                       ( 1u << (11  - 0 * 32) )
#define GPIO_MMC2_CLK                   ( 1u << (13  - 0 * 32) )
#define GPIO_MMC2_CMD                   ( 1u << (14  - 0 * 32) )
#define GPIO_TF_CD                      ( 1u << (29  - 0 * 32) )

#define GPIO_LCM_ID                     ( 1u << (70  - 2 * 32) )
#define GPIO_MODEM_STATUS               ( 1u << (82  - 2 * 32) )

#define GPIO_BT_INT                     ( 1u << (104 - 3 * 32) )
#define GPIO_PMIC_INT                   ( 1u << (127 - 3 * 32) )

// Output Low
#define REG_GPCR0_VAL                   (GPIO_CHGB_EN)                                                      // Eanble Charge at first.
#define REG_GPCR1_VAL                   0
#define REG_GPCR2_VAL                   (GPIO_LCM_RST | GPIO_MP3_OP_ON | GPIO_MODEM_DTR | GPIO_MODEM_RTS | GPIO_MODEM_RST | GPIO_MODEM_ONKEY)
#define REG_GPCR3_VAL                   (GPIO_WIFI_SD)

// Output High
#define REG_GPSR0_VAL                   (GPIO_ULPI_RESET | GPIO_DF_WP | GPIO_CHGB_EN * CHARGER_DISABLE)     // Disable Charge according to setting
#define REG_GPSR1_VAL                   (GPIO_CIF_RST)
#define REG_GPSR2_VAL                   (GPIO_CIF_SD)
#define REG_GPSR3_VAL                   (GPIO_BT_RST)

// Rasing interrupt enable
#define REG_GSRER0_VAL                  (GPIO_TF_CD)
#define REG_GSRER1_VAL                  0
#define REG_GSRER2_VAL                  0
#define REG_GSRER3_VAL                  0

// Falling interrupt enable
#define REG_GSFER0_VAL                  (GPIO_TF_CD)
#define REG_GSFER1_VAL                  0
#define REG_GSFER2_VAL                  0
#define REG_GSFER3_VAL                  (GPIO_PMIC_INT)

/*
    MMC/SD
*/

#define MMC_CONTROLLER_ID               0

/*
    Keypad
*/

#define KEYPAD_ROW_NUMBER               3
#define KEYPAD_COL_NUMBER               4
//#define KEYPAD_DIR_NUMBER

#define KP_SCANCODE_0_UP                ((1 << 0) << 0)
#define KP_SCANCODE_0_DOWN              ((1 << 0) << 16)
#define KP_SCANCODE_0_CALL              ((1 << 1) << 0)
#define KP_SCANCODE_0_HANG              ((1 << 1) << 16)
#define KP_SCANCODE_0_PLUS              ((1 << 2) << 0)
#define KP_SCANCODE_0_MINUS             ((1 << 2) << 16)

#define USER_SEL_GOTO_MOBM              (KP_SCANCODE_0_PLUS | KP_SCANCODE_0_DOWN)
#define USER_SEL_GOTO_HWT               (KP_SCANCODE_0_CALL | KP_SCANCODE_0_HANG)
#define USER_SEL_GOTO_EBOOT1            (KP_SCANCODE_0_PLUS | KP_SCANCODE_0_MINUS)
#define USER_SEL_GOTO_EBOOT2            (KP_SCANCODE_0_PLUS | KP_SCANCODE_0_CALL)
#define USER_SEL_GOTO_ULDR              (KP_SCANCODE_0_PLUS | KP_SCANCODE_0_UP)
#define USER_SEL_GOTO_CLEANBOOT         (KP_SCANCODE_0_MINUS | KP_SCANCODE_0_DOWN)
#define USER_SEL_GOTO_KITL              (KP_SCANCODE_0_UP | KP_SCANCODE_0_DOWN)

#define KEY_FUNCTION_CAMERA             'C'

#define KEY_FUNCTION_VOLUME_PLUS        '+'
#define KEY_FUNCTION_VOLUME_MINUS       '-'

#define KEY_FUNCTION_ACTION             '#'

#define KEY_FUNCTION_CALL               '@'
#define KEY_FUNCTION_HANGUP             '&'

#define KEY_FUNCTION_DIR_UP             'u'
#define KEY_FUNCTION_DIR_LEFT           'l'
#define KEY_FUNCTION_DIR_RIGHT          'r'
#define KEY_FUNCTION_DIR_DOWN           'd'

/*
    Display
*/

#define DISP_BK_CONTROL(p)              PMIC_Backlight(p)

#define OVERLAY2_MODE_YUV
//#define OVERLAY2_MODE_RGB

//#define DISPLAY_RESOLUSION_WVGA_LANDSCAPE
#define DISPLAY_RESOLUSION_QVGA_PORTRAIT

#ifdef DISPLAY_RESOLUSION_WVGA_LANDSCAPE
#define LCD_WIDTH                       800
#define LCD_HEIGHT                      480

#define LCCR1_BLW_BEGIN_OF_LINE_WAIT    88
#define LCCR1_ELW_END_OF_LINE_WAIT      40
#define LCCR1_HSW_LSYNC_PULSE_WIDTH     128

#define LCCR2_BFW_BEGIN_OF_FRAME_WAIT   33
#define LCCR2_EFW_END_OF_FRAME_WAIT     10
#define LCCR2_VSW_FSYNC_PULSE_WIDTH     2

#define LCCR3_PCP_PIXEL_CLK_POLARITY    PCP_PIXEL_CLK_DATA_ON_FALLING
#define LCCR3_HSP_HORI_SYNC_POLARITY    HSP_HSYNC_ACTIVE_LOW
#define LCCR3_VSP_VERT_SYNC_POLARITY    VSP_VSYNC_ACTIVE_LOW

#define LCCR3_BPP_BIT_PER_PIXEL         BPP_16BIT_PER_PIXEL

#define LCCR3_PCD_PIXEL_CLK_DIVIDE      1
#define LCCR4_PCD_DIV_FORMULA_SEL       PCD_DIV_FORMULA0
#endif

#ifdef DISPLAY_RESOLUSION_QVGA_PORTRAIT
#define LCD_WIDTH                       240
#define LCD_HEIGHT                      320

#define LCCR1_BLW_BEGIN_OF_LINE_WAIT    10
#define LCCR1_ELW_END_OF_LINE_WAIT      20
#define LCCR1_HSW_LSYNC_PULSE_WIDTH     10

#define LCCR2_BFW_BEGIN_OF_FRAME_WAIT   2
#define LCCR2_EFW_END_OF_FRAME_WAIT     8
#define LCCR2_VSW_FSYNC_PULSE_WIDTH     2

#define LCCR3_PCP_PIXEL_CLK_POLARITY    PCP_PIXEL_CLK_DATA_ON_FALLING
#define LCCR3_HSP_HORI_SYNC_POLARITY    HSP_HSYNC_ACTIVE_LOW
#define LCCR3_VSP_VERT_SYNC_POLARITY    VSP_VSYNC_ACTIVE_LOW

#define LCCR3_BPP_BIT_PER_PIXEL         BPP_16BIT_PER_PIXEL

#define LCCR3_PCD_PIXEL_CLK_DIVIDE      12
#define LCCR4_PCD_DIV_FORMULA_SEL       PCD_DIV_FORMULA0
#endif

#define LCD_OUTPUT_BPP                  16
#define LCD_OUTPUT_PIXEL_SIZE           (LCD_OUTPUT_BPP/8)

#define LCD_BK_CONTROL(p)               DA9034_BackLight(p);

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
#define SSP_AUDIO_PLAY                  SSP_ID_3
#define SSP_AUDIO_RECORD                SSP_ID_4


