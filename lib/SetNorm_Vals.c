#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void SetNorm_Vals() __naked
{
__asm
push iy
push ix
push hl
push de
push bc
push af
ld iy,#flags___dw ; load TIOS iy value
BCALL(_SetNorm_Vals___db)
pop af
pop bc
pop de
pop hl
pop ix
pop iy
ret
__endasm;
}

#endif
