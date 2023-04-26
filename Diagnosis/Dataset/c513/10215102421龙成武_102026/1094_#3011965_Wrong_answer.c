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
int bigintmax(pBIGINT a, pBIGINT b)  //得到绝对值的大小
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
int compar(const void* p1, const void* p2)
{
    int flag = 0;
    pBIGINT a, b;
    a = *(pBIGINT*)p1; b = *(pBIGINT*)p2;
    if (a->sign < b->sign)
        flag = -1;
    else if (a->sign > b->sign)
        flag = 1;
    else
    {
        if (a->sign > 0)
        {
            if (bigintmax(a, b) == 0) flag = -1;
            else flag = 1;
        }
        else
        {
            if (bigintmax(a, b) == 0) flag = 1;
            else flag = 0;
        }
    }
    return flag;
}
int main()
{
    BIGINT** love;
    BIGINT res;  memset(&res, 0, sizeof(BIGINT));
    char step[200];
    int n,i,j,len;
    scanf("%d", &n);
    love = (BIGINT**)malloc(n * sizeof(BIGINT*));
    for (i = 0;i < n;i++)
    {
        love[i] = (BIGINT*)malloc(sizeof(BIGINT));
        memset(love[i], 0, sizeof(BIGINT));
        scanf("%s", step);
        len = strlen(step);
        if (step[0] == '-')
        {
            love[i]->sign = -1;
            for (j = len - 1;j > 0;j--)
            {
                love[i]->num[love[i]->digit++] = step[j]-'0';
            }
        }
        else
        {
            love[i]->sign = 1;
            for (j = len - 1;j > -1;j--)
            {
                love[i]->num[love[i]->digit++] = step[j]-'0';
            }
        }
    }
    qsort(love, n, sizeof(BIGINT*), compar);
    for (i = love[n - 1]->digit - 1;i > -1;i--)
        printf("%d", love[n - 1]->num[i]);
    printf("\n");
    for (i = love[0]->digit - 1;i > -1;i--)
        printf("%d", love[0]->num[i]);
    printf("\n");

    love[0]->sign *= -1;
    BigIntAdd(love[n - 1], love[0], &res);
    if (res.sign == -1) printf("-");
    for (i = res.digit - 1;i > -1;i--)
        printf("%d",res.num[i]);
    for (i = 0;i < n;i++) free(love[i]); free(love);
    return 0;
}
