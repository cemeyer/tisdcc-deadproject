#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void PushRealO6() __naked
{
__asm
push iy
ld iy,#flags___dw
BCALL(_PushRealO6___db)
pop iy
ret
__endasm;
}

#endif
