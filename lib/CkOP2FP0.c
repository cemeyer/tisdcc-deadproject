#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned char CkOP2FP0() __naked
{
__asm
push af
push iy
ld iy,#flags___dw
BCALL(_CkOP2FP0___db)
pop iy
ld l,#1
jr z,___doneZZ131
dec l
___doneZZ131:
pop af
ret
__endasm;
}

#endif
