#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void Regraph() __naked
{
__asm
push iy
push ix
push hl
push de
push bc
ld iy,#flags___dw
BCALL(_Regraph___db)
pop bc
pop de
pop hl
pop ix
pop iy
ret
__endasm;
}

#endif
