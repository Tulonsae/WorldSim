# Makefile for rng library unit tests
.SILENT:

all: clean utest

clean:
	rm -f *.o utest

utest: ../rng.h ../librng.a utest.c
	$(CC) $(CFLAGS) -o utest utest.c ../librng.a

runtest: utest
	./utest
