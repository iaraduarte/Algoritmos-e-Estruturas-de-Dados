main: main.o pessoa.o
	gcc -o main main.o inteiro.o

main.o: main.c inteiro.h
	gcc -c main.c

pessoa.o: inteiro.c inteiro.h
	gcc -c inteiro.c

clean:
	rm *.o main
