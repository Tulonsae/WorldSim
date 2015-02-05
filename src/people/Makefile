# Makefile for people library

all: libpeople.a

libpeople.a: person.o
	$(AR) rc $@ $^

%.o: %.c person.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f *.o *.a

ROOT = ..
include $(ROOT)/Makefile.inc

install: $(INC)/person.h $(LIB)/libpeople.a
$(INC)/person.h: $(INC) person.h
	cp person.h $(INC)
$(LIB)/libpeople.a: $(LIB) libpeople.a
	cp libpeople.a $(LIB)
$(INC) $(LIB):
	$(MAKE) -C $(ROOT) dirs

deinstall:
	rm -f $(INC)/person.h
	rm -f $(LIB)/libpeople.a
