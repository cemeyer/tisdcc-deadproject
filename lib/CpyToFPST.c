#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void CpyToFPST(void *ptr) __naked
{
ptr;
__asm
push iy
push ix
push hl
push de
push bc
push af
ld hl,#14
add hl,sp
ld e,(hl)
inc hl
ld d,(hl)
ld iy,#flags___dw
BCALL(_CpyToFPST___db)
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
