#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned char CkOP1Cplx() __naked
{
__asm
push af
push iy
ld iy,#flags___dw
BCALL(_CkOP1Cplx___db)
pop iy
ld l,#1
jr z,___doneZZ127
dec l
___doneZZ127:
pop af
ret
__endasm;
}

#endif
