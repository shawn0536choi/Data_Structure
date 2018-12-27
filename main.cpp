#include <stdio.h>
#include <stdlib.h>

typedef struct ID{
    int number;
    ID* link;
}ID;
ID* head= NULL;

void push(){
    int temp;
    printf("입력할 숫자 입력:");
    scanf("%d",&temp);
    if(head == NULL){
        head =(ID*)malloc(sizeof(ID));
        head->number = temp;
        head->link = NULL;
    }else{
        ID* ptr;
        for(ptr=head;ptr->link;ptr=ptr->link);
        ptr->link = (ID*)malloc(sizeof(ID));
        ptr->link->number = temp;
        ptr->link->link = NULL;
    }
}
void pop(){
    if(head == NULL){
        printf("ERROR\n");
        return;
    }else{
        ID* temp = head;
        head = head->link;
        printf("%d\n", temp->number);
        free(temp);
        return;
    }
}

void print(){
    ID* ptr;
    for(ptr=head;ptr;ptr=ptr->link){
        printf("%d",ptr->number);
    }
    printf("\n");
}
int main()
{
    int a;
    while(true){
        printf("Menu\n\t삽입\n\t삭제\n\t내용표시\nEnter Number: ");
        scanf("%d",&a);
        switch(a){
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            print();
            break;
        default:
            printf("404 ERROR!!");
        }
    }
    return 0;
}
