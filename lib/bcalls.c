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
    ld l,#1
    push iy           ; save our iy value
    ld iy,#flags___dw ; load TIOS' iy value
    BCALL(_Bit_VertSplit___db)
    jr nz,screen_is_split
    dec l
screen_is_split:
    pop iy            ; restore iy
    ret
  __endasm;
}

unsigned char CheckSplitFlag() __naked
{
  __asm
    ld l,#0
    push iy           ; save our iy value
    ld iy,#flags___dw ; load TIOS' iy value
    BCALL(_CheckSplitFlag___db)
    jr z,split_inactive
    inc l
split_inactive:
    pop iy            ; restore iy
    ret
  __endasm;
}

void ClearRow(unsigned char a) __naked
{
  a;
  __asm
    push ix
    push de
    push bc
    push af
    ld ix,#0
    add ix,sp
    ld a,10(ix) ; stack is AF, BC, DE, IX, RA, A
    BCALL(_ClearRow___db)
    pop af
    pop bc
    pop de
    pop ix
    ret
  __endasm;
}

void ClrLCD() __naked
{
  __asm
    push bc
    push de
    push hl
    push af
    push ix
    BCALL(_ClrLCD___db)
    pop ix
    pop af
    pop hl
    pop de
    pop bc
    ret
  __endasm;
}

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

void ClrOP2S() __naked
{
  __asm
    BCALL(_ClrOP2S___db)
    ret
  __endasm;
}

void ClrScrn() __naked
{
  __asm
    push ix
    push iy
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw ; load TIOS' iy value
    BCALL(_ClrScrn___db)
    pop af
    pop bc
    pop de
    pop hl
    pop iy
    pop ix
    ret
  __endasm;
}

