#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void CpyO5ToFPS3() __naked
{
__asm
push iy
push ix
push hl
push de
push bc
push af
ld iy,#flags___dw
BCALL(_CpyO5ToFPS3___db)
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
