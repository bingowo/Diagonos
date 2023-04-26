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
    int a, n,T;
    BIGINT num1, num2, res;
    scanf("%d", &T);
    for(int j=0;j<T;j++)
    {
        printf("case #%d:\n", j);
        memset(num1.num, 0, sizeof(num1.num));
        memset(num2.num, 0, sizeof(num2.num));
        memset(res.num, 0, sizeof(res.num));
        scanf("%d%d", &a, &n);
        num1.num[0] = num2.num[0] = a;
        num1.sign = num2.sign = 1;
        num1.digit = num2.digit = 1;
        if (n == 0)
            printf("1\n");
        else {
            n--;
            while (n--)
            {
                BigIntMul(&num1, &num2, &res);
                num1 = res;
                memset(res.num, 0, sizeof(res.num));
            }
            for (int i = num1.digit - 1;i > -1;i--)
            {
                printf("%d", num1.num[i]);
            }
            printf("\n");
        }
    }
    return 0;
}

