#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long f(int n)
{
    static long long m[50];
    if (n<0) return 0;
    if(!m[n]) m[n]=n?f(n-1)+f(n-2)+f(n-3)+f(n-4):1;
    return m[n];
}

int main()
{
    int T,I,n;
    for (scanf("%d",&T),I=0;I<T;I++)
    {
        printf("case #%d:\n",I);
        scanf("%d",&n);
        printf("%lld\n",f(n));
    }
    return 0;
}
