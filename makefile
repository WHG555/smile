objects=main.o
CC=gcc
CFG=-std=c99 -Wall
LIB=-lreadline

nn: main.o
	gcc $(CFG) -o $@ $^    $(LIB)
main.o:main.c
	gcc $(CFG) -o $@ -c $^ $(LIB)
clean:
	rm nn $(objects)
