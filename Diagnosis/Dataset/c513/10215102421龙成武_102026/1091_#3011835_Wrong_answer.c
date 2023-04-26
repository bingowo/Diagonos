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
typedef struct
{
    BIGINT a;
    BIGINT b;  //虚部
}COMPLEX, * pCOMPLEX;
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
void BigComMul(pCOMPLEX cnum1, pCOMPLEX cnum2, pCOMPLEX res)
{
    COMPLEX temp1, temp2;
    memset(&temp1, 0, sizeof(COMPLEX));memset(&temp2, 0, sizeof(COMPLEX));
    BigIntMul(&cnum1->a, &cnum2->a, &temp1.a);
    BigIntMul(&cnum1->b, &cnum2->b, &temp2.a);
    temp2.a.sign *= -1;
    BigIntAdd(&temp1.a, &temp2.a, &res->a);
    BigIntMul(&cnum1->a, &cnum2->b, &temp1.b);
    BigIntMul(&cnum1->b, &cnum2->a, &temp2.b);
    BigIntAdd(&temp1.b, &temp2.b, &res->b);
}
int main()
{
    char c[100];
    int n, a, b, i,flaga=0,flagb=0;
    COMPLEX cnum1, cnum2, cnum3;
    scanf("%s %d", c, &n);
    memset(&cnum1, 0, sizeof(COMPLEX));memset(&cnum2, 0, sizeof(COMPLEX));memset(&cnum3, 0, sizeof(COMPLEX));
    cnum1.a.digit = 10;
    cnum2.b.digit = 10;
    if (sscanf(c, "%d %d %c", &a, &b, &i) == 3);
    else if (sscanf(c, "%d %d %c", &a, &b, &i) == 1)
    {
        if (strchr(c, 'i') != NULL)   //找到i了
        {
            char* p = strchr(c, 'i');
            if (*(p - 1) == '-')
            {
                b = -1;
                sscanf(c, "%d", &a);
            }
            else if (*(p - 1) == '+')
            {
                b = 1;
                sscanf(c, "%d", &a);
            }
            else
            {
                a = 0;
                sscanf(c, "%d %c", &b, &i);
            }
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
    cnum1.a.num[0] = a > 0 ? a : -a;
    cnum1.b.num[0] = b > 0 ? b : -b;
    BigIntTrim(&cnum1.a);
    BigIntTrim(&cnum1.b);
    cnum1.a.sign = a > 0 ? 1 : -1;
    cnum1.b.sign = b > 0 ? 1 : -1;
    cnum2 = cnum1;
    n--;
    while (n--)
    {
        BigComMul(&cnum1, &cnum2, &cnum3);
        cnum1 = cnum3;
        memset(&cnum3, 0, sizeof(COMPLEX));
    }
    if (cnum1.a.digit == 1 && cnum1.a.num[0] == 0)
        flaga = 1;
    else
    {
        for (int j = cnum1.a.digit-1;j>-1;j--)
        {
            printf("%d", cnum1.a.num[j]);
        }
    }
    //flag==0:输出a了，==1：没输出a 
    if (cnum1.b.digit == 1 && cnum1.b.num[0] == 0)
        flagb = 1;
    else
    {
        if (cnum1.b.sign == -1)
            printf("-");
        else if (flaga == 0)
            printf("+");
        if (cnum1.b.digit == 1 && cnum1.b.num[0] == 1);
        else
            for (int j = cnum1.b.digit-1;j > -1;j--)
            {
                printf("%d", cnum1.b.num[j]);
            }
        printf("i");
    }
    if (flaga && flagb)
        printf("0");
    return 0;
}

