#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define N 95

typedef struct
{
    int cnt,v[N];//cnt位数v[N]大数据
}BIGINT;

BIGINT mul(BIGINT s,BIGINT t)
{
    BIGINT r={s.cnt+t.cnt,{0}};
    for(int i=0;i<t.cnt;i++)
    {
        int temp,k,j;
        int carry =0;
        for(j=0;j<s.cnt;j++)
        {
            temp=s.v[j]*t.v[i]+carry+r.v[i+j];
            r.v[i+j]=temp%10;
            carry=temp/10;
            k++;
        }
    }
    if(r.v[s.cnt+t.cnt-1]==0) r.cnt--;
    return r;
}

BIGINT transtoBIG(int x)//将小数据转为大数据
{
    BIGINT R={0,{0}};
    do
    {
        R.v[R.cnt++]=x%10;
        x/=10;
    }
    while(x>0);
    return R;
}

BIGINT powerside(BIGINT a,int n)
{
    BIGINT r;
    r=powerside(a,n/2);
    r=mul(r,r);
    if(n%2) r=mul(r,a);
    return r;
}

int main()
{
    int T,a,n;
    scanf("%d\n",&T);

    int i;
    for(i=0;i<T;i++)
    {
        scanf("%d %d",&a,&n);
        printf("case #%d:\n",i);
        if(n==0)
        {
            printf("1");
            continue;
        }
        if(n==1)
        {
            printf("%d",a);
            continue;
        }
        BIGINT r=transtoBIG(a);
        BIGINT keda=powerside(r,n);
        for(int k=keda.cnt;k>=0;k--)
            printf("%d",keda.v[k]);
    }
    return 0;
}
