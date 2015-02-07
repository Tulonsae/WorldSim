# Makefile for fertility library unit tests

all: clean utest

clean:
	rm -f *.o utest

utest: ../fertility.h ../libfert.a utest.c
	$(CC) $(CFLAGS) -o utest utest.c ../libfert.a $(LIB)/librng.a $(LIB)/libcal.a

runtest: utest
	./utest

ROOT = ../..
include $(ROOT)/Makefile.inc
