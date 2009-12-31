#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void ClrLp(void *ptr, unsigned char n) __naked
{
ptr; n;
__asm
push iy
push hl
push bc
ld hl,#10
add hl,sp
ld b,(hl)
dec hl
ld c,(hl)
dec hl
ld l,(hl)
ld h,c
ld iy,#flags___dw
BCALL(_ClrLp___db)
pop bc
pop hl
pop iy
ret
__endasm;
}

#endif
