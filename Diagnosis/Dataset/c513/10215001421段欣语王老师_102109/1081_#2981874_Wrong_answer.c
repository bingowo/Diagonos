#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 95

typedef struct { int cnt,v[N] } BIGINT;

BIGINT int2BIG(int x)
{
    BIGINT R={0,{0}};
    do
    {
        R.v[R.cnt++]=x%10;
        x/=10;
    }while (x>0);
    return R;
}

BIGINT mul(BIGINT S,BIGINT T)
{
    BIGINT R={S.cnt+T.cnt,{0}};
    for(int i=0;i<T.cnt;i++)
    {
        int t,k,j;
        int carry=0;
        for(j=0;j<S.cnt;j++)
        {
            t=S.v[j]*T.v[i]+carry+R.v[i+j];
            R.v[i+j]=t%10;
            carry=t/10;
        }
        k=i+j;
        while(carry>0)
        {
            t=carry+R.v[k];
            R.v[k]=t%10;
            carry=t/10;
            k++; 
        }
    }
}

BIGINT pow(BIGINT a,int n)
{
    BIGINT r;
    if(n==0)return int2BIG(1);
    if(n==1)return a;
    r=pow(a,n/2);
    r=mul(r,r);
    if(n%2)r=mul(r,a);
    return r;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int a,n;
        scanf("%d %d",&a,&n);
        BIGINT r1;
        r1=pow(int2BIG(a),n);
        for(int j=94;j>=0;j--)
        {
            if(r1.v[i]!=0)printf("%d",r1.v[i]);
        }
        printf("\n");
    }
    return 0;
}