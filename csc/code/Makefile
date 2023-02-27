all: fibo.o main.o
fibo.o: fibo.c 
	gcc -c fibo.c -o fibo.o -I ../include

main.o: main.c
	gcc -c main.c -o main.o -I ../include

clean:
	rm -rf fibo.o main.o
