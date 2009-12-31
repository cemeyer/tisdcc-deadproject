#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void CkValidNum() __naked
{
__asm
push af
push iy
push hl
ld iy,#flags___dw
BCALL(_CkValidNum___db)
pop hl
pop iy
pop af
ret
__endasm;
}

#endif
