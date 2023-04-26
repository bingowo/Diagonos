#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int cnt;//位数
    int v[1000];
} BIGINT ;

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

BIGINT mul(BIGINT S, BIGINT T)//大整数乘法
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
    if (R.v[S.cnt+T.cnt-1]==0)
        R.cnt--; //最高位0不统计在一个大整数的位数中
    return R;
}

BIGINT pow(BIGINT a, int n)//计算 a的n次方
{
    BIGINT r;
    if (n==0)
        return int2BIG(1);
    if (n==1)
        return a;
    r=pow(a, n/2);
    r=mul(r,r);
    if (n%2)
        r=mul(r, a);
    return r;
}
int main()
{
    int t,a,n;
    scanf("%d",&t);
    for(int z=0;z<t;z++)
    {
        scanf("%d %d",&a,&n);
        printf("case #%d:\n",z);
        BIGINT end;
        end=pow(int2BIG(a),n);
        for(int i=end.cnt-1;i>=0;i--)
            printf("%d",end.v[i]);
        printf("\n");
    }
    return 0;
}
