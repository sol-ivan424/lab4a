#include "func.h"

int D_Find(Node **proot)
{
	int k, n;
	Node *ptr;
	puts("Enter key: -->");
	n = getInt(&k);
	if (n == 0)
		return 0;

	ptr = find(*proot, k);
	if (ptr)
		printf("key = %d was found\n", ptr->key);
	else
		printf("Node with key %d was not found\n", k);
	return 1;
}

int S_Find(Node **proot){
    Node *tmp = NULL;

    tmp = findMax(*proot);
    printf("Max element: %d\n", tmp->key);
    return 1;
}

Node *find(Node *ptr, int k)
{
	while (ptr){
		if (ptr->key == k)
			return ptr;
		ptr = k < ptr->key ? ptr->left : ptr->right;
	}
	return NULL;
}

Node *findMax(Node *ptr){
    if (!ptr)
		return NULL;
	while (ptr->right)
		ptr = ptr->right;
	return ptr;
}

Node *findMin(Node *ptr)
{
	if (!ptr)
		return NULL;
	while (ptr->left)
		ptr = ptr->left;
	return ptr;
}
