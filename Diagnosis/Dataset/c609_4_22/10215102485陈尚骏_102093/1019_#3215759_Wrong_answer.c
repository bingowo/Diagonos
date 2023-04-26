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
    int*p=malloc(100000*sizeof(int));
    int*q=p;
    int len=0;
    while(scanf("%d",q)!=EOF)
    {
        q++;
        len++;
    }
    qsort(p,len,sizeof(int),cmp);
    for(int i=len;i>=0;i--)
    {
        printf("%d ",q--);
    }
    return 0;
}
