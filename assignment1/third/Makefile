CFLAGS = -c -Wall -Werror

all: third

third: third.o
	gcc third.o -o third

third.o: third.c third.h
	gcc $(CFLAGS) third.c

clean:
	rm -f third
