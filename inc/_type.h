#ifndef INC_TYPE
#define INC_TYPE

#define __STR__(s)              #s
#define __CONSTR__(s1, s2)      (s1##s2)

typedef unsigned char           BYTE;
typedef unsigned short          WORD;
typedef unsigned long           DWORD;

typedef unsigned char*          PBYTE;
typedef unsigned short*         PWORD;
typedef unsigned long*          PDWORD;

typedef unsigned char           U8;
typedef unsigned short          U16;
typedef unsigned long           U32;
typedef char                    S8;
typedef char                    CHAR;
typedef short                   S16;
typedef long                    S32;

typedef U8*                     PU8;
typedef U16*                    PU16;
typedef U32*                    PU32;
typedef S8*                     PS8;
typedef S16*                    PS16;
typedef S32*                    PS32;

typedef U8                      u8;
typedef U16                     u16;
typedef U32                     u32;
typedef S8                      s8;
typedef S16                     s16;
typedef S32                     s32;

typedef U8*                     P_U8;
typedef U16*                    P_U16;
typedef U32*                    P_U32;
typedef S8*                     P_S8;
typedef S16*                    P_S16;
typedef S32*                    P_S32;

typedef void*                   PVOID;

#define LOHALF(v)               ((BYTE)(v & 0xF))
#define HIHALF(v)               ((BYTE)((v >> 4) & 0xF))
#define LOBYTE(v)               ((BYTE)(v & 0xFF))
#define HIBYTE(v)               ((BYTE)((v >> 8) & 0xFF))
#define LOWORD(v)               ((WORD)(v & 0xFFFF))
#define HIWORD(v)               ((WORD)((v >> 16) & 0xFFFF))
#define LLBYTE(v)               ((BYTE)(v & 0xFF))
#define LHBYTE(v)               ((BYTE)((v >> 8) & 0xFF))
#define HLBYTE(v)               ((BYTE)((v >> 16) & 0xFF))
#define HHBYTE(v)               ((BYTE)((v >> 24) & 0xFF))

#define MAKEBYTE(lo,hi)         (((BYTE)(lo & 0xF)) | ((BYTE)((hi & 0xF)<<4)))
#define MAKEWORD(lo,hi)         ((((WORD)((BYTE)(lo))) | (((WORD)(BYTE)(hi))<<8)))
#define MAKEDWORD(lo,hi)        ((((DWORD)((WORD)(lo))) | (((DWORD)(WORD)(hi))<<16)))

#define REVERSEDWORD(v)         MAKEDWORD(MAKEWORD(HHBYTE(v), HLBYTE(v)), MAKEWORD(LHBYTE(v), LLBYTE(v)))

typedef U32                     BOOL;

#define TRUE                    (0 == 0)
#define FALSE                   (0 == 1)

#define NULL                    0

#endif

