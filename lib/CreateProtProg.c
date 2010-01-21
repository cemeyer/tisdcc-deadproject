#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned long CreateProtProg(unsigned int size) __naked
{
size;
__asm
push iy
ld iy,#flags___dw
ld hl,#4
add hl,sp
ld e,(hl)
inc hl
ld d,(hl)
ex de,hl
BCALL(_CreateProtProg___db)
pop iy
ret
__endasm;
}

#endif
