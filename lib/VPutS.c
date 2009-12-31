#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void VPutS(char *str) __naked
{
str;
__asm
push iy
push hl
push bc
ld hl,#8
add hl,sp
ld b,(hl)
inc hl
ld h,(hl)
ld l,b
ld iy,#flags___dw
BCALL(_VPutS___db)
pop bc
pop hl
pop iy
ret
__endasm;
}

#endif
