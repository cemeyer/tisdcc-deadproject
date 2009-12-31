#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void SetParM() __naked
{
__asm
push iy
push hl
push de
push bc
push af
ld iy,#flags___dw
BCALL(_SetParM___db)
pop af
pop bc
pop de
pop hl
pop iy
ret
__endasm;
}

#endif
