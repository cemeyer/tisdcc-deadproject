#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void ErrD_OP1_0() __naked
{
__asm
push iy
ld iy,#flags___dw
push af
BJUMP(_ErrD_OP1_0___db)
pop af
pop iy
ret
__endasm;
}

#endif
