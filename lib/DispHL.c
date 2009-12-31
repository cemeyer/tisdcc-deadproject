#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void DispHL(int n) __naked
{
n;
__asm
push hl
push af
push de
ld hl,#8
add hl,sp
ld a,(hl)
inc hl
ld h,(hl)
ld l,a
BCALL(_DispHL___db)
pop de
pop af
pop hl
ret
__endasm;
}

#endif