void ClrScrnFull() __naked
{
  __asm
    push ix
    push iy
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw ; load TIOS' iy value
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

void DispDone() __naked
{
  __asm
    push hl
    BCALL(_DispDone___db)
    pop hl
    ret
  __endasm;
}

void DispHL(int n) __naked
{
  n;
  __asm
    push hl
    push af
    push de
    ld hl,#8
    add hl,sp
    ld a,(hl)
    inc hl
    ld h,(hl)
    ld l,a
    BCALL(_DispHL___db)
    pop de
    pop af
    pop hl
    ret
  __endasm;
}

void DisplayImage(void *img, int loc) __naked
{
  img; loc;
  __asm
    push ix
    push iy
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw ; load TIOS' iy value
    ; stack is AF, BC, DE, HL, IY, IX, RA, img, loc
    ld hl,#17
    add hl,sp
    ld d,(hl)
    dec hl
    ld e,(hl)
    dec hl
    ld a,(hl)
    dec hl
    ld l,(hl)
    ld h,a
    BCALL(_DisplayImage___db)
    pop af
    pop bc
    pop de
    pop hl
    pop iy
    pop ix
    ret
  __endasm;
}

void DispOP1A(unsigned char maxdigits) __naked
{
  maxdigits;
  __asm
    push ix
    push iy
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw ; load TIOS' iy value
    ld hl,#14
    add hl,sp
    ld a,(hl)
    BCALL(_DispOP1A___db)
    pop af
    pop bc
    pop de
    pop hl
    pop iy
    pop ix
    ret
  __endasm;
}

void EraseEOL() __naked
{
  __asm
    push iy
    ld iy,#flags___dw ; load TIOS' iy value
    BCALL(_EraseEOL___db)
    pop iy
    ret
  __endasm;
}

int FormBase() __naked
{
  __asm
    push ix
    push iy
    push de
    push bc
    push af
    ld iy,#flags___dw ; load TIOS' iy value
    BCALL(_FormBase___db)
    ld h,b
    ld l,c
    pop af
    pop bc
    pop de
    pop iy
    pop ix
    ret
  __endasm;
}

int FormDCplx() __naked
{
  __asm
    push ix
    push iy
    push de
    push bc
    push af
    ld iy,#flags___dw ; load TIOS' iy value
    BCALL(_FormDCplx___db)
    ld h,b
    ld l,c
    pop af
    pop bc
    pop de
    pop iy
    pop ix
    ret
  __endasm;
}

int FormEReal(unsigned char maxwidth) __naked
{
  maxwidth;
  __asm
    push ix
    push iy
    push de
    push bc
    push af
    ld iy,#flags___dw ; load TIOS' iy value
    ld hl,#12
    add hl,sp
    ld a,(hl)
    BCALL(_FormEReal___db)
    ld h,b
    ld l,c
    pop af
    pop bc
    pop de
    pop iy
    pop ix
    ret
  __endasm;
}

int FormReal(unsigned char maxwidth) __naked
{
  maxwidth;
  __asm
    push ix
    push iy
    push de
    push bc
    push af
    ld iy,#flags___dw ; load TIOS' iy value
    ld hl,#12
    add hl,sp
    ld a,(hl)
    BCALL(_FormReal___db)
    ld h,b
    ld l,c
    pop af
    pop bc
    pop de
    pop iy
    pop ix
    ret
  __endasm;
}

void LoadPattern(unsigned char charequate) __naked
{
  charequate;
  __asm
    push ix
    push iy
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw ; load TIOS' iy value
    ld hl,#14
    add hl,sp
    ld a,(hl)
    BCALL(_LoadPattern___db)
    pop af
    pop bc
    pop de
    pop hl
    pop iy
    pop ix
    ret
  __endasm;
}

void *Load_SFont(unsigned int offset) __naked
{
  offset;
  __asm
    push de
    ld hl,#4
    add hl,sp
    ld e,(hl)
    inc hl
    ld h,(hl)
    ld l,e
    BCALL(_Load_SFont___db)
    pop de
    ret
  __endasm;
}

void NewLine() __naked
{
  __asm
    push ix
    push iy
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw ; load TIOS' iy value
    BCALL(_NewLine___db)
    pop af
    pop bc
    pop de
    pop hl
    pop iy
    pop ix
    ret
  __endasm;
}


void OutputExpr(unsigned char col, unsigned char row) __naked
{
  col; row;
  __asm
    push ix
    push iy
    push hl
    push de
    push bc
    push af
    ld hl,#14
    add hl,sp
    ld a,(hl)
    inc hl
    ld l,(hl)
    ld h,a
    ld iy,#flags___dw ; load TIOS' iy value
    BCALL(_OutputExpr___db)
    pop af
    pop bc
    pop de
    pop hl
    pop iy
    pop ix
    ret
  __endasm;
}

void PutC(char c) __naked
{
  c;
  __asm
    push iy
    push hl
    ld hl,#6
    add hl,sp
    ld a,(hl)
    ld iy,#flags___dw ; load TIOS' iy value
    BCALL(_PutC___db)
    pop hl
    pop iy
    ret
  __endasm;
}

void PutMap(char c) __naked
{
  c;
  __asm
    push iy
    push hl
    ld hl,#6
    add hl,sp
    ld a,(hl)
    ld iy,#flags___dw ; load TIOS' iy value
    BCALL(_PutMap___db)
    pop hl
    pop iy
    ret
  __endasm;
}

void PutPS(char *str) __naked
{
  str;
  __asm
    push ix
    push iy
    push hl
    push bc
    push af
    ld iy,#flags___dw ; load TIOS' iy value
    ld hl,#12
    add hl,sp
    ld c,(hl)
    inc hl
    ld h,(hl)
    ld l,c
    BCALL(_PutPS___db)
    pop af
    pop bc
    pop hl
    pop iy
    pop ix
    ret
  __endasm;
}

void PutPSB(char *str) __naked
{
  str;
  __asm
    push ix
    push iy
    push hl
    push bc
    push af
    ld iy,#flags___dw ; load TIOS' iy value
    ld hl,#12
    add hl,sp
    ld c,(hl)
    inc hl
    ld h,(hl)
    ld l,c
    BCALL(_PutPSB___db)
    pop af
    pop bc
    pop hl
    pop iy
    pop ix
    ret
  __endasm;
}

void PutS(char *str) __naked
{
  str;
  __asm
    push iy
    push hl
    push af
    ld iy,#flags___dw ; load TIOS' iy value
    ld hl,#8
    add hl,sp
    ld a,(hl)
    inc hl
    ld h,(hl)
    ld l,a
    pop af  ; only need a temporarily to put str in hl
    BCALL(_PutS___db)
    pop hl
    pop iy
    ret
  __endasm;
}

void PutTokString(int tok) __naked
{
  str;
  __asm
    push iy ; not entirely sure we need to save iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw ; load TIOS' iy value
    ld hl,#14
    add hl,sp
    ld e,(hl)
    inc hl
    ld d,(hl)
    BCALL(_PutTokString___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

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
    ld iy,#flags___dw ; load TIOS' iy value
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

void RunIndicOff() __naked
{
  __asm
    push iy
    ld iy,#flags___dw ; load TIOS' iy value
    BCALL(_RunIndicOff___db)
    pop iy
    ret
  __endasm;
}

void RunIndicOn() __naked
{
  __asm
    push iy
    ld iy,#flags___dw ; load TIOS' iy value
    BCALL(_RunIndicOn___db)
    pop iy
    ret
  __endasm;
}

void SaveDisp(void *ptr) __naked
{
  ptr;
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw ; load TIOS' iy value
    ld hl,#14
    ld a,(hl)
    inc hl
    ld h,(hl)
    ld l,a
    BCALL(_SaveDisp___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void SetNorm_Vals() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw ; load TIOS' iy value
    BCALL(_SetNorm_Vals___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

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
    ld iy,#flags___dw ; load TIOS' iy value
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

unsigned int SStringLength(char *str) __naked
{
  str;
  __asm
    push iy
    push ix
    push de
    push bc
    push af
    ld iy,#flags___dw
    ld hl,#12
    add hl,sp
    ld a,(hl)
    inc hl
    ld h,(hl)
    ld l,a
    BCALL(_SStringLength___db)
    ld h,a
    ld l,b
    pop af
    pop bc
    pop de
    pop ix
    pop iy
    ret
  __endasm;
}

void VPutMap(char c) __naked
{
  c;
  __asm
    push iy
    push ix
    push af
    push hl
    ld hl,#10
    add hl,sp
    ld a,(hl)
    ex de,hl
    ld iy,#flags___dw
    BCALL(_VPutMap___db)
    ex de,hl
    pop hl
    pop af
    pop ix
    pop iy
    ret
  __endasm;
}

void VPutS(char *str) __naked
{
  str;
  __asm
    push iy
    push hl
    push bc
    ld hl,#8
    add hl,sp
    ld b,(hl)
    inc hl
    ld h,(hl)
    ld l,b
    ld iy,#flags___dw
    BCALL(_VPutS___db)
    pop bc
    pop hl
    pop iy
    ret
  __endasm;
}

void VPutSN(char *str, unsigned char len) __naked
{
  str;
  __asm
    push iy
    push hl
    push bc
    ld hl,#10
    add hl,sp
    ld b,(hl)
    dec hl
    ld c,(hl)
    dec hl
    ld l,(hl)
    ld h,c
    ld iy,#flags___dw
    BCALL(_VPutSN___db)
    pop bc
    pop hl
    pop iy
    ret
  __endasm;
}
#endif
