#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

int cmp(const void*a,const void*b)
{
    int a1=*(int*)a;
    int b1=*(int*)b;
    return a1-b1;
}

int main()
{
    int a[100001];
    int i=0;
    while(scanf("%d",&a[i])!=EOF)
    {
        i++;
    }
    printf("%d\n",sizeof(a));
    return 0;
}
