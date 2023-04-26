#include <stdio.h>
#include <stdlib.h>
int cmp1(const void *a, const void *b)
{
    return *((int *)a)-*((int *)b);
}
int cmp2(const void *a, const void *b)
{
    return *((int *)b)-*((int *)a);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n,a[1000],b[1000],sum=0;
        scanf("%d",&n);
        for(int j=0;j<n;j++) scanf("%d",&a[j]);
        for(int j=0;j<n;j++) scanf("%d",&b[j]);
        qsort(a,n,sizeof(a[0]),cmp1);
        qsort(b,n,sizeof(b[0]),cmp2);
        for(int j=0;j<n;j++) sum=sum+a[j]*b[j];
        printf("case #%d:\n",i);
        printf("%d\n",sum);
    }
    return 0;
}
