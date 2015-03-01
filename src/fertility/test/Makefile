# Makefile for fertility library unit tests

all: clean utest

clean:
	rm -f *.o utest

utest: ../fertility.h ../libfert.a utest.c
	$(CC) $(CFLAGS) -o utest utest.c ../libfert.a $(LIB)/libcal.a $(LIB)/libwstime.a $(LIB)/librng.a -lm

runtest: utest
	./utest

ROOT = ../..
include $(ROOT)/Makefile.inc
