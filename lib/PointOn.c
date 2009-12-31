#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void PointOn(unsigned char x, unsigned char y) __naked
{
x; y;
__asm
push iy
push hl
push bc
ld hl,#8
add hl,sp
ld b,(hl)
inc hl
ld c,(hl)
ld iy,#flags___dw
ex de,hl
BCALL(_PointOn___db)
ex de,hl
pop bc
pop hl
pop iy
ret
__endasm;
}

#endif
