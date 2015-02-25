# Makefile for wstime library unit tests

all: clean utest

clean:
	rm -f *.o utest

utest: ../wstime.h ../libwstime.a utest.c
	$(CC) -o utest $(CFLAGS) -lm utest.c ../libwstime.a $(LIB)/librng.a

runtest: utest
	./utest

ROOT = ../..
include $(ROOT)/Makefile.inc
