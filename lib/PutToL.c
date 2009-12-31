#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void *PutToL(unsigned int idx, void *ptr) __naked
{
ptr; idx;
__asm
push iy
push ix
push de
push bc
push af
ld hl,#15
ld d,(hl)
dec hl
ld e,(hl)
dec hl
ld a,(hl)
dec hl
ld l,(hl)
ld h,a
BCALL(_PutToL___db)
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
