#include <stdio.h>
#include <stdlib.h>
int A[1001]={0};

int cmp1(const void*a, const void*b)
{
    int *m=(int *)a;
    int *n=(int *)b;
    return A[*m]-A[*n];
}
int cmp2(const void *a,const void*b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    int m,i,a;
    int n,j,b,B1[1001]={0},B2[1001]={0};
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&a);
        A[a]=i;
    }
    scanf("%d",&n);
    int k=0,l=0;
    for(j=0;j<n;j++)
    {
        scanf("%d",&b);
        if(A[b])
            B1[k++]=b;
        else B2[l++]=b;
    }
    qsort(B1,k,sizeof(B1[0]),cmp1);
    qsort(B2,l,sizeof(B2[0]),cmp2);
    for(j=0;j<k;j++)
        printf("%d ",B1[j]);
    for(j=0;j<l;j++)
        printf("%d ",B2[j]);
    return 0;
}