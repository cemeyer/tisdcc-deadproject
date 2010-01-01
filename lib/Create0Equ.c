#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned long Create0Equ() __naked
{
__asm
push iy
ld iy,#flags___dw
BCALL(_Create0Equ___db)
pop iy
ret
__endasm;
}

#endif
