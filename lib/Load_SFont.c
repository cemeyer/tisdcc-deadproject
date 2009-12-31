#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void *Load_SFont(unsigned int offset) __naked
{
offset;
__asm
push de
ld hl,#4
add hl,sp
ld e,(hl)
inc hl
ld h,(hl)
ld l,e
BCALL(_Load_SFont___db)
pop de
ret
__endasm;
}

#endif
