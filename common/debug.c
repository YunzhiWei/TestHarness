/*
*/

#include "_platform.h"

#ifdef INCLUDE_MODULE_DEBUG

#define __DBG_Wait1Second               msSleep(1000);
#define __DBG_MemSet(p1, p2, p3)        MemSet(p1, p2, p3);

typedef U8                              (*F_GetChar_t)(void);
typedef void                            (*F_PutChar_t)(U8);
typedef BOOL                            (*F_IsDataReady_t)(void);

static F_GetChar_t                      g_fGetChar;
static F_PutChar_t                      g_fPutChar;
static F_IsDataReady_t                  g_fIsDataReady;

//////////////////////////////////////////////////////////////////////////

static BOOL _IsUARTDataReady(void)
{
    return(UART_IsDataReady(UART_ID_DBG));
}

static U8 _GetUARTChar(void)
{
    return(UART_GetChar(UART_ID_DBG));
}

static void _PutUARTChar(U8 c)
{
    UART_PutChar(UART_ID_DBG, c);
}

static BOOL _IsUSERDataReady(void)
{
    return(0 != SERIAL_ValidDataSize());
}

static U8 _GetUSERChar(void)
{
    return(SERIAL_GetChar());
}

static void _PutUSERChar(U8 c)
{
    SERIAL_PutChar(c);
}

void __DBG_InitialUART(void)
{
    g_fGetChar     = _GetUARTChar;
    g_fPutChar     = _PutUARTChar;
    g_fIsDataReady = _IsUARTDataReady;
}

void __DBG_InitialUSB(void)
{
    g_fGetChar     = _GetUSERChar;
    g_fPutChar     = _PutUSERChar;
    g_fIsDataReady = _IsUSERDataReady;
}

BOOL __DBG_IsDataReady(void)
{
    return(g_fIsDataReady());
}

U8 __DBG_GetChar(void)
{
    return(g_fGetChar());
}

void __DBG_PutChar(U8 c)
{
    g_fPutChar(c);
}

void __DBG_TraceString(U8 *line)
{
    while (*line)
    {
        __DBG_PutChar(*(line++));
    }
}

void __DBG_TraceStrLine(U8 *line)
{
    __DBG_TraceString ("\r\n");
    __DBG_TraceString (line);
}

void __DBG_CountDown(U32 t)
{
    __DBG_PutChar('\r');
    __DBG_PutChar('\n');
    while(t)
    {
        __DBG_PutChar('\r');
        __DBG_PutChar('0' + t--);
        __DBG_Wait1Second;
    }
    __DBG_PutChar('\r');
    __DBG_PutChar('\n');
}

void __DBG_TraceMem(U8 *str, U8* pAddr, U32 dwLen)
{
    U32 l;

    __DBG_TraceString("\r\n");
    __DBG_TraceString(str);
    __DBG_TraceString("\r\nESC to return");

    while(1)
    {
        if(__DBG_GetChar() == ASCII_CODE_ESC) break;

        __DBG_TraceString("\r\n[");
        DBG_TraceHex(NULL, (U32)pAddr);
        __DBG_TraceString("]");
        for(l=0;l<dwLen;l++)
        {
            __DBG_PutChar('0');
            __DBG_PutChar('x');
            DBG_TraceByte(*pAddr++);
            __DBG_PutChar(',');
            __DBG_PutChar(' ');
        }
    }

    __DBG_TraceString("\r\n");
}

U32 __DBG_GetHex(char *pszTitle, U32 lLength, U32 dwDefaultValue)
{
    U8  c, c0;
    U32 v;

    __DBG_TraceString("\r\nGetHex: ");
    DBG_TraceHex((U8*)pszTitle, lLength);

    for(v=0;lLength>0;lLength--){
        c0 = c = __DBG_GetChar();
        if(c==ASCII_CODE_ESC)
        {
            v = dwDefaultValue;
            break;
        }
        if((c=='\r')||(c=='\n')){
            break;
        }

        if((c>='0')&&(c<='9')) c=c-'0';
        else if((c>='A')&&(c<='F')) c=c-'A'+10;
        else if((c>='a')&&(c<='f')) c=c-'a'+10;
        else{
            lLength++;
            continue;
        }

        __DBG_PutChar(c0);
        v<<=4;
        v|=c;
    }

    DBG_TraceHex("OK! Got: ", v);
    return(v);
}

