# Makefile for wstime library

all: libwstime.a

libwstime.a: wstime.o
	$(AR) rc $@ $^

%.o: %.c wstime.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f *.o *.a
	$(MAKE) -C test clean

runtest: libwstime.a
	$(MAKE) -C test all runtest

ROOT = ..
include $(ROOT)/Makefile.inc

install: $(INC)/wstime.h $(LIB)/libwstime.a
$(INC)/wstime.h: $(INC) wstime.h
	cp wstime.h $(INC)
$(LIB)/libwstime.a: $(LIB) libwstime.a
	cp libwstime.a $(LIB)
$(INC) $(LIB):
	$(MAKE) -C $(ROOT) dirs

deinstall:
	rm -f $(INC)/wstime.h
	rm -f $(LIB)/libwstime.a
