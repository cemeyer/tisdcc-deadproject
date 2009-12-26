SDCCAS = sdcc-as-z80

all: objects

objects:
	for sfile in *.s; do $(SDCCAS) -o "$${sfile/.s/.o}" "$$sfile" ; done
