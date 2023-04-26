#include <stdio.h>
#define N 1000
typedef struct
{
    int cnt, v[N];//cnt为长度，vn存放数字
} BigInt;

BigInt mul(BigInt S, BigInt T)     //两个大整数相乘
{
    BigInt R= {S.cnt+T.cnt,{0}};
    for (int i=0; i<T.cnt; i++)
    {
        int t,k,j;
        int carry=0;
        for (j=0; j<S.cnt; j++)
        {
            t=S.v[j]*T.v[i]+carry+R.v[i+j];
            R.v[i+j]=t%10;
            carry=t/10;
        }
        k=i+j;
        while (carry>0)
        {
            t=carry+R.v[k];
            R.v[k]=t%10;
            carry=t/10;
            k++;
        }
    }
    if (R.v[S.cnt+T.cnt-1]==0) R.cnt--; //最高位0不统计在一个大整数的位数中
    return R;
}


void printBigInt(BigInt R)
{
    for (int i = R.cnt-1; i >= 0; i--) printf("%d",R.v[i]);
}

BigInt int2Big(int x)
{
    BigInt R = {0,{0}};
    do
    {
        R.v[R.cnt++] = x%10;
        x /= 10;
    } while (x > 0);
    return R;
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int I = 0; I < T; I++)
    {
        BigInt T, ans = {1,{1}};
        int a,n;
        scanf("%d%d",&a,&n);
        T = int2Big(a);
        printf("case #%d:\n",I);
        for (int i = 0; i < n; i++)
        {
            ans = mul(T,ans);

        }
        printBigInt(ans);
        printf("\n");
    }
    return 0;
}