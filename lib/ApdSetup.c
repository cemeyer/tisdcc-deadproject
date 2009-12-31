#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void ApdSetup() __naked
{
__asm
push hl
push iy
ld iy,#flags___dw
BCALL(_ApdSetup___db)
pop iy
pop hl
ret
__endasm;
}

#endif
