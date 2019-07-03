#include "headers/binaryTrie.h"
#include "headers/queue.h"

#include <stdio.h>
#include <stddef.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    trie newTrie = makeTrie(NULL);
    pointer newNode;
    cell newCell;
    FILE *morse;
    Queue q;
    int i;
    char letter, morseCode[6], *code;
    
    //assuming that one line of morse code has less than 500 characters
    //and a transcripted line has less than 150 characters 
    char message[150], originalMessage[500];

    makeEmptyQueue(&q); //initializing the queue of messages

    morse = fopen("morse.txt", "r");    //reading the file with the morse codes
    while(fscanf(morse, " %c %s", &letter, morseCode) != EOF) {
        strcpy(newCell.key, morseCode);
        newCell.letter = letter;
        insert(&newTrie, newCell);  //adding the morse code and its letter to the trie
    }
    fclose(morse);  //closing the file
    
    //reading keyboard input until EOF
    while (fgets(originalMessage, 500, stdin) != NULL) {
        i = 0;
        //removing \n if there's one on the ending of message to prevent errors
        if(originalMessage[strlen(originalMessage)-1] == '\n')
            originalMessage[strlen(originalMessage)-1] = '\0';
        code = strtok(originalMessage, " ");    //getting the first morse code
        while (code != NULL) {
            //if it's an '/' just put a blank space on message
            if(strcmp(code, "/") == 0)
                message[i] = ' ';

            //searching the letter on trie and putting it on the message     
            else
                message[i] = search(newTrie, code)->data.letter;
            code = strtok(NULL, " ");   //getting the next morse code
            i++;
        }
        message[i] = '\0';  //setting the end of the message
        enqueue(message, &q);   //adding the message to the queue
    }

    printQueue(&q); //printing all the messages from the queue

    //if the argument -a was on the input, print the trie
    if(argc == 2 && strcmp(argv[1], "-a") == 0)
        printTrie(newTrie);

    freeQueue(&q);
    freeTrie(newTrie);
}