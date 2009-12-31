#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void EraseEOL() __naked
{
__asm
push iy
ld iy,#flags___dw ; load TIOS iy value
BCALL(_EraseEOL___db)
pop iy
ret
__endasm;
}

#endif
