#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void VPutSN(char *str, unsigned char len) __naked
{
str; len;
__asm
push iy
push hl
push bc
ld hl,#10
add hl,sp
ld b,(hl)
dec hl
ld c,(hl)
dec hl
ld l,(hl)
ld h,c
ld iy,#flags___dw
BCALL(_VPutSN___db)
pop bc
pop hl
pop iy
ret
__endasm;
}

#endif
