# Makefile for gender library unit tests
.SILENT:

all: clean utest

clean:
	rm -f *.o utest

utest: ../gender.h ../libgender.a
	$(CC) $(CFLAGS) -o utest utest.c $(LIB)/librng.a ../libgender.a

runtest: utest
	./utest

ROOT = ../..
include $(ROOT)/Makefile.inc
