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
    ld iy,#flags___dw ; load TIOS iy value
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
    ld iy,#flags___dw ; load TIOS iy value
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
    ld iy,#flags___dw ; load TIOS iy value
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
    ld iy,#flags___dw ; load TIOS iy value
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
    ld iy,#flags___dw ; load TIOS iy value
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
    ld iy,#flags___dw ; load TIOS iy value
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
    ld iy,#flags___dw ; load TIOS iy value
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
    ld iy,#flags___dw ; load TIOS iy value
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
    ld iy,#flags___dw ; load TIOS iy value
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
    ld iy,#flags___dw ; load TIOS iy value
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
    ld iy,#flags___dw ; load TIOS iy value
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
    ld iy,#flags___dw ; load TIOS iy value
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
    ld iy,#flags___dw ; load TIOS iy value
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
    ld iy,#flags___dw ; load TIOS iy value
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
    ld iy,#flags___dw ; load TIOS iy value
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
    ld iy,#flags___dw ; load TIOS iy value
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
    ld iy,#flags___dw ; load TIOS iy value
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
    ld iy,#flags___dw ; load TIOS iy value
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
  tok;
  __asm
    push iy ; not entirely sure we need to save iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw ; load TIOS iy value
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

void RunIndicOff() __naked
{
  __asm
    push iy
    ld iy,#flags___dw ; load TIOS iy value
    BCALL(_RunIndicOff___db)
    pop iy
    ret
  __endasm;
}

void RunIndicOn() __naked
{
  __asm
    push iy
    ld iy,#flags___dw ; load TIOS iy value
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
    ld iy,#flags___dw ; load TIOS iy value
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
    ld iy,#flags___dw ; load TIOS iy value
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
  str; len;
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

void CloseEditBuf() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CloseEditBuf___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CloseEditBufNoR() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CloseEditBufNoR___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CloseEditEqu() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CloseEditEqu___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CursorOff() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CursorOff___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CursorOn() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CursorOn___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void DispEOL() __naked
{
  __asm
    push iy ; not entirely sure this is needed
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_DispEOL___db)
    pop af
    pop bc
    pop de
    pop hl
    pop iy
    ret
  __endasm;
}

unsigned char IsEditEmpty() __naked
{
  __asm
    push iy ; not entirely sure this is needed
    push de
    ld l,a
    push hl
    ld iy,#flags___dw
    BCALL(_IsEditEmpty___db)
    pop hl
    ld a,l
    pop de
    pop iy
    ld l,1
    ret z
    dec l
    ret
  __endasm;
}

char *KeyToString(int key) __naked
{
  key;
  __asm
    push iy ; not entirely sure this is needed
    push af
    push bc
    push de
    ld hl,#10
    ld e,(hl)
    inc hl
    ld d,(hl)
    ld iy,#flags___dw
    BCALL(_KeyToString___db)
    pop de
    pop bc
    pop af
    pop iy
    ret
  __endasm;
}

void ReleaseBuffer() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_ReleaseBuffer___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void ErrArgument() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BJUMP(_ErrArgument___db)
    pop iy
    ret
  __endasm;
}

void ErrBadGuess() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BJUMP(_ErrBadGuess___db)
    pop iy
    ret
  __endasm;
}

void ErrBreak() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BJUMP(_ErrBreak___db)
    pop iy
    ret
  __endasm;
}

void ErrD_OP1_0() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    push af
    BJUMP(_ErrD_OP1_0___db)
    pop af
    pop iy
    ret
  __endasm;
}

void ErrD_OP1_LE_0() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    push af
    BJUMP(_ErrD_OP1_LE_0___db)
    pop af
    pop iy
    ret
  __endasm;
}

void ErrD_OP1Not_R() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    push af
    BJUMP(_ErrD_OP1Not_R___db)
    pop af
    pop iy
    ret
  __endasm;
}

void ErrD_OP1NotPos() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    push af
    BJUMP(_ErrD_OP1NotPos___db)
    pop af
    pop iy
    ret
  __endasm;
}

void ErrD_OP1NotPosInt() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    push af
    BJUMP(_ErrD_OP1NotPosInt___db)
    pop af
    pop iy
    ret
  __endasm;
}

void ErrDataType() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BJUMP(_ErrDataType___db)
    pop iy
    ret
  __endasm;
}

void ErrDimension() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BJUMP(_ErrDimension___db)
    pop iy
    ret
  __endasm;
}

void ErrDimMismatch() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BJUMP(_ErrDimMismatch___db)
    pop iy
    ret
  __endasm;
}

void ErrDivBy0() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BJUMP(_ErrDivBy0___db)
    pop iy
    ret
  __endasm;
}

void ErrDomain() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BJUMP(_ErrDomain___db)
    pop iy
    ret
  __endasm;
}

void ErrIncrement() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BJUMP(_ErrIncrement___db)
    pop iy
    ret
  __endasm;
}

void ErrInvalid() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BJUMP(_ErrInvalid___db)
    pop iy
    ret
  __endasm;
}

void ErrIterations() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BJUMP(_ErrIterations___db)
    pop iy
    ret
  __endasm;
}

