/*
*/

#include "_platform.h"

void SO_TraceByte(PCallBackSOPutChar_t pCallBack, U8 data)
{
    U8 d;

    d = data >> 4;
    d &= 0xf;
    if (d > 9)
        d += ('A' - 0xA);
    else
        d += '0';
    pCallBack(d);

    d = data & 0xf;
    if (d > 9)
        d += ('A' - 0xA);
    else
        d += '0';
    pCallBack(d);
}

void SO_TraceHex(PCallBackSOPutChar_t pCallBackChar, PCallBackSOPutString_t pCallBackStr, U8 *pszTitle, U32 v, U32 size)
{
    U8 *p;
    int i;

    if(pszTitle)
    {
        pCallBackStr("\r\n");
        pCallBackStr(pszTitle);
        pCallBackStr(": 0x");
    }

    p = (U8 *)(&v);

    for(i=(size-1);i>=0;i--)
    {
        SO_TraceByte(pCallBackChar, p[i]);
    }

    pCallBackStr(" ");
}

void SO_TraceDec(PCallBackSOPutString_t pCallBack, U8 *pszTitle, U32 v)
{
    char s[12];
    int i;

    MemSet(s, '0', sizeof(s));

    if(pszTitle)
    {
        pCallBack("\r\n");
        pCallBack(pszTitle);
        pCallBack(": ");
    }

    if(v == 0)
    {
        pCallBack("0");
        return;
    }

    i=sizeof(s) - 1;
    s[i--] = '\0';

    for(;v>0;i--)
    {
        s[i] = ((v%10) + '0');
        v = v / 10;

        if(i==0) return;
    }

    pCallBack((U8*)(s + i + 1));
}

