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
int lenfloat;
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
    BigIntTrim(res);
    //整数部分的前导零要清除，小数部分就不用了
    //而且只有在整数部分全为0的时候，才会清理到小数部分的前导零,也就是说，在trim后，res->digit小于等于浮点数长度
    if (res->digit <= lenfloat)
    {
        res->digit = lenfloat + 1;      
        //之所以要加一，是因为进入这个if说明整数部分全是0，但是输出的时候需要输出一个整数0
    }
}
int main()
{
    int posa,posb,lena,lenb,i,N,x;
    int flag = 0;
    char A[1500]={'0'}, B[1500]={'0'}, temp1[1000], temp2[1000];
    BIGINT num1, num2,num3;
    memset(&num1, 0, sizeof(BIGINT));memset(&num2, 0, sizeof(BIGINT));memset(&num3, 0, sizeof(BIGINT));
    scanf("%s %s %d", temp1, temp2, &N);
    if (temp1[0] == '.')
    {
        strcpy(A + 1, temp1);
        strcpy(temp1, A);
    }
    if (temp2[0] == '.')
    {
        strcpy(B + 1, temp2);
        strcpy(temp2, B);
    }
    lena = strlen(temp1);
    lenb = strlen(temp2);
    if (strchr(temp1, '.') == NULL)     //浮点计算输入整数的话，需要手动添加小数点
    {
        temp1[lena++] = '.';
        temp1[lena] = 0;
    }
    if (strchr(temp2, '.') == NULL)
    {
        temp2[lenb++] = '.';
        temp2[lenb] = 0;
    }
    posa = strchr(temp1, '.') - temp1;  //小数点的下标
    posb = strchr(temp2, '.') - temp2;
    //小数的位数为 lena-posa-1==lena-(posa+1)
    if ((lena - posa - 1) == (lenb - posb - 1))
        lenfloat = lena - posa - 1;                 //小数的长度
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

    //这是在四舍五入
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
        if (i < 0)
            printf("0");
        else
            printf("%d", num3.num[i]);
    }
    return 0;
}
