#include <stdio.h>
#define N 1000

int* findPrimes(int* prs)
{
    int i,j;
    int b[N+1] = {0};
    int *primes = prs;
    for (i = 2; i <= N; i++)
    {
        if (!b[i])
        {
            *prs++ = i;
            for (j = 2;i*j <= N; j++) b[i*j] = 1;
        }
    }
    *prs = N+1;
    return primes;
}

long long f(int n, int *prs)
{
    static long long m[N+1][N+1];
    int t,k = 0;
    if (!m[n][*prs])
    {
        if (!n) m[n][*prs] = 1;
        else if (n >= *prs)
        {
            while ((t = n - *prs * k++) >= 0)
                m[n][*prs] += f(t,prs+1);
        }
    }
    return m[n][*prs];
}

int main()
{
    int n;
    int primes[N/5];
    printf("%lld\n",f((scanf("%d",&n),n), findPrimes(primes)));
    return 0;
}