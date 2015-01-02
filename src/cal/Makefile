# Makefile for calenar
.SILENT:

all: libcal.a

libcal.a: calendar.o
	$(AR) rc $@ $^

%.o: %.c calendar.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f *.o *.a

ROOT = ..
include $(ROOT)/Makefile.inc

install: $(INC)/calendar.h $(LIB)/libcal.a
$(INC)/calendar.h: $(INC) calendar.h
	cp calendar.h $(INC)
$(LIB)/libcal.a: $(LIB) libcal.a
	cp libcal.a $(LIB)
$(INC) $(LIB):
	make -C $(ROOT) dirs

deinstall:
	rm -f $(INC)/calendar.h
	rm -f $(LIB)/libcal.a
