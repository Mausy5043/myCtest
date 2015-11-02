# Makefile
CC=g++
CFLAGS=-c -Wall
OBJECTS=main.o factorial.o hello.o

all: hello

hello: main.o factorial.o hello.o
	$(CC) $(OBJECTS) -o hello

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

factorial.o: factorial.cpp
	$(CC) $(CFLAGS) factorial.cpp

hello.o: hello.cpp
	$(CC) $(CFLAGS) hello.cpp

clean:
	rm *.o hello
