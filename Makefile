all: make-source

include ./Makefile.inc

.PHONY: make-source clean clean-src all

make-source:
	@cd ./src; $(MAKE) $(MFLAGS)

clean: clean-src

clean-src: $(abspath ./src)
	@cd ./src; $(MAKE) $(MFLAGS) clean