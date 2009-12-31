#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned char IBoundsFull(unsigned char x, unsigned char y) __naked
{
x; y;
__asm
push iy
push bc
push hl
ld iy,#flags___dw
ld hl,#8
add hl,sp
ld b,(hl)
inc hl
ld c,(hl)
BCALL(_IBoundsFull___db)
pop hl
pop bc
pop iy
ld l,#1
ret c
dec l
ret
__endasm;
}

#endif
