#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void ZmDecml() __naked
{
__asm
push iy
push ix
push de
push bc
push af
push hl
ld iy,#flags___dw
BCALL(_ZmDecml___db)
pop hl
pop af
pop bc
pop de
pop ix
pop iy
ret
__endasm;
}

#endif
