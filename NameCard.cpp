#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN	30
#define PHONE_LEN	30

typedef struct __namecard {
	char name[NAME_LEN];
	char phone[PHONE_LEN];
} NameCard;

NameCard * MakeNameCard(char * name, char * phone) {
	NameCard* add_node = (NameCard *)malloc(sizeof(NameCard));
	strcpy(add_node->name, name);
	strcpy(add_node->phone, phone);
	return add_node;
}

void ChangePhoneNum(NameCard * pcard, char * phone) {
	strcpy(pcard->phone, phone);
}

void ShowNameCardInfo(NameCard* pcard) {
	printf("Name: %s\nPhoneNum: %s\n", pcard->name, pcard->phone);
}

int NameCompare(NameCard* pcard, char * name) {
	return strcmp(pcard->name, name);
}

int main()
{
	bool off = false;
	NameCard* namecard[10];
	int choose = 0;
	while (off == false) {
		int choice;
		printf("#Menu#\n1. 입력\n2. 출력\n3. 비교\n4. 변경\n5. 나가기\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:

			char name[30];
			printf("Name: ");
			scanf("%s", name);
			char phone[30];
			printf("phone: ");
			scanf("%s", phone);

			namecard[choose++] = MakeNameCard(name, phone);
			break;
		case 2:
			ShowNameCardInfo(namecard[choose-1]);
			break;
		case 3:
			char name1[30];
			printf("Name: ");
			scanf("%s", name1);
			for (int i = 0; i < choose; i++) {
				if (NameCompare(namecard[i], name1) == 0) {
					printf("%d\n", i);
				}
			}
			break;
		case 4:
			char new_phone[30];
			printf("New Phone: ");
			scanf("%s", new_phone);
			ChangePhoneNum(namecard[choose-1], new_phone);
			break;
		case 5:
			off = true;
			break;
		default:
			printf("다시 입력하십시오");
			break;
		}
	}
	return 0;
}