#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned char ToFrac() __naked
{
__asm
push af
push bc
push de
push ix
push iy
push hl
ld iy,#flags___dw
BCALL(_ToFrac___db)
pop hl
ld l,#0
jr c,___failureZZ105
inc l
___failureZZ105:
pop iy
pop ix
pop de
pop bc
pop af
ret
__endasm;
}

#endif
