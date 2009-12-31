#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned int CmpSyms(void *ptr1, void *ptr2, unsigned char n) __naked
{
ptr1; ptr2; n;
__asm
push af
push bc
push de
push iy
ld iy,#flags___dw
ld hl,#14
add hl,sp
ld b,(hl)
dec hl
ld d,(hl)
dec hl
ld e,(hl)
dec hl
ld c,(hl)
dec hl
ld l,(hl)
ld h,c
BCALL(_CmpSyms___db)
ld l,c
ld h,#1
jr c,___Sym2GreaterZZ141
dec h
___Sym2GreaterZZ141:
pop iy
pop de
pop bc
pop af
ret
__endasm;
}

#endif
