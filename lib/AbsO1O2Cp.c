#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

char AbsO1O2Cp() __naked
{
__asm
push iy
push de
push bc
push af
push hl
ld iy,#flags___dw
BCALL(_AbsO1O2Cp___db)
pop hl
ld l,#0
jr z,___doneZZ123
dec l
jr c,___doneZZ123
inc l
inc l
___doneZZ123:
pop af
pop bc
pop de
pop iy
ret
__endasm;
}

#endif
