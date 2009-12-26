all: includes libs startups

includes:
	cd include/ ; $(MAKE) ; cd ..

libs:
	cd lib/ ; $(MAKE) ; cd ..

startups:
	cd startup/ ; $(MAKE) ; cd ..
