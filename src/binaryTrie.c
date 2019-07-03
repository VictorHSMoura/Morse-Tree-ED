#include "headers/binaryTrie.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//recursively search an key for search function
pointer searchR(pointer t, char *key, int p) {
    if (t == NULL) return NULL;     //node not found
    //check if the node exists after reading all characters of the key
    if(strlen(key) == p) {
        if(strcmp(t->data.key, key) == 0)
            return t;   //if exists, return a pointer to it
        else
            return NULL;    //else, return a NULL pointer
    }
    //check the p-th character of the key
    if(key[p] == '.')
        return searchR(t->left, key, p+1);  //search on left sub-tree
    else
        return searchR(t->right, key, p+1); //search on right sub-tree
}

//search an key on the trie and return a pointer to it
pointer search(pointer t, char *key) {
    return searchR(t, key, 0);
}

//recursive function to do insertion
pointer insertR(pointer t, cell data, int p) {
    char key[5];
    strcpy(key, data.key);

    //check if the node exists after reading all characters of the key
    if (strlen(key) == p) {
        if (t == NULL)
            return makeNode(data);  //if not, create a new node
        else {
            t->data = data; //else, overwrite the previous data on the node
            return t;
        }
    }

    //if the searching pointer is null, create a new node pointed by the searching pointer
    if (t == NULL) {
        t = makeTrie();
    }

    //check the p-th character of the key
    if (key[p] == '.')
        t->left = insertR(t->left, data, p+1);  //insert on left sub-tree
    else
        t->right = insertR(t->right, data, p+1);    //insert on left sub-tree
    return t;
}

//insert an node on the trie
void insert(pointer *trieT, cell data) { 
    *trieT = insertR(*trieT, data, 0);
}

//make a new non-empty node
pointer makeNode(cell data) {
    pointer newNode = (pointer) malloc(sizeof(node));
    newNode->data = data;
    //setting left and right pointers to NULL to prevent errors
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//make a newTrie (or a new empty node)
pointer makeTrie() { 
    pointer newNode = (pointer) malloc(sizeof(node));
    newNode->data.letter = '*';
    //setting left and right pointers to NULL to prevent errors
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//free all the nodes on the Trie
void freeTrie(pointer trieT) {
    if(trieT != NULL) {
        freeTrie(trieT->left);
        freeTrie(trieT->right);
        free(trieT);
    }
}

//print the nodes on the Trie using pre-order traversal
void printTrie(pointer trieT) {
    if(trieT != NULL) {
        if(trieT->data.letter != '*')
            printf("%c %s\n", trieT->data.letter, trieT->data.key);
        printTrie(trieT->left);
        printTrie(trieT->right);
    }
}