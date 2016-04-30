
                    .align  4
                    .extern     Main

START:
#                    b           START

                    mov         r0,         #(CPSR_Mode_SYS)        /* Enable I-bit & F-bit */
                    msr         CPSR,       r0

                    bl          Main

                    ldr         pc,         =0x83F00000

                    .end
