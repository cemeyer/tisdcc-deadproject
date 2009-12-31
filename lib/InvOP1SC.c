#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void InvOP1SC() __naked
{
__asm
push af
push iy
ld iy,#flags___dw
BCALL(_InvOP1SC___db)
pop iy
pop af
ret
__endasm;
}

#endif
