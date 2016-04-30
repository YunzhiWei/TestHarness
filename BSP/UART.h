
/*
    Basic Functions
    Supported by other Modules
*/

/*
    Public Data Structure
    Public Functions
    Export to other Modules
*/

#define UART_FLOW_CONTROL_AUTO          (MCR_AFE | MCR_RTS)

void UART_Initial(UART_ID_T tID, U32 dwBaud, U32 dwEPSPEN, U32 dwMCR);

void    UART_PutChar(UART_ID_T tID, U8 c);
void    UART_PutString(UART_ID_T tID, char *str);

U8      UART_GetChar(UART_ID_T tID);
BOOL    UART_IsDataReady(UART_ID_T tID);

