#include <stdio.h>
#include <stdlib.h>

typedef struct Stack Stack;
typedef struct Stack {
	bool dummy;
	int data;
	Stack* next;
}Stack;

void StackInit(Stack **stack) {
	Stack* newnode = (Stack*)malloc(sizeof(Stack));
	newnode->dummy = true;
	newnode->data = -99;
	newnode->next = NULL;
	*stack = newnode;
}

int IsEmpty(Stack *stack) {
	return stack->next==NULL;
}

void Push(Stack* stack, int data) {
	Stack* newnode = (Stack*)malloc(sizeof(Stack));
	newnode->data = data;
	newnode->next = NULL;
	newnode->dummy = false;

	newnode->next = stack->next;
	stack->next = newnode;
}

void peek(Stack* stack) {
	if (IsEmpty(stack)) {
		printf("Nothing!\n");
	}
	else {
		printf("%d\n", stack->next->data);
	}
}

Stack* Pop(Stack *stack){
	if (stack->next == NULL) {
		printf("Stack underflow\n");
		return stack;
	}
	else {
		Stack* temp = stack->next;
		stack->next = stack->next->next;
		return temp;
	}
}


int main(void)
{
	Stack* stack = NULL;

	StackInit(&stack);

	bool exit = false;
	while (exit == false) {
		int choice;
		printf("Menu\n1. push\n2. pop\n3. peek\n4. exit\n");
		printf("Your choice: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			int data;
			printf("Enter number: ");
			scanf("%d", &data);
			Push(stack, data);
			break;
		case 2:
			printf("Pop: %d\n",Pop(stack)->data);
			break;
		case 3:
			peek(stack);
			break;
		case 4:
			exit = true;
		default:
			printf("Wrong choice\n");
		}
	}
	return 0;
}