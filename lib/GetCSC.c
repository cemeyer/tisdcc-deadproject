#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned char GetCSC() __naked
{
__asm
push iy
push af
push hl
ld iy,#flags___dw
BCALL(_GetCSC___db)
pop hl
ld l,a
pop af
pop iy
ret
__endasm;
}

#endif
