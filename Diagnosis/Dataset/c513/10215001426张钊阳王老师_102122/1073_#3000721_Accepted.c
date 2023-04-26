#include <stdio.h>
#include <string.h>
#include <stdlib.h>


long long POW(long long base, long long power)
{
    long long temp = 1;
    while(power--)
    {
        temp *= base;
    }
    return temp;
}

long long distan(char* s)
{
    int len=strlen(s);
    int times = 0;
    for(int i = 0; i < len - 1; i++)
    {
        times += s[i] -'0';
    }
    return (times % 9) ? (9 - times % 9) : 0;
    //判断这个数字抹去个位数后离下一个9的倍数还有多少个数

}

long long solve(char *s)
{
    long long min(long long a,long long b);
    int len  = strlen(s);
    long long num = 0;
    for(int i = 0; i < len - 1; i++)
    {
        if(s[i] == '9')
        {
            for(int j = i; j < len; j++)
                s[j] = '8';
        }
        num += (s[i] - '0') * POW(9, len - i - 2) * 8;
        //比如 1023，每个整千就会有0~8 九个整百数需要处理累加
        //每个整百又可以分0~8九个整10来处理，每个整十均有8个满足条件的数
    }

    long long remain = min(s[len - 1], '8') - '0';
    num += remain;//个位数单独处理
    num ++;//别忘了0

    if(distan(s) <= remain)
        num--;

    return num;
}

long long min(long long a,long long b)
{
    return (a>b)?b:a;
}
int main()
{
    char *a,*b;
    a=(char*)malloc(sizeof(char)*20);
    b=(char*)malloc(sizeof(char)*20);
    scanf("%s %s",a,b);
    long long way = solve(b) - solve(a);
    printf("%lld",way+1);
    //别忘了a是闭区间
    free(a),free(b);
    return 0;
}
