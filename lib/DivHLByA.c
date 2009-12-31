#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned long DivHLByA(unsigned int hl, unsigned char a) __naked
{
hl; a;
__asm
push af
push bc
ld hl,#8
add hl,sp
ld a,(hl)
dec hl
ld b,(hl)
dec hl
ld l,(hl)
ld h,b
BCALL(_DivHLByA___db)
ld e,a
ld d,#0
pop bc
pop af
ret
__endasm;
}

#endif
