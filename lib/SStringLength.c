#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned int SStringLength(char *str) __naked
{
str;
__asm
push iy
push ix
push de
push bc
push af
ld iy,#flags___dw
ld hl,#12
add hl,sp
ld a,(hl)
inc hl
ld h,(hl)
ld l,a
BCALL(_SStringLength___db)
ld h,a
ld l,b
pop af
pop bc
pop de
pop ix
pop iy
ret
__endasm;
}

#endif
