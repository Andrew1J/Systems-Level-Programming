all: user.o worker.o
	gcc -o user user.o
	gcc -o worker worker.o

user.o: user.c
	gcc -c user.c

worker.o: worker.c
	gcc -c worker.c

clean:
	rm *.o
	rm user
	rm worker
	rm toChild
	rm toParent
