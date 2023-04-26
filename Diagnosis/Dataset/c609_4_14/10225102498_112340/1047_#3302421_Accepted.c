#include <stdio.h>
#include <stdlib.h>
#define N 1000

typedef struct{
    int cnt;
    int v[N];
}BIGINT;

BIGINT MUL(BIGINT R, int a)
{
    int carry = 0, j, t; //carry表示进位的整数
    for(j=0; j<R.cnt; j++) //cnt用于标记目前会到哪一位，减少循环次数
    {
        t = R.v[j]*a + carry; //t为j位上数字乘a后加上carry
        R.v[j] = t%10;
        carry = t/10;
    }
    while(carry > 0) //如果在cnt-1位还有需要进位的整数，说明下一次乘a时需要多带一位，故cnt++
    {
        R.v[R.cnt++] = carry%10;
        carry /= 10;
    }
    return R;
}
void printBIGINT(BIGINT R)
{
    int i;
    for(i=R.cnt-1; i>=0; i--)
        printf("%d", R.v[i]);
}

int main()
{
    int I, T;
    scanf("%d", &T);
    for(I=0; I<T; I++)
    {
        int a, n, i;
        BIGINT ans = {1,{1}};
        printf("case #%d:\n", I);
        scanf("%d%d", &a, &n);
        for(i=0; i<n; i++)
            ans = MUL(ans,a);
        printBIGINT(ans);
        printf("\n");
    }

    return 0;
}
