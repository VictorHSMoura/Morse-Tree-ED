#include "headers/binaryTrie.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//not working yet. Didn't start to work on that properly
pointer searchR(pointer t, char *key, int p) {
    if (t == NULL) return NULL;     //node not found
    if (t->left == NULL && t->right == NULL) {
        char cellkey[5];
        strcpy(cellkey, t->data.key);
        if (cellkey == key)
            return t;   //node found. Returning its pointer
        else
            return NULL;   //node not found
    }
    if(key[p] == '.')
        return searchR(t->left, key, p+1);
    else
        return searchR(t->right, key, p+1);
}

pointer search(pointer t, char *key) {
    return searchR(t, key, 0);
}

pointer insertR(pointer t, cell data, int p) {
    char key[5];
    strcpy(key, data.key);

    if (strlen(key) == p) {
        if (t == NULL)
            return makeNode(data);
        else {
            t->data = data;
            return t;
        }
    }
    if (t == NULL) {
        cell auxCell;
        auxCell.letter = '*';   //just to initialize the cell
        t = makeNode(auxCell);
    }
    if (key[p] == '.')
        t->left = insertR(t->left, data, p+1);
    else
        t->right = insertR(t->right, data, p+1);
    return t;
}

void insert(pointer *trieT, cell data) { 
    *trieT = insertR(*trieT, data, 0);
}

pointer makeNode(cell data) {
    pointer newNode = (pointer) malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

pointer makeTrie() { 
    pointer newNode = (pointer) malloc(sizeof(node));
    newNode->data.letter = '*';
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void freeTrie(pointer trieT) {
    if(trieT != NULL) {
        freeTrie(trieT->left);
        freeTrie(trieT->right);
        free(trieT);
    }
}

void printTrie(pointer trieT) {
    if(trieT != NULL) {
        if(trieT->data.letter != '*')
            printf("%c %s\n", trieT->data.letter, trieT->data.key);
        printTrie(trieT->left);
        printTrie(trieT->right);
    }
}