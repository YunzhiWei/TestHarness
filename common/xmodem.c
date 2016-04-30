/*
*  |--------------------------------------------------------------------------|
*  |0|1|2|3|...................................................|1026|1027|1028|
*  |--------------------------------------------------------------------------|
*
*   0字节：Start of Header to sync and identify the protocol: STX for 1K Modem, and SOH for normal xModem
*   1字节：Lo byte of the Data Package ID
*   2字节：Always == 0xFE ????
*   3字节：   First byte of the valid package data
*   1026字节：Last byte of the valid package data
*   1027字节：Hi byte of CRC16
*   1028字节：Lo byte of CRC16
*

    This file support 1K-xModem and simple xModem protocol

    2007-4-19          Modified by Wei Yunzhi

*/

#include "_Platform.h"

#ifdef INCLUDE_MODULE_XMODEM

/*
    Basic Functions
    Supported by other Modules
*/

#define XMdm_GetData                    __DBG_GetChar()
#define XMdm_SendRsp(c)                 __DBG_PutChar(c)
#define XMdm_IsDataReady                __DBG_IsDataReady()

// xModem Protocol Character
#define X_SOH                           0x01        // Start of Header for xModem
#define X_STX                           0x02        // Start of Header for 1K xModem
#define X_EOT                           0x04        // Flag for the last data package
#define X_ACK                           0x06        // Acknowledge
#define X_NAK                           0x15        // Deny
#define X_CAN                           0x18        // Cancel
#define X_C                             0x43        // CRC-XMODEM Protocol Sync Start

// Program Option
#define WAIT_DATA_TIME_LIMIT            0x100000
#define WAIT_START_TIME_LIMIT           0x10000
#define WAIT_START_RETRY_TIMES          50

//////////////////////////////////////////////////////////////////////////
// the following is the 'adapt layer' for xModem
// when porting this xModem protocol to your own system, pls modify the 'adapt layer' if necessary

static int XMdm_WaitRx( U32 dwTimeLimit )
{
    while( dwTimeLimit-- > 0 )
    {
        if(XMdm_IsDataReady)
        {
            return(ERR_CODE_SUCCESS);
        }
//        msSleep(1);
    }

    return(ERR_CODE_XMD_TIMEOUT);
}

static int XMdm_RecordByte( U8 *pBuffer, U32 dwCount )
{
    U32 i;

    for(i=0;i<dwCount;i++)
    {
        if ( XMdm_WaitRx(WAIT_DATA_TIME_LIMIT) == ERR_CODE_SUCCESS )
        {
            pBuffer[i] = XMdm_GetData;
        }
        else
        {
            return(ERR_CODE_XMD_TIMEOUT);
        }
    }

    return(ERR_CODE_SUCCESS);
}

//////////////////////////////////////////////////////////////////////////
// the following is the main protocol implementation
// in most occasion, you just need to use it correctly
// you can use xModem or 1K-xModem protocol

static int XMdm_RecordBlk( U8 *pData, U32 dwCount, U32 dwBlkNum )
{
    U8 blknum[2];
    U16 crc0, crc1;

    if(XMdm_RecordByte(blknum, sizeof(blknum)) != ERR_CODE_SUCCESS)     return(ERR_CODE_XMD_TIMEOUT);
    if(XMdm_RecordByte(pData, dwCount) != ERR_CODE_SUCCESS)             return(ERR_CODE_XMD_TIMEOUT);
    if(XMdm_RecordByte((U8*)(&crc0), sizeof(crc0)) != ERR_CODE_SUCCESS) return(ERR_CODE_XMD_TIMEOUT);
    if(blknum[0] != ((U8)(dwBlkNum)))                                   return(ERR_CODE_XMD_BLKNUM);
//    if(blknum[0] != (~blknum[1]))                                     return(ERR_CODE_XMD_BLKNUM);

    crc1 = CRC_Block(pData, dwCount);
    if(LOBYTE(crc0) != HIBYTE(crc1))                                    return(ERR_CODE_XMD_CHKSUM);
    if(LOBYTE(crc1) != HIBYTE(crc0))                                    return(ERR_CODE_XMD_CHKSUM);

    return(ERR_CODE_SUCCESS);
}

/*
 *  pBuffer         the buffer where the received data will be stored in
 *  dwLen           the buffer size limit
 *  pdwSize         the data size ( in byte ) received from xModem
 */
int XMdm_Receive( U8 *pBuffer, U32 dwLen, U32* pdwSize)
{
    U32 trytimes;
    U32 blklen;
    U32 blknum;

    *pdwSize = 0;
    blklen = 0;
    blknum = 1;

    trytimes = 0;

    while(1)
    {
        if( XMdm_WaitRx(WAIT_START_TIME_LIMIT) == ERR_CODE_SUCCESS )
        {
            trytimes = 0;

            switch (XMdm_GetData)
            {
            case X_SOH:
                if(blklen == 0)     blklen = 128;
            case X_STX:
                if(blklen == 0)     blklen = 1024;

                (*pdwSize) += blklen;
                if((*pdwSize) > dwLen) return(ERR_CODE_XMD_OVERFLOW);

                switch(XMdm_RecordBlk( pBuffer, blklen, blknum ))
                {
                case ERR_CODE_SUCCESS:
                    XMdm_SendRsp( X_ACK );
                    pBuffer += blklen;
                    blknum++;
                    blklen = 0;
                    break;
                case ERR_CODE_XMD_CHKSUM:
                case ERR_CODE_XMD_TIMEOUT:
                    XMdm_SendRsp( X_NAK );
                    (*pdwSize) -= blklen;
                    blklen = 0;
                    break;
                case ERR_CODE_XMD_BLKNUM:
                    XMdm_SendRsp( X_CAN );
                    return(ERR_CODE_XMD_BLKNUM);
                }
                break;
            case X_CAN:                             // 超级终端结束传输
                XMdm_SendRsp( X_ACK );
                return(ERR_CODE_XMD_CANCEL);
            case X_EOT:                             // 数据传输完毕
                XMdm_SendRsp( X_ACK );
                return(ERR_CODE_DONE);
            default:
                XMdm_SendRsp( X_NAK );
                return(ERR_CODE_XMD_INVALID);
            }
        }
        else
        {
            if(trytimes++ == WAIT_START_RETRY_TIMES)
            {
                return(ERR_CODE_XMD_TIMEOUT);
            }
            XMdm_SendRsp(X_C);
        }
    }
}

#endif //INCLUDE_MODULE_XMODEM

