#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void VtoWHLDE(unsigned char x, unsigned char y) __naked
{
x; y;
__asm
push iy
push ix
push hl
push de
push bc
push af
ld iy,#flags___dw
ld hl,#14
add hl,sp
ld b,(hl)
inc hl
ld c,(hl)
BCALL(_VtoWHLDE___db)
pop af
pop bc
pop de
pop hl
pop ix
pop iy
ret
__endasm;
}

#endif
