
#include "NTIM.h"

/*
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    Please DO REMEMBER removing the 8 dummy bytes at the beginning of the NTIM.bin

    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

static NTIM_Image image =
{
    {   // Header
        0x00030102,
        {'H','M','I','T'},
        0x00000000,
        0x11032006,
        0xDEADBEEF,

        {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF},

        0x4E414E04,

        (sizeof(NTIM_Image) - sizeof(NTIM_Header)) / sizeof(NTIM_Section),

        0x00000000,

        0x00000000
    },
    {   // Section[2]
        {
            {'H','M','I','T'},
            {'I','M','B','O'},
            0x00000000,                 // NAND Block[0]
            0x5C008000,
            sizeof(NTIM_Image),
            {0x00000000,0x00000000,0x6A15B7D3,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000}
        },
        {
            {'I','M','B','O'},
            {(U8)(-1), (U8)(-1), (U8)(-1), (U8)(-1)},
            0x00020000,                 // NAND Block[1]
            0x5C020000,
#include "__ImageSize.c"
            ,

            {0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000}
        }
/*
        ,
        {
            {'O','L','S','O'},
            {(U8)(-1), (U8)(-1), (U8)(-1), (U8)(-1)},
            0x00040000,
            0x83F00000,
            0x000152E4,
            {0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000}
        }
*/
    }
};

