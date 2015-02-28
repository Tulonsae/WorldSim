# Makefile for calendar library unit tests

all: clean utest

clean:
	rm -f *.o utest

utest: ../calendar.h ../libcal.a utest.c
	$(CC) -o utest $(CFLAGS) -lm utest.c ../libcal.a $(LIB)/libwstime.a $(LIB)/librng.a

runtest: utest
	./utest

ROOT = ../..
include $(ROOT)/Makefile.inc
