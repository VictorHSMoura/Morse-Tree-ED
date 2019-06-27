#include "headers/binaryTrie.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    trie newTrie = makeTrie(NULL);
    pointer newNode;
    cell newCell;
    FILE *morse;
    char letter, morseCode[6], *code, message[100], originalMessage[500];
    int i;

    morse = fopen("morse.txt", "r");
    while(fscanf(morse, " %c %s", &letter, morseCode) != EOF) {
        strcpy(newCell.key, morseCode);
        newCell.letter = letter;
        insert(&newTrie, newCell);
    }
    fclose(morse);
    
    while (fgets(originalMessage, 500, stdin) != NULL) {
        i = 0;
        if(originalMessage[strlen(originalMessage)-1] == '\n')
            originalMessage[strlen(originalMessage)-1] = '\0';
        code = strtok(originalMessage, " ");
        while (code != NULL) {
            if(strcmp(code, "/") == 0)
                message[i] = ' ';
            else
                message[i] = search(newTrie, code)->data.letter;
            code = strtok(NULL, " ");
            i++;
        }
        message[i] = '\0';  //setting the end of the message
        printf("%s\n", message);
    }

    if(argc == 2 && strcmp(argv[1], "-a") == 0)
        printTrie(newTrie);

    freeTrie(newTrie);
}