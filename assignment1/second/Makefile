CFLAGS = -c -Wall -Werror

all: second

second: second.o
	gcc second.o -o second 

second.o: second.c second.h
	gcc $(CFLAGS) second.c

clean:
	rm -f second
