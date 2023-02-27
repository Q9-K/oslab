all: fibo.o main.o
fibo.o: fibo.c fibo.h
	gcc -c fibo.c -o fibo.o -L ../include

main.o: main.c fibo.h
	gcc -c main.c -o main.o -L ../include

clean:
	rm -rf fibo.o main.o
