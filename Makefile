NAME = tisdcc

SDCC = sdcc
SDCCAS = sdcc-as-z80
SDCCLIB = sdcclib

DESTDIR = 

PREFIX = /usr/local
BINDIR = $(PREFIX)/bin
DATADIR = $(PREFIX)/share
DOCDIR = $(DATADIR)/doc

all: includes libs startups

includes:
	cd include/ ; $(MAKE) ; cd ..

libs: includes
	cd lib/ ; $(MAKE) SDCC=$(SDCC) SDCCLIB=$(SDCCLIB) ; cd ..

startups: includes
	cd startup/ ; $(MAKE) SDCCAS=$(SDCCAS) ; cd ..

install: all
	echo "PREFIX: $(PREFIX) BINDIR: $(BINDIR) DESTDIR: $(DESTDIR)"
	mkdir -p install-prep
	cp pctools/libtisdcc.py install-prep/
	cp pctools/tisdcc install-prep/
	mkdir -p install-prep/include/
	mkdir -p install-prep/lib/
	mkdir -p install-prep/startup/
	mkdir -p install-prep/doc/
	cp include/*.h install-prep/include/
	cp lib/*.lib install-prep/lib/
	cp startup/*.o install-prep/startup/
	cp doc/index.html install-prep/doc/
	sed -i -e 's|^DATADIR=.*$$|DATADIR="$(DATADIR)"|' \
	  install-prep/tisdcc install-prep/libtisdcc.py
	mkdir -p $(DESTDIR)$(BINDIR)
	mkdir -p $(DESTDIR)$(DATADIR)/$(NAME)/startup/
	mkdir -p $(DESTDIR)$(DATADIR)/$(NAME)/lib/
	mkdir -p $(DESTDIR)$(DATADIR)/$(NAME)/include/
	install -m755 install-prep/tisdcc $(DESTDIR)$(BINDIR)/
	install -m644 install-prep/libtisdcc.py $(DESTDIR)$(DATADIR)/$(NAME)/
	install -m644 install-prep/lib/* $(DESTDIR)$(DATADIR)/$(NAME)/lib/
	install -m644 install-prep/startup/* $(DESTDIR)$(DATADIR)/$(NAME)/startup/
	install -m644 install-prep/include/* $(DESTDIR)$(DATADIR)/$(NAME)/include/
