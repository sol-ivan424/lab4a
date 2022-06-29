#include <stdio.h>
#include <string.h>
#include <malloc.h>

const char *msgs[7];
const int NMsgs;

typedef struct Node{
	int key;
    struct Node *left;
	struct Node *right;
	struct Node *next;
	struct Node *parent;
}Node;

int S_Find(Node **proot);
Node *findMax(Node *ptr);
int inorder(Node **proot);
Node *next(Node *);
int getInt(int *);
int insert(Node **, int);
int delNode(Node **, int);
Node *find(Node *, int);
Node *findMin(Node *);
void putTree(Node *, int);
void delTree(Node **);
int dialog(const char *msgs[], int);
int D_Add(Node **),
D_Find(Node **),
D_Delete(Node **),
D_Show(Node **);
