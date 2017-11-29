CFLAGS = -c -Wall -Werror

all: first

first: CircuitSimulator.o Decoder.o Multiplexer.o
	gcc CircuitSimulator.o Decoder.o Multiplexer.o -o first

CircuitSimulator.o: CircuitSimulator.c
	gcc $(CFLAGS) CircuitSimulator.c

Multiplexer.o: Multiplexer.c Multiplexer.h
	gcc $(CFLAGS) Multiplexer.c Multiplexer.h

Decoder.o: Decoder.c Decoder.h
	gcc $(CFLAGS) Decoder.c Decoder.h

clean:
	rm -f *.o first
