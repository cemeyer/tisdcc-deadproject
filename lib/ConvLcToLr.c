#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void ConvLcToLr() __naked
{
__asm
push iy
ld iy,#flags___dw
push ix
push hl
push af
push bc
push de
BCALL(_ConvLcToLr___db)
pop de
pop bc
pop af
pop hl
pop ix
pop iy
ret
__endasm;
}

#endif
