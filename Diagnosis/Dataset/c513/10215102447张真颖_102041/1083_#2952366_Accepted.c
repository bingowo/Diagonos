#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int cnt;
    int v[10000];
}BIGINT;

BIGINT mul(BIGINT x,int b)
{
    BIGINT r;
    r.cnt=0;
    int carry=0;
    for(;r.cnt<x.cnt;r.cnt++)
    {
        int tmp=x.v[r.cnt]*b+carry;
        r.v[r.cnt]=tmp%10;
        carry=tmp/10;
    }
    if(carry) r.v[r.cnt]=carry,r.cnt++;
    return r;
}



int main()
{
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N=0;
        scanf("%d",&N);
        BIGINT bign;
        bign.cnt=1,bign.v[0]=1;
        for(int i=N;i>=1;i--)
            bign=mul(bign,i);
        int cnt0=0;
        for(;bign.v[cnt0]==0;cnt0++);
        printf("case #%d:\n%d\n",i,cnt0);
    }
    return 0;
}