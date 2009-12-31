#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned int IncLstSize(unsigned char type, void *ptr) __naked
{
type; ptr;
__asm
push iy
push ix
push de
push bc
push af
ld hl,#12
ld a,(hl)
inc hl
ld e,(hl)
inc hl
ld d,(hl)
BCALL(_IncLstSize___db)
pop af
pop bc
pop de
pop ix
pop iy
ret
__endasm;
}

#endif
