#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

int FormReal(unsigned char maxwidth) __naked
{
maxwidth;
__asm
push ix
push iy
push de
push bc
push af
ld iy,#flags___dw ; load TIOS iy value
ld hl,#12
add hl,sp
ld a,(hl)
BCALL(_FormReal___db)
ld h,b
ld l,c
pop af
pop bc
pop de
pop iy
pop ix
ret
__endasm;
}

#endif
