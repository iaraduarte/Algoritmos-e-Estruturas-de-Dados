objects = fila.o main.o

teste: $(objects)
	gcc -o teste $(objects)

fila.o: fila.h

main.o: fila.h

clean:
	rm *.o teste
