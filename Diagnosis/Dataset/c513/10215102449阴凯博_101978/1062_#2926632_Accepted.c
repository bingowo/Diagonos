#include <stdio.h>
#include <stdlib.h>

long long steps(int n)
{
    long long a[55];
    a[0]=0;a[1]=1;a[2]=2;a[3]=4;a[4]=8;a[5]=15;
    for (int i=5;i<=n;i++)
    {
        a[i]=a[i-1]+a[i-2]+a[i-3]+a[i-4];
    }
    return a[n];


}

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int n;
        scanf("%d",&n);
        printf("%lld\n",steps(n));

    }
    return 0;
}
