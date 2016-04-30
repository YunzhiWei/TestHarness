/*

*/

#ifdef INCLUDE_MODULE_U2D

#define INCLUDE_MODULE_SERIAL

#define SERIAL_EP_INDEX_INT_IN          U2D_EP_ID_J
#define SERIAL_EP_INDEX_BULK_IN         U2D_EP_ID_K
#define SERIAL_EP_INDEX_BULK_OUT        U2D_EP_ID_C

void SERIAL_Send(PU8 pdwBuffer, U32 dwSize);
U32  SERIAL_Receive(PU8 pbBuffer, U32 dwSize);
U32  SERIAL_ValidDataSize(void);

void SERIAL_PutChar(U8 c);
U8   SERIAL_GetChar(void);
void SERIAL_Dump(void);

void USB_EP0PkgUnknownSerial(StandardRequest_t *pRequest);
void USB_OnOutPkgCompleteSerial(void);
void USB_SerialInitial(void);

#endif

