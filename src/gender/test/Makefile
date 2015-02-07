# Makefile for gender library unit tests

all: clean utest

clean:
	rm -f *.o utest

utest: ../gender.h ../libgender.a utest.c
	$(CC) $(CFLAGS) -o utest utest.c ../libgender.a $(LIB)/librng.a

runtest: utest
	./utest

ROOT = ../..
include $(ROOT)/Makefile.inc
