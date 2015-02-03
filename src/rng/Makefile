# Makefile for rng library
.SILENT:

all: librng.a

librng.a: rng.o
	$(AR) rc $@ $^

%.o: %.c rng.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f *.o *.a

runtest: librng.a
	$(MAKE) -C test all runtest

ROOT = ..
include $(ROOT)/Makefile.inc

install: $(INC)/rng.h $(LIB)/librng.a
$(INC)/rng.h: $(INC) rng.h
	cp rng.h $(INC)
$(LIB)/librng.a: $(LIB) librng.a
	cp librng.a $(LIB)
$(INC) $(LIB):
	$(MAKE) -C $(ROOT) dirs

deinstall:
	rm -f $(INC)/rng.h
	rm -f $(LIB)/librng.a
