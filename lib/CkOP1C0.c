#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned char CkOP1C0() __naked
{
__asm
push af
push iy
ld iy,#flags___dw
BCALL(_CkOP1C0___db)
pop iy
ld l,#1
jr z,___doneZZ126
dec l
___doneZZ126:
pop af
ret
__endasm;
}

#endif
