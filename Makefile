CC=g++

MakeO=-c

CFlags=-Wall -std=c++11 -g -lglut -lGLU -lGLEW -IGLEW -lGL

all: main

recompile: clean all

main: main.o geom.o
	$(CC) main.o geom.o -o main $(CFlags)

main.o:
	$(CC) $(MakeO) $(CFlags) main.cpp

geom.o:
	$(CC) $(MakeO) $(CFlags) geom.cpp

clean:
	rm -rf *.o main
