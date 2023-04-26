#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//char alpha[128] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
//int alpha[128];
//void getalpha()
//{
//    int i;
//    for (i = 0;i < 10;i++)
//    {
//        alpha[i] = i;
//    }
//    for (i = 'A';i <= 'F';i++)
//    {
//        alpha[i] = i - 'A' + 10;
//    }
//}
int refera[16] = { 0,1,-1,0,0,1,-1,0,2,3,1,2,2,3,1,2 };
int referb[16] = { 0,0,1,1,-2,-2,-1,-1,2,2,3,3,0,0,1,1 };
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
void BigIntMul(pBIGINT num1, pBIGINT num2, pBIGINT res)
{
    int i, j;
    //res->sign = num1->sign * num2->sign; 
    //因为乘法的时候，正负号不会导致各位上的数值出现正负，或者换句话说，各位上的数值一定是正数，和做加减法不一样
    //所以要先修改符号位为1，然后在最后再得到正确的符号位
    res->sign = 1;
    res->digit = num1->digit + num2->digit;
    for (i = 0;i < num1->digit;i++)
    {
        for (j = 0;j < num2->digit;j++)
        {
            res->num[i + j] += num1->num[i] * num2->num[j];
        }
    }
    BigIntTrim(res);
    res->sign = num1->sign * num2->sign;
}
int main()
{
    char s[3000];
    int c[3000], i, len;
    getchar();getchar();
    scanf("%s", s);
    BIGINT num1, num2, num3, num4, num5;
    memset(&num1, 0, sizeof(BIGINT));memset(&num2, 0, sizeof(BIGINT));
    memset(&num3, 0, sizeof(BIGINT));memset(&num4, 0, sizeof(BIGINT));
    memset(&num5, 0, sizeof(BIGINT));
    len = strlen(s);
    for (i = 0;i < len;i++)
    {
        if (s[i] >= 'A')  c[i] = s[i] - 'A' + 10;
        else c[i] = s[i] - '0';
    }
    num1.digit = 1;num1.sign = 1;
    num2.digit = 1;num2.sign = -1;num2.num[0] = 4;   //往num2里存-4;num1里存0
    num4.digit = 1;
    for (i = 0;i < len;i++)              //计算a
    {
        BigIntMul(&num1, &num2, &num3);
        num1 = num3;
        memset(&num3, 0, sizeof(BIGINT));

        num4.sign = refera[c[i]] > 0 ? 1 : -1;
        num4.num[0] = num4.sign * refera[c[i]];    //num4里存下一位
        BigIntAdd(&num1, &num4, &num3);
        num1 = num3;
        memset(&num3, 0, sizeof(BIGINT));
    }
    for (i = 0;i < len;i++)
    {
        BigIntMul(&num5, &num2, &num3);
        num5 = num3;
        memset(&num3, 0, sizeof(BIGINT));

        num4.sign = referb[c[i]] > 0 ? 1 : -1;
        num4.num[0] = num4.sign * referb[c[i]];
        BigIntAdd(&num5, &num4, &num3);
        num5 = num3;
        memset(&num3, 0, sizeof(BIGINT));
    }

    int flaga, flagb;
    flaga = flagb = 0;
    if (num1.digit > 1 || (num1.digit == 1 && num1.num[0] != 0))
        flaga = 1;
    if (num5.digit > 1 || num5.digit == 1 && num5.num[0] != 0)
        flagb = 1;
    if (flaga == 1)
    {
        if (num1.sign == -1) printf("-");
        for (i = num1.digit - 1;i > -1;i--)
        {
            printf("%d", num1.num[i]);
        }
    }
    if (flagb == 1)
    {
        if (flaga == 1)
        {
            if (num5.sign == 1) printf("+");
            else printf("-");
        }
        else
        {
            if (num5.sign == -1) printf("+");
        }
        for (i = num5.digit - 1;i > -1;i--)
        {
            printf("%d", num5.num[i]);
        }
        printf("i");
    }
    return 0;
}
