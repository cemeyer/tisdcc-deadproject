#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned char CheckSplitFlag() __naked
{
__asm
ld l,#0
push iy           ; save our iy value
ld iy,#flags___dw ; load TIOS iy value
BCALL(_CheckSplitFlag___db)
jr z,___split_inactiveZZ101
inc l
___split_inactiveZZ101:
pop iy            ; restore iy
ret
__endasm;
}

#endif
