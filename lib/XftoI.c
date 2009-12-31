#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned char XftoI(void *ptr) __naked
{
ptr;
__asm
push iy
push ix
push de
push bc
push af
push hl
ld iy,#flags___dw
ld hl,#14
add hl,sp
ld a,(hl)
inc hl
ld h,(hl)
ld l,a
BCALL(_XftoI___db)
pop hl
ld l,a
pop af
pop bc
pop de
pop ix
pop iy
ret
__endasm;
}

#endif
