CC=gcc
LD=gcc
CFLAGS=-ggdb -std=c99 -Wall
LIBS= -lm

testArraysStrings: testArraysStrings.o arraysStrings.o vectors.o
	$(LD) -o testArraysStrings testArraysStrings.o arraysStrings.o vectors.o $(LIBS)

testArraysStrings.o: testArraysStrings.c
	$(CC) $(CFLAGS) -o testArraysStrings.o -c testArraysStrings.c

arraysStrings.o: arraysStrings.c
	$(CC) $(CFLAGS) -o arraysStrings.o -c arraysStrings.c

vectors.o: vectors.c
	$(CC) $(CFLAGS) -o vectors.o -c vectors.c

clean:
	rm *.o
	rm testArraysStrings
