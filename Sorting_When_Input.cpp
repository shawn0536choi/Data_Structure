#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct NODE1 NODE;
typedef struct NODE1 {
	NODE *next;
	int data;
}NODE;

void ListInsert(NODE** node, int data);
void printnode(NODE* root);

int main()
{
	srand(time(NULL));
	int num;
	int first;
	first = rand() % 100 + 1;
	NODE* root = NULL;
	bool off = false;
	while (off == false) {
		int option;
		num = rand() % 100 + 1;
		printf("\t=======================\n\t=====\t *MENU*    ====\t\n\t=======================\n\n\t\t1. INPUT\n\t\t2. OUTPUT\n\t\t3. EXIT\n");
		printf("\tYour choice: ");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			ListInsert(&root,num);
			printf("\n\tAdded list: %d\n\n", num);
			break;
		case 2:
			printnode(root);
			break;
		case 3:
			off = true;
			printf("\t\tYou Exited!!!\n\n\t\tPress Any Key\n");
			break;
		}
	}
	return 0;
}

void ListInsert(NODE** node, int data) {

	NODE* temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->next = NULL;

	if (*node == NULL) {//Empty list
		*node = temp;
		return;
	}
	NODE* prev = *node;
	for (NODE* i = *node; i != NULL; i = i->next) {

		if (i->data > data) {
			if (i == *node) {//Insert at the front of the list (use '*node' instead of 'i')
				temp->next = *node;
				*node = temp;
			}
			else {//Normal insert
				temp->next = i;
				prev->next = temp;
			}
			return;
		}
		if (i->next == NULL) {//Insert at the end of the list
			i->next = temp;
			return;
		}
		prev = i;
	}
}

void printnode(NODE* root) {
	NODE* i = root;
	printf("\n\n\tRoot");
	while (i != NULL) {
		printf("-->%d", i->data);
		i = i->next;
	}
	printf("-->NULL\n\n");
}