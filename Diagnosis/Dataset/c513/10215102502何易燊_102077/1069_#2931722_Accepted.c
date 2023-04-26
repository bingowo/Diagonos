#include <stdio.h>

int isreverse(long long num)
{
    long long temp = 0, copy = num;
    do
    {
        temp = temp*10+copy%10;
        copy /= 10;
    } while (copy>0);
    while (num>0)
    {
        if (num%10!=temp%10) return 0;
        num /= 10; temp /= 10;
    }
    return 1;
}

int main()
{
    long long num; scanf("%lld",&num);
    int ans = 0;
    while (!isreverse(num))
    {
        ans++;
        long long temp = 0;
        long long copy = num;
        do
        {
            temp = (temp*10)+(copy%10);
            copy /= 10;
        } while (copy>0);
        num += temp;
    }
    printf("%d %lld\n",ans,num);
    return 0;
}