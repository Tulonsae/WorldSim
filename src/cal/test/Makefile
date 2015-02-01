# Makefile for calendar library unit tests
.SILENT:

all: clean utest

clean:
	rm -f *.o utest

utest: ../calendar.h ../libcal.a utest.c
	cc -o utest $(CFLAGS) utest.c $(LIB)/librng.a ../libcal.a

runtest: utest
	./utest

ROOT = ../..
include $(ROOT)/Makefile.inc
