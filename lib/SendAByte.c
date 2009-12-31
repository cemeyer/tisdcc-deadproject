#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void SendAByte(unsigned char byte) __naked
{
byte;
__asm
push bc
push de
push ix
push iy
push hl
push af
ld iy,#flags___dw
ld hl,#14
add hl,sp
ld a,(hl)
BCALL(_SendAByte___db)
pop af
pop hl
pop iy
pop ix
pop de
pop bc
ret
__endasm;
}

#endif
