
#include "_Platform.h"

/*
    Public Data Structure
    Public Functions
    Export to other Modules
*/

typedef struct
{
    U32 m_dwEntry[4 * 1024];
}MMU_Table_t __attribute__ ((aligned (16 * 1024)));         // ARM require: MMU Table Base Must be 16KB aligned

static MMU_Table_t g_MMUTable;

U32 MMUTableSetup(const MMU_Mapping_t *pMMUMapping)
{   // This function may be invoked before UART initial.
    // Do not use any DBG_xxx Function.

    U32 i;
    U32 size;
    U32 paddr;

    while((pMMUMapping->m_dwSize) != 0)
    {
        if(
            ((pMMUMapping->m_dwVirtual) & (~MMU_ADDR_MASK)) ||
            ((pMMUMapping->m_dwPhysical) & (~MMU_ADDR_MASK))
        )
        {
            while(1)
            {
                DBG_TraceStrLine("Address format error!");
            }
        }
        i = (pMMUMapping->m_dwVirtual)>>20;
        paddr = (pMMUMapping->m_dwPhysical) & MMU_ADDR_MASK | (pMMUMapping->m_bType);

        size = pMMUMapping->m_dwSize;
        while(size-- > 0)
        {   // each MB space
            g_MMUTable.m_dwEntry[i++] = paddr;
            paddr += 0x100000;
        }

        pMMUMapping++;
    }

    return((U32)(&g_MMUTable));
}

void MMUSetup(void)
{
    const MMU_Mapping_t vpMapping[] = {
        {MMU_ADDR_FORMAT(0x00000000),        MMU_ADDR_FORMAT(EXE_IMAGE_BASE),       1,                                  MMU_MAPPING_TYPE_UNCATCH},  // This program is running in this space and the vector table is at the beginning
        {MMU_ADDR_FORMAT(0x40000000),        MMU_ADDR_FORMAT(0x40000000),           512,                                MMU_MAPPING_TYPE_UNCATCH},  // 0x40000000 ~ 0x5FFFFFFF: MH IO registers
        {MMU_ADDR_FORMAT(SYS_SDRAM_BASE),    MMU_ADDR_FORMAT(PHISICAL_SDRAM_BASE),  PHISICAL_SDRAM_SIZE/(1024 * 1024),  MMU_MAPPING_TYPE_UNCATCH},  // We map all physical memory to logical virtual memory
        {0,0,0,0},                                          // End of MMU Table
    };

    MMUTableSetup(vpMapping);                               /* I have to do so!!! */
    MMUTableSetup(vpMapping);                               /* some time, if do this only once, the MMU may fail. */
    MMUBaseSet(MMUTableSetup(vpMapping));
    MMUEnable();
}


