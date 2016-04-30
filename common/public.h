
#define ASCII_CODE_ESC                  0x1B
#define ASCII_CODE_NAK                  0x15

void ErrCodeDisplay(int iCode);

void StrUpperCase(char *pStr);
void StrLowerCase(char *pStr);
void StrCopy(char *pDest, char *pSour);
int  StrLength(const char *pString);
int  StrCompare(const char *pDest, const char *pSour);
int  MemCompare(PBYTE pDest, PBYTE pSour, int iSize);
void MemCopy(PBYTE pDest, PBYTE pSour, int iSize);
void MemSet(PBYTE pDest, BYTE v, int iSize);
U32  MemSum(PBYTE pData, int iSize, U32 dwSum);

// 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
// R  R  R  R  R  G  G G G G G B B B B B
#define GetRGB565(r, g, b)              ((U16) ( ((r & 0x1Fu) << 11) | ((g & 0x3Fu) << 5) | ((b & 0x1Fu)) ) )
// 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
// T  R  R  R  R  R  G G G G G B B B B B
#define GetRGBT555(r, g, b, t)          ((U16) ( ((t & 1u) << 15) | ((r & 0x1Fu) << 10) | ((g & 0x1Fu) << 5) | ((b & 0x1Fu)) ) )
// [25][24:16][15:8][7:0]
//  T     R      G    B
#define GetRGBT888(r, g, b, t)          ((U32) ( ((t & 1u) << 25) | ((r & 0xFFu) << 16) | ((g & 0xFFu) << 8) | ((b & 0xFFu)) ) )

void GetYUV(U8 *bColorY, U8 *bColorU, U8 *bColorV);

char *strstr(const char *s1, const char *s2);
int  abs(int i);

