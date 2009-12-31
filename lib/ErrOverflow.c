#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void ErrOverflow() __naked
{
__asm
push iy
ld iy,#flags___dw
BJUMP(_ErrOverflow___db)
pop iy
ret
__endasm;
}

#endif
