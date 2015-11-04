# Makefile

# Project-specific definitions
SOURCES=fc.c
EXECUTABLE=main

# Default definitions
CC=gcc
CCFLAGS=-c -Wall
LDFLAGS=

# Platform specific definitions
ifeq ($(OS),Windows_NT)
	CC=gcc
	## Use default CCFLAGS=-c -Wall
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		CC=gcc
		CCFLAGS+=-Oz
	endif
	ifeq ($(UNAME_S),Darwin)
		CC=clang
		CCFLAGS+=-Oz
	endif
endif

# Macro definitions
OBJECTS=$(SOURCES:.c=.o)


# `make` options
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CCFLAGS) $< -o $@

clean:
	rm *.o

allclean:
	rm *.o $(EXECUTABLE)
