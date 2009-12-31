#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void SaveDisp(void *ptr) __naked
{
ptr;
__asm
push iy
push ix
push hl
push de
push bc
push af
ld iy,#flags___dw ; load TIOS iy value
ld hl,#14
ld a,(hl)
inc hl
ld h,(hl)
ld l,a
BCALL(_SaveDisp___db)
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
