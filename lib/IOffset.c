#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned long IOffset(unsigned char col, unsigned char row) __naked
{
row; col;
__asm
push iy
push ix
push bc
push af
ld hl,#10
add hl,sp
ld b,(hl)
inc hl
ld c,(hl)
ld iy,#flags___dw
BCALL(_IOffset___db)
ld d,#0
ld e,a
pop af
pop bc
pop ix
pop iy
ret
__endasm;
}

#endif
