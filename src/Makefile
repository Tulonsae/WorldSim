# Makefile
.SILENT:

ROOT = .
include Makefile.inc

MODULES = rng cal people

ALLMODS = $(MODULES:%=all-%)
CLEANMODS = $(MODULES:%=clean-%)
INSTMODS = $(MODULES:%=install-%)
DEINSTMODS = $(MODULES:%=deinstall-%)

all: sim $(ALLMODS)
$(ALLMODS):
	make -C $(@:all-%=%) all

clean: $(CLEANMODS)
$(CLEANMODS):
	make -C $(@:clean-%=%) clean

install: sim $(INSTMODS)
$(INSTMODS):
	make -C $(@:install-%=%) install

deinstall: $(DEINSTMODS)
$(DEINSTMODS):
	make -C $(@:deinstall-%=%) deinstall

dirs: $(LIB) $(INC)
$(INC):
	mkdir -p $(INC)
$(LIB):
	mkdir -p $(LIB)

sim: $(INC)/sim.h
$(INC)/sim.h: $(INC) sim.h
	cp sim.h $(INC)

# need to add a "deinstall" for sim.h
