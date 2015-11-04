# Makefile

# Project-specific definitions
SOURCES=fc.c
EXECUTABLE=main

# Default definitions
CC=gcc
CFLAGS=-c -Wall
LFLAGS=-Wall

# Platform specific definitions
ifeq ($(OS),Windows_NT)
	CC=gcc
	## Use default CFLAGS=-c -Wall
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		CC=gcc
		CFLAGS+=-Os
	endif
	ifeq ($(UNAME_S),Darwin)
		CC=clang
		CFLAGS+=-Os
	endif
endif

# Macro definitions
OBJECTS=$(SOURCES:.c=.o)


# `make` options
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-$(RM) *.o *.out

allclean:
	-$(RM) *.o *.out $(EXECUTABLE)
