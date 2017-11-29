CFLAGS = -c -Wall -Werror

all: first

first: StatGenerator.o BinarySearchTree.o
	gcc StatGenerator.o BinarySearchTree.o -o first

StatGenerator.o: StatGenerator.c
	gcc $(CFLAGS) StatGenerator.c

BinarySearchTree.o: BinarySearchTree.c BinarySearchTree.h
	gcc $(CFLAGS) BinarySearchTree.c

clean:
	rm -f *.o first
