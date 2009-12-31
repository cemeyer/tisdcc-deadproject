#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void Round(unsigned char n) __naked
{
n;
__asm
push af
push bc
push de
push hl
push ix
push iy
ld iy,#flags___dw
ld hl,#14
add hl,sp
ld d,(hl)
BCALL(_Round___db)
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
