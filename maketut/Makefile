# Makefile

# Project-specific
SOURCES=main.cpp factorial.cpp hello.cpp
EXECUTABLE=hello

# Default fixed values
CC=g++
CCFLAGS=-c -Wall
LDFLAGS=

# Platform specific
ifeq ($(OS),Windows_NT)
	CC=g++
	# Use default CCFLAGS: CCFLAGS=-c -Wall
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

# Built macros
OBJECTS=$(SOURCES:.cpp=.o)


all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CCFLAGS) $< -o $@

clean:
	rm *.o

allclean:
	rm *.o $(EXECUTABLE)
