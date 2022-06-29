#include "func.h"

const char *msgs[] = { "0. Quit", "1. Add", "2. Find", "3. Delete", "4. Show", "5. Inorder", "6. Special F"};
const int NMsgs = sizeof(msgs) / sizeof(msgs[0]);

int getInt(int *pn)
{
	const char *errmsg = "";
	int n;
	do{
		puts(errmsg);
		errmsg = "Illegal integer; enter once more";
		n = scanf("%d", pn);
		if (n < 0)
			return 0;
		scanf("%*[^\n]");
		scanf("%*c");
	} while (n == 0);
	return 1;
}

int inorder(Node **proot){
    Node *tmp = findMin(*proot);

    while(tmp != NULL){
        printf("(%d) -> ", tmp->key);

        if (tmp->right == NULL)
        tmp = tmp->next;

        else
        tmp = findMin(tmp->right);
    }
    printf("\n");
    return 1;
}

void delTree(Node **proot)
{
	if (*proot){
		delTree(&((*proot)->left));
		delTree(&((*proot)->right));
		free(*proot);
	}
	*proot = NULL;
}

int dialog(const char *msgs[], int N)
{
	const char *errmsg = "";
	int rc;
	int i, n;

	do{
		puts(errmsg);
		errmsg = "You are wrong. Repeat, please!";

		for (i = 0; i < N; ++i)
			puts(msgs[i]);
		puts("Make your choice: --> ");

		n = getInt(&rc);
		if (n == 0)
			rc = 0;
	} while (rc < 0 || rc >= N);

	return rc;
}
