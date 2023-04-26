#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    int A,B,i,j;scanf("%d",&A);int a[A];int d[500];
    for(i=0;i<A;i++)scanf("%d",&a[i]);scanf("%d",&B);
    int b[B];for(i=0;i<B;i++)scanf("%d",&b[i]);
    int c[B],k=0;
    for(i=0;i<A;i++)
    {
        for(j=0;j<B;j++)
        if(b[j]==a[i])
        {
            c[k++]=b[j];
            b[j]=-1;
        }
    }int k1=0;
    for(i=0;i<B;i++)if(b[i]!=-1)d[k1++]=b[i];
    qsort(d,k1,sizeof(int),cmp);
    if(k>0)printf("%d",c[0]);
    for(i=1;i<k;i++)printf(" %d",c[i]);
    if(k1>0)printf("%d",d[i]);
    for(i=1;i<k1;i++)printf(" %d",d[i]);
}