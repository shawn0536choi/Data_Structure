#include <stdio.h>
#include <stdlib.h>

int main()
{
	int len;
	printf("size of arr\n-->");
	scanf("%d", &len);
	int *arr = (int *)malloc(sizeof(int)*len);
	printf("input array\n-->");
	for (int i = 0; i < len; i++) {
		scanf("%d", &arr[i]);
	}
	int purpose;
	printf("What do you want to find?\n-->");
	scanf("%d", &purpose);
	int standard = len / 2;
	bool found = false;
	while (found == false) {
		if (arr[standard] > purpose) {
			standard = standard / 2;
		}
		else if (arr[standard] == purpose) {
			found = true;
			printf("\narr[%d] = %d", standard, purpose);
		}
		else {
			standard = (standard + len) / 2;
		}
	}
	return 0;
}