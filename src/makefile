trabalho: queue.o binaryTrie.o main.o
	gcc queue.o binaryTrie.o main.o -o trab.exe
	make clean
	clear

main.o: main.c
	gcc -c main.c

binaryTrie.o: binaryTrie.c headers/binaryTrie.h
	gcc -c binaryTrie.c

queue.o: queue.c headers/queue.h
	gcc -c queue.c

clean:
	rm *.o
