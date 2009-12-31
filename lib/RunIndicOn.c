#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void RunIndicOn() __naked
{
__asm
push iy
ld iy,#flags___dw ; load TIOS iy value
BCALL(_RunIndicOn___db)
pop iy
ret
__endasm;
}

#endif
