#include <stdio.h>
long long int ways(int n)
{
    long long int a[50];
    a[1]=1;
    a[2]=2;
    a[3]=4;
    a[4]=8;
    for(int i=5;i<=n;i++)
    {
        a[i]=a[i-1]+a[i-2]+a[i-3]+a[i-4];
    }
    return a[n];
}
int main() {
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        int n;
        scanf("%d",&n);
        long long int sum=ways(n);
        printf("case #%d:\n%lld\n",t,sum);
    }
    return 0;
}
