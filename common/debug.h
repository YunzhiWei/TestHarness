/*
    Public Data Structure
    Public Functions
    Export to other Modules
*/

#define INCLUDE_MODULE_DEBUG

void __DBG_InitialUART(void);
void __DBG_InitialUSB(void);

BOOL __DBG_IsDataReady(void);
U8   __DBG_GetChar(void);
void __DBG_PutChar(U8 c);
void __DBG_TraceString(U8 *line);
void __DBG_TraceStrLine(U8 *line);

void __DBG_TraceMem(U8 *str, U8 *pAddr, U32 dwLen);

U32  __DBG_GetHex(char *pszTitle, U32 lLength, U32 dwDefaultValue);
U32  __DBG_GetDec(char *pszTitle, U32 lLength, U32 dwDefaultValue);
U32  __DBG_GetString(char *pszTitle, U32 lLength, char *pString);

void __DBG_BreakPoint(char *pszTitle);
void __DBG_CountDown(U32 t);

