
/*
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    Logic Address

    PLEASE Check link script file and _MemoryMap*.inc

    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

.equ       SYS_SRAM_BASE,               0x5C000000
.equ       SYS_SDRAM_BASE,              0x80000000

.equ       EXE_STACK_INDIVIDUAL_SIZE,   (16 * 1024)

.equ       RUNTIME_PROGRAM_BASE,        (SYS_SDRAM_BASE)
.equ       RUNTIME_PROGRAM_SIZE,        (1 * 1024 * 1024)

.equ       EXE_STACK_TOP,               (RUNTIME_PROGRAM_BASE + RUNTIME_PROGRAM_SIZE)
.equ       EXE_STACK_LAST,              (EXE_STACK_TOP - 4)

