include bcalls.mk

SDCC = sdcc
SDCCLIB = sdcclib

all: ti83p.lib

ti83p.lib: $(TI83P_BCALLS)
	rm -f ti83p.lib
	$(SDCCLIB) ti83p.lib $^

%.o: %.c
	$(SDCC) -mz80 -DTI83P -I../include/ -c -o $@ $^
	rm $*.asm $*.lst $*.sym
