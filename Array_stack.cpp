#include <stdio.h>
#include <stdlib.h>

void push(int *top, int stack1[]) {
	int temp;
	printf("Enter number: ");
	scanf("%d", &temp);
	
	stack1[++(*top)] = temp;
}

int pop(int *top, int stack1[]) {
	if (*top == -1) return 0;
	else return stack1[(*top)--];
}

void peek(int top, int stack1[]) {
	if (top == -1) {
		printf("Stack is empty");
	}
	else {
		printf("%d", stack1[top]);
	}
}


int main()
{
	int choice, stack[10] = { 0, };
	int* stack1 = stack;
	int top = -1, max_size = 10;
	bool exit = false;
	while (exit == false) {
		printf("Menu\n1. push\n2. pop\n3. peek\n4. exit\n");
		printf("Your choice: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			if (top == max_size-1) {
				stack1 = (int*)realloc(stack1, sizeof(max_size) * 2);
			}
			push(&top, stack1);
			break;
		case 2:
			printf("%d\n", pop(&top, stack1));
			break;
		case 3:
			peek(top, stack1);
			break;
		case 4:
			exit = true;
		default:
			printf("Wrong choice\n");
		}
	}
	return 0;
}