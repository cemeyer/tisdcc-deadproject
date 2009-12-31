#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned int HTimesL(unsigned char h, unsigned char l) __naked
{
h; l;
__asm
push bc
push de
push iy
ld iy,#flags___dw
ld hl,#8
add hl,sp
ld b,(hl)
inc hl
ld l,(hl)
ld h,b
BCALL(_HTimesL___db)
pop iy
pop de
pop bc
ret
__endasm;
}

#endif
