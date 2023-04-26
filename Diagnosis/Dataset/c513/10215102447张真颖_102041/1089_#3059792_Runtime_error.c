#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int cnt;
    int v[10];
}BIGINT;

BIGINT mul(BIGINT x,BIGINT y)
{
    BIGINT re={10,{0}};
    re.cnt=x.cnt;
    for(int i=0;i<y.cnt;i++)
    {
        int carry=0,j;
        for(j=0;j<x.cnt;j++)
        {
            int t=x.v[j]*y.v[i]+carry+re.v[i+j];
            re.v[i+j]=t%10;
            carry=t/10;
        }
    }
    return re;
}



int main()
{
    int T=0;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        long long a=0;
        int b=0,n=0;
        scanf("%lld%d%d",&a,&b,&n);

        BIGINT re={0,{0}},data={0,{0}};
        re.cnt=n,data.cnt=n;
        for(int i=0;i<n;i++)
        {
            data.v[i]=a%10;
            re.v[i]=a%10;
            a/=10;
        }
        for(int i=1;i<b;i++)
        {
            re=mul(re,data);
        }
        printf("case #%d:\n",cas);
        for(int i=n-1;i>=0;i--)
            printf("%d",re.v[i]);
        printf("\n");
    }
    return 0;
}