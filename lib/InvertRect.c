#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void InvertRect(unsigned char row1, unsigned char col1, unsigned char row2, unsigned char col2) __naked
{
row1; col1; row2; col2;
__asm
push iy
push hl
push de
push af
ld hl,#13
add hl,sp
ld e,(hl)
dec hl
ld d,(hl)
dec hl
ld a,(hl)
dec hl
ld h,(hl)
ld l,a
ld iy,#flags___dw
BCALL(_InvertRect___db)
pop af
pop de
pop hl
pop iy
ret
__endasm;
}

#endif
