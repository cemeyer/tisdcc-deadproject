#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void PutS(char *str) __naked
{
str;
__asm
push iy
push hl
push af
ld iy,#flags___dw ; load TIOS iy value
ld hl,#8
add hl,sp
ld a,(hl)
inc hl
ld h,(hl)
ld l,a
pop af  ; only need a temporarily to put str in hl
BCALL(_PutS___db)
pop hl
pop iy
ret
__endasm;
}

#endif
