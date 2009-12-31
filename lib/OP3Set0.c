#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void OP3Set0() __naked
{
__asm
push af
push hl
push iy
ld iy,#flags___dw
BCALL(_OP3Set0___db)
pop iy
pop hl
pop af
ret
__endasm;
}

#endif
