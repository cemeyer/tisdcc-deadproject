#ifdef TI83P
unsigned char Bit_VertSplit();
unsigned char CheckSplitFlag();
void ClearRow(unsigned char a);
void ClrLCD();
void ClrLCDFull();
void ClrOP2S();
void ClrScrn();
void ClrScrnFull();
void ClrTxtShd();
void DispDone();
void DispHL(int n);
void DisplayImage(void *img, int loc);
void DispOP1A(unsigned char maxdigits);
void EraseEOL();
int FormBase();
int FormDCplx();
int FormEReal(unsigned char maxwidth);
int FormReal(unsigned char maxwidth);
void LoadPattern(unsigned char charequate);
#endif
