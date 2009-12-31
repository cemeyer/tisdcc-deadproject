#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned char CkInt(void *ptr) __naked
{
ptr;
__asm
push af
push bc
push de
push hl
push ix
push iy
ld iy,#flags___dw
ld hl,#14
add hl,sp
ld a,(hl)
inc hl
ld h,(hl)
ld l,a
BCALL(_CkInt___db)
pop iy
pop ix
pop hl
ld l,#1
jr z,___doneZZ124
dec l
___doneZZ124:
pop de
pop bc
pop af
ret
__endasm;
}

#endif
