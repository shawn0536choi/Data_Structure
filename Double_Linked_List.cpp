/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct NODE1 NODE;
typedef struct NODE1 {g
	int data;
	struct NODE1 * prev;
	struct NODE1 * next;
}NODE;

void ListInsert(NODE** node, int data)
{
	NODE* newnode = (NODE*)malloc(sizeof(NODE));
	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;

	if (*node == NULL) {
		*node = newnode;
		return;
	}

	newnode->next = *node;
	(*node)->prev = newnode;
	*node = newnode;
}

int main()
{
	NODE* root = NULL;
	bool off = false;
	srand(time(NULL));
	int num;
	while (off == false) {
		int option;
		num = rand() % 100 + 1;
		printf("= MENU =\n1. INPUT\n2. OUTPUT\n3. EXIT\n");
		printf("Your choice: ");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			ListInsert(&root, num);
			printf("Added list: %d\n", num);
			break;
		case 2:
			printf("Root");
			for (NODE* i = root; i != NULL; i = i->next) {
				printf("<=>%d", i->data);
			}
			printf("<=>NULL\n");
			break;
		case 3:
			off = true;
			break;
		}
	}
	return 0;
}
*/