#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void ClrLCDFull() __naked
{
__asm
push bc
push de
push hl
push af
push ix
BCALL(_ClrLCDFull___db)
pop ix
pop af
pop hl
pop de
pop bc
ret
__endasm;
}

#endif
