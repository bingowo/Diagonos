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
    int posa,posb,lena,lenb,i,lenfloat,N,x;
    char A[1500], B[1500],temp1[1000],temp2[1000];
    BIGINT num1, num2,num3;
    memset(&num1, 0, sizeof(BIGINT));memset(&num2, 0, sizeof(BIGINT));memset(&num3, 0, sizeof(BIGINT));
    scanf("%s %s %d", temp1, temp2, &N);
    lena = strlen(temp1);
    lenb = strlen(temp2);
    posa = strchr(temp1, '.') - temp1;
    posb = strchr(temp2, '.') - temp2;
    if ((lena - posa - 1) == (lenb - posb - 1))
        lenfloat = lena - posa - 1;                 //浮点数的长度
    else if ((lena - posa - 1) < (lenb - posb - 1))
    {
        lenfloat = lenb - posb - 1;
        x = (lenb - posb - 1) - (lena - posa - 1);
        //for (i = 0;i < (lenb - posb - 1) - (lena - posa - 1);i++) 这不行，lena在循环里变了
        for (i = 0;i < x;i++)
        {
            temp1[lena++] = '0';
        }
        temp1[lena] = 0;
    }
    else
    {
        lenfloat = lena - posa - 1;
        x = (lena - posa - 1) - (lenb - posb - 1);
        for (i = 0;i < x;i++)
        {
            temp2[lenb++] = '0';
        }
        temp2[lenb] = 0;
    }
    for (i = lena-1;i>-1;i--)
    {
        if (temp1[i] == '.');
        else
            num1.num[num1.digit++] = temp1[i] - '0';
    }
    for (i = lenb - 1;i > -1;i--)
    {
        if (temp2[i] == '.');
        else
            num2.num[num2.digit++] = temp2[i] - '0';
    }
    BigIntSub(&num1, &num2, &num3);
    if (lenfloat > N)  //lenfloat-1:小数点后第一位，lenfloat-N:小数点后第N位
    {
        if (num3.num[lenfloat-N-1] > 4)
        {
            num3.num[lenfloat-N-1] = 0;
            num3.num[lenfloat - N] += 1;
        }
        i = lenfloat - N;
        while (num3.num[i] >= 10)
        {
            num3.num[i] %= 10;
            num3.num[i + 1] += 1;
            i++;
        }
    }
    if (num3.sign == -1)
        printf("-");

    for (i = num3.digit - 1;i > lenfloat-N-1;i--)
    {
        if (i == lenfloat-1)
            printf(".");
        printf("%d", num3.num[i]);
    }
    return 0;
}
