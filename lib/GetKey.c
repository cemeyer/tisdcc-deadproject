#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned char GetKey() __naked
{
__asm
push iy
push de
ld l,a
push hl
ld iy,#flags___dw
BCALL(_GetKey___db)
pop hl
ld d,a
ld a,l
ld l,d
pop de
pop iy
ret
__endasm;
}

#endif
