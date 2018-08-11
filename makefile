objects=main.o mpc.o whg.o
CC=gcc
CFG=-g -std=c99 -Wall
LIB=-lm -lreadline

nn: main.o mpc.o whg.o
	gcc $(CFG) -o $@ $^    $(LIB)
	ctags *
main.o:main.c
	gcc $(CFG) -o $@ -c $^ $(LIB)
mpc.o:mpc.c
	gcc $(CFG) -o $@ -c $^ $(LIB)
whg.o:whg.c
	gcc $(CFG) -o $@ -c $^ $(LIB)

clean:
	rm nn $(objects)
