# Makefile includes
.SILENT:

BUILD = $(ROOT)/..
INC = $(BUILD)/include
LIB = $(BUILD)/lib

CFLAGS = -std=c99 -I$(INC)
