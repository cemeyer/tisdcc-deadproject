#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void ClearRow(unsigned char a) __naked
{
a;
__asm
push hl
push bc
inc sp
push af
inc sp
ld hl,#6
add hl,sp
ld a,(hl) ; stack is AF, BC, DE, IX, RA, A
ex de,hl
BCALL(_ClearRow___db)
ex de,hl
ld l,c
pop bc
ld a,c
ld c,l
pop hl
ret
__endasm;
}

#endif
