#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned char IPoint(unsigned char col, unsigned char row, unsigned char func) __naked
{
col; row; func;
__asm
push iy
push ix
push bc
push de
push af
push hl
ld hl,#14
add hl,sp
ld b,(hl)
inc hl
ld c,(hl)
inc hl
ld d,(hl)
BCALL(_IPoint___db)
pop hl
ld l,#1
jr z,___point_is_offZZ102
dec l
___point_is_offZZ102:
pop af
pop de
pop bc
pop ix
pop iy
ret
__endasm;
}

#endif
