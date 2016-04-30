
#define INCLUDE_MODULE_FIFO

#define FIFO_BUFFER_SIZE                (2 * 1024)

#define FIFO_BUFFER_NUMBER              2u

typedef enum
{
    FIFO_ID_USBSERIAL        = 0u,
    FIFO_ID_RESERVE          = 1u,
    FIFO_ID_MAX              = FIFO_BUFFER_NUMBER
}FIFO_ID_t;

void FIFO_Dump(FIFO_ID_t tID);
void FIFO_Clear(FIFO_ID_t tID);
U32  FIFO_DataSize(FIFO_ID_t tID);
U32  FIFO_In(FIFO_ID_t tID, PU8 pbData, U32 dwSize);
U32  FIFO_Out(FIFO_ID_t tID, PU8 pbData, U32 dwSize);

