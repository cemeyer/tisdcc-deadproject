#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned char Bit_VertSplit() __naked
{
__asm
ld l,#1
push iy           ; save our iy value
ld iy,#flags___dw ; load TIOS iy value
BCALL(_Bit_VertSplit___db)
jr nz,___split_activeZZ100
dec l
___split_activeZZ100:
pop iy            ; restore iy
ret
__endasm;
}

#endif
