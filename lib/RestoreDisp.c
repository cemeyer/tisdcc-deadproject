#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

void RestoreDisp(void *data, unsigned char numrows) __naked
{
data; numrows;
__asm
push iy ; not entirely sure we need to save iy
push ix
push hl
push de
push bc
push af
ld iy,#flags___dw ; load TIOS iy value
ld hl,#16
add hl,sp
ld b,(hl)
dec hl
ld c,(hl)
dec hl
ld l,(hl)
ld h,c
BCALL(_RestoreDisp___db)
pop af
pop bc
pop de
pop hl
pop ix
pop iy
ret
__endasm;
}

#endif
