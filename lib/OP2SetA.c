#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void OP2SetA(unsigned char i) __naked
{
i;
__asm
push af
push hl
push iy
ld hl,#8
add hl,sp
ld a,(hl)
ld iy,#flags___dw
BCALL(_OP2Set8___db)
pop iy
pop hl
pop af
ret
__endasm;
}

#endif
