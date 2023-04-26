#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct
{
    int num[10000];           
    int sign;
    int digit;
}BIGINT, * pBIGINT;
typedef struct
{
    BIGINT a;
    BIGINT b;  //虚部
}COMPLEX, * pCOMPLEX;
int mymax(int a, int b)
{
    return a > b ? a : b;
}
void BigIntTrim(pBIGINT a)
{
    int i;
    for (i = 0;i < a->digit;i++)
    {
        if (a->num[i] >= 0)
        {
            a->num[i + 1] += a->num[i] / 10;
            a->num[i] %= 10;
        }
        else
        {
            a->num[i + 1] -= 1;
            a->num[i] += 10;
        }
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
void BigComMul(pCOMPLEX cnum1, pCOMPLEX cnum2, pCOMPLEX res)
{
    COMPLEX temp1, temp2;
    BigIntMul(&cnum1->a, &cnum2->a, &temp1.a);
    BigIntMul(&cnum1->b, &cnum2->b, &temp2.a);
    BigIntSub(&temp1.a, &temp2.a, &res->a);
    BigIntMul(&cnum1->a, &cnum2->b, &temp1.b);
    BigIntMul(&cnum1->b, &cnum2->a, &temp2.b);
    
}
int main()
{
    char c[100], * p, * q;
    int n, a, b,i;
    COMPLEX cnum1, cnum2, cnum3;
    scanf("%s %d", c, &n);
    memset(&cnum1, 0, sizeof(COMPLEX));memset(&cnum2, 0, sizeof(COMPLEX));memset(&cnum3, 0, sizeof(COMPLEX));
    cnum1.a.digit = 10;
    cnum2.b.digit = 10;
    if (sscanf(c, "%d %d %c", &a, &b, &i) == 3);
    else if (sscanf(c, "%d %d %c", &a, &b, &i) == 1)
    {
        if (strchr(c, 'i') != NULL)
        {
            a = 0;
            sscanf(c, "%d %c", &b, &i);
        }
        else
        {
            b = 0;
            sscanf(c, "%d", &a);
        }
    }
    else if (sscanf(c, "%d %d %c", &a, &b, &i) == 0)
    {
        a = 0;
        if (c[0] == '-')
            b = -1;
        else
            b = 1;
    }
    cnum1.a.num[0] = a;
    cnum1.a.sign = a > 0 ? 1 : -1;
    cnum1.b.num[0] = b;
    cnum1.b.sign = b > 0 ? 1 : -1;
    BigIntTrim(&cnum1.a);
    BigIntTrim(&cnum1.b);
    cnum2 = cnum1;

    return 0;
}

