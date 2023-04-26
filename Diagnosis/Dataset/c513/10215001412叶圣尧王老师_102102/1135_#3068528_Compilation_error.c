#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct
{
    int cnt,v[200];
}BIGINT;

BIGINT int2BIG(int x)
{
    BIGINT R={0,{0}};
    do
    {
        R.v[cnt++]=x%10;
        x/=10;
    }while(x>0);
    return R;
}

BIGINT add(BIGINT S,BIGINT T)
{
    BIGINT R={0,{0}};int i,j,carry=0,t;
    for(i=0;i<S.cnt||i<T.cnt;i++)
    {
        t=S.v[i]+T.v[i]+carry;
        R.v[i]=t%10;
        carry=t/10;
    }
    if(carry>0)R.v[i++]=1;
    R.cnt=i;
    return R;
}

void output(BIGINT T)
{
    int i=199;
    while(T.v[i]==0)i--;
    for(;i>=0;i--)printf("%d",T.v[i]);
}

int main()
{
    BIGINT T[501];
    BIGINT int2BIG(int x);
    BIGINT add(BIGINT S,BIGINT T);
    T[1]=int2BIG(1);
    T[2]=int2BIG(2);
    T[3]=int2BIG(3);
    T[4]=int2BIG(6;)
    int n;scanf("%d",&n);
    for(int i=5;i<=n;i++)T[i]=add(add(T[i-1],T[i-2]),T[i-4]);
    output(T[n]);
}