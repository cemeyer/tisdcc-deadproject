#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void ClrScrnFull() __naked
{
__asm
push ix
push iy
push hl
push de
push bc
push af
ld iy,#flags___dw ; load TIOS iy value
BCALL(_ClrScrnFull___db)
pop af
pop bc
pop de
pop hl
pop iy
pop ix
ret
__endasm;
}

#endif
