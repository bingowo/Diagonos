#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int cmp1(const void *a,const void *b)
{
    int*p1=(int*)a;
    int*p2=(int*)b;
    return *p1-*p2;
}

int cmp2(const void *a,const void *b)
{
    int*p1=(int*)a;
    int*p2=(int*)b;
    return *p2-*p1;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        int a[1001],b[1001];
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int j=0;j<n;j++)
            scanf("%d",&a[j]);
        for(int j=0;j<n;j++)
            scanf("%d",&b[j]);
        qsort(a,n,sizeof(a[0]),cmp1);
        qsort(b,n,sizeof(b[0]),cmp2);
        int sum=0;
        for(int j=0;j<n;j++)
            sum+=a[j]*b[j];
        printf("case #%d:\n",i);
        printf("%d\n",sum);
    }
    return 0;
}
