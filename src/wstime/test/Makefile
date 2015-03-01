# Makefile for wstime library unit tests

all: clean utest

clean:
	rm -f *.o utest

utest: ../wstime.h ../libwstime.a utest.c
	$(CC) -o utest $(CFLAGS) utest.c ../libwstime.a $(LIB)/librng.a -lm

runtest: utest
	./utest

ROOT = ../..
include $(ROOT)/Makefile.inc
