include bcalls.mk

all: ti83p.lib

ti83p.lib: $(TI83P_BCALLS)
	../../pctools/tisdcc -t ti83p $^ -o ti83p.lib

%.o: %.c
	../../pctools/tisdcc -t ti83p -D TI83P -I `pwd`/../../include/ -c -o $@ $^
