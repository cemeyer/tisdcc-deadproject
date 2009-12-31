#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void BufCpy(void *ptr) __naked
{
ptr;
__asm
push iy
push ix
push hl
push de
push bc
push af
ld iy,#flags___dw
ld hl,#14
add hl,sp
ld a,(hl)
inc hl
ld h,(hl)
ld l,a
BCALL(_BufCpy___db)
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
