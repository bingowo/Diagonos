#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct
{
    int num[10000];           //使用时一定要记得申请空间，以及各位全赋值为0
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
    char c[1001];
    int len,i,val;
    BIGINT num1, num2, res;
    scanf("%s", c);
    len = strlen(c);
    if (len == 1)
        printf("1");
    else if (len == 2)
    {
        memset(num1.num, 0, sizeof(BIGINT));
        memset(num2.num, 0, sizeof(BIGINT));
        memset(res.num, 0, sizeof(BIGINT));
        num1.digit = num2.digit = 1;
        if (c[0] == c[1])
            num1.num[0] = 1;
        else
            num1.num[0] = 2;
        for (i = 1;i < len - 1;i++)
        {
            val = 1;
            if (c[i] != c[i - 1]) val++;
            if (c[i] != c[i + 1]) val++;
            num2.num[0] = val;
            BigIntMul(&num1, &num2, &res);
            num1 = res;
            memset(&res, 0, sizeof(BIGINT));
        }
        if (c[len - 2] == c[len - 1])
            num2.num[0] = 1;
        else
            num2.num[0] = 2;
        BigIntMul(&num1, &num2, &res);
        num1 = res;
        for (i = num1.digit - 1;i > -1;i--)
        {
            printf("%d", num1.num[i]);
        }
        printf("\n");
    }
    return 0;
}