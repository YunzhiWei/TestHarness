
#include "_Platform.h"

/*
    Caution:

    1. For Direct Key, the Pull-Low resistor in MFPR must be set.
    2. The KPAS_MUKP value is not right for Multi Key press.
    3. KPAS_SO is not checked here. This may cause bug!

*/

#ifdef INCLUDE_MODULE_KEYPAD

#include "Keypad_Map.c"

#define REG_KPC                         (*MH_KPC)
#define REG_KPKDI                       (*MH_KPKDI)
#define REG_KPREC                       (*MH_KPREC)
#define REG_KPAS                        (*MH_KPAS)
#define REG_KPDK                        (*MH_KPDK)
#define REG_KPASMKP0                    (*MH_KPASMKP0)
#define REG_KPASMKP1                    (*MH_KPASMKP1)
#define REG_KPASMKP2                    (*MH_KPASMKP2)
#define REG_KPASMKP3                    (*MH_KPASMKP3)

void KP_Initial(void)
{
    REG_KPC = KPC_ASACT |
              KPC_MS0 | KPC_MS1 | KPC_MS2 | KPC_MS3 | KPC_MS4 | KPC_MS5 | KPC_MS6 | KPC_MS7 |
              KPC_ME | KPC_MKRN(KEYPAD_ROW_NUMBER) | KPC_MKCN(KEYPAD_COL_NUMBER)
#ifdef KEYPAD_DIR_NUMBER
              | KPC_DE | KPC_DKN(KEYPAD_DIR_NUMBER)
#endif
              ;

    REG_KPKDI = KPKDI_DKDI(4) | KPKDI_MKDI(4);
//    REG_KPREC = KPREC_COUNTA(0x7f);

//    DBG_TraceStrLine("Key @ " __DATE__ " " __TIME__);
}

int KP_MatrixScan(U32 *pdwRow, U32 *pdwCol, U32 *pdwScanMap)
{
    U32 kpas, mukp;
    U8  k;

    do
    {
        kpas = REG_KPAS;
    }while(kpas & KPAS_SO);

    mukp = kpas & KPAS_MUKP_MASK;

//  k = REG_KPC;
//  k&= (KPC_MI | KPC_DI);

//    DBG_TraceStrLine("");
//    DBG_TraceHex("kpc",  k);
//    DBG_TraceHex("kpas", kpas);
//    DBG_TraceHex("mukp", mukp>>26);

    if(mukp == KPAS_MUKP(0))
    {
        return(ERR_CODE_KP_NOKEY);
    }
    else if(mukp == KPAS_MUKP(1))
    {
        if(kpas & KPAS_XP_ERR_MASK)
        {
            return(ERR_CODE_KP_NOKEY);
        }

        k = kpas & KPAS_XP_MASK;

        *pdwRow = HIHALF(k);
        *pdwCol = LOHALF(k);

        if(((*pdwRow) >= KEYPAD_ROW_NUMBER) || ((*pdwCol) >= KEYPAD_COL_NUMBER)) return(ERR_CODE_KP_NOKEY);

        return(ERR_CODE_KP_SINGLE);
    }
    else
    {
        // !!! KPAS_SO needs to be checked here!!!

        // Pay attention to KP_SCAN_CODE_NUMBER!!!

        do
        {
            pdwScanMap[0] = REG_KPASMKP0;
        }while(pdwScanMap[0] & KPAS_SO);

        pdwScanMap[1] = REG_KPASMKP1;
        pdwScanMap[2] = REG_KPASMKP2;
        pdwScanMap[3] = REG_KPASMKP3;

        return(ERR_CODE_KP_MULTI);
    }
}

char KP_MatrixTranslate(U32 dwRow, U32 dwCol)
{
    return(g_MKTable[dwRow][dwCol]);
}

static int KP_DirectScan(U32 *pdwScanCode)
{
    U32 k;

    k = REG_KPDK;

    if((k & KPDK_DKP) == 0)
    {
        return(ERR_CODE_KP_NOKEY);
    }

    *pdwScanCode = k & KPDK_DKx_MASK;

    return(ERR_CODE_KP_VALID);
}

#ifdef KEYPAD_DIR_NUMBER
static void KP_DirectTranslate(U32 dwScan)
{
    U32 i, mask;

    for(i=0, mask = 1;i < KEYPAD_DIR_NUMBER;i++, mask <<= 1)
    {
        if(dwScan & mask) MY_PutChar(g_DKTable[i]);
    }
}
#endif

static void tScanMapPrint(U32* pdwScanCode, U32 dwCount)
{
    U32 i, b;

    for(i=0;i<dwCount;i++)
    {
#if 0
        DBG_TraceHex("", pdwScanCode[i]);
#else
        DBG_TraceStrLine("");
        for(b=0;b<8;b++)
        {
            if((1<<b) & pdwScanCode[i]) DBG_PutChar('#');
            else                        DBG_PutChar('.');
        }
        DBG_TraceStrLine("");
        for(b=16;b<24;b++)
        {
            if((1<<b) & pdwScanCode[i]) DBG_PutChar('#');
            else                        DBG_PutChar('.');
        }
#endif
    }
}

void KP_Scan(void)
{
    U32 k;

    k = REG_KPC;

    if(k & KPC_MI)
    {
        U32 r;
        U32 row, col;
        U32 smap[KP_SCAN_CODE_NUMBER];

        r = KP_MatrixScan(&row, &col, smap);

        if(ERR_CODE_KP_SINGLE == r)
        {
            MY_PutChar(KP_MatrixTranslate(row, col));

#ifdef KEYPAD_EVENT_TABLE
            if(MAIN_EVENT_NULL != g_MKEventTable[row][col]) SetEvent(g_MKEventTable[row][col]);
#endif
        }
        else if(ERR_CODE_KP_MULTI == r)
        {
            tScanMapPrint(smap, sizeof(smap)/sizeof(U32));
        }
    }

    if(k & KPC_DI)
    {
        U32 smap;

        if(ERR_CODE_KP_VALID == KP_DirectScan(&smap))
        {
#ifdef KEYPAD_DIR_NUMBER
            KP_DirectTranslate(smap);
#endif
        }
    }

    return;
}

void KP_INTHandler(void)
{
    KP_Scan();
}

void KP_INTEnable(void)
{
    REG_KPC |= (KPC_MIE | KPC_DIE);
}

void KP_INTDisable(void)
{
    REG_KPC &=~ (KPC_MIE | KPC_DIE);
}

#endif

