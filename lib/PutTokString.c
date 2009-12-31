#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void PutTokString(int tok) __naked
{
tok;
__asm
push iy ; not entirely sure we need to save iy
push ix
push hl
push de
push bc
push af
ld iy,#flags___dw ; load TIOS iy value
ld hl,#14
add hl,sp
ld e,(hl)
inc hl
ld d,(hl)
BCALL(_PutTokString___db)
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
