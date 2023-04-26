#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include <stdio.h>

void NumConvert(long long num, long long radix)
{
    if (num == 0)
        return;
    else if(num > 0)
    {
        NumConvert(num / radix, radix);
        if (num % radix >= 0 && num % radix < 10)
            printf("%lld", num % radix);
        else
            printf("%c", (char)(num % radix + 55));//num % radix + 55是对应的大写字母ASCII码
    }
    else
    {
        if (num % radix == 0)
        {
            NumConvert(num / radix, radix);
            printf("%lld", num % radix);
        }
        else if (num % radix - radix > 0 && num % radix - radix < 10)
        {
            NumConvert(num / radix + 1, radix);
            printf("%lld", num % radix - radix);
        }
        else
        {
            NumConvert(num / radix + 1, radix);
            printf("%c", (char)(num % radix - radix + 55));
        }
    }
}
int main()
{
    long long num = 0, radix = 0;
    scanf("%lld", &num);
    scanf("%lld", &radix);
    NumConvert(num, radix);
    return 0;
}
