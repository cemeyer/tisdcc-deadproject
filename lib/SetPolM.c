#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void SetPolM() __naked
{
__asm
push iy
push hl
push de
push bc
push af
ld iy,#flags___dw
BCALL(_SetPolM___db)
pop af
pop bc
pop de
pop hl
pop iy
ret
__endasm;
}

#endif
