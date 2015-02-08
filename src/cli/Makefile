# Makefile for cli programs

all: genPeople

clean:
	rm -f *.o run

genPeople: genPeople.c
	cc $(CFLAGS) -o run genPeople.c $(LIB)/libpeople.a

run: clean all
	./run

ROOT = ..
include $(ROOT)/Makefile.inc
