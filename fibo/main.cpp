#include <stdio.h>

int fibo(int t){
    if(t==1 || t==2) return 1;
    else return fibo(t-1)+fibo(t-2);
}
int main()
{
    int a;
    scanf("%d",&a);
    fibo(a);
    int tt=fibo(t);
    printf("%d",tt);
    return 0;
}
