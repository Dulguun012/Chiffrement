all: main

main: Chiffrement.o
	gcc Chiffrement.o -o main

Chiffrement.o: Chiffrement.c
	gcc -c Chiffrement.c -o Chiffrement.o

clean:
	rm -f main *.o
