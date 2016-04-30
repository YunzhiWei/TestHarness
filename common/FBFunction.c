
#include "_Platform.h"
#ifdef  INCLUDE_MODULE_FBFunction

#ifdef FONT_SELECT_8X12
#include "Font_8x12.c"
#endif
#ifdef FONT_SELECT_11X17
#include "Font_11x17.c"
#endif
#ifdef FONT_SELECT_32X18
#include "Font_32x18.c"
#endif

void FB_Clear(const FB_Context_t *pParameter, U32 dwStartX, U32 dwStartY, U32 dwWidth, U32 dwHeight)
{
    U32 i,j;
    U16 *p;
    U16 *pAddr;

    pAddr = (U16*)(pParameter->m_FBAddress +(dwStartY * pParameter->m_dwWidth + dwStartX) * sizeof(U16));

    for(i=0;i<dwHeight;i++)
    {
        p = pAddr;

        for(j=0;j<dwWidth;j++)
        {
            *p++ = pParameter->s_BkColor;
        }

        pAddr += pParameter->m_dwWidth;
    }
}

void FB_PutChar(const FB_Context_t *pParameter, U32 dwStartX, U32 dwStartY, const char cChar)
{
    FONTLINEUNIT *pfont;
    FONTLINEUNIT mask;
    U16 *pfbtarget;

    U32 i, j, k;

    // Here should test if the target buffer address are all valid for Frame Buffer
    // It is dangerous if the writting action access any memory out of Frame Buffer
    {
        pfont = (FONTLINEUNIT *)(&(g_Font[cChar - ' '][0]));

        pfbtarget = (U16*)(pParameter->m_FBAddress +(dwStartY * pParameter->m_dwWidth + dwStartX) * sizeof(U16));

        for(i=0; i<FONT_CHAR_LINE_PER_CHAR; i++)
        {
            FONT_MASK_INITIAL(mask);

            for(j=0; j<FONT_CHAR_BIT_PER_LINE; j++)
            {
                if(pfont[i] & mask)
                {
                    pfbtarget[j] = pParameter->s_FrColor;
                }
                else
                {
                    pfbtarget[j] = pParameter->s_BkColor;
                }
                FONT_MASK_NEXT(mask);
            }
            pfbtarget += pParameter->m_dwWidth;
        }
    }
}

void FB_PutString(const FB_Context_t *pParameter, U32 dwStartX, U32 dwStartY, U8 *pString)
{
    while(pString[0] != '\0')
    {
        FB_PutChar(pParameter, dwStartX, dwStartY, pString[0]);

        pString++;
        dwStartX += FONT_CHAR_BIT_PER_LINE;
        if((dwStartX + FONT_CHAR_BIT_PER_LINE) >= (pParameter->m_dwWidth) )
        {
            dwStartY += FONT_CHAR_LINE_PER_CHAR;
        }
    }
}

void FB_Scroll(const FB_Context_t *pParameter, U32 dwLines)
{
    U32 x, y;
    U16 *src, *dst;

    if((dwLines==0) || (dwLines > pParameter->m_dwHeight))
    {
        return;
    }

    MemCopy((void*)pParameter->m_FBAddress, (void*)(pParameter->m_FBAddress + dwLines * pParameter->m_dwWidth * sizeof(U16)),(pParameter->m_dwHeight - dwLines) * pParameter->m_dwWidth *sizeof(U16));
    FB_Clear(pParameter, 0, pParameter->m_dwHeight - dwLines, pParameter->m_dwWidth, dwLines);
}

#endif

