
// All
#define ERR_CODE_NONE                   (-1)
#define ERR_CODE_SUCCESS                ERR_CODE_NONE
#define ERR_CODE_DONE                   ERR_CODE_NONE

// XModem
#define ERR_CODE_XMD_INVALID            (-100 - 1)
#define ERR_CODE_XMD_TIMEOUT            (-100 - 2)
#define ERR_CODE_XMD_BLKNUM             (-100 - 3)
#define ERR_CODE_XMD_CHKSUM             (-100 - 4)
#define ERR_CODE_XMD_CANCEL             (-100 - 5)
#define ERR_CODE_XMD_OVERFLOW           (-100 - 6)

// NAND
#define ERR_CODE_NAND_PARAMETER         (-200 - 1)
#define ERR_CODE_NAND_TIMEOUT           (-200 - 2)
#define ERR_CODE_NAND_BADBLOCK          (-200 - 3)
#define ERR_CODE_NAND_DBERR             (-200 - 4)
#define ERR_CODE_NAND_SBERR             (-200 - 5)

// BBM
#define ERR_CODE_BBM_NOFOUND            (-300 - 1)
#define ERR_CODE_BBM_PARAMETER          (-300 - 2)
#define ERR_CODE_BBM_APPEND_FAIL        (-300 - 3)
#define ERR_CODE_BBM_WR_BACK_FAIL       (-300 - 4)

// Flash
#define ERR_CODE_FLASH_INVALID          (-400 - 1)
#define ERR_CODE_FLASH_FAIL             (-400 - 2)

// Update
#define ERR_CODE_UPD_PARAMETER          (-500 - 1)
#define ERR_CODE_UPD_INVALID            (-500 - 2)
#define ERR_CODE_UPD_BINREC_INVALID     (-500 - 3)
#define ERR_CODE_UPD_BINREC_CHKSUM      (-500 - 4)

// FAL
#define ERR_CODE_FAL_INVALID            (-600 - 1)

#define ERR_CODE_FAL_NORMAL             ( 600 + 1)
#define ERR_CODE_FAL_RESERVE            ( 600 + 2)
#define ERR_CODE_FAL_FFFFFFFF           ( 600 + 3)

// FAT
#define ERR_CODE_FAT_NOFOUND            (-700 - 1)
#define ERR_CODE_FAT_PARAMETER          (-700 - 2)
#define ERR_CODE_FAT_INVALID            (-700 - 3)
#define ERR_CODE_FAT_CLUID_BREAK        (-700 - 4)

#define ERR_CODE_FAT_EOF                ( 700 + 1)

// File System
#define ERR_CODE_FSYS_INVALID           (-800 - 1)

#define ERR_CODE_FSYS_FOUND             ( 800 + 1)

// SD Card
#define ERR_CODE_MMCSD_CMD_TIMEOUT      (-900 - 1)
#define ERR_CODE_MMCSD_RESP_CRC         (-900 - 2)
#define ERR_CODE_MMCSD_RESP_INVALID     (-900 - 3)
#define ERR_CODE_MMCSD_POWERUP_FAIL     (-900 - 4)

#define ERR_CODE_MMCSD_POWERUP_DONE     ( 900 + 1)

// Keypad
#define ERR_CODE_KP_NOKEY               (-1000 - 0)
#define ERR_CODE_KP_VALID               (-1000 - 1)
#define ERR_CODE_KP_SINGLE              (-1000 - 2)
#define ERR_CODE_KP_MULTI               (-1000 - 3)

// I2C
#define ERR_CODE_I2C_TIMEOUT            (-1100 - 0)
#define ERR_CODE_I2C_ARBI_LOSS          (-1100 - 1)

// PMIC
#define ERR_CODE_PMIC_PARAMETER         (-1200 - 0)

// WAV
#define ERR_CODE_WAV_FORMAT             (-1300 - 0)

