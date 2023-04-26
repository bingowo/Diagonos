#include <stdio.h>
#define LL long long
LL qpow(LL a, LL n)
{
    LL ans = 1;
    while(n)
    {
        if(n & 1)
            ans = ans * a;
        a *= a;
        n>>=1;
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i<T; i++)
    {
        LL x, y;
        scanf("%lld %lld", &x, &y);
        printf("case #%d:\n", i);
        printf("%lld\n", qpow(x, y));
    }
    return 0;
}
