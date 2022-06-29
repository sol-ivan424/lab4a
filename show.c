#include "func.h"

void putTree(Node *ptr, int level)
{
	int i = level;
	if (ptr){
		putTree(ptr->right, level + 1);
		while (i-- > 0)
			printf("  ");
		printf("%d\n", ptr->key);
		putTree(ptr->left, level + 1
			);
	}
}

int D_Show(Node **proot)
{
	printf("\n=== Your tree: ===\n\n");
	putTree(*proot, 0);
	return 1;
}
