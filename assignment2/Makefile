CFLAGS = -c -Wall -Werror

all: first

first: first.o statGenerator.o binarySearchTree.o
	gcc first.o statGenerator.o binarySearchTree.o -o first

first.o: first.c
	gcc $(CFLAGS) first.c

statGenerator.o: statGenerator.c statGenerator.h
	gcc $(CFLAGS) statGenerator.c

binarySearchTree.o: binarySearchTree.c binarySearchTree.h
	gcc $(CFLAGS) binarySearchTree.c

clean:
	rm -f *.o $(objects) first
