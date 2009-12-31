#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void DispEOL() __naked
{
__asm
push iy ; not entirely sure this is needed
push hl
push de
push bc
push af
ld iy,#flags___dw
BCALL(_DispEOL___db)
pop af
pop bc
pop de
pop hl
pop iy
ret
__endasm;
}

#endif
