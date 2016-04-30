
#include "_Platform.h"

static UART_REGs_t *uart[] = {
    (UART_REGs_t *)MH_UART1_BASE,
    (UART_REGs_t *)MH_UART2_BASE,
    (UART_REGs_t *)MH_UART3_BASE
};

// 0: Positive Pulse for Zero, Pulse Width = 3/16
#define ISR_DEFAULT_VALUE               (ISR_RXPL | ISR_TXPL)

void UART_Initial(UART_ID_T tID, U32 dwBaud, U32 dwEPSPEN, U32 dwMCR)
{
    // Disable UART and all of the interrupt, DMA & NRZ coding
    uart[tID]->ier = 0;

    // 1 bit stop, 8 bit data
    uart[tID]->lcr = dwEPSPEN | (0 * LCR_STB) | (3 * LCR_WLS);

    // set baud rate
    {
#define UARTCLK                         14745600

        U32 divisor;

        divisor = (UARTCLK >> 4) / dwBaud;

        uart[tID]->lcr  |=  LCR_DLAB;   // Access Baud Rate Registers instead of Data Buffer and IER
        uart[tID]->udata =  divisor & 0xFF;
        uart[tID]->ier   =  (divisor & 0xFF00) >> 8;
        uart[tID]->lcr  &=~ LCR_DLAB;   // Access Data Buffer and IER
    }

    uart[tID]->isr = 0;
    uart[tID]->mcr = dwMCR;

#define TRIGGER_LEVEL_1BYTE         0
#define TRIGGER_LEVEL_8BYTE         1
#define TRIGGER_LEVEL_16BYTE        2
#define TRIGGER_LEVEL_132BYTE       3

    // Enalbe and reset the Rx & Tx FIFO
    // Set Interrupt Trigger Level
    uart[tID]->fcr = (TRIGGER_LEVEL_8BYTE * FCR_ITL)|(FCR_TRFIFOE | FCR_RESETRF | FCR_RESETTF);

#undef TRIGGER_LEVEL_1BYTE
#undef TRIGGER_LEVEL_8BYTE
#undef TRIGGER_LEVEL_16BYTE
#undef TRIGGER_LEVEL_132BYTE

    // Enable UART
    uart[tID]->ier = IER_UUE;

    // Data Terminal Ready    uart[iID]->mcr = MCR_DTR;
}

void UART_PutChar(UART_ID_T tID, U8 c)
{
    while ((uart[tID]->lsr & LSR_TDRQ) == 0)
    {  ;  }

    uart[tID]->udata = c;
}

void UART_PutString(UART_ID_T tID, char *str)
{
    while(*str != '\0')
    {
        while ((uart[tID]->lsr & LSR_TDRQ) == 0)
        {  ;  }

        uart[tID]->udata = *str++;
    }
}

U8 UART_GetChar(UART_ID_T tID)
{
    while ((uart[tID]->lsr & LSR_DR) == 0)
    {
        ;
    }

    return((uart[tID]->udata) & 0xff);
}

BOOL UART_IsDataReady(UART_ID_T tID)
{
    return((uart[tID]->lsr & LSR_DR) == LSR_DR);
}

