CFLAGS = -c -Wall -Werror

all: seventh

seventh: seventh.o
	gcc seventh.o -o seventh

seventh.o: seventh.c seventh.h
	gcc $(CFLAGS) seventh.c

clean:
	rm -f seventh
