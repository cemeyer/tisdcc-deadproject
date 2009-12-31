#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned int DelListEl(unsigned char type, void *data, unsigned int idx, unsigned int n) __naked
{
type; data; idx; n;
__asm
push iy
ld iy,#flags___dw
push ix
push de
push bc
push af
ld hl,#12
add hl,sp
ld a,(hl)
inc hl
ld e,(hl)
inc hl
ld d,(hl)
inc hl
ld c,(hl)
inc hl
ld b,(hl)
inc hl
push bc
ld b,(hl)
inc hl
ld h,(hl)
ld l,b
pop bc
BCALL(_DelListEl___db)
ex de,hl
pop af
pop bc
pop de
pop ix
pop iy
ret
__endasm;
}

#endif
