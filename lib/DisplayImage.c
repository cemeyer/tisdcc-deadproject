#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void DisplayImage(void *img, int loc) __naked
{
img; loc;
__asm
push ix
push iy
push hl
push de
push bc
push af
ld iy,#flags___dw ; load TIOS iy value
; stack is AF, BC, DE, HL, IY, IX, RA, img, loc
ld hl,#17
add hl,sp
ld d,(hl)
dec hl
ld e,(hl)
dec hl
ld a,(hl)
dec hl
ld l,(hl)
ld h,a
BCALL(_DisplayImage___db)
pop af
pop bc
pop de
pop hl
pop iy
pop ix
ret
__endasm;
}

#endif
