#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void *AdrMRow(void *ptr, unsigned char row) __naked
{
ptr; row;
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
BCALL(_AdrMRow___db)
pop iy
pop ix
pop de
pop bc
pop af
ret
__endasm;
}

#endif
