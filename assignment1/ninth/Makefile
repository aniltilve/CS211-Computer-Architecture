CFLAGS = -c -Wall -Werror

all: ninth

ninth: ninth.o
	gcc ninth.o -o ninth

ninth.o: ninth.c ninth.h
	gcc $(CFLAGS) ninth.c

clean:
	rm -f ninth
