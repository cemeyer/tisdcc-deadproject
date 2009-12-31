#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void *PutToMat(void *ptr, unsigned char row, unsigned char col) __naked
{
ptr; row; col;
__asm
push af
push bc
push de
push ix
push iy
ld iy,#flags___dw
ld hl,#12
add hl,sp
ld e,(hl)
inc hl
ld d,(hl)
inc hl
ld b,(hl)
inc hl
ld c,(hl)
BCALL(_PutToMat___db)
ex de,hl
pop iy
pop ix
pop de
pop bc
pop af
ret
__endasm;
}

#endif
