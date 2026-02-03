all:
	gcc main.c io.c queue.c sort.c -o main.exe

clean:
	del main.exe