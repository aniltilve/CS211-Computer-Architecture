CFLAGS = -c -Wall -Werror

all: fifth

fifth: fifth.o
	gcc fifth.o -o fifth

fifth.o: fifth.c fifth.h
	gcc $(CFLAGS) fifth.c

clean:
	rm -f fifth
