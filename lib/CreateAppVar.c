#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned long CreateAppVar(unsigned int size) __naked
{
size;
__asm
push iy
ld iy,#flags___dw
;// we can trash dehl because we return a long
ld hl,#4
add hl,sp
ld e,(hl)
inc hl
ld d,(hl)
ex de,hl
BCALL(_CreateAppVar___db)
pop iy
ret
__endasm;
}

#endif
