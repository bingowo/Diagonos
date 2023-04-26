#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long a,b;
    scanf("%lld %lld",&a,&b);
    long long ans = 0;
    while (a!=b)
    {
        if (b>a) a ^= b, b ^= a, a^= b;
        ans += a/b*b*4;
        a %= b;
    }
    ans += a*4;
    printf("%lld\n",ans);
    system("pause");
    return 0;
}