# Makefile
CC=clang++
CFLAGS=-c -std=c++11 -stdlib=libc++
SOURCES=for.cpp
OBJECTS=for.o
EXEC=for

all: for

for: for.o
	$(CC) $(OBJECTS) -o $(EXEC)

for.o: for.cpp
	$(CC) $(CFLAGS) for.cpp

clean:
	rm *.o *.out $(EXEC)
