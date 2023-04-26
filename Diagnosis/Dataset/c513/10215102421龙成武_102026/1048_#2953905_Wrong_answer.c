#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int getcoe(char* A, long long* a);
void multiply(long long* a, long long* b, long long* res, int numa, int numb);
int main()
{
    char A[101], B[101];
    long long a[51], b[51], res[51];
    int numa, numb, i, j;                               //记录系数的最高位数
    while (scanf("%s %s", A, B) == 2)                //scanf的返回值是成功赋值的个数
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(res, 0, sizeof(res));
        numa = getcoe(A, a);
        numb = getcoe(B, b);
        multiply(a, b, res, numa, numb);
        for (i = 50;i >= 0;i--)
            if (res[i] != 0)
                break;
        for (j = 0;j <= i;j++)
            if(res[j]!=0)
                printf("%lld ", res[j]);
        printf("\n");
    }
    return 0;
}
int getcoe(char* A, long long* a)
{
    int sign, power, maxpower;
    long long coe;
    maxpower = 0;
    while (*A)
    {
        coe = 0;sign = 1;power = 0;               //很精妙的一个点，默认正负号为正，因为正号也是会省略，和我们日常生活习惯一致
        if (*A == '-')
        {
            sign = -1;
            A++;                             //在while循环里多次++，这是我没想过的,但好用
        }
        else if (*A == '+')
        {
            A++;
        }
        while (isdigit(*A))             //处理可能存在的系数，鉴于系数存在和不存在是不一样的计算方法，省略掉的1比较特殊，所以1在后面重新判断
        {
            coe = coe * 10 + (*A - '0');
            A++;
        }
        if (*A == 0)
            //原本接下来可能是该去处理x，但是x也可能没有，也就是到了最后一项常数项（可能存在），如果存在常数项，那么到这儿就该返回了
        {
            a[0] = coe * sign;
            return maxpower;
        }
        if (!coe)
            coe = sign;               //经历了常数项的判断，*A这一项必为x
        A++;
        if (*A == '^')
        {
            A++;
            while (isdigit(*A))
            {
                power = power * 10 + (*A - '0');
                A++;
            }
        }
        else
            power = 1;
        a[power] = coe * sign;
        maxpower = maxpower < power ? power : maxpower;
    }
    return maxpower;
}
void multiply(long long* a, long long* b, long long* res, int numa, int numb)
{
    int i, j;
    for (i = 0;i < numa + 1;i++)
    {
        for (j = 0;j < numb + 1;j++)
        {
            res[i + j] += a[i] * b[j];
        }
    }
   /* i = 0;
    while (i <= numa + numb || abs(res[i]) >= 10)
    {
        res[i + 1] = res[i] / 10;
        res[i] %= 10;
        i++;
    }*/                     //不需要进位，进啥位啊，这又不是得出一个数值
}
