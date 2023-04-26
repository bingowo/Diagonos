#include<stdio.h>
#include<stdlib.h>
int table[1001];
int cmp(const void *a,const void *b)
{
    int *s1,*s2;
    s1=(int*)a;
    s2=(int*)b;
    return table[*s1]-table[*s2];
}
int main()
{
    int i;
    for(i=0;i<=1000;i++)
    {
        table[i]=(i+1)*1000;
    }
    int an;
    scanf("%d",&an);
    int A[an];
    for(i=0;i<an;i++)
    {
        scanf("%d",&A[i]);
        table[A[i]]=i;
    }
    int bn;
    scanf("%d",&bn);
    int B[bn];
    for(i=0;i<bn;i++)
    {
        scanf("%d",&B[i]);
    }
    qsort(B,bn,sizeof(B[0]),cmp);
    for(i=0;i<bn;i++)
    {
        printf("%d ",B[i]);
    }
    return 0;
}
