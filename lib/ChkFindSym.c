#ifdef TI83P
# include <ti83pdefs.h>
# include <ti83p.h>

unsigned char ChkFindSym(unsigned char *typeflags, unsigned char *rompage,
    void **symtblentryptrptr, void **dataareaptrptr) __naked
{
typeflags; rompage; symtblentryptrptr; dataareaptrptr;
__asm
push af
push bc
push de
push hl
push ix
push iy
ld iy,#flags___dw
BCALL(_ChkFindSym___db)
ld c,#1
jr c,___symbolnotfoundZZ140
dec c
___symbolnotfoundZZ140:
push de
push hl
; typeflags
ld hl,#18
add hl,sp
ld e,(hl)
inc hl
ld d,(hl)
inc hl
ex de,hl
ld (hl),a ; type, flags
ex de,hl
; rompage
ld e,(hl)
inc hl
ld d,(hl)
inc hl
ex de,hl
ld (hl),b ; rom page (or 0 for ram)
ex de,hl
; symtblentryptrptr
ld e,(hl)
inc hl
ld d,(hl)
ld a,c
pop bc ; hl from bcall
ex de,hl
ld (hl),c
inc hl
ld (hl),b
ex de,hl
; dataareaptrptr
inc hl
ld e,(hl)
inc hl
ld d,(hl)
ex de,hl
pop de  ; de from bcall
ld (hl),e
inc hl
ld (hl),d
; everything is stored; ret value in a.
; stack is: iy ix hl de bc af
pop iy
pop ix
pop hl
ld l,a
pop de
pop bc
pop af
ret
__endasm;
}

#endif
