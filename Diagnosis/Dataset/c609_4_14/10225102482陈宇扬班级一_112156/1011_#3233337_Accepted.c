#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define LL long long int
LL GCD(LL a, LL b)
{
    if(b == 0)
        return a;
    return GCD(b, a%b);
}

int main()
{
    char s[50] ={0};
    scanf("%s", s);

    LL ansA = 0, ansB = 0, ansC = 1;
    unsigned int p = 0;
    for(; p < strlen(s); p++)//整数部分
    {
        if(s[p] == '.')
            break;
        ansA = ansA * 3;
        if(s[p] == '1')
            ansA += 1;
        if(s[p] == '2')
            ansA -= 1;
    }
    p++;// very important! 把跳出的小数点加上了
    for(; p < strlen(s); p++)//小数部分
    {
        ansB = ansB * 3;
        if(s[p] == '1')
            ansB += 1;
        if(s[p] == '2')
            ansB -= 1;
        ansC = ansC * 3;
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
        if(ansA == 0)
            ansB = -ansB;
    }

    LL absB = llabs(ansB), absC = llabs(ansC);
    LL t = GCD(absB, absC);

    if(ansB == 0)
        printf("%lld\n", ansA);
    else
    {
        if(ansA != 0)
         printf("%lld ", ansA);
        printf("%lld %lld\n", ansB / t, ansC /t);
    }
    return 0;
}
