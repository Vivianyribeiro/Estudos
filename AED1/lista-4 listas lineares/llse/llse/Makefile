main: main.o llse.o
	gcc main.o llse.o -o main
main.o: main.c
	gcc -Wall -c main.c -o main.o
llse.o: llse.c llse.h
	gcc -Wall -c llse.c  -o llse.o
clean: 
	rm *.o main 
