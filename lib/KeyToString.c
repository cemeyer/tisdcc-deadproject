#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

char *KeyToString(int key) __naked
{
key;
__asm
push iy ; not entirely sure this is needed
push af
push bc
push de
ld hl,#10
ld e,(hl)
inc hl
ld d,(hl)
ld iy,#flags___dw
BCALL(_KeyToString___db)
pop de
pop bc
pop af
pop iy
ret
__endasm;
}

#endif
