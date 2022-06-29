#include "func.h"

int D_Add(Node **proot){
	int k, rc, n;
	puts("Enter key: -->");
	n = getInt(&k);
	if (n == 0)
		return 0;

	rc = insert(proot, k);
    if (rc)
    puts("Ok\n");

	return 1;
}

Node *next(Node *ptr){
    Node *tmp = ptr->parent;

    while ((tmp != NULL)&&(tmp->key <= ptr->key)){
        tmp = tmp->parent;
    }
    if (ptr->parent->next == tmp)
    ptr->parent->next = ptr;

    return tmp;
}

int insert(Node **proot, int k){
	Node *ptr = *proot, *par = NULL;

	while (ptr){
		par = ptr;

		if (k < ptr->key)
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}

	ptr = (Node *)calloc(1, sizeof(Node));
	ptr->key = k;
	ptr->parent = par;

	if (par == NULL)
		*proot = ptr;
	else{
        if (k < par->key)
            par->left = ptr;
        else
            par->right = ptr;
        ptr->next = next(ptr);
	}
	return 1;
}
