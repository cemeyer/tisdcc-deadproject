#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned char CkOP2Pos() __naked
{
__asm
push af
push iy
ld iy,#flags___dw
BCALL(_CkOP2Pos___db)
pop iy
ld l,#1
jr z,___doneZZ132
dec l
___doneZZ132:
pop af
ret
__endasm;
}

#endif
