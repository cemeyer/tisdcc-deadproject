#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void ErrDomain() __naked
{
__asm
push iy
ld iy,#flags___dw
BJUMP(_ErrDomain___db)
pop iy
ret
__endasm;
}

#endif
