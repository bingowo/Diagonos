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
int bigintmax(pBIGINT a, pBIGINT b)
{
    if (a->digit > b->digit)
        return 1;
    else if (a->digit < b->digit)
        return 0;
    else
    {
        for (int i = a->digit;i > -1;i--)
        {
            if (a->num[i] > b->num[i])
                return 1;
            else if (a->num[i] < b->num[i])
                return 0;
        }
    }
    return -1;      //一样大
}
void getsign(pBIGINT num1, pBIGINT num2, pBIGINT res)   //加法器中得到结果的正负号
{
    if (num1->sign == 1 && num2->sign == 1)
        res->sign = 1;
    else if (num1->sign == -1 && num2->sign == -1)
        res->sign = -1;
    else if (bigintmax(num1, num2) == -1)
        res->sign = 1;
    else if (num1->sign == 1 && num2->sign == -1)
    {
        if (bigintmax(num1, num2) == 1)
            res->sign = 1;
        else
            res->sign = -1;
    }
    else
    {
        if (bigintmax(num1, num2) == 1)
            res->sign = -1;
        else
            res->sign = 1;
    }
}
void BigIntTrim(pBIGINT a)
{
    int i;
    if (a->sign == -1)
    {
        for (i = a->digit;i > 0;i--) //找到负数情况下的有效位数
        {
            if (a->num[i] != 0)
                break;
        }
        a->digit = i + 1;
        for (i = 0;i < a->digit;i++)
            a->num[i] *= -1;
    }
    a->digit += 10;  //因为可能有进位，所以为了下面的循环，需要把digit补回来
    for (i = 0;i < a->digit;i++)
    {
        if (a->num[i] >= 0)
        {
            a->num[i + 1] += a->num[i] / 10;
            a->num[i] %= 10;
        }
        else                //相比原来多了个这个，判断这一位是不是负数
        {
            a->num[i + 1] -= 1;
            a->num[i] += 10;
        }
    }
    for (i = a->digit;i > 0;i--) //清除前导零
    {
        if (a->num[i] != 0)
            break;
    }
    a->digit = i + 1;
}
void BigIntAdd(pBIGINT num1, pBIGINT num2, pBIGINT res)
{
    int i;
    getsign(num1, num2, res);
    if (num1->sign == -1)
    {
        for (i = 0;i < num1->digit;i++)
            num1->num[i] *= -1;
    }
    if (num2->sign == -1)
    {
        for (i = 0;i < num2->digit;i++)
            num2->num[i] *= -1;
    }
    for (i = 0;i < mymax(num1->digit, num2->digit);i++)
    {
        res->num[i] = num1->num[i] + num2->num[i];
    }
    res->digit = num1->digit + num2->digit;
    BigIntTrim(res);
}
int isrepeat(int* a, int len)    //如果是不重复数，会返回-1，不然就返回最大的那两个相邻重复数中次大的下标
{
    int i, sum = 0, flag=-1;
    for (i = len - 1;i > 0;i--)
    {
        if (a[i] == a[i - 1])
        {
            flag = i - 1;break;
        }
    }
    return flag;
}
int main()
{
    int len, i, T, x;
    char s[200];
    BIGINT num1, num2, num3;
    scanf("%d", &T);
    for (x = 0;x < T;x++)
    {
        printf("case #%d:\n", x);
        scanf("%s", s);
        len = strlen(s);
        memset(&num1, 0, sizeof(BIGINT));memset(&num2, 0, sizeof(BIGINT));memset(&num3, 0, sizeof(BIGINT));
        num1.sign = num2.sign = num3.sign = 1;
        for (i = len - 1;i > -1;i--)
        {
            num1.num[num1.digit++] = s[i] - '0';
        }
        num2.num[num2.digit++] = 1;
        BigIntAdd(&num1, &num2, &num3); num1 = num3;memset(&num3, 0, sizeof(BIGINT));memset(&num2, 0, sizeof(BIGINT));
        while (isrepeat(num1.num, num1.digit) != -1)
        {
            num2.digit = isrepeat(num1.num, num1.digit) + 1;
            num2.num[num2.digit - 1] = 1;
            num2.sign = num3.sign = 1;                                  //新的加法器的弊端，必须要记录符号
            BigIntAdd(&num1, &num2, &num3); num1 = num3;
            memset(&num3, 0, sizeof(BIGINT));memset(&num2, 0, sizeof(BIGINT));
        }
        for (i = num1.digit - 1;i > -1;i--)
            printf("%d", num1.num[i]);
        printf("\n");
    }
    return 0;
}
