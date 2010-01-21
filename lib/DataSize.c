#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned long DataSize(unsigned char type, unsigned int size) __naked
{
type; size;
__asm
push iy
ld iy,#flags___dw
push bc
ld hl,#6
add hl,sp
ld a,(hl)
inc hl
ld e,(hl)
inc hl
ld d,(hl)
ex de,hl
BCALL(_DataSize___db)
pop bc
pop iy
ret
__endasm;
}

#endif
