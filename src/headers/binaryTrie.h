typedef struct {
    char key[6];
    char letter;
} cell;

typedef struct _node *pointer;

typedef struct _node {
    cell data;
    pointer left, right;
} node;

typedef pointer trie;

pointer searchR(pointer t, char *key, int p);
pointer search(pointer t, char *key);
pointer insertR(pointer t, cell data, int p);
void insert(pointer *trieT, cell data);
pointer split(pointer node1, pointer node2, int p);
pointer makeTrie();
pointer makeNode(cell data);
cell *makeCell(char *key, char letter);
void freeTrie(pointer trieT);
void printTrie(pointer trieT);