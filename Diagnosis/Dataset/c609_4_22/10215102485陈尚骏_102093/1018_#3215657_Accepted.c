#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<malloc.h>

int cmp(const void*a,const void*b)
{
    int a1=*(int*)a;
    int b1=*(int*)b;
    return a1-b1;
}

int main()
{
    int n;
    scanf("%d",&n);
    int*p=malloc(n*sizeof(int));
    int*q=p;
    for(int i=0;i<n;++i)
    {
        scanf("%d",q++);
    }
    qsort(p,n,sizeof(int),cmp);
    int res=0;
    for(int i=0;i<n;i+=2)
    {
        res+=abs(p[i]-p[i+1]);
    }
    printf("%d\n",res);
    return 0;
}
