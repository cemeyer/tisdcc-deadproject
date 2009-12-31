#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void ErrDimension() __naked
{
__asm
push iy
ld iy,#flags___dw
BJUMP(_ErrDimension___db)
pop iy
ret
__endasm;
}

#endif
