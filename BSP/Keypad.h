
#define INCLUDE_MODULE_KEYPAD

#define KP_SCAN_CODE_NUMBER                   4

void KP_Initial(void);

int  KP_MatrixScan(U32 *pdwRow, U32 *pdwCol, U32 *pdwScanMap);
char KP_MatrixTranslate(U32 dwRow, U32 dwCol);

void KP_INTHandler(void);
void KP_INTEnable(void);
void KP_INTDisable(void);