void ErrLinkXmit() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BJUMP(_ErrLinkXmit___db)
    pop iy
    ret
  __endasm;
}

void ErrMemory() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BJUMP(_ErrMemory___db)
    pop iy
    ret
  __endasm;
}

void ErrNon_Real() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BJUMP(_ErrNon_Real___db)
    pop iy
    ret
  __endasm;
}

void ErrNonReal(unsigned char numargs) __naked
{
  numargs;
  __asm
    push iy
    ld iy,#flags___dw
    push hl
    ld l,c
    ld c,a
    push bc ; save b, a
    ld c,l
    ld hl,#8
    add hl,sp
    ld b,(hl)
    BJUMP(_ErrNonReal___db)
    ld l,c
    pop bc
    ld a,c
    ld c,l
    pop hl
    pop iy
    ret
  __endasm;
}

void ErrNotEnoughMem(unsigned int size) __naked
{
  size;
  __asm
    push iy
    ld iy,#flags___dw
    push hl
    push af
    ld hl,#8
    ld a,(hl)
    inc hl
    ld h,(hl)
    ld l,a
    BJUMP(_ErrNotEnoughMem___db)
    pop af
    pop hl
    pop iy
    ret
  __endasm;
}

void ErrOverflow() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BJUMP(_ErrOverflow___db)
    pop iy
    ret
  __endasm;
}

void ErrSignChange() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BJUMP(_ErrSignChange___db)
    pop iy
    ret
  __endasm;
}

void ErrSingularMat() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BJUMP(_ErrSingularMat___db)
    pop iy
    ret
  __endasm;
}

void ErrStat() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BJUMP(_ErrStat___db)
    pop iy
    ret
  __endasm;
}

void ErrStatPlot() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BJUMP(_ErrStatPlot___db)
    pop iy
    ret
  __endasm;
}

void ErrSyntax() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BJUMP(_ErrSyntax___db)
    pop iy
    ret
  __endasm;
}

void ErrTolTooSmall() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BJUMP(_ErrTolTooSmall___db)
    pop iy
    ret
  __endasm;
}

void ErrUndefined() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BJUMP(_ErrUndefined___db)
    pop iy
    ret
  __endasm;
}

