#include <stdio.h>
#define N 102
#define R -2

typedef struct
{
    int sign;
    int d[N];
    int i1,i2;//i1为最高位，i2为最低位
} T;

int isZero(T n) //判断是否已经除完
{
    return n.i1 == n.i2 && n.d[n.i1] == 0;
}

T Dec(T n, int b)
{
    if (b) //余数0时无需减一
    {
        if (!n.sign) n.d[n.i2]--; //n为正整数时个位数减一
    }
    else //n为负数时处理
    /*
    if (x < 0){ x -=R; N++;}
    */
    {
        int i;
        n.d[i=n.i2]++;//个位数加一
        while (n.d[i] > 9) //调整进位
        {
            n.d[i] = 0;
            n.d[--i]++;
        }
        if (i < n.i1) n.i1--; //若调整到最高位，i1向前一位
    }
    return n;
}

T DivR(T n)
{
    int i,t,carry = 0;
    n.sign = !n.sign; //符号正负切换
    for (i = n.i1; i <= n.i2; i++)
    {
        t = n.d[i]&1;
        n.d[i] = (carry*10+n.d[i])/-R;
        carry = t;
    }
    if (!isZero(n) && !n.d[n.i1]) n.i1++;
    return n;
}

void dec2R(T n)
{
    int b;
    if (!isZero(n))
    {
        dec2R(DivR(Dec(n,b = n.d[n.i2]&1)));
        printf("%1d",b);
    }
}

int main()
{
    T n = {0};
    char s[N+1];
    char *p = s;
    scanf("%s",s);
    if (*p == '+' || *p == '-')
    {
        if (*p == '-') n.sign = 1;
        p++;
    }
    n.i1 = n.i2 = 1;
    while (*p)
    {
        n.d[n.i2++] = *p++ - '0';
    }
    n.i2--;
    if (isZero(n)) printf("0");
    else dec2R(n);
    printf("\n");
    return 0;
}