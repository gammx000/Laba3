all:
	gcc main.c io.c queue.c sort.c -o main

clean:
	rm -rf main