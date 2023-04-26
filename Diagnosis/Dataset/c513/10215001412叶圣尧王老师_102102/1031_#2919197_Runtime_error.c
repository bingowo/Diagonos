#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmpup(const void*a,const void*b)
{
    return *(int *)a-*(int *)b;
}

int cmpdw(const void*a,const void*b)
{
    return *(int *)b-*(int *)a;
}

int main()
{
    int T,t;scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        int i,n;scanf("%d",&n);int a[n],b[n];long long sum=0;
        for(i=0;i<n;i++)scanf("%d",a[i]);
        for(i=0;i<n;i++)scanf("%d",b[i]);
        qsort(a,n,sizeof(a[0]),cmpup);
        qsort(b,n,sizeof(b[0]),cmpdw);
        for(i=0;i<n;i++)sum=sum+a[i]*b[i];
        printf("%lld",sum);
    }
}