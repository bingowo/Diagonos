#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int m=1,A[501]={0};
int ord(int x)
{
    int i;
    for(i=0;i<m;i++)
    {
        if(x==A[i])
            return i;
    }
    return m;
}
int cmp(const void* a,const void* b)
{
    int c=*(int*)a,d=*(int*)b;
    int i=ord(c),j=ord(d);
    if(i!=m || j!=m) return i-j;
    return c-d;
}
int main()
{
    int i,n,B[501];
    scanf("%d",&m);
    for(i=0;i<m;i++)
        scanf("%d",&A[i]);
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&B[i]);
    qsort(B,n,sizeof(B[0]),cmp);
    for(i=0;i<n;i++)
        printf("%d ",B[i]);
    return 0;
}
