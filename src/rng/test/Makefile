# Makefile for rng library unit tests

all: clean utest

clean:
	rm -f *.o utest

utest: ../rng.h ../librng.a utest.c
	$(CC) $(CFLAGS) -o utest utest.c ../librng.a

runtest: utest
	./utest

ROOT = ../..
include $(ROOT)/Makefile.inc
