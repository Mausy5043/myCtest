# Makefile

# Project-specific definitions
SOURCES=for.cpp
EXECUTABLE=main

# Default definitions
CC=g++
CCFLAGS=-c -Wall
LDFLAGS=

# Platform specific definitions
ifeq ($(OS),Windows_NT)
	CC=g++
	## Use default CCFLAGS=-c -Wall
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		CC=g++
		CCFLAGS+=-std=c++11
	endif
	ifeq ($(UNAME_S),Darwin)
		CC=clang++
		CCFLAGS+=-std=c++11 -stdlib=libc++
	endif
endif

# Macro definitions
OBJECTS=$(SOURCES:.cpp=.o)


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
