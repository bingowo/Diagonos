#include <stdio.h>
#include <string.h>
#include <math.h>

int gcd(long long int a,long long int b)
{
    while(a%b)
    {
        long long int c = a%b;
        a = b;
        b = c;
    }
    return b;
}
int main()
{
    char s[50];
    long long int sum = 0,a = 0,b = 1;
    scanf("%s",s);
    unsigned int count = 0;
    for(;count < strlen(s);count++)
    {
        if(s[count]=='.')
            break;
        sum = sum * 3;
        if(s[count]=='2')
            sum -= 1;
        if(s[count]=='1')
            sum += 1;
    }
    count++;
    for(;count < strlen(s);count++)
    {
        a = a * 3;
        if(s[count]=='2')
            a -= 1;
        if(s[count]=='1')
            a += 1;
        b = b * 3;
    }
    if(sum > 0&&a < 0)
    {
        sum -= 1;
        a = a + b;
    }
    if(sum < 0&&a > 0)
    {
        sum += 1;
        a = b - a;
        if(sum == 0)
            a = -a;
    }
    if(a == 0)
        printf("%lld",sum);
    else
    {
        if(sum!=0)
            printf("%lld ",sum);
        long long int c = gcd(llabs(b),llabs(a));
        printf("%lld %lld",a/c,b/c);
    }
    return 0;
}
