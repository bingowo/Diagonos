#include <stdio.h>
#include <string.h>
#include <math.h>

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
    long long int sum = 0;
    unsigned int i;
    for(i = 0;i < len;i++)
    {
        if(s[i] == '.')
            break;
        sum = sum * 3;
        if(s[i] == '2')
            sum = sum - 1;
        else if(s[i] == '1')
            sum = sum + 1;
    }
    long long int a = 0,b = 1;
    for(;i < len;i++)
    {
        b = b * 3;
        a = a * 3;
        if(s[i] == '2')
            a = a - 1;
        else if(s[i] == '1')
            a = a + 1;
    }
    if(a < 0&&sum > 0)
    {
        sum--;
        a = b + a;
    }
    if(a > 0&&sum < 0)
    {
        sum++;
        a = b - a;
    }
    long long int c = gcd(llabs(b),llabs(a));
    if(a == 0)
        printf("%lld",sum);
    else
    {
        if(sum != 0)
            printf("%lld",sum);
        printf("%lld %lld",a/c,b/c);
    }
    return 0;
}
