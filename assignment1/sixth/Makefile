CFLAGS = -c -Wall -Werror

all: sixth

sixth: sixth.o
	gcc sixth.o -o sixth

sixth.o: sixth.c sixth.h
	gcc $(CFLAGS) sixth.c

clean:
	rm -f sixth
