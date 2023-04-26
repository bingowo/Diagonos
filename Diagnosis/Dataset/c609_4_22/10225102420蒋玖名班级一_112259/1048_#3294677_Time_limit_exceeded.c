#include <stdio.h>
#include <stdlib.h>
#define N 50
typedef struct { int cnt,v[N];} BIGINT;
BIGINT addd(BIGINT S,BIGINT T)
{
    BIGINT R={S.cnt+1,{0}};
    int carry=0;
    for(int i=0;i<S.cnt;i++)
    {
        int t=S.v[i]+T.v[i]+carry;
        R.v[i]=t%10;
        carry=t/10;
    }
    if(carry>0) R.v[R.cnt-1]=1;
    else R.cnt--;
    return R;
}
BIGINT fib(int n)
{
    BIGINT x={1,{0}};
    BIGINT y={1,{1}};
    if(n==0) return x;
    if(n==1) return y;
    if(n>1) return addd(fib(n-1),fib(n-2));
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",i);
        BIGINT ANS;
        ANS=fib(n);
        for(int j=ANS.cnt-1;j>=0;j--)
            printf("%d",ANS.v[j]);
        printf("\n");
    }
    return 0;
}
