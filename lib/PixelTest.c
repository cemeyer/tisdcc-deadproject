#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned char PixelTest() __naked
{
__asm
push af
push iy
push ix
push de
push bc
push hl
ld iy,#flags___dw
BCALL(_PixelTest___db)
pop hl
ld l,#1
jr z,___point_is_offZZ103
dec l
___point_is_offZZ103:
pop bc
pop de
pop ix
pop iy
pop af
ret
__endasm;
}

#endif
