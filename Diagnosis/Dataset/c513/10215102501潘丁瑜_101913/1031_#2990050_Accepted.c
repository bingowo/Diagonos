#include <stdio.h>
#include <stdlib.h>

int acmp(const void*a,const void*b)
{
    int *m=(int *)a;
    int *n=(int *)b;
    return *m-*n;
}

int bcmp(const void*a,const void*b)
{
    int *c=(int *)a;
    int *d=(int *)b;
    return *d-*c;
}
int main()
{
    int T,i;
    int N,j;
    scanf("%d\n",&T);
    for(i=0;i<T;i++)
    {
        long long int sum=0;
        int a[1001]={0};
        int b[1001]={0};
        scanf("%d\n",&N);
        for(j=0;j<N;j++)
            scanf("%d",&a[j]);
        qsort(a,j,sizeof(a[0]),acmp);
        for(j=0;j<N;j++)
            scanf("%d",&b[j]);
        qsort(b,j,sizeof(b[0]),bcmp);
        for(j=0;j<N;j++)
            sum=sum+(a[j]*b[j]);
        printf("case #%d:\n",i);
        printf("%lld\n",sum);
    }
    return 0;
}
