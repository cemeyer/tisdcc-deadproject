#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void VPutMap(char c) __naked
{
c;
__asm
push iy
push ix
push af
push hl
ld hl,#10
add hl,sp
ld a,(hl)
ex de,hl
ld iy,#flags___dw
BCALL(_VPutMap___db)
ex de,hl
pop hl
pop af
pop ix
pop iy
ret
__endasm;
}

#endif
