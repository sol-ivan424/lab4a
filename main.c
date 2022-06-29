#include "func.h"

int main()
{
	Node *root = NULL;
	int rc;
	int(*fptr[])(Node **) = { NULL, D_Add, D_Find, D_Delete, D_Show, inorder, S_Find };

	while (rc = dialog(msgs, NMsgs))
	if (!fptr[rc](&root))
		break;

	printf("That's all. Bye!\n");
	delTree(&root);
	return 0;
}
