#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void SetTblGraphDraw() __naked
{
__asm
push iy
ld iy,#flags___dw
BCALL(_SetTblGraphDraw___db)
pop iy
ret
__endasm;
}

#endif
