#include <stdio.h>
#include <stdlib.h>
#define L 8000000001

typedef struct{
    int cnt,v[L];
}BIGINT;

BIGINT mul(BIGINT S,BIGINT T)
{
    BIGINT R = {S.cnt + T.cnt,{0}};
    for(int i = 0;i < T.cnt;i++)
    {
        int t,k,j;
        int carry = 0;
        for(j = 0;j < S.cnt;j++)
        {
            t = S.v[j] * T.v[i] + carry + R.v[i + j];
            R.v[i + j] = t % 10;
            carry = t / 10;
        }
        k = i + j;
        while(carry > 0)
        {
            t = carry + R.v[k];
            R.v[k] = t % 10;
            carry = t / 10;
            k++;
        }
    }
    if(R.v[S.cnt + T.cnt - 1] == 0)
        R.cnt--;
    //最高位0不统计在一个大整数的位数中
    return R;
}

int main()
{
    char N[10];
    while(scanf("%s",N))
    {
        int n = atoi(N);
        if(n == 0)
            break;
        BIGINT S,T = {0,{0}};
        int len = strlen(N);
        S.cnt = len;
        for(int i = 0;i < len;i++)
        {
            S.v[i] = N[len - i -1] - '0';
        }
        for(int i = 0;i < atoi(N);i++)
        {
            T = mul(S,T);
        }
        printf("%d\n",T.v[0]);
    }
    return 0;
}