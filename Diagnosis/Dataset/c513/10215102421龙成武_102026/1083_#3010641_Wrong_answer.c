#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct
{
    int num[1000];           //使用时一定要记得申请空间，以及各位全赋值为0
    int sign;
    int digit;
}BIGINT, * pBIGINT;
int mymax(int a, int b)
{
    return a > b ? a : b;
}
void BigIntTrim(pBIGINT a)
{
    int i;
    for (i = 0;i < a->digit;i++)
    {
        a->num[i + 1] += a->num[i] / 10;
        a->num[i] %= 10;
    }
    for (i = a->digit;i > 0;i--)
    {
        if (a->num[i] != 0)
            break;
    }
    a->digit = i + 1;
}
void BigIntAdd(pBIGINT num1, pBIGINT num2, pBIGINT res)
{
    int i;
    res->sign = num1->sign;   //保存符号
    for (i = 0;i < mymax(num1->digit, num2->digit);i++)
    {
        res->num[i] = num1->num[i] + num2->num[i];
    }
    res->digit = num1->digit + num2->digit;
    BigIntTrim(res);
}
void BigIntMul(pBIGINT num1, pBIGINT num2, pBIGINT res)
{
    int i, j;
    res->sign = num1->sign * num2->sign;
    res->digit = num1->digit + num2->digit;
    for (i = 0;i < num1->digit;i++)
    {
        for (j = 0;j < num2->digit;j++)
        {
            res->num[i + j] += num1->num[i] * num2->num[j];
        }
    }
    BigIntTrim(res);
}
int main()
{
    int T, N, i,res;
    BIGINT num1, num2;
    scanf("%d", &T);
    for (i = 0;i < T;i++)
    {
        scanf("%d", &N);
        memset(&num1, 0, sizeof(num1));memset(&num2, 0, sizeof(num2));
        printf("case #%d:\n", i);
        num1.digit = 1;
        num1.num[0] = N;
        num2.digit = 1;
        while (--N)
        {
            num2.num[0] = N;
            BigIntMul(&num1, &num2, &num1);
        }
        res = 0;
        for (N = 0;N < num1.digit;N++)
        {
            if (num1.num[N] != 0) break;
            else res++;
        }
        printf("%d\n", res);
    }
    return 0;
}

