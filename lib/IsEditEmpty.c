#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned char IsEditEmpty() __naked
{
__asm
push iy ; not entirely sure this is needed
push de
ld l,a
push hl
ld iy,#flags___dw
BCALL(_IsEditEmpty___db)
pop hl
ld a,l
pop de
pop iy
ld l,#1
ret z
dec l
ret
__endasm;
}

#endif
