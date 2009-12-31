#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void *GetLToOP1(unsigned int n, void *ptr) __naked
{
n; ptr;
__asm
push iy
push ix
push de
push bc
push af
ld iy,#flags___dw
ld hl,#15
add hl,sp
ld d,(hl)
dec hl
ld e,(hl)
dec hl
ld a,(hl)
dec hl
ld l,(hl)
ld h,a
BCALL(_GetLToOP1___db)
pop af
pop bc
pop de
pop ix
pop iy
ret
__endasm;
}

#endif
