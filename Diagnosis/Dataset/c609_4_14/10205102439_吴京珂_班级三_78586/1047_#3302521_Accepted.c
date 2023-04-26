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

BIGINT mul(BIGINT S, BIGINT T)//两个大整数相乘
{
    BIGINT R= {S.cnt+T.cnt,{0}};
    for (int i=0; i<T.cnt; i++)
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
    //最高位0不统计在一个大整数的位数中
    return R;
}

BIGINT pow(BIGINT a, int n)//计算a的n次方
{
    BIGINT r;
    if(n==0) return int2BIG(1);
    if(n==1) return a;
    r=pow(a, n/2);
    r=mul(r,r);
    if(n%2) r=mul(r,a);//n%2!=0
    return r;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        int a,n;
        scanf("%d %d",&a,&n);
        BIGINT m={0,{0}},ans={0,{0}};
        m=int2BIG(a);
        ans=pow(m,n);

        printf("case #%d:\n",i);
        for(int j=ans.cnt-1;j>=0;j--)
        {
            printf("%d",ans.v[j]);
        }
        printf("\n");
    }
    return 0;
}



