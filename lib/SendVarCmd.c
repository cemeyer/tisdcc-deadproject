#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void SendVarCmd() __naked
{
__asm
push bc
push de
push ix
push iy
push hl
push af
ld iy,#flags___dw
BCALL(_SendVarCmd___db)
pop af
pop hl
pop iy
pop ix
pop de
pop bc
ret
__endasm;
}

#endif
