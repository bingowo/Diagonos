#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 95

typedef struct
{
    int cnt,v[N];
}BIGINT;

BIGINT mul(BIGINT S,BIGINT T)
{
    BIGINT R={S.cnt+T.cnt,{0}};
    for(int i=0;i<T.cnt;i++)
    {
        int t,k,j;int carry=0;
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
    if(R.v[S.cnt+T.cnt-1]==0)R.cnt--;
    return R;
}

BIGINT int2BIG(int x)
{
    BIGINT R={0,{0}};
    do{
        R.v[R.cnt++]=x%10;
        x/=10;
    }while(x>0);
    return R;
}

BIGINT po(BIGINT a,int n)
{
    BIGINT r;
    if(n==0)return int2BIG(1);
    if(n==1)return a;
       r=po(a,n/2);
        r=mul(r,r);
        if(n%2)r=mul(r,a);
        return r;
}

int main()
{
    int T,a,n;scanf("%d",&T);int *result;
    for(int t=0;t<T;t++)
    {
        scanf("%d %d",&a,&n);
        BIGINT d=int2BIG(a);
        BIGINT X=po(d,n);
        printf("case #%d:\n",t);
        for(int i=X.cnt-1;i>=0;i--)printf("%d",X.v[i]);
        printf("\n");
    }
}