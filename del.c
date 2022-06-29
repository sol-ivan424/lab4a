#include "func.h"

int delNode(Node **proot, int k)
{
	Node *y = NULL, *par = NULL, *ptr = NULL, *x = find(*proot, k);
	if (x == NULL)
		return 0;

	if (x->left == NULL || x->right == NULL)
		y = x;
	else
		y = findMin(x->right);

	if (y->left)
		ptr = y->left;
	else
		ptr = y->right;

	par = y->parent;
	if (ptr){
		ptr->parent = par;
		ptr->next = x->next;
	}
	if (!par)
		*proot = ptr;

	else
        if (par->left == y)
            par->left = ptr;
        else{
            par->right = ptr;
            par->next = x->next;
        }
	if (y != x){
        x->key = y->key;
        x->next = y->next;
	}

	free(y);
	return 1;
}

int D_Delete(Node **proot)
{
	int n, k;
	int rc;
	puts("Enter key: -->");
	n = getInt(&k);
	if (n == 0)
		return 0;
	rc = delNode(proot, k);
	if (rc)
		printf("Ok\n");
	else
		printf("Node with key %d was not found\n", k);
	return 1;
}
