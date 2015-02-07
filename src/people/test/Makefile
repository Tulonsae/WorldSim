# Makefile for people library unit tests

all: clean utest

clean:
	rm -f *.o utest

utest: ../person.h ../libpeople.a utest.c
	$(CC) $(CFLAGS) -o utest utest.c ../libpeople.a $(LIB)/libgender.a $(LIB)/librng.a

runtest: utest
	./utest

ROOT = ../..
include $(ROOT)/Makefile.inc
