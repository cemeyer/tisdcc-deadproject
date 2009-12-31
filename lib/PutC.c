#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void PutC(char c) __naked
{
c;
__asm
push iy
push hl
ld hl,#6
add hl,sp
ld a,(hl)
ld iy,#flags___dw ; load TIOS iy value
BCALL(_PutC___db)
pop hl
pop iy
ret
__endasm;
}

#endif
