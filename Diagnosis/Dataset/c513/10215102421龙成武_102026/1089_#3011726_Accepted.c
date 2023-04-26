#define _CRT_SECURE_NO_WARNINGS
//就是把前面a的n次方那道题换了个皮，还吓到我了
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
    int a, b,n, T;
    BIGINT num1, num2, res;
    scanf("%d", &T);
    for (int j = 0;j < T;j++)
    {
        printf("case #%d:\n", j);
        memset(num1.num, 0, sizeof(num1.num));
        memset(num2.num, 0, sizeof(num2.num));
        memset(res.num, 0, sizeof(res.num));
        scanf("%d%d%d", &a,&b, &n);
        num1.num[0] = num2.num[0] = a;
        num1.digit = num2.digit = 10;
        BigIntTrim(&num1);
        BigIntTrim(&num2);
        if (b == 0)
        {
            res.digit = 1;
            res.num[0] = 1;
        }
        else {
            b--;
            while (b--)
            {
                BigIntMul(&num1, &num2, &res);
                num1 = res;
                memset(res.num, 0, sizeof(res.num));
            }
            if (num1.digit >= n)
            {
                for (int i = n - 1;i > -1;i--)
                {
                    printf("%d", num1.num[i]);
                }
            }
            else
            {
                for (int i = n - 1;i > -1;i--)
                {
                    if (i < num1.digit)
                    {
                        printf("%d", num1.num[i]);
                    }
                    else
                        printf("0");
                }
            }
            printf("\n");
        }
    }
    return 0;
}

