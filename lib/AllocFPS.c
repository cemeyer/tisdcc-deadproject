#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void AllocFPS(unsigned int entries) __naked
{
entries;
__asm
push iy
ld iy,#flags___dw
push ix
push hl
push de
push bc
push af
ld hl,#14
add hl,sp
ld a,(hl)
inc hl
ld h,(hl)
ld l,a
BCALL(_AllocFPS___db)
pop af
pop bc
pop de
pop hl
pop ix
pop iy
ret
__endasm;
}

#endif
