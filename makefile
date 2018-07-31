objects=main.o
CC=gcc
CFG=-std=c99 -Wall
LIB=-lm -lreadline

nn: main.o mpc.o
	gcc $(CFG) -o $@ $^    $(LIB)
main.o:main.c
	gcc $(CFG) -o $@ -c $^ $(LIB)
mpc.o:mpc.c
	gcc $(CFG) -o $@ -c $^ $(LIB)

clean:
	rm nn $(objects)
