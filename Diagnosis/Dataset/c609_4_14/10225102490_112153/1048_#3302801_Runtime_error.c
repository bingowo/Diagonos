#include <stdio.h>
#include <stdlib.h>
#define N 1000
typedef struct
{
    int cnt, v[N];
} BigInt;

void printBigInt(BigInt R)
{
    for (int i = R.cnt-1; i >= 0; i--) printf("%d",R.v[i]);
}

BigInt Add(BigInt a, BigInt b)
{
    BigInt R = {a.cnt+2,{0}};
    //printf("cnt_start = %d\n",R.cnt);
    int i,t,carry = 0;
    for (i = 0; i < a.cnt; i++) //a为较大的数
    {
        t = a.v[i] + b.v[i] + carry;
        R.v[i] = t%10;
        carry = t/10;
    }
    while (carry > 0)
    {
        t = carry + R.v[i];
        R.v[i] = t%10;
        carry = t/10;
        i++;
    }
    while (R.v[R.cnt] == 0) R.cnt--;
    //printf("cnt = %d\n",R.cnt);
    return R;
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int I = 0; I < T; I++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",I);
        BigInt *ans = (BigInt*)malloc(sizeof(BigInt) * 121);
        ans[0].cnt = 1; ans[0].v[0] = 0;
        ans[1].cnt = 1; ans[1].v[0] = 1;
        ans[2].cnt = 1; ans[2].v[0] = 1;
        for (int i = 3; i <= n; i++)
        {
            ans[i] = Add(ans[i-1],ans[i-2]);
        }
        printBigInt(ans[n]);
        printf("\n");
    }
}
