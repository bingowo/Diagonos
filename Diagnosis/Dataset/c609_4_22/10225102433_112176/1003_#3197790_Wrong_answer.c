#include <stdio.h>

void solve(long long num)
{
    long long int a[1000] = {0};
    int cnt = 0;
    while(num)
    {
        long long int res = num%2333;
        num /= 2333;
        a[cnt++] = res;
    }
    for(int i = cnt-1;i >= 0;i--)
        printf("%lld%c",a[i],i == 0 ? '\n': ' ');
}

int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        long long num;
        scanf("%lld",&num);
        solve(num);
    }

    return 0;
}