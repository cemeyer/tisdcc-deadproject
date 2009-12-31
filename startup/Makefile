startupobjs = \
ti73_app1.o \
ti73_app2.o \
ti73_mallard1.o \
ti73_mallard2.o \
ti82_crash1.o \
ti82_crash2.o \
ti831.o \
ti832.o \
ti83_ion1.o \
ti83_ion2.o \
ti83p1.o \
ti83p2.o \
ti83p_app1.o \
ti83p_app2.o \
ti83p_appi1.o \
ti83p_appi2.o \
ti83p_asmi1.o \
ti83p_asmi2.o \
ti83p_ion1.o \
ti83p_ion2.o \
ti83p_ioni1.o \
ti83p_ioni2.o \
ti85_zshell1.o \
ti85_zshell2.o \
ti86_crash1.o \
ti86_crash2.o

SDCCAS = sdcc-as-z80

all: $(startupobjs)

%.o: %.s
	$(SDCCAS) -o "$@" "$<"
