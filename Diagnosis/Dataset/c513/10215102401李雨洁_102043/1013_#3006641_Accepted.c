#include <stdio.h>
#include <string.h>
#include <math.h>

long long GCD(long long m, long long n)
{
    return n ? GCD( n , m % n) : m;
}
int main()
{
    char s[100000];
    scanf("%s",s);
    int p = 0;
    long long ansA = 0;
    long long ansB = 0, ansC = 1;
    for(; p < (int)strlen(s); p++)
    {//整数部分
        if(s[p] == '.')
            break;
        ansA = ansA *3;
        if(s[p] == '1') ansA += 1;
        if(s[p] == '2') ansA -= 1;
    }
    p++;
    for(; p < (int)strlen(s); p++)
    { //小数部分
        ansB = ansB * 3; //分子
        if (s[p] == '2') ansB -= 1;
        if (s[p] == '1') ansB += 1;
        ansC = ansC * 3; //分母
    }
    if(ansA > 0 && ansB < 0)
    {
        ansA--;
        ansB = ansC + ansB;
    }
    else if(ansA < 0 && ansB > 0)
    {
        ansA++;
        ansB = ansC - ansB;
    }
    if(ansA == 0)
        ansB = -ansB;
    long long t = GCD(abs(ansB),abs(ansC));
    if(ansB == 0)
        printf("%lld\n",ansA);
    else
    {
        if(s[0]=='0')
        {
            if(ansA != 0)
                printf("%lld ",ansA);
            printf("%lld %lld\n",-1*(ansB / t),ansC / t);
        }
        else
        {
            if(ansA != 0)
                printf("%lld ",ansA);
            printf("%lld %lld\n",ansB / t,ansC / t);
        }
    }
    return 0;
}

