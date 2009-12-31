#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void ErrNotEnoughMem(unsigned int size) __naked
{
size;
__asm
push iy
ld iy,#flags___dw
push hl
push af
ld hl,#8
ld a,(hl)
inc hl
ld h,(hl)
ld l,a
BJUMP(_ErrNotEnoughMem___db)
pop af
pop hl
pop iy
ret
__endasm;
}

#endif
