CC = gcc
CFLAGS = -g -std=c99 -Wno-unused-result -pipe -O3

all:  main

main: main.o list.o
	$(CC) $^ -o $@

clean:
	rm -f main *.o