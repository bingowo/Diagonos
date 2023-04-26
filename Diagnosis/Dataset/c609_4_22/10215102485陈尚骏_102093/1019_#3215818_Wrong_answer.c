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
    int a[100001]={0};
    int n;
    int i=0;
    while(scanf("%d",&n)!=EOF)
    {
        a[i]=n;
        i++;
    }
    int*b=malloc((i+1)*sizeof(int));
    for(int j=0;j<i;j++)
    {
        b[j]=a[j];
    }
    qsort(b,i+1,sizeof(int),cmp);
    for(int j=0;j<i;j++)
    {
        printf("%d ",b[j]);
    }
    return 0;
}
