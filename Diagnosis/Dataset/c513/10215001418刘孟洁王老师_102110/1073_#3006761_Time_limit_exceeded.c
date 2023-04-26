#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long turn(long long n)
{
    int i,j,s[100007];
    i = 0;
    while(n)
    {
        s[i++] = n%10;
        n /= 10;
    }
    for(j = i-1; j >= 0; j--)n = n*9 + s[j];
    return n;
}

int main()
{
    long long a,b,ans;
    int i;
    char s[1007];
    scanf("%lld%lld",&a,&b);
    ans = turn(b) - turn(a) + 1;//转化为九进制可知道a与b之间有多少不含9的数；
    //printf("%lld %lld %lld\n",turn(a),turn(b),ans);
    for(i = a; i <= b; i++)
    {
        sprintf(s,"%lld",i);
        if(i%9 == 0 && strchr(s,'9') == 0)ans--;//除掉那些不含9但可以被9整除的数；
    }
    printf("%lld",ans);
    return 0;
}
