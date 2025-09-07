CC = gcc
CFLAGS = -Wall -g

all: demo

demo: src/allocator.c src/main.c
	$(CC) $(CFLAGS) src/allocator.c src/main.c -o demo

clean:
	rm -f demo test_allocator
