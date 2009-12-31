#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void *ExpToHex(void *ptr) __naked
{
ptr;
__asm
push af
push iy
ld iy,#flags___dw
ld hl,#6
add hl,sp
ld a,(hl)
inc hl
ld h,(hl)
ld l,a
BCALL(_ExpToHex___db)
pop iy
pop af
ret
__endasm;
}

#endif
