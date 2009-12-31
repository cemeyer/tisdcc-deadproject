#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned char Rec1stByte() __naked
{
__asm
push bc
push de
push ix
push iy
ld l,a
push hl
ld iy,#flags___dw
BCALL(_Rec1stByte___db)
pop hl
ld b,a
ld a,l
ld l,b
pop iy
pop ix
pop de
pop bc
ret
__endasm;
}

#endif
