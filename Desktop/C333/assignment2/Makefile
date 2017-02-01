CC=gcc
LD=gcc
CFLAGS=-ggdb -std=c99 -Wall
LIBS= -lm

testArraysStrings: testArraysStrings.o arraysStrings.o arraysStrings.h
	$(LD) -o testArraysStrings arraysStrings.o arraysStrings.o $(LIBS)

testArraysStrings.o: testArraysStrings.c
	$(CC) $(CFLAGS) -o testArraysStrings.o -c arraysStrings.c

arraysStrings.o: arraysStrings.c arraysStrings.h
	$(CC) $(CFLAGS) -o arraysStrings.o -c arraysStrings.c

clean:
rm *.o
rm testArraysStrings
