#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long turn(long long n)
{
    return n < 9?n:turn(n/10)*9 + n%10;
}

long long val(long long n)
{
    long long rest = n%10;
    long long i;
    char s[107];
    for(i = n-rest; i <= n; i++)
    {
        memset(s,0,sizeof(s));
        sprintf(s,"%lld",i);
        if(i%9 == 0 || strchr(s,'9') != 0)rest--;//除掉余数里面的不妙数；
    }
    long long number = rest + 8*turn(n-n%10)/9;//9个里有1个是9的倍数；
    return number;
}

int main()
{
    long long a,b,ans;
    scanf("%lld%lld",&a,&b);
    ans = val(b) - val(a)+1;
    printf("%lld",ans);
    return 0;
}
