#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void RandInit() __naked
{
__asm
push bc
push de
push hl
push iy
ld iy,#flags___dw
BCALL(_RandInit___db)
pop iy
pop hl
pop de
pop bc
ret
__endasm;
}

#endif
