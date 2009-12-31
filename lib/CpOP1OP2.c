#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

char CpOP1OP2() __naked
{
__asm
push iy
push de
push bc
push af
push hl
ld iy,#flags___dw
BCALL(_CpOP1OP2___db)
pop hl
ld l,#0
jr z,___doneZZ135
dec l
jr c,___doneZZ135
inc l
inc l
___doneZZ135:
pop af
pop bc
pop de
pop iy
ret
__endasm;
}

#endif
