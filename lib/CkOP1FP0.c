#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned char CkOP1FP0() __naked
{
__asm
push af
push iy
ld iy,#flags___dw
BCALL(_CkOP1FP0___db)
pop iy
ld l,#1
jr z,___doneZZ128
dec l
___doneZZ128:
pop af
ret
__endasm;
}

#endif
