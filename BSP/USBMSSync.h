/*

*/

#ifdef INCLUDE_MODULE_U2D

#define INCLUDE_MODULE_MSSYNC

#define MSSYNC_EP_INDEX_BULK_IN         U2D_EP_ID_I
#define MSSYNC_EP_INDEX_BULK_OUT        U2D_EP_ID_B

void USB_OnOutPkgCompleteMSSYNC(void);
void USB_EP0PkgUnknownMSSYNC(StandardRequest_t *pRequest);

void USB_MSSyncInitial(void);

#endif


