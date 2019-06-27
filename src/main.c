#include "headers/binaryTrie.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>

int main() {
    trie newTrie = makeTrie(NULL);
    cell newCell;
    FILE *morse;
    char letter, code[6];

    morse = fopen("morse.txt", "r");
    while(fscanf(morse, " %c %s", &letter, code) != EOF) {
        strcpy(newCell.key, code);
        newCell.letter = letter;
        insert(&newTrie, newCell);
    }
    fclose(morse);
    
    printTrie(newTrie);
    freeTrie(newTrie);
}