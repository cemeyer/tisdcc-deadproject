#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void InvSub() __naked
{
__asm
push af
push bc
push de
push hl
push iy
ld iy,#flags___dw
BCALL(_InvSub___db)
pop iy
pop hl
pop de
pop bc
pop af
ret
__endasm;
}

#endif
