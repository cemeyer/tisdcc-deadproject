#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void PopRealO3() __naked
{
__asm
push iy
ld iy,#flags___dw
BCALL(_PopRealO3___db)
pop iy
ret
__endasm;
}

#endif
