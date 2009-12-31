#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void DarkLine(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2) __naked
{
x1; y1; x2; y2;
__asm
push iy
push hl
push de
push bc
ld hl,#10
add hl,sp
ld b,(hl)
inc hl
ld c,(hl)
inc hl
ld d,(hl)
inc hl
ld e,(hl)
ld iy,#flags___dw
BCALL(_DarkLine___db)
pop bc
pop de
pop hl
pop iy
ret
__endasm;
}

#endif