void JError(unsigned char flags) __naked
{
  flags;
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    ld hl,#14
    add hl,sp
    ld a,(hl)
    BJUMP(_ErrUndefined___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void JErrorNo() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BJUMP(_ErrUndefined___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void AllocFPS(unsigned int entries) __naked
{
  entries;
  __asm
    push iy
    ld iy,#flags___dw
    push ix
    push hl
    push de
    push bc
    push af
    ld hl,#14
    add hl,sp
    ld a,(hl)
    inc hl
    ld h,(hl)
    ld l,a
    BCALL(_AllocFPS___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void AllocFPS1(unsigned int size) __naked
{
  size;
  __asm
    push iy
    ld iy,#flags___dw
    push ix
    push hl
    push de
    push bc
    push af
    ld hl,#14
    add hl,sp
    ld a,(hl)
    inc hl
    ld h,(hl)
    ld l,a
    BCALL(_AllocFPS1___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyStack(unsigned char bytes, void *freebyte, void *copyto) __naked
{
  bytes; freebyte; copyto;
  __asm
    push iy
    ld iy,#flags___dw
    push ix
    push hl
    push de
    push bc
    push af
    ld hl,#14
    ld c,(hl)
    inc hl
    ld e,(hl)
    inc hl
    ld d,(hl)
    inc hl
    ld b,(hl)
    inc hl
    ld h,(hl)
    ld l,b
    ex de,hl
    BCALL(_CpyStack___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyO1ToFPST() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyO1ToFPST___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyO1ToFPS1() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyO1ToFPS1___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyO1ToFPS2() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyO1ToFPS2___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyO1ToFPS3() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyO1ToFPS3___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyO1ToFPS4() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyO1ToFPS4___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyO1ToFPS5() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyO1ToFPS5___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyO1ToFPS6() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyO1ToFPS6___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyO1ToFPS7() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyO1ToFPS7___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyO2ToFPST() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyO2ToFPST___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyO2ToFPS1() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyO2ToFPS1___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyO2ToFPS2() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyO2ToFPS2___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyO2ToFPS3() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyO2ToFPS3___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyO2ToFPS4() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyO2ToFPS4___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyO3ToFPST() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyO3ToFPST___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyO3ToFPS1() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyO3ToFPS1___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyO3ToFPS2() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyO3ToFPS2___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyO5ToFPS1() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyO5ToFPS1___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyO5ToFPS3() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyO5ToFPS3___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyO6ToFPST() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyO6ToFPST___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyO6ToFPS2() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyO6ToFPS2___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyTo1FPST() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyTo1FPST___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyTo1FPS1() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyTo1FPS1___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyTo1FPS2() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyTo1FPS2___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyTo1FPS3() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyTo1FPS3___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyTo1FPS4() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyTo1FPS4___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyTo1FPS5() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyTo1FPS5___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyTo1FPS6() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyTo1FPS6___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyTo1FPS7() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyTo1FPS7___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyTo1FPS8() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyTo1FPS8___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyTo1FPS9() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyTo1FPS9___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyTo1FPS10() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyTo1FPS10___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyTo1FPS11() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyTo1FPS11___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyTo2FPST() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyTo2FPST___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyTo2FPS1() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyTo2FPS1___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyTo2FPS2() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyTo2FPS2___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyTo2FPS3() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyTo2FPS3___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyTo2FPS4() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyTo2FPS4___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyTo2FPS5() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyTo2FPS5___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyTo2FPS6() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyTo2FPS6___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyTo2FPS7() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyTo2FPS7___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyTo2FPS8() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyTo2FPS8___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyTo3FPST() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyTo3FPST___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyTo3FPS1() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyTo3FPS1___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyTo3FPS2() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyTo3FPS2___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyTo4FPST() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyTo4FPST___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyTo5FPST() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyTo5FPST___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyTo6FPST() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyTo6FPST___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyTo6FPS2() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyTo6FPS2___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyTo6FPS3() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_CpyTo6FPS3___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyToFPST(void *ptr) __naked
{
  ptr;
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld hl,#14
    add hl,sp
    ld e,(hl)
    inc hl
    ld d,(hl)
    ld iy,#flags___dw
    BCALL(_CpyToFPST___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyToFPS1(void *ptr) __naked
{
  ptr;
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld hl,#14
    add hl,sp
    ld e,(hl)
    inc hl
    ld d,(hl)
    ld iy,#flags___dw
    BCALL(_CpyToFPS1___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyToFPS2(void *ptr) __naked
{
  ptr;
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld hl,#14
    add hl,sp
    ld e,(hl)
    inc hl
    ld d,(hl)
    ld iy,#flags___dw
    BCALL(_CpyToFPS2___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyToFPS3(void *ptr) __naked
{
  ptr;
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld hl,#14
    add hl,sp
    ld e,(hl)
    inc hl
    ld d,(hl)
    ld iy,#flags___dw
    BCALL(_CpyToFPS3___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void CpyToStack(unsigned char bytes, void *freebyte, void *from) __naked
{
  bytes; freebyte; from;
  __asm
    push iy
    ld iy,#flags___dw
    push ix
    push hl
    push de
    push bc
    push af
    ld hl,#14
    ld c,(hl)
    inc hl
    ld e,(hl)
    inc hl
    ld d,(hl)
    inc hl
    ld b,(hl)
    inc hl
    ld h,(hl)
    ld l,b
    ex de,hl
    BCALL(_CpyToStack___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void PopMCplxO1() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_PopMCplxO1___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void PopOP1() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_PopOP1___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void PopOP3() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_PopOP3___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void PopOP5() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_PopOP5___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void PopReal(void *ptr) __naked
{
  ptr;
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    ld hl,#14
    add hl,sp
    ld e,(hl)
    inc hl
    ld d,(hl)
    ld iy,#flags___dw
    BCALL(_PopReal___db)
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void PopRealO1() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BCALL(_PopRealO1___db)
    pop iy
    ret
  __endasm;
}

void PopRealO2() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BCALL(_PopRealO2___db)
    pop iy
    ret
  __endasm;
}

void PopRealO3() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BCALL(_PopRealO3___db)
    pop iy
    ret
  __endasm;
}

void PopRealO4() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BCALL(_PopRealO4___db)
    pop iy
    ret
  __endasm;
}

void PopRealO5() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BCALL(_PopRealO5___db)
    pop iy
    ret
  __endasm;
}

void PopRealO6() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BCALL(_PopRealO6___db)
    pop iy
    ret
  __endasm;
}

void PushMCplxO1() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_PushMCplxO1___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void PushMCplxO3() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_PushMCplxO3___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void PushOP1() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_PushOP1___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void PushOP3() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_PushOP3___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void PushOP5() __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld iy,#flags___dw
    BCALL(_PushOP5___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void PushReal(void *ptr) __naked
{
  __asm
    push iy
    push ix
    push hl
    push de
    push bc
    push af
    ld hl,#14
    ld a,(hl)
    inc hl
    ld h,(hl)
    ld l,a
    ld iy,#flags___dw
    BCALL(_PushReal___db)
    pop af
    pop bc
    pop de
    pop hl
    pop ix
    pop iy
    ret
  __endasm;
}

void PushRealO1() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BCALL(_PushRealO1___db)
    pop iy
    ret
  __endasm;
}

void PushRealO2() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BCALL(_PushRealO2___db)
    pop iy
    ret
  __endasm;
}

void PushRealO3() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BCALL(_PushRealO3___db)
    pop iy
    ret
  __endasm;
}

void PushRealO4() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BCALL(_PushRealO4___db)
    pop iy
    ret
  __endasm;
}

void PushRealO5() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BCALL(_PushRealO5___db)
    pop iy
    ret
  __endasm;
}

void PushRealO6() __naked
{
  __asm
    push iy
    ld iy,#flags___dw
    BCALL(_PushRealO6___db)
    pop iy
    ret
  __endasm;
}
#endif
