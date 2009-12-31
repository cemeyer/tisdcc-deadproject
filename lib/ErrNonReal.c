#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void ErrNonReal(unsigned char numargs) __naked
{
numargs;
__asm
push iy
ld iy,#flags___dw
push hl
ld l,c
ld c,a
push bc ; save b, a
ld c,l
ld hl,#8
add hl,sp
ld b,(hl)
BJUMP(_ErrNonReal___db)
ld l,c
pop bc
ld a,c
ld c,l
pop hl
pop iy
ret
__endasm;
}

#endif
