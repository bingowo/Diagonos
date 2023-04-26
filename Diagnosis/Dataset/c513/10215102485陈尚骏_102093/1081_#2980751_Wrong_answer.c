#include <stdio.h>
#include <stdlib.h>
#define N 95

typedef struct{
    int cnt;
    int V[N];
}BIGINT;

BIGINT INT2BIG(int x)
{
    BIGINT R={0,{0}};
    do
    {
        R.V[R.cnt++]=x%10;
        x/=10;
    }while(x>0);
    return R;
}


BIGINT mul(BIGINT S,BIGINT T)
{
    BIGINT R={S.cnt+T.cnt,{0}};
    for(int i=0;i<T.cnt;i++)
    {
        int k,j,t;
        int cry=0;
        for(j=0;j<S.cnt;j++)
        {
            t=S.V[j]*T.V[i]+R.V[i+j]+cry;
            R.V[i+j]=t%10;
            cry=t/10;
        }
        k=i+j;
        while(cry>0)
        {
            t=cry+R.V[k];
            R.V[k]=t%10;
            cry=t/10;
            k++;
        }
    }
    if(R.V[S.cnt+T.cnt-1]==0) R.cnt--;
    return R;
}

BIGINT POW(BIGINT a,int n)
{
    BIGINT R;
    if(n==0) return INT2BIG(1);
    if(n==1) return a;
    R=POW(a,n/2);
    R=mul(R,R);
    if(n%2) R=mul(R,a);
    return R;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        BIGINT R;
        int a,n;
        scanf("%d %d",&a,&n);
        R=INT2BIG(a);
        BIGINT S=POW(R,n);
        printf("case #%d:\n",i);
        for(int j=0;j<S.cnt;j++)
            printf("%d",S.V[j]);
        printf("\n");
    }
    return 0;
}
