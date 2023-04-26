#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
#define N 100
typedef struct { int cnt,v[N]; } BIGINT;
BIGINT int2BIG(int x)  //int 转换成BIGINT
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
BIGINT bigpow(BIGINT a,int n)  //计算 a的n次方
{
    BIGINT r;
    if (n==0) return int2BIG(1);
    if (n==1) return a;
    r=bigpow(a, n/2);
    r=mul(r,r);
    if (n%2) r=mul(r, a);
    return r;
}

int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int a,b,j;
        scanf("%d%d",&a,&b);
        BIGINT ans=bigpow(int2BIG(a),b);
        printf("case #%d:\n",i);
        for(j=ans.cnt-1;j>=0;j--)printf("%d",ans.v[j]);
        printf("\n");
    }
}

