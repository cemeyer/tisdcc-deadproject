#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void DispDone() __naked
{
__asm
push hl
BCALL(_DispDone___db)
pop hl
ret
__endasm;
}

#endif
