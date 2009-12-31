#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned int ConvDim() __naked
{
__asm
push iy
ld iy,#flags___dw
push af
push bc
push de
BCALL(_ConvDim___db)
ex de,hl
pop de
pop bc
pop af
pop iy
ret
__endasm;
}

#endif
