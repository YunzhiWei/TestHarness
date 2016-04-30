
// UART

typedef enum
{
    UART_ID_1 = 0,                      // Full function
    UART_ID_2 = 1,                      // BT UART
    UART_ID_3 = 2                       // BT UART
}UART_ID_T;

typedef struct s_UART_REGs {
    volatile U32    udata;              // 0000 Receive Buffer Reg. (RBR), Transmit Holding Reg. (THR) and DLL
    volatile U32    ier;                // 0004 Interrupt Enable Reg. (IER) and Baud Divisor Higher Byte Reg. (DLH)
    volatile U32    fcr;                // 0008 Interrupt ID Reg. (read only) and FIFO Control Reg. (write only)
    volatile U32    lcr;                // 000C Line Control Reg.
    volatile U32    mcr;                // 0010 Modem Control Reg.
    volatile U32    lsr;                // 0014 Line Status Reg.
    volatile U32    msr;                // 0018 Modem Status Reg.
    volatile U32    spr;                // 001C Scratch Pad Reg.
    volatile U32    isr;                // 0020 Slow Infrared Select Reg.
    volatile U32    rfor;               // 0024 Byte count: number of bytes remaining in the receive FIFO
    volatile U32    abr;                // 0028 Autobaud Control
    volatile U32    acr;                // 002C Autobaud Count
}UART_REGs_t;

// LCD

typedef struct
{
    U32 dwNextDescAddr;
    U32 dwSourceAddr;
    U32 dwFrameID;
    U32 dwLCDCmd;
}LCD_DMA_Descriptor_t __attribute__ ((aligned (16)));

#define LCD_DMA_DESC_SIZE               sizeof(LCD_DMA_Descriptor_t)

// QCI

typedef struct
{
    U32 dwNextDescAddr;
    U32 dwSourceAddr;
    U32 dwTargetAddr;
    U32 dwCIFCmd;
}CIF_DMA_Descriptor_t __attribute__ ((aligned (16)));

#define CIF_DMA_DESC_SIZE               sizeof(CIF_DMA_Descriptor_t)

// U2D

#define U2D_ENDPOINT_NUMBER             16

typedef enum
{
    U2D_EP_ID_0 = 0,
    U2D_EP_ID_A = 1,
    U2D_EP_ID_B = 2,
    U2D_EP_ID_C = 3,
    U2D_EP_ID_D = 4,
    U2D_EP_ID_E = 5,
    U2D_EP_ID_F = 6,
    U2D_EP_ID_G = 7,
    U2D_EP_ID_H = 8,
    U2D_EP_ID_I = 9,
    U2D_EP_ID_J = 10,
    U2D_EP_ID_K = 11,
    U2D_EP_ID_L = 12,
    U2D_EP_ID_M = 13,
    U2D_EP_ID_N = 14,
    U2D_EP_ID_O = 15,
    U2D_EP_ID_LIMIT = U2D_ENDPOINT_NUMBER,
}U2D_EP_ID_e;

typedef struct s_U2D_DMA_REGs {
    volatile U32 m_dwDescAddr;
    volatile U32 m_dwSourceAddr;
    volatile U32 m_dwTargetAddr;
    volatile U32 m_dwCommandAddr;
}U2D_DMA_REGs_t;


