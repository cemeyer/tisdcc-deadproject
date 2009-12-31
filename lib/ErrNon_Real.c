#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void ErrNon_Real() __naked
{
__asm
push iy
ld iy,#flags___dw
BJUMP(_ErrNon_Real___db)
pop iy
ret
__endasm;
}

#endif
