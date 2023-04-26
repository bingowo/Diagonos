#include <stdio.h>
long long int map[51] = {0};
long long int ways(int n)
{
    long long int ret;
    if(n == 1) ret = 1LL;
    if(n == 2) ret = 2LL;
    if(n == 3) ret = 4LL;
    if(n == 4) ret = 8LL;
    if(n > 4) 
    {
        if(map[n] != 0 ) 
        ret =map[n];
        else 
        {
        ret = ways(n-1) + ways(n-2) +ways(n-3) + ways(n-4);
        map[n] = ret;
        }
    }
    return ret;
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