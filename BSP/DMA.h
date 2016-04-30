
#define INCLUDE_MODULE_DMA

typedef struct
{
    U32 m_dwDescLinkAddr;
    U32 m_dwSourceAddr;
    U32 m_dwTargetAddr;
    U32 m_dwCommand;
}DMA_Descriptor_t __attribute__ ((aligned (16)));

