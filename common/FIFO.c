
#include "_platform.h"

#ifdef INCLUDE_MODULE_FIFO

static U32 g_dwInPos[FIFO_BUFFER_NUMBER]  = {0, 0};
static U32 g_dwOutPos[FIFO_BUFFER_NUMBER] = {0, 0};
static U8  g_cBuffer[FIFO_BUFFER_NUMBER][FIFO_BUFFER_SIZE];

/*
    InPos     == OutPos: FIFO is Empty
    InPos + 1 == OutPos: FIFO is Full
*/

#define FIFO_VALID_DATA_SIZE            ((g_dwInPos[tID] >= g_dwOutPos[tID]) ? (g_dwInPos[tID] - g_dwOutPos[tID])     : (FIFO_BUFFER_SIZE - g_dwOutPos[tID] + g_dwInPos[tID]))
#define FIFO_VALID_BUFFER_SIZE          ((g_dwOutPos[tID] > g_dwInPos[tID] ) ? (g_dwOutPos[tID] - g_dwInPos[tID] - 1) : (FIFO_BUFFER_SIZE - g_dwInPos[tID]  + g_dwOutPos[tID] - 1))

void FIFO_Dump(FIFO_ID_t tID)
{
    DBG_TraceDec("IN",  g_dwInPos[tID]);
    DBG_TraceDec("OUT", g_dwOutPos[tID]);
}

void FIFO_Clear(FIFO_ID_t tID)
{
    g_dwInPos[tID] = 0;
    g_dwOutPos[tID]= 0;
}

U32 FIFO_ValidDataSize(FIFO_ID_t tID)
{
    return(FIFO_VALID_DATA_SIZE);
}

U32 FIFO_In(FIFO_ID_t tID, PU8 pbData, U32 dwSize)
{
    U32 size, newIN, snapFifoSize;

    if((pbData == NULL) || (dwSize == 0))
    {
        return 0;
    }

    snapFifoSize = FIFO_VALID_BUFFER_SIZE;

    size = dwSize < snapFifoSize ? dwSize : snapFifoSize;

    newIN = g_dwInPos[tID] + size;
    if(newIN < FIFO_BUFFER_SIZE)
    {
        MemCopy(&g_cBuffer[tID][g_dwInPos[tID]], pbData, size);
    }
    else
    {
        U32 s;
        newIN -= FIFO_BUFFER_SIZE;
        MemCopy(&g_cBuffer[tID][g_dwInPos[tID]], pbData,     s = (FIFO_BUFFER_SIZE - g_dwInPos[tID]));
        MemCopy(&g_cBuffer[tID][0],              pbData + s, newIN);
    }
    g_dwInPos[tID] = newIN;

    return(size);
}

U32 FIFO_Out(FIFO_ID_t tID, PU8 pbData, U32 dwSize)
{
    U32 size, newOUT, snapFifoSize;

    if((pbData == NULL) || (dwSize == 0))
    {
        return 0;
    }

    snapFifoSize = FIFO_VALID_DATA_SIZE;

    size = dwSize < snapFifoSize ? dwSize : snapFifoSize;

    newOUT = g_dwOutPos[tID] + size;
    if(newOUT < FIFO_BUFFER_SIZE)
    {
        MemCopy(pbData, &g_cBuffer[tID][g_dwOutPos[tID]], size);
    }
    else
    {
        U32 s;
        newOUT -= FIFO_BUFFER_SIZE;
        MemCopy(pbData,     &g_cBuffer[tID][g_dwOutPos[tID]], s = (FIFO_BUFFER_SIZE - g_dwOutPos[tID]));
        MemCopy(pbData + s, &g_cBuffer[tID][0],               newOUT);
    }
    g_dwOutPos[tID] = newOUT;

    return (size);
}

#endif // INCLUDE_MODULE_FIFO

