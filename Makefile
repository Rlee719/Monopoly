Molopoly: main.o command.o
	gcc -o Molopoly main.o command.o

main.o: main.c main.h
	gcc -c main.c

command.o: command.c command.h define.h	
	gcc -c command.c

