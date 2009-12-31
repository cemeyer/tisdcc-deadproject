#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void PushReal(void *ptr) __naked
{
ptr;
__asm
push iy
push ix
push hl
push de
push bc
push af
ld hl,#14
ld a,(hl)
inc hl
ld h,(hl)
ld l,a
ld iy,#flags___dw
BCALL(_PushReal___db)
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
