
/*
    Platform Name
*/

#define PLATFORM_NAME_ZYLONITE          "Zylonite"
#define PLATFORM_TYPE                   PLATFORM_NAME_ZYLONITE

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
    Clock
*/
#define REG_CKENA_SETTING               (CKENA_USB|CKENA_CAM|CKENA_NAND|CKENA_MMC3|CKENA_U2D|CKENA_DMC|CKENA_SMC|CKENA_SRAM|CKENA_BTROM|CKENA_MMC0|CKENA_MMC1|CKENA_KEYP|CKENA_UDC|CKENA_UART2|CKENA_UART1|CKENA_UART3|CKENA_SSP1|CKENA_SSP2|CKENA_SSP3|CKENA_SSP4|CKENA_SET_ALWAYS)
#define REG_CKENB_SETTING               (CKENB_PWM01|CKENB_PWM23|CKENB_I2C|CKENB_GPIO|CKENB_HSIO2|CKENB_GCU|CKENB_VAU|CKENB_SET_ALWAYS)

/*
    NAND Flash
*/

#define NAND_TYPE_ST2GBit

#ifdef NAND_TYPE_ST2GBit

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
    UART Port
*/

#define UART_ID_DBG                     UART_ID_1
#define UART_ID_MENU                    UART_ID_1
#define UART_ID_XMDM                    UART_ID_1

/*
    GPIO
*/

#define GPIO_LCD_VSYNC                  ( 1u << (76  - 2 * 32) )
#define GPIO_M_CIF_HI_PWDN              ( 1u << (102 - 3 * 32) )
#define GPIO_K_CIF_LO_PWDN              ( 1u << (103 - 3 * 32) )

#define GPIO_107_KP_DKIN0               ( 1u << (107 - 3 * 32))
#define GPIO_108_KP_DKIN1               ( 1u << (108 - 3 * 32))

// Output Low
#define REG_GPCR0_VAL                   0
#define REG_GPCR1_VAL                   0
#define REG_GPCR2_VAL                   (GPIO_LCD_VSYNC)
#define REG_GPCR3_VAL                   0

// Output High
#define REG_GPSR0_VAL                   0
#define REG_GPSR1_VAL                   0
#define REG_GPSR2_VAL                   0
#define REG_GPSR3_VAL                   (GPIO_M_CIF_HI_PWDN | GPIO_K_CIF_LO_PWDN)

// Rasing interrupt enable
#define REG_GSRER0_VAL                   0
#define REG_GSRER1_VAL                   0
#define REG_GSRER2_VAL                   0
#define REG_GSRER3_VAL                   (GPIO_108_KP_DKIN1)

// Falling interrupt enable
#define REG_GSFER0_VAL                   0
#define REG_GSFER1_VAL                   0
#define REG_GSFER2_VAL                   0
#define REG_GSFER3_VAL                   (GPIO_107_KP_DKIN0)

/*
    MMC/SD
*/

#define MMC_CONTROLLER_ID               2

/*
    Keypad
*/

#define KEY_PHONE_ANSWER                'a'
#define KEY_PHONE_HANGUP                'h'

#define KEY_ARROW_UP                    'u'
#define KEY_ARROW_DOWN                  'd'
#define KEY_ARROW_LEFT                  'l'
#define KEY_ARROW_RIGHT                 'r'

#define KEY_ACTION_OK                   'o'
#define KEY_ACTION_HOME                 'm'
#define KEY_ACTION_RETURN               't'

#define KEY_SOFT_LEFT                   '['
#define KEY_SOFT_RIGHT                  ']'

#define KEY_BLACK_1                     'w'
#define KEY_BLACK_2                     'y'
#define KEY_BLACK_3                     'z'

#define KEYPAD_ROW_NUMBER               8
#define KEYPAD_COL_NUMBER               8
#define KEYPAD_DIR_NUMBER               3

#define KP_SCANCODE_0_UP                ((1 << 0) << 0)
#define KP_SCANCODE_0_DOWN              ((1 << 1) << 0)
#define KP_SCANCODE_0_CAM1              ((1 << 2) << 0)
#define KP_SCANCODE_0_CAM2              ((1 << 3) << 0)

#define USER_SEL_GOTO_MOBM              (0xFFFFFFFF - 0)
#define USER_SEL_GOTO_HWT               (0xFFFFFFFF - 1)
#define USER_SEL_GOTO_EBOOT1            (0xFFFFFFFF - 2)
#define USER_SEL_GOTO_EBOOT2            (0xFFFFFFFF - 3)
#define USER_SEL_GOTO_ULDR              (0xFFFFFFFF - 4)
#define USER_SEL_GOTO_CLEANBOOT         (0xFFFFFFFF - 5)
#define USER_SEL_GOTO_KITL              (0xFFFFFFFF - 6)

/*
    Display
*/

#define DISP_BK_CONTROL(p)              PWM3_OutControl(p)


#define OVERLAY2_MODE_YUV
//#define OVERLAY2_MODE_RGB

#define DISPLAY_RESOLUSION_VGA_PORTRAIT

#ifdef DISPLAY_RESOLUSION_VGA_PORTRAIT
#define LCD_WIDTH                       480
#define LCD_HEIGHT                      640

#define LCCR1_BLW_BEGIN_OF_LINE_WAIT    79
#define LCCR1_ELW_END_OF_LINE_WAIT      80
#define LCCR1_HSW_LSYNC_PULSE_WIDTH     7

#define LCCR2_BFW_BEGIN_OF_FRAME_WAIT   2
#define LCCR2_EFW_END_OF_FRAME_WAIT     6
#define LCCR2_VSW_FSYNC_PULSE_WIDTH     0

#define LCCR3_PCP_PIXEL_CLK_POLARITY    PCP_PIXEL_CLK_DATA_ON_FALLING
#define LCCR3_HSP_HORI_SYNC_POLARITY    HSP_HSYNC_ACTIVE_LOW
#define LCCR3_VSP_VERT_SYNC_POLARITY    VSP_VSYNC_ACTIVE_LOW

#define LCCR3_BPP_BIT_PER_PIXEL         BPP_16BIT_PER_PIXEL

#define LCCR3_PCD_PIXEL_CLK_DIVIDE      1
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
#define SSP_AUDIO_PLAY                  SSP_ID_3
#define SSP_AUDIO_RECORD                SSP_ID_4


