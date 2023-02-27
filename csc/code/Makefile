all: fibo.o main.o
fibo.o: fibo.c fibo.h
	gcc -c fibo.c -o fibo.o -I ../include

main.o: main.c fibo.h
	gcc -c main.c -o main.o -I ../include

clean:
	rm -rf fibo.o main.o
