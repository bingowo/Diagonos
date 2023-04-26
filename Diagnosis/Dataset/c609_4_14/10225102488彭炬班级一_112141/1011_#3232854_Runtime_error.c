#include <stdio.h>
#include <string.h>

int gcd(long long int a,long long int b)
{
    while(a%b)
    {
        long long int c = a % b;
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    char s[100];
    scanf("%s",s);
    int len = strlen(s);
    long long int sum;
    int i;
    for(i = 0;i < len;i++)
    {
        if(s[i] == '.')
            break;
        sum *= 3;
        if(s[i] == '2')
            sum--;
        else if(s[i] == '1')
            sum++;
    }
    long long int a = 0,b = 1;
    for(;i < len;i++)
    {
        b *= 3;
        a *= 3;
        if(s[i] == '2')
            a--;
        else if(s[i] == '1')
            a++;
    }
    if(a < 0)
    {
        sum--;
        a = b - a;
    }
    long long int c = gcd(b,a);
    if(a == 0)
        printf("%lld",sum);
    else
        printf("%lld %lld %lld",sum,a/c,b/c);
    return 0;
}
