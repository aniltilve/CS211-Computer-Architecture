CFLAGS = -c -Wall -Werror

all: fourth

fourth: fourth.o
	gcc fourth.o -o fourth

fourth.o: fourth.c fourth.h
	gcc $(CFLAGS) fourth.c

clean:
	rm -f fourth
