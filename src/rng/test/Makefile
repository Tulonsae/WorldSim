# Makefile for rng
.SILENT:

all: test

%.o: %.c ../rng.h
	$(CC) -c $< -o $@

clean:
	rm -f *.o utest

test: ../rng.h ../librng.a
	cc -o utest utest.c ../librng.a
