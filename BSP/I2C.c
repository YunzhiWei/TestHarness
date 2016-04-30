#include "_Platform.h"

#ifdef INCLUDE_MODULE_I2C

#define     I2C_IBMR    (*MH_IBMR)
#define     I2C_IDBR    (*MH_IDBR)
#define     I2C_ICR     (*MH_ICR)
#define     I2C_ISR     (*MH_ISR)
#define     I2C_ISAR    (*MH_ISAR)

static int WaitFlag(U32 dwFlag, U32 dwTimeLimit)
{
    U32 tmp;

    while(dwTimeLimit--)
    {
        tmp = I2C_ISR;
        if((tmp & dwFlag) == dwFlag)
        {
            I2C_ISR = dwFlag;

            if((tmp & ISR_ALD) == ISR_ALD)
            {
                I2C_ISR = ISR_ALD;
                DBG_TraceStrLine("Arbitration Loss");
                return(ERR_CODE_I2C_ARBI_LOSS);
            }
            return(ERR_CODE_DONE);
        }
        msSleep(1);
    }

    return(ERR_CODE_I2C_TIMEOUT);
}

void I2C_Initial(void)
{
    I2C_ICR = 0;

    //Reset I2C interface
    I2C_ICR |= ICR_UR;  //Reset I2C interface
    I2C_ICR &= ~ICR_UR; //No reset

    //Set I2C control reg
    I2C_ICR &=~(ICR_ALDIE|ICR_SCLEA|ICR_UIE);
    I2C_ICR |=(ICR_UIE|ICR_SCLEA);

    return;
}

int I2C_Write(U8 bSlaveAddr, U8 * pBuf, U32 dwSize, BOOL isSendStop)
{
    U32 reg;
    int ret;

    I2C_IDBR = (bSlaveAddr ) & ~1;
    reg = I2C_ICR;
    reg |= (ICR_START | ICR_TB);
    reg &= ~(ICR_STOP | ICR_ALDIE);
    I2C_ICR = reg;

    if((ret = WaitFlag(ISR_ITE, 100)) != ERR_CODE_DONE)
    {
        return(ret);
    }

    while(dwSize--)
    {
        I2C_IDBR = (U32)(*pBuf++);

        reg = I2C_ICR;

        reg &= ~ICR_START;
        reg |= (ICR_ALDIE | ICR_TB);

        if((dwSize == 0) && isSendStop)
        {
            reg |= ICR_STOP;
        }
        else
        {
            reg &= ~ICR_STOP;
        }

        I2C_ICR = reg;

        if((ret = WaitFlag(ISR_ITE, 100)) != ERR_CODE_DONE)
        {
            return(ret);
        }
    }

    // Clear the STOP bit always
    I2C_ICR &= ~ICR_STOP;

    return(ERR_CODE_SUCCESS);
}

int I2C_Read(U8 bSlaveAddr, U8 * pBuf, U32 dwSize, BOOL isSendStop)
{
    U32 reg;
    int ret;

    I2C_IDBR = (bSlaveAddr ) | 1;

    reg = I2C_ICR;
    reg |= (ICR_START | ICR_TB);
    reg &= ~(ICR_STOP | ICR_ALDIE);
    I2C_ICR = reg;

    if((ret = WaitFlag(ISR_ITE, 100)) != ERR_CODE_DONE)
    {
        return(ret);
    }

    while(dwSize--)
    {
        reg = I2C_ICR;
        reg &= ~ICR_START;
        reg |= ICR_ALDIE | ICR_TB;
        if (dwSize == 0)
        {
            reg |= ICR_ACKNACK;
            if (isSendStop)
            {
                reg |= ICR_STOP;
            }
            else
            {
                reg &= ~ICR_STOP;
            }
        }
        else
        {
            reg &= ~ICR_ACKNACK;
        }
        I2C_ICR = reg;

        if((ret = WaitFlag(ISR_IRF, 100)) != ERR_CODE_DONE)
        {
            return(ret);
        }

        reg = I2C_IDBR & 0xFF;
        *pBuf++ = (U8)reg;
    }

    I2C_ICR &= ~(ICR_STOP | ICR_ACKNACK);

    return(ERR_CODE_SUCCESS);
}

#endif

