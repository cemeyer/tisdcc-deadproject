all: ti83p.lib

ti83p.lib: ti83p_bcalls.o
	../pctools/tisdcc -t ti83p $* -o ti83p.lib

ti83p_bcalls.o: bcalls.c
	../pctools/tisdcc -t ti83p -D TI83P -I `pwd`/../include/ -c -o ti83p_bcalls.o bcalls.c
