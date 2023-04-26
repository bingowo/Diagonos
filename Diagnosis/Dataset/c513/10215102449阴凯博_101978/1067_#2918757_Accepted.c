#include <stdio.h>
#include <stdlib.h>
#define N 75
#define MAXLINES 1000

unsigned long long tribonacci(int n)
{
    unsigned long long a[N];
    a[0]=0;a[1]=1;a[2]=1;
    for (int i=3;i<=n;i++)
        a[i]=a[i-1]+a[i-2]+a[i-3];
    return a[n];
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",i);
        printf("%llu\n",tribonacci(n));
    }

}
