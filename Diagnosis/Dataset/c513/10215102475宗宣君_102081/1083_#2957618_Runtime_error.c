#include <stdio.h>
#include <stdlib.h>
typedef struct{
int cnt;
int v[1000];
}bigint;
bigint int2big(int x)
{
    bigint R = {0,{0}};
    do{
        R.v[R.cnt++] = x%10;
        x/=10;
    }while(x>0);
    return R;
}
bigint mul(bigint S, bigint T)     //两个大整数相乘
{
    int i;
    bigint R= {S.cnt+T.cnt,{0}};
    for (i=0; i<T.cnt; i++)
    {
         int t,k,j;
        int carry=0;
        for (j=0; j<S.cnt; j++)
        {
            t=S.v[j]*T.v[i]+carry+R.v[i+j];
            R.v[i+j]=t%10;
            carry=t/10;
        }
        k=i+j;
        while (carry>0)
        {
            t=carry+R.v[k];
            R.v[k]=t%10;
            carry=t/10;
            k++;
        }
    }
    if (R.v[S.cnt+T.cnt-1]==0) R.cnt--;
    return R;
}

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        int N,res=0,j;
        scanf("%d",&N);
        bigint A = int2big(N);
        for(j = N-1;j>0;j--)
        {
            A = mul(int2big(j),A);
        }
        for(j = 0;j<A.cnt;j++)
            {if(A.v[j]==0) res++;
            else break;}
        printf("case #%d:\n%d\n",i,res);
    }
    return 0;
}
