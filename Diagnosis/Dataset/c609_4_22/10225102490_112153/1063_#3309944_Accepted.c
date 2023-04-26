#include <stdio.h>

#define N 50

long long f(int n)
{
    static long long m[N];
    if (n < 0) return 0;
    if (m[n] == 0) m[n] = n ? (f(n-1) + f(n-2) + f(n-3) + f(n-4)) : 1;
    return m[n];
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int I = 0; I < T; I++)
    {
        printf("case #%d:\n",I);
        int n;
        scanf("%d",&n);
        printf("%lld\n",f(n));
    }
    return 0;
}