U32 __DBG_GetDec(char *pszTitle, U32 lLength, U32 dwDefaultValue)
{
    U8  c;
    U32 v;

    __DBG_TraceString("\r\nGetDec: ");
    DBG_TraceHex((U8*)pszTitle, lLength);

    for(v=0;lLength>0;lLength--){
        c = __DBG_GetChar();
        if(c==ASCII_CODE_ESC)
        {
            v = dwDefaultValue;
            break;
        }
        if((c=='\r')||(c=='\n')){
            break;
        }

        if((c<'0') || (c>'9'))
        {
            lLength++;
            continue;
        }

        __DBG_PutChar(c);
        v *= 10;
        v += c - '0';
    }

    DBG_TraceDec("OK! Got: ", v);
    return(v);
}

U32 __DBG_GetString(char *pszTitle, U32 lLength, char *pString)
{
    U32 i;

    __DBG_TraceString("\r\nGetString: ");
    DBG_TraceHex((U8*)pszTitle, lLength);

    for(i=0;i < lLength;i++){
        pString[i] = __DBG_GetChar();
        if(pString[i] == '\n' || pString[i] == '\r')
        {
            pString[i] = '\0';
            break;
        }
        else if(pString[i] == ASCII_CODE_ESC)
        {
            i = 0;
            pString[0] = '\0';
            break;
        }
        else
        {
            __DBG_PutChar(pString[i]);
        }
    }
    pString[i] = '\0';

    DBG_TraceDec("OK! Got: ", i);
    __DBG_TraceStrLine(pString);
    return(i);
}

void __DBG_BreakPoint(char *pszTitle)
{
    if(pszTitle)
    {
        __DBG_TraceString("\r\n\r\n");
        __DBG_TraceString((U8*)pszTitle);
    }
    else
    {
        __DBG_TraceString("\r\n\r\nPress any key to continue!");
    }
    __DBG_GetChar();
    __DBG_PutChar('\r');
}

/*
void __DBG_Pringtf(const U8 *szFmt, ...)
{
    U8      c;
    BOOL    f;
    va_list vl;

    va_start(vl, szFmt);

    f = FALSE;
    while(c = *szFmt++)
    {
        if(f)
        {
            switch (c) {
            case 'B':
            case 'b':
                {
                    U8  v;
                    v = va_arg(vl, U8);
                    __DBG_TraceByte(v);
                }
                break;
            case 'W':
            case 'w':
                {
                    U16  v;
                    U8*  p;

                    v = va_arg(vl, U16);
                    p = &v;

                    __DBG_TraceByte(p[1]);
                    __DBG_TraceByte(p[0]);
                }
                break;
            case 'X':
            case 'x':
                {
                    U32  v;
                    U8*  p;

                    v = va_arg(vl, U32);
                    p = &v;

                    __DBG_TraceByte(p[3]);
                    __DBG_TraceByte(p[2]);
                    __DBG_TraceByte(p[1]);
                    __DBG_TraceByte(p[0]);
                }
                break;
            case 'D':
            case 'd':
                {
                    char s[12];
                    int i;
                    int  v;

                    v = va_arg(vl, int);

                    __MemSet(s, '0', sizeof(s));
                    i = sizeof(s) - 1;
                    s[i--] = '\0';

                    if(v == 0)
                    {
                        i--;
                    }
                    else
                    {
                        for(;v>0;i--)
                        {
                            s[i] = ((v%10) + '0');
                            v = v / 10;

                            if(i==0)
                            {
                                __DBG_TraceString("\r\n error!\r\n");
                                break;
                            }
                        }
                    }

                    __DBG_TraceString(s + i + 1);
                }
                break;
            default:
                __DBG_PutChar('%');
                __DBG_PutChar(c);
                break;
            }

            f = FALSE;
            continue;
        }

        if(c == '%')
        {
            f = TRUE;
            continue;
        }
        else
        {
            __DBG_PutChar(c);
        }
    }

    va_end(vl);
}
*/

#endif

