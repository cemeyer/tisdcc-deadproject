#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void ClrOP1S() __naked
{
__asm
push iy
ld iy,#flags___dw
BCALL(_ClrOP1S___db)
pop iy
ret
__endasm;
}

#endif
