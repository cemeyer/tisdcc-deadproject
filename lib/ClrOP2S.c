#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void ClrOP2S() __naked
{
__asm
BCALL(_ClrOP2S___db)
ret
__endasm;
}

#endif
