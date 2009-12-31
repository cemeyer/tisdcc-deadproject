#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void LoadPattern(unsigned char charequate) __naked
{
charequate;
__asm
push ix
push iy
push hl
push de
push bc
push af
ld iy,#flags___dw ; load TIOS iy value
ld hl,#14
add hl,sp
ld a,(hl)
BCALL(_LoadPattern___db)
pop af
pop bc
pop de
pop hl
pop iy
pop ix
ret
__endasm;
}

#endif
