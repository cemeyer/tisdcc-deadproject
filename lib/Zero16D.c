#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void Zero16D(void *ptr) __naked
{
ptr;
__asm
push af
push hl
push iy
ld iy,#flags___dw
ld hl,#8
add hl,sp
ld a,(hl)
inc hl
ld h,(hl)
ld l,a
BCALL(_Zero16D___db)
pop iy
pop hl
pop af
ret
__endasm;
}

#endif
