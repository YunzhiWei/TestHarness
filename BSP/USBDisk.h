/*

*/

#ifdef INCLUDE_MODULE_U2D

#define INCLUDE_MODULE_UDSK

#define UDSK_EP_INDEX_BULK_IN           U2D_EP_ID_H
#define UDSK_EP_INDEX_BULK_OUT          U2D_EP_ID_A

void USB_EP0PkgUnknownUDSK(StandardRequest_t *pRequest);
void USB_OnOutPkgCompleteUDSK(void);
void USB_DiskInitial(void);

#endif

