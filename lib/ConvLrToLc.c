#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void *ConvLrToLc(void *ptr) __naked
{
ptr;
__asm
push iy
ld iy,#flags___dw
push ix
push af
push bc
push de
ld hl,#12
add hl,sp
ld e,(hl)
inc hl
ld d,(hl)
BCALL(_ConvLrToLc___db)
ex de,hl
pop de
pop bc
pop af
pop ix
pop iy
ret
__endasm;
}

#endif
