#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void DispOP1A(unsigned char maxdigits) __naked
{
maxdigits;
__asm
push ix
push iy
push hl
push de
push bc
push af
ld iy,#flags___dw ; load TIOS iy value
ld hl,#14
add hl,sp
ld a,(hl)
BCALL(_DispOP1A___db)
pop af
pop bc
pop de
pop hl
pop iy
pop ix
ret
__endasm;
}

#endif
