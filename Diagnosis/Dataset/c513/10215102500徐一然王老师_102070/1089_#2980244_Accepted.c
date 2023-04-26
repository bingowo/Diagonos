#include <stdio.h>
#define N 95
typedef struct { int cnt,v[N]; } BIGINT ;

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
    BIGINT R= {11,{0}};
    for (int i=0; i<10; i++)
    {
        int t,k,j;
        int carry=0;
        for (j=0; j<10; j++)
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

BIGINT pow1(BIGINT a, int n)  //计算a的n次方
{
    BIGINT r;
    if (n==0) return int2BIG(1);
    if (n==1) return a;
    r=pow1(a, n/2);
    r=mul(r,r);
    if (n%2) r=mul(r, a);
    return r;
}

int main()
{
    int count,count1;
    scanf("%d",&count);
    count1=count;
    int a,b,n;
    while(count--)
    {
        BIGINT R;
        scanf("%d %d %d",&a,&b,&n);
        R=int2BIG(a);
        R=pow1(R,b);
        printf("case #%d:\n",count1-count-1);
        for(int i=n-1;i>0;i--)
        {
            printf("%d",R.v[i]);
        }
        printf("%d\n",R.v[0]);

    }
}
