#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned long CreatePict() __naked
{
__asm
push iy
ld iy,#flags___dw
BCALL(_CreatePict___db)
pop iy
ret
__endasm;
}

#endif
