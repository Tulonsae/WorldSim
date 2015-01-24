# Makefile for calendar library unit tests
.SILENT:

all: clean utest

clean:
	rm -f *.o utest

utest: ../calendar.h ../libcal.a
	cc -o utest utest.c ../libcal.a

runtest: utest
	./utest
