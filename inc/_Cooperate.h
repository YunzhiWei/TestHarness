
/*
    State Flag for State Machine of whole device
*/
#define PSPR_DEFAULT                    0                   // !!! '0' is the DEFAULT value of PSPR and Kernel is the DEFAULT target we want to go !!!

#define PSPR_MASK_FLAG                  (0xFF000000)
#define PSPR_MASK_STYLE                 (0x00FFFF00)
#define PSPR_MASK_PARAMETER             (0x000000FF)

#define PSPR_FLAG_USB_KITL              (1u << 31)
#define PSPR_FLAG_FMD_CLEANBOOT         (1u << 30)

#define PSPR_STYLE_GOTO                 (0x4754 << 8)

#define PSPR_GOTO_MOBM                  (PSPR_STYLE_GOTO | 0)
#define PSPR_GOTO_HWTESTER              (PSPR_STYLE_GOTO | 1)
#define PSPR_GOTO_EBOOT                 (PSPR_STYLE_GOTO | 2)
#define PSPR_GOTO_ULDR                  (PSPR_STYLE_GOTO | 3)
#define PSPR_GOTO_WM_RESUME             (PSPR_STYLE_GOTO | 4)
#define PSPR_GOTO_WM_RESET              (PSPR_STYLE_GOTO | 5)

/*
    Display Frame Buffer Address
*/

#define DISP_FRAME_BUFFER_ADDRESS       0x80000000

/*
    Flash Memory Map
    Used by Update module in HWTester
*/
#define UPD_STORE_POS_BLOCK_ID_NTIM     0
#define UPD_STORE_POS_SECTOR_ID_NTIM    0
#define UPD_STORE_BLOCK_NUMBER_NTIM     1
#define UPD_STORE_RAM_ADDRESS_NTIM      BUFFER_SHARED_UNION_BASE

#define UPD_STORE_POS_BLOCK_ID_TABLE    0
#define UPD_STORE_POS_SECTOR_ID_TABLE   (NAND_SECTOR_NUMBER_PER_BLOCK - 1)

#define UPD_STORE_POS_BLOCK_ID_MOBM     1
#define UPD_STORE_BLOCK_NUMBER_MOBM     1
#define UPD_STORE_RAM_ADDRESS_MOBM      BUFFER_SHARED_UNION_BASE
// EXE_IMG_BASE !!! We cannot load the image into EXE_IMG_BASE, because the current program is running on this space.

#define UPD_STORE_POS_BLOCK_ID_HWTESTER 2
#define UPD_STORE_BLOCK_NUMBER_HWTESTER 1
#define UPD_STORE_RAM_ADDRESS_HWTESTER  BUFFER_SHARED_UNION_BASE
// EXE_IMG_BASE !!! We cannot load the image into EXE_IMG_BASE, because the current program is running on this space.

#define UPD_STORE_POS_BLOCK_ID_SCREEN   3
#define UPD_STORE_BLOCK_NUMBER_SCREEN   2
#define UPD_STORE_RAM_ADDRESS_SCREEN    DISP_FRAME_BUFFER_ADDRESS

#define UPD_STORE_POS_BLOCK_ID_IPL      5
#define UPD_STORE_BLOCK_NUMBER_IPL      1
#define UPD_STORE_RAM_ADDRESS_IPL       0x83900000

#define UPD_STORE_POS_BLOCK_ID_EBOOT    6
#define UPD_STORE_BLOCK_NUMBER_EBOOT    2
#define UPD_STORE_RAM_ADDRESS_EBOOT     0x87C00000

#define UPD_STORE_POS_BLOCK_ID_8        8
#define UPD_STORE_BLOCK_NUMBER_8        1
#define UPD_STORE_RAM_ADDRESS_8         BUFFER_SHARED_UNION_BASE
#define UPD_STORE_POS_BLOCK_ID_9        9
#define UPD_STORE_BLOCK_NUMBER_9        1
#define UPD_STORE_RAM_ADDRESS_9         BUFFER_SHARED_UNION_BASE

#define UPD_STORE_POS_BLOCK_ID_IMAGE    10

/*
    Data Structure in CE
*/

typedef struct{
    U32 ddlfirst;
    U32 ddllast;
    U32 physfirst;
    U32 physlast;
}ROMHDR_t __attribute__ ((aligned (4)));


