# Makefile for fertility library
.SILENT:

all: libfert.a

libfert.a: fertility.o
	$(AR) rc $@ $^

%.o: %.c fertility.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f *.o *.a
	$(MAKE) -C test clean

runtest: libfert.a
	$(MAKE) -C test all runtest

ROOT = ..
include $(ROOT)/Makefile.inc

install: $(INC)/fertility.h $(LIB)/libfert.a
$(INC)/fertility.h: $(INC) fertility.h
	cp fertility.h $(INC)
$(LIB)/libfert.a: $(LIB) libfert.a
	cp libfert.a $(LIB)
$(INC) $(LIB):
	$(MAKE) -C $(ROOT) dirs

deinstall:
	rm -f $(INC)/fertility.h
	rm -f $(LIB)/libfert.a
