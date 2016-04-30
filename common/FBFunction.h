
#define INCLUDE_MODULE_FBFunction

typedef struct{
    U32 m_dwWidth;
    U32 m_dwHeight;
    U32 m_FBAddress;
    U16 s_BkColor;
    U16 s_FrColor;
}FB_Context_t;

void FB_Clear(const FB_Context_t *pParameter, U32 dwStartX, U32 dwStartY, U32 dwWidth, U32 dwHeight);
void FB_PutChar(const FB_Context_t *pParameter, U32 dwStartX, U32 dwStartY, char cChar);
void FB_PutString(const FB_Context_t *pParameter, U32 dwStartX, U32 dwStartY, U8 *pString);
void FB_Scroll(const FB_Context_t *pParameter, U32 dwLines);

