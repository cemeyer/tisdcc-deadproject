#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void OP1ExpToDec() __naked
{
__asm
push af
push bc
push iy
ld iy,#flags___dw
BCALL(_OP1ExpToDec___db)
pop iy
pop bc
pop af
ret
__endasm;
}

#endif
