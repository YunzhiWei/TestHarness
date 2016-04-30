
/* ------------------------------------------------------------------------------------- */

                    .macro          APIStub         NUMBER, NAME_API

                    .global         \NAME_API
                    .type           \NAME_API,      function
\NAME_API:
                    swi             \NUMBER

                    .endm

/* ------------------------------------------------------------------------------------- */

                    .macro          APIEntrance     NAME_FUNC, NAME_API
                    
                    APIStub         COUNT,          \NAME_API
                    COUNT           = COUNT + 1

                    .endm

/* ------------------------------------------------------------------------------------- */
                    .align      4
API_STUB:
                     COUNT=0
                    .include        "../../BSP/_APIEntrance._s"

                    .end

