CFLAGS = -c -Wall -Werror

all: first

first: first.o
	gcc first.o -o first

first.o: first.c first.h
	gcc $(CFLAGS) first.c

clean:
	rm -f first
