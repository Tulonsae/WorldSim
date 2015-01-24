# Makefile for rng
.SILENT:

all: clean utest

clean:
	rm -f *.o utest

utest: ../rng.h ../librng.a
	cc -o utest utest.c ../librng.a

runtest: utest
	./utest
