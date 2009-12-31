#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned char CkOP1Pos() __naked
{
__asm
push af
push iy
ld iy,#flags___dw
BCALL(_CkOP1Pos___db)
pop iy
ld l,#1
jr z,___doneZZ129
dec l
___doneZZ129:
pop af
ret
__endasm;
}

#endif
