#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void ErrD_OP1NotPosInt() __naked
{
__asm
push iy
ld iy,#flags___dw
push af
BJUMP(_ErrD_OP1NotPosInt___db)
pop af
pop iy
ret
__endasm;
}

#endif
