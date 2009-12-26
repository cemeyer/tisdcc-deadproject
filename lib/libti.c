#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>
#else
# error "NEED TI83P"
#endif

#ifdef TI83P
unsigned char Bit_VertSplit() __naked
{
  __asm
    .db 0x2E, 0x01    ;   ld l,1
    BCALL(_Bit_VertSplit___)
    jr nz,screen_is_split
    dec l
screen_is_split:
    ret
  __endasm;
}
#endif
