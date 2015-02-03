# Makefile for gender library
.SILENT:

all: libgender.a

libgender.a: gender.o
	$(AR) rc $@ $^

%.o: %.c gender.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f *.o *.a

runtest: libgender.a
	$(MAKE) -C test all runtest

ROOT = ..
include $(ROOT)/Makefile.inc

install: $(INC)/gender.h $(LIB)/libgender.a
$(INC)/gender.h: $(INC) gender.h
	cp gender.h $(INC)
$(LIB)/libgender.a: $(LIB) libgender.a
	cp libgender.a $(LIB)
$(INC) $(LIB):
	$(MAKE) -C $(ROOT) dirs

deinstall:
	rm -f $(INC)/gender.h
	rm -f $(LIB)/libgender.a
