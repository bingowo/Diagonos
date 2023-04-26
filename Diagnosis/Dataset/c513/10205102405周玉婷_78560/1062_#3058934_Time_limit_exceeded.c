#include <stdio.h>

long long int ways(int n)
{
    if(n == 1) return 1LL;
    if(n == 2) return 2LL;
    if(n == 3) return 4LL;
    if(n == 4) return 8LL;
    if(n > 4) return ways(n-1) + ways(n-2) +ways(n-3) + ways(n-4);
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int j=0; j<t; j++)
    {
        int n;
        scanf("%d", &n);
        long long int res = ways(n);
        printf("case #%d:\n", j);
        printf("%lld\n", res);
    }
    return 0;
}