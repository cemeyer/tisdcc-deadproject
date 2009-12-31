#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned char CkOP1Real() __naked
{
__asm
push af
push iy
ld iy,#flags___dw
BCALL(_CkOP1Real___db)
pop iy
ld l,#1
jr z,___doneZZ130
dec l
___doneZZ130:
pop af
ret
__endasm;
}

#endif
