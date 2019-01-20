#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct NODE1 NODE;
typedef struct NODE1 {
	NODE *next;
	int data;
}NODE;


void ListInsert(NODE **target, int data)
{
	NODE *newNode = (NODE*)malloc(sizeof(NODE));
	newNode->next = *target;  //newNode의 노드의 next가 head 값이다.
	newNode->data = data;

	*target = newNode;  //새로운 head가 newNode이다.
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

int main()
{
	NODE* root = NULL;
	bool off = false;
	srand(time(NULL));
	int num;
	while (off == false) {
		int option;
		num = rand() % 100 + 1;
		printf("\t=======================\n\t=====\t *MENU*    ====\t\n\t=======================\n\n\t\t1. INPUT\n\t\t2. OUTPUT\n\t\t3. SORT\n\t\t4. EXIT\n");
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
			
			int swapped;
			do
			{
				swapped = 0;//Check if there was a swap in while loop
				NODE* ptr = root;//Indicate node to swap
				NODE* prev = root;//Node before ptr
				bool first = true;//
				while (ptr->next != NULL)
				{
					bool swapped2 = false;
					if (ptr->data > ptr->next->data)
					{
						NODE* temp = ptr;
						ptr = ptr->next;
						temp->next = ptr->next;
						ptr->next = temp;
						swapped = 1;
						swapped2 = true;
					}
					if (first) {
						root = ptr;
						first = false;
					}
					else if (swapped2) {
						prev->next = ptr;
					}
					prev = ptr;
					ptr = ptr->next;
				}
			} while (swapped);
			printf("\t\tSorted!!!\n");
			break;
		case 4:
			off = true;
			printf("\t\tYou Exited!!!\n\n\t\tPress Any Key\n");
			break;
		}
	}
	return 0;
}