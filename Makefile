CC=g++

CFlags=-c -Wall -std=c++11

all: main

recompile: clean all

main: main.o geom.o
	$(CC) main.o geom.o -o main

main.o:
	$(CC) $(CFlags) main.cpp

geom.o:
	$(CC) $(CFlags) geom.cpp

clean:
	rm -rf *.o main
