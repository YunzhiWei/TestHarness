
#include "_Platform.h"

#ifdef INCLUDE_MODULE_CONSOLE

#ifdef FONT_SELECT_8X12
#define CHAR_HEIGHT                     16
#define CHAR_WIDTH                      8
#endif
#ifdef FONT_SELECT_11X17
#define CHAR_HEIGHT                     20
#define CHAR_WIDTH                      11
#endif
#ifdef FONT_SELECT_32X18
#define CHAR_HEIGHT                     20
#define CHAR_WIDTH                      32
#endif

#define CONSOLE_FB_WIDTH                LCD_WIDTH
#define CONSOLE_FB_HEIGHT               LCD_HEIGHT
#define CONSOLE_FB_ADDRESS              FB_BASE_RGB565_ADDR
static const FB_Context_t fb = {
    CONSOLE_FB_WIDTH,
    CONSOLE_FB_HEIGHT,
    CONSOLE_FB_ADDRESS,
    GetRGB565(0, 0, 0),
    GetRGB565((U32)(-1), (U32)(-1), (U32)(-1))
};

static U32 g_dwCurrentX, g_dwCurrentY;

inline void CS_PutChar(char cInput)
{
    if(cInput == '\r')
    {
        g_dwCurrentX = 0;
        return;
    }
    else if(cInput == '\n')
    {
        if(g_dwCurrentY >= (CONSOLE_FB_HEIGHT - CHAR_HEIGHT))
        {
            FB_Scroll(&fb, CHAR_HEIGHT);
        }
        else
        {
            g_dwCurrentY += CHAR_HEIGHT;
        }
        return;
    }
    else if((cInput < ' ') || (cInput > 'z'))
    {
        return;
    }
    else
    {
        FB_PutChar(&fb, g_dwCurrentX, g_dwCurrentY, cInput);
        g_dwCurrentX += CHAR_WIDTH;
        if(g_dwCurrentX >= CONSOLE_FB_WIDTH)
        {
            g_dwCurrentX = 0;
            if(g_dwCurrentY >= (CONSOLE_FB_HEIGHT - CHAR_HEIGHT))
            {
                FB_Scroll(&fb, CHAR_HEIGHT);
            }
            else
            {
                g_dwCurrentY += CHAR_HEIGHT;
            }
        }
    }
}

void CS_PutString(char *sString)
{
    while(sString[0] != '\0') CS_PutChar(*sString++);
}

void CS_PutStrLine(char *sString)
{
    CS_PutString("\r\n");
    CS_PutString(sString);
}

void CS_Initial(void)
{
    FB_Clear(&fb, 0, 0, fb.m_dwWidth, fb.m_dwHeight);

    g_dwCurrentX = 0; g_dwCurrentY = 0;
}

#endif


