#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned char SFont_Len(unsigned int offset) __naked
{
offset;
__asm
push iy
push ix
push de
push bc
ld l,a      ; save h, a on stack
push hl     ; (we trash l and f safely)
ld iy,#flags___dw ; load TIOS iy value
ld hl,#12   ; load offset off the stack
add hl,sp
ld a,(hl)
inc hl
ld h,(hl)
ld l,a
BCALL(_SFont_Len___db)
pop hl
ld b,a  ; swap l, a
ld a,l
ld l,b
pop bc
pop de
pop ix
pop iy
ret
__endasm;
}

#endif
