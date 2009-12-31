#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void SetAllPlots(unsigned char select) __naked
{
select;
__asm
push iy
push ix
push hl
push de
push bc
push af
ld iy,#flags___dw
ld hl,#14
add hl,sp
ld b,(hl)
BCALL(_SetAllPlots___db)
pop af
pop bc
pop de
pop hl
pop ix
pop iy
ret
__endasm;
}

#endif
