#include <stdio.h>

int factorial(int num) {
	if (num == 0)	return 1;
	return num*factorial(num - 1);
}

int main()
{
	int num;
	scanf("%d", &num);
	int ans = factorial(num);
	printf("%d", ans);
	return 0;
}