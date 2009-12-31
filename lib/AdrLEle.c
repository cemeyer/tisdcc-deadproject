#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void *AdrLEle(void *list, unsigned int index) __naked
{
list; index;
__asm
push iy
ld iy,#flags___dw
push af
push bc
push de
ld hl,#10
add hl,sp
ld e,(hl)
inc hl
ld d,(hl)
inc hl
ld a,(hl)
inc hl
ld h,(hl)
ld l,a
BCALL(_AdrLEle___db)
pop de
pop bc
pop af
pop iy
ret
__endasm;
}

#endif
