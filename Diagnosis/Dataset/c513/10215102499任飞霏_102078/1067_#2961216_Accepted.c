#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned long long a[74];

unsigned long long fib(int n)
{
    if(a[n]!=3)return a[n];
    else
        a[n]=fib(n-1)+fib(n-2)+fib(n-3);
        return a[n];
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<74;i++){
        a[i]=3;
    }
    a[0]=0;a[1]=1;a[2]=1;
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        int n;
        scanf("%d",&n);
        printf("%llu\n",fib(n));
    }
    return 0;
}
