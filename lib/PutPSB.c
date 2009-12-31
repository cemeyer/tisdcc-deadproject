#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void PutPSB(char *str) __naked
{
str;
__asm
push ix
push iy
push hl
push bc
push af
ld iy,#flags___dw ; load TIOS iy value
ld hl,#12
add hl,sp
ld c,(hl)
inc hl
ld h,(hl)
ld l,c
BCALL(_PutPSB___db)
pop af
pop bc
pop hl
pop iy
pop ix
ret
__endasm;
}

#endif
