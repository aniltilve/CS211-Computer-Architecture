CFLAGS = -c -Wall -Werror

all: eighth

eighth: eighth.o
	gcc eighth.o -o eighth

eighth.o: eighth.c eighth.h
	gcc $(CFLAGS) eighth.c

clean:
	rm -f eighth
