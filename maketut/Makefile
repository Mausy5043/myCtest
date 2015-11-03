# Makefile
CC=g++
CCFLAGS=-c -std=c++11 -stdlib=libc++
LDFLAGS=
SOURCES=main.cpp factorial.cpp hello.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=hello

ifeq ($(OS),Windows_NT)
	CC=g++
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		CC=g++
	endif
	ifeq ($(UNAME_S),Darwin)
		CC=clang++
	endif
endif

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CCFLAGS) $< -o $@

clean:
	rm *.o

allclean:
	rm *.o $(EXECUTABLE)
