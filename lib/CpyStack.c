#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void CpyStack(unsigned char bytes, void *freebyte, void *copyto) __naked
{
bytes; freebyte; copyto;
__asm
push iy
ld iy,#flags___dw
push ix
push hl
push de
push bc
push af
ld hl,#14
ld c,(hl)
inc hl
ld e,(hl)
inc hl
ld d,(hl)
inc hl
ld b,(hl)
inc hl
ld h,(hl)
ld l,b
ex de,hl
BCALL(_CpyStack___db)
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
