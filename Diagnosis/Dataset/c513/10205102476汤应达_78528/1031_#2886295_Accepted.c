#include<stdio.h>
#include<stdlib.h>

int cmp1(const void*a,const void*b)
{return *(int*)a-*(int*)b;}

int cmp2(const void*a,const void*b)
{return *(int*)b-*(int*)a;}

int main()
{
    int T,n,sum;scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d",&n);
        int a[n],b[n];sum=0;
        for(int t=0;t<n;t++) scanf("%d",&a[t]);
        for(int t=0;t<n;t++) scanf("%d",&b[t]);
        qsort(a,n,sizeof(a[0]),cmp1);
        qsort(b,n,sizeof(b[0]),cmp2);
        for(int t=0;t<n;t++) sum+=a[t]*b[t];
        printf("case #%d:\n%d\n",i,sum);
    }

    return 0;
}
