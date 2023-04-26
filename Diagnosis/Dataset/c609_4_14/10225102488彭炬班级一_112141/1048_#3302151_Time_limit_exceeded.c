#include <stdio.h>

typedef struct
{
    int n[100];
    int len;
}BigInt;

BigInt transInt(int N)
{
    BigInt s = {{0}, 0};
    do{
        s.n[s.len++] = N % 10;
        N /= 10;
    }while(N > 0);
    return s;
}

BigInt plus(BigInt a, BigInt b)
{
    BigInt d;
    if(a.len < b.len)
    {
        d = a;
        a = b;
        b = d;
    }
    BigInt c = {{0}, a.len};
    int i = 0, rest = 0;
    for(; i < a.len; i++)
    {
        int sum = (i < b.len) ? (a.n[i] + b.n[i] + rest) : (a.n[i] + rest);
        c.n[i] = sum % 10;
        rest = sum / 10;
    }
    if(rest)
        c.n[++c.len] = rest;
    return c;
}

BigInt list(int n)
{
    if(n == 1 || n == 2)
        return transInt(1);
    else if(n == 0)
        return transInt(0);
    else
        return plus(list(n - 1), list(n - 2));
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0; i < T; i++)
    {
        int n;
        scanf("%d",&n);
        BigInt number = list(n);
        printf("case #%d:\n",i);
        for(int j = number.len - 1;j >= 0;j--)
            printf("%d",number.n[j]);
        printf("\n");
    }
}
