#makefile for creator and convertor
create: create.o converter.o
	gcc -o create create.o
	gcc -o converter converter.o

create.o: create.c
	gcc -c create.c

converter.o: converter.c
	gcc -c converter.c

clean: *.o
	rm -rf *.o create
