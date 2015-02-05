# Makefile

ROOT = .
include Makefile.inc

MODULES = rng cal gender fertility

ALLMODS = $(MODULES:%=all-%)
CLEANMODS = $(MODULES:%=clean-%)
INSTMODS = $(MODULES:%=install-%)
DEINSTMODS = $(MODULES:%=deinstall-%)
TESTMODS = $(MODULES:%=runtest-%)

test: install $(TESTMODS)
$(TESTMODS):
	$(MAKE) -C $(@:runtest-%=%) runtest

all: sim $(ALLMODS)
$(ALLMODS):
	$(MAKE) -C $(@:all-%=%) all

clean: $(CLEANMODS)
$(CLEANMODS):
	$(MAKE) -C $(@:clean-%=%) clean

install: sim $(INSTMODS)
$(INSTMODS):
	$(MAKE) -C $(@:install-%=%) install

deinstall: $(DEINSTMODS)
$(DEINSTMODS):
	$(MAKE) -C $(@:deinstall-%=%) deinstall

dirs: $(LIB) $(INC)
$(INC):
	mkdir -p $(INC)
$(LIB):
	mkdir -p $(LIB)

sim: $(INC)/sim.h
$(INC)/sim.h: $(INC) sim.h
	cp sim.h $(INC)

# need to add a "deinstall" for sim.h
