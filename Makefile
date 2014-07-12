all: make-source

P_DIR = /home/rapid/Desktop/repository/rp-mdedit

include $(P_DIR)/Makefile.inc

.PHONY: make-source clean clean-src all

make-source: $(P_DIR)/src
	@cd $(P_DIR)/src; $(MAKE) $(MFLAGS)

clean: clean-src

clean-src: $(P_DIR)/src
	@cd $(P_DIR)/src; $(MAKE) $(MFLAGS) clean
