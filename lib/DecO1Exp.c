#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void DecO1Exp() __naked
{
__asm
push af
push iy
ld iy,#flags___dw
BCALL(_DecO1Exp___db)
pop iy
pop af
ret
__endasm;
}

#endif
