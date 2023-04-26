#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 9001
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
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        char A[11];
        int B,N,j;
        scanf("%s %d %d",A,&B,&N);
        int len = strlen(A);
        BIGINT S,T = {1,{1}};
        S.cnt = len;
        for(j = 0;j < len;j++)
        {
            S.v[j] = A[len - j - 1] - '0';
        }
        for(j = 0;j < B;j++)
        {
            T = mul(S,T);
        }
        printf("case #%d:\n",i);
        for(j = 0;j < N;j++)
        {
            printf("%d",T.v[j]);
        }
        putchar('\n');
    }
    return 0;
}