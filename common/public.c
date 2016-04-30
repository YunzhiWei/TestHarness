
#include "_Platform.h"

/*
    Public Data Structure
    Public Functions
    Export to other Modules
*/

void ErrCodeDisplay(int iCode)
{
    DBG_TraceStrLine("ERROR CODE: ");

    if(iCode < 0)
    {
        iCode = abs(iCode);
        DBG_PutChar('-');
    }

    DBG_TraceDec(NULL, iCode);
}

void StrUpperCase(char *pStr)
{
    while(pStr[0] != '\0')
    {
        if(pStr[0] >= 'a' && pStr[0] <= 'z')
        {
            pStr[0] &=~ 0x20;
        }
        pStr++;
    }
}

void StrLowerCase(char *pStr)
{
    while(pStr[0] != '\0')
    {
        if(pStr[0] >= 'A' && pStr[0] <= 'Z')
        {
            pStr[0] |= 0x20;
        }
        pStr++;
    }
}

void StrCopy(char *pDest, char *pSour)
{
    while(*pSour != '\0')
    {
        *pDest++ = *pSour++;
    }
    *pDest = *pSour;
}

int StrLength(const char *pString)
{
    int i;

    for(i = 0;*pString++ != '\0';i++)
    {
    }
    return(i);
}

int StrCompare(const char *pDest, const char *pSour)
{
    int i;

    for(i=0;pDest[i] != '\0';i++)
    {
        if(pDest[i] != pSour[i]) return(i + 1);
    }
    return(0);
}

int MemCompare(PBYTE pDest, PBYTE pSour, int iSize)
{
    int i;

    for(i=0;i<iSize;i++)
    {
        if(pDest[i] != pSour[i]) break;
    }
    return (iSize - i);
}

void MemCopy(PBYTE pDest, PBYTE pSour, int iSize)
{
    int i;

    for(i=0;i<iSize;i++)
    {
        pDest[i] = pSour[i];
    }
}

void MemSet(PBYTE pDest, BYTE v, int iSize)
{
    int i;

    for(i=0;i<iSize;i++)
    {
        pDest[i] = v;
    }
}

U32 MemSum(PBYTE pData, int iSize, U32 dwSum)
{
    while(iSize-- > 0)
    {
        dwSum += *pData++;
    }

    return(dwSum);
}

void GetYUV(U8 *bColorY, U8 *bColorU, U8 *bColorV)
{
#define RGB_2_YUV_DIV_RATIAL            10000
#define RGB_2_YUV_U_OFFSET              128
#define RGB_2_YUV_V_OFFSET              128

    U8 r,g,b;
    U32 y, u, v;

    r = DBG_GetHex("r", 2);
    g = DBG_GetHex("g", 2);
    b = DBG_GetHex("b", 2);

    y = (2990u * r + 5780 *g + 1140 * b)/RGB_2_YUV_DIV_RATIAL;
    u = (5000u * r - 4187 *g - 813  * b)/RGB_2_YUV_DIV_RATIAL + RGB_2_YUV_U_OFFSET;
    v = (1687u * r - 3313 *g + 5000 * b)/RGB_2_YUV_DIV_RATIAL + RGB_2_YUV_V_OFFSET;

    *bColorY = ((U8)y);
    *bColorU = ((U8)u);
    *bColorV = ((U8)v);
}

