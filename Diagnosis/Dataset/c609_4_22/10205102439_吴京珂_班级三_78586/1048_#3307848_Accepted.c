#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int cnt,v[100];
} BIGINT;

BIGINT int2BIG(int x)//int转BIGINT
{
    BIGINT r= {0,{0}};
    while(x>0)
    {
        r.v[r.cnt++]=x%10;
        x/=10;
    }
    return r;
}

BIGINT add(BIGINT S, BIGINT T)//大整数加法
{
    BIGINT R= {0};
    int i,carry=0;
    for(i=0; i<S.cnt && i<T.cnt; i++)
    {
        int temp=(S.v[i]+T.v[i]+carry);
        R.v[i]=temp%10;
        carry=temp/10;
    }
    while(i<S.cnt)
    {
        int temp=(S.v[i]+carry);
        R.v[i++]=temp%10;
        carry=temp/10;
    }
    while(i<T.cnt)
    {
        int temp=(T.v[i]+carry);
        R.v[i++]=temp%10;
        carry=temp/10;
    }
    if(carry)
    {
        R.v[i++]=carry%10;
    }
    R.cnt=i;
    return R;
}

BIGINT pow(int n)//循环求斐波那契数
{
    BIGINT R= {0},S,T;
    S=int2BIG(1);
    T=int2BIG(1);
    if(n==0) return int2BIG(0);
    if(n==1||n==2) return int2BIG(1);
    while(n>2)
    {
        R=add(S,T);
        S=T;
        T=R;
        n--;
    }
    return R;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        int n;
        scanf("%d",&n);
        BIGINT ans= {0,{0}};
        ans=pow(n);
        printf("case #%d:\n",i);
        if(n==0) printf("0");
        else
        {
            for(int j=ans.cnt-1; j>=0; j--)
            {
                printf("%d",ans.v[j]);
            }
        }
        printf("\n");
    }
    return 0;
}



