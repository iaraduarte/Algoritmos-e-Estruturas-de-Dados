objects = lista.o main.o

teste: $(objects)
	gcc -o teste $(objects)

lista.o: lista.h

main.o: lista.h

clean:
	rm *.o teste
