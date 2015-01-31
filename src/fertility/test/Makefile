# Makefile for fertility library unit tests
.SILENT:

all: clean utest

clean:
	rm -f *.o utest

utest: ../fertility.h ../libfert.a
	cc $(CFLAGS) -o utest utest.c $(LIB)/librng.a ../libfert.a

runtest: utest
	./utest

ROOT = ../..
include $(ROOT)/Makefile.inc
