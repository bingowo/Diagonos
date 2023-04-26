#include <stdio.h>
#define N 50

long long f(int n)
{
    static long long m[N];
    if(n<0)
        return 0;
    if(m[n]==0)
        m[n] = n?f(n-1)+f(n-2)+f(n-3)+f(n-4):1;
    return m[n];
}

int main()
{
    int i, T, n;
    scanf("%d", &T);
    for(i=0; i<T; i++)
    {
        scanf("%d", &n);
        printf("case #%d:\n%lld\n", i, f(n));
    }
    
    return 0;
}
