#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned int InsertList(unsigned char type, void *ptr, unsigned int idx, unsigned int n, unsigned char set) __naked
{
type; ptr; idx; n; set;
__asm
push iy
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
push bc
inc hl
ld c,(hl)
inc hl
ld b,(hl)
push bc
inc hl
ld b,(hl)
ld c,a
ld a,b
cp #0
ccf
jr z,___set_zeroZZ104
scf
___set_zeroZZ104:
pop hl
ld a,c
pop bc
BCALL(_InsertList___db)
pop af
pop bc
pop de
pop ix
pop iy
ret
__endasm;
}

#endif
