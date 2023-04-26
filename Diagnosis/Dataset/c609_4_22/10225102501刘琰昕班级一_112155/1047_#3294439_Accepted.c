#include <stdio.h>
#include <stdlib.h>
typedef struct{int cnt,v[101];}BIGINT;

BIGINT int2BIG(int x)//int 转换成BIGINT
{
    BIGINT R= {0,{0}};
    do
    {
        R.v[R.cnt++]=x%10;
        x/=10;
    } while (x>0);
    return R;
}

BIGINT mul(BIGINT S, BIGINT T)     //两个大整数相乘
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
    if (R.v[S.cnt+T.cnt-1]==0) R.cnt--; //最高位0不统计在一个大整数的位数中
    return R;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int Case=0;Case<T;Case++)
    {
        int a,n;
        scanf("%d%d",&a,&n);
        BIGINT biga=int2BIG(a);
        BIGINT bigans=int2BIG(1);
        for(int i=0;i<n;i++)
            bigans=mul(bigans, biga);
        printf("case #%d:\n",Case);
        for(int i=bigans.cnt-1;i>=0;i--)
            printf("%d",bigans.v[i]);
        printf("\n");
    }
    return 0;
}
