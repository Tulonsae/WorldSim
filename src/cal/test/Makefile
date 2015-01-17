# Makefile for calendar library unit tests
.SILENT:

all: test

clean:
	rm -f *.o utest

test: ../calendar.h ../libcal.a
	cc -o utest utest.c ../libcal.a
