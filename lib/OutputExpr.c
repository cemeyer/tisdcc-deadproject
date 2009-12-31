#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void OutputExpr(unsigned char col, unsigned char row) __naked
{
col; row;
__asm
push ix
push iy
push hl
push de
push bc
push af
ld hl,#14
add hl,sp
ld a,(hl)
inc hl
ld l,(hl)
ld h,a
ld iy,#flags___dw ; load TIOS iy value
BCALL(_OutputExpr___db)
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
