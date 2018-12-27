#include <stdio.h>
#include <stdlib.h>

typedef struct NODE1 NODE;
typedef struct NODE1 {
	NODE *next;
	int data;
}NODE;

void addFirst(NODE **target, int data)
{
	NODE *newNode = (NODE*)malloc(sizeof(NODE));
	newNode->next = *target;  //newNode�� ����� next�� head ���̴�.
	newNode->data = data;

	*target = newNode;  //���ο� head�� newNode�̴�.
}

int main()
{
	NODE *head = NULL;

	addFirst(&head, 10);
	addFirst(&head, 20);
	addFirst(&head, 30);

	NODE *curr = head;

	while (curr != NULL)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}

	curr = head->next;
	while (curr != NULL)
	{
		NODE *next = curr->next;
		free(curr);
		curr = next;
	}

	free(head);

	return 0;
}