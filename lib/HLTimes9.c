#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned int HLTimes9(unsigned int n) __naked
{
n;
__asm
push bc
push iy
ld iy,#flags___dw
ld hl,#6
add hl,sp
ld b,(hl)
inc hl
ld h,(hl)
ld l,b
BCALL(_HLTimes9___db)
pop iy
pop bc
ret
__endasm;
}

#endif
