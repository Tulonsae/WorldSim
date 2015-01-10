# Makefile for cal
.SILENT:

all: test

%.o: %.c ../calendar.h
	$(CC) -c $< -o $@

clean:
	rm -f *.o utest

test: ../calendar.h ../libcal.a
	cc -o utest utest.c ../libcal.a
