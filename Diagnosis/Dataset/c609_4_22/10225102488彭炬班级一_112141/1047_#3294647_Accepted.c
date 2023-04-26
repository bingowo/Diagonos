#include <stdio.h>
#include <string.h>

typedef struct
{
    int len;
    int n[100];
}BigInt;

BigInt transint(int N)
{
    BigInt s = {0,{0}};
    do{
        s.n[s.len++] = N % 10;
        N /= 10;
    }while(N > 0);
    return s;
}

BigInt mul(BigInt a,BigInt b)
{
    BigInt c = {a.len + b.len,{0}};
    for(int i = 0;i < a.len;i++)
    {
        int t,j,plus = 0;
        for(j = 0;j < b.len;j++)
        {
            t = a.n[i] * b.n[j] + plus + c.n[i + j];
            c.n[i + j] = t % 10;
            plus = t / 10;
        }
        int k = i + j;
        while(plus > 0)
        {
            t = c.n[k] + plus;
            c.n[k++] = t % 10;
            plus = t / 10;
        }
    }
    if(c.n[a.len + b.len - 1] == 0)
        c.len--;
    return c;
}

BigInt pow(BigInt s,int n)
{
    BigInt r;
    if(n == 0) return transint(1);
    if(n == 1) return s;
    r = pow(s , n/2);
    r = mul(r,r);
    if(n % 2)
        r = mul(r,s);
    return r;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0;i < T;i++)
    {
        int a,n;
        scanf("%d %d",&a,&n);
        printf("case #%d:\n",i);
        BigInt s = pow(transint(a),n);
        for(int j = s.len - 1;j >= 0;j--)
            printf("%d",s.n[j]);
        printf("\n");
    }
    return 0;
}
