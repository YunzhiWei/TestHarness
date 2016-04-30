/* Processor Type */
.equ         PROCESSOR_TYPE_PXA310,         1
.equ         PROCESSOR_STEPPING_B1,         1

                    .include     "./MCU/_Reg_PXA3xx.inc"
                    .include     "./MCU/_MemoryBase_PXA3xx.inc"
                    .include     "./Platform/Gryphus/MemorySize.inc"
                    .include     "./Platform/_MemoryMap_EXE_at_SDRAM.inc"

/* Frequency */
.equ         ACCR_VALUE,                     0x09233210

/* EMPI - 16bir or 32bit */
.equ         EMPI_VALUE,                     0xC1000000      /* 0xC1000000    16bit EMPI */

/* PAD setting for B1 stepping */
.equ         PAD_VALUE_1,                    0x1B250808
.equ         PAD_VALUE_2,                    0x1B250808
.equ         DDRHCAL_VALUE,                  0x90001102

/*Rcomp Evaluation Interval */
.equ         REI_VALUE,                      0x00013D62      /*0x13D62*7.8us*32 = 0.2 second */
.equ         MRS_COMMAND_VALUE,              0x00000033      /*CL=3 and Burst length=8 to be modified */

/*SDRAM Refresh Interval, All partitions: */
.equ         DRI_VALUE,                      0x00000023      /*7.8us*13M/4 */

#      .end

