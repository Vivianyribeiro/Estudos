main: main.o aluno.o turma.o
	gcc main.o aluno.o turma.o -o main
main.o: main.c
	gcc -Wall -c main.c -o main.o
aluno.o: aluno.c aluno.h
	gcc -Wall -c aluno.c -o aluno.o
turma.o: turma.c turma.h
	gcc -Wall -c turma.c -o turma.o
clean: 
	rm *.o main 
