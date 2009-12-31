#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned long DivHLBy10(unsigned int hl) __naked
{
hl;
__asm
push af
ld hl,#4
add hl,sp
ld a,(hl)
inc hl
ld h,(hl)
ld l,a
BCALL(_DivHLBy10___db)
ld e,a
ld d,#0
pop af
ret
__endasm;
}

#endif
