# Makefile for people library unit tests

all: clean utest

clean:
	rm -f *.o utest

utest: ../people.h ../libpeople.a utest.c
	$(CC) $(CFLAGS) -o utest utest.c ../libpeople.a $(LIB)/libgender.a $(LIB)/libcal.a $(LIB)/libwstime.a $(LIB)/librng.a -lm

runtest: utest
	./utest

ROOT = ../..
include $(ROOT)/Makefile.inc
