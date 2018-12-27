#include <stdio.h>
#include <string.h>

int check_space(char str[],int len){
    for(int i=0;i<len;i++){
        if(str[i]==' '){
            return i;
        }
    }
    return -1;
}

int main()
{
    char str1[50];
    char str2[50];
    scanf("%[^\n]",str1);
    getchar();
    scanf("%[^\n]",str2);

    int len1=strlen(str1);
    int len2=strlen(str2);

    int space1=check_space(str1,len1);
    int space2=check_space(str2,len2);

    if(space1!=space2) printf("different name!\n");
    else{
        int i;
        for(i=0;i<space1;i++)
            if(str1[i]!=str2[i])break;
        if(space1==i)
            printf("same name!\n");
        else
            printf("different name!\n");
    }

    if(len1-space1!=len2-space2) printf("different age!\n");
    else{
        int i;
        for(i=0;i<len1-space1;i++)
            if(str1[space1+i]!=str2[space2+i])break;
        if(len1-space1==i)
            printf("same age!\n");
        else
            printf("different age!\n");
    }
    return 0;
}
