# Makefile for people library

all: libpeople.a

libpeople.a: person.o
	$(AR) rc $@ $^

%.o: %.c people.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f *.o *.a
	$(MAKE) -C test clean

runtest: libpeople.a
	$(MAKE) -C test all runtest

ROOT = ..
include $(ROOT)/Makefile.inc

install: $(INC)/people.h $(LIB)/libpeople.a
$(INC)/people.h: $(INC) people.h
	cp people.h $(INC)
$(LIB)/libpeople.a: $(LIB) libpeople.a
	cp libpeople.a $(LIB)
$(INC) $(LIB):
	$(MAKE) -C $(ROOT) dirs

deinstall:
	rm -f $(INC)/people.h
	rm -f $(LIB)/libpeople.a
