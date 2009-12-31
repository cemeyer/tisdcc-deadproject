#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned char CkPosInt() __naked
{
__asm
push iy
push ix
push de
push bc
push af
ld iy,#flags___dw
push hl
BCALL(_CkPosInt___db)
pop hl
ld l,#1
jr z,___doneZZ134
dec l
___doneZZ134:
pop af
pop bc
pop de
pop ix
pop iy
ret
__endasm;
}

#endif
