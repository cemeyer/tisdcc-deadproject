#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned int CreatePair(unsigned int size) __naked
{
size;
__asm
push iy
push de
ld iy,#flags___dw
ld hl,#6
add hl,sp
ld e,(hl)
inc hl
ld d,(hl)
ex de,hl
BCALL(_CreatePair___db)
pop de
pop iy
ret
__endasm;
}

#endif
