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
void BigIntSub(pBIGINT num1, pBIGINT num2, pBIGINT res)
{
    int i;
    pBIGINT temp;
    if (num1->digit < num2->digit)
    {
        temp = num1;
        num1 = num2;
        num2 = temp;             //尽量让num1是绝对值大的那个
        res->sign = -1;
    }
    else if (num1->digit > num2->digit) res->sign = 1;
    else
    {
        for (i = num1->digit-1;i > -1;i--)
        {
            if (num1->num[i] < num2->num[i])
            {
                temp = num1;
                num1 = num2;
                num2 = temp;  
                res->sign = -1;break;
            }
            else if (num1->num[i] > num2->num[i])
            {
                res->sign = 1;break;
            }
        }
    }
    for (i = 0;i < mymax(num1->digit, num2->digit);i++)
    {
        res->num[i] = num1->num[i] - num2->num[i];
    }
    res->digit = mymax(num1->digit, num2->digit);
    BigIntTrim(res);
}
int main()
{
    int lena, lenb;
    char A[501], B[501];
    BIGINT num1, num2,num3;
    while (scanf("%s %s", A, B)!=-1)
    {
        lena = strlen(A)-1;lenb = strlen(B)-1;
        memset(&num1, 0, sizeof(num1));memset(&num2, 0, sizeof(num2));memset(&num3, 0, sizeof(num3));
        for (;lena > -1;lena--)
        {
            num1.num[num1.digit++] = A[lena]-'0';
        }
        for (;lenb > -1;lenb--)
        {
            num2.num[num2.digit++] = B[lenb]-'0';
        }
        BigIntSub(&num1, &num2, &num3);
        if (num3.sign == -1) printf("-");
        for (int i = num3.digit - 1;i > -1;i--)
        {
            printf("%d", num3.num[i]);
        }
        printf("\n");
    }
    return 0;
}
