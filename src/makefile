trabalho: binaryTrie.o main.o
	gcc binaryTrie.o main.o -o trab.exe
	make clean
	clear

main.o: main.c
	gcc -c main.c

binaryTrie.o: binaryTrie.c headers/binaryTrie.h
	gcc -c binaryTrie.c

clean:
	rm *.o
