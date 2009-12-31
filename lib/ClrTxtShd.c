#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void ClrTxtShd() __naked
{
__asm
push bc
push de
push hl
BCALL(_ClrTxtShd___db)
pop hl
pop de
pop bc
ret
__endasm;
}

#endif
