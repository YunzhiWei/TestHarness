/*
;      --- Virtual Offset ---- 0 0 0 0 0 0 0 X -AP 0 -Domain 0 C B 1 0     <---- 1MB page descriptor
;
;
;
;    X     C     B
;    0     0     0       IO Cycle, stall until complete
;    0     0     1       Write merging, but uncached
;    0     1     0       Buffering, cache Write-Through mode, read allocate
;    0     1     1       Regular Caching, Write-Back mode, read allocate
;
;    1     0     0       Unpredictable
;    1     0     1       Buffer Writes, but don't coalesce
;    1     1     0       Mini D-Cache, (cache policy is determined by MD field of Auxillary Control Reg)
;    1     1     1       Same as X=0 with Read & Write Allocate
*/

#define MMU_MAPPING_TYPE_CATCH          0xE
#define MMU_MAPPING_TYPE_UNCATCH        0x2

typedef struct{
    U32     m_dwVirtual;
    U32     m_dwPhysical;
    U32     m_dwSize;                                       // in MB
    U8      m_bType;
}MMU_Mapping_t  __attribute__ ((aligned (4)));;

#define MMU_ADDR_MASK                   0xFFF00000
#define MMU_ADDR_FORMAT(addr)           (addr & MMU_ADDR_MASK) // MMU address must be 1MB align

U32 MMUTableSetup(const MMU_Mapping_t *pMMUMapping);
void MMUSetup(void);


