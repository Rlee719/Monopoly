monopoly:main.o display.o 
	gcc -o monopoly main.o display.o

main.o: main.c main.h define.h display.h
	gcc -c main.c

display.o: display.c display.h define.h
	gcc -c display.c
