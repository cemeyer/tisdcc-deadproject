#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void RToD() __naked
{
__asm
push af
push bc
push de
push hl
push ix
push iy
ld iy,#flags___dw
BCALL(_RToD___db)
pop iy
pop ix
pop hl
pop de
pop bc
pop af
ret
__endasm;
}

#endif
