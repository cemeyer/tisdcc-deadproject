#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void AllocFPS1(unsigned int size) __naked
{
size;
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
BCALL(_AllocFPS1___db)
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
