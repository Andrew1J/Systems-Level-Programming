ALL: main.o stuystudent.o
	gcc -o program main.o stuystudent.o
main.o: main.c stuystudent.h
	gcc -c main.c
stuystudent.o: stuystudent.c stuystudent.h
	gcc -c stuystudent.c
run:
	./program
clean:
	rm *.o
	rm program
