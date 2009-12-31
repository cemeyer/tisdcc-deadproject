#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

char CpOP4OP3() __naked
{
__asm
push iy
push de
push bc
push af
push hl
ld iy,#flags___dw
BCALL(_CpOP4OP3___db)
pop hl
ld l,#0
jr z,___doneZZ136
dec l
jr c,___doneZZ136
inc l
inc l
___doneZZ136:
pop af
pop bc
pop de
pop iy
ret
__endasm;
}

#endif
