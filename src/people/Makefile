# Makefile for calenar
.SILENT:

all: libpeople.a

libpeople.a: person.o fertility.o
	$(AR) rc $@ $^

%.o: %.c person.h fertility.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f *.o *.a

ROOT = ..
include $(ROOT)/Makefile.inc

install: $(INC)/person.h $(INC)/fertility.h $(LIB)/libpeople.a
$(INC)/person.h: $(INC) person.h
	cp person.h $(INC)
$(INC)/fertility.h: $(INC) fertility.h
	cp fertility.h $(INC)
$(LIB)/libpeople.a: $(LIB) libpeople.a
	cp libpeople.a $(LIB)
$(INC) $(LIB):
	make -C $(ROOT) dirs

deinstall:
	rm -f $(INC)/person.h
	rm -f $(INC)/fertility.h
	rm -f $(LIB)/libpeople.a
