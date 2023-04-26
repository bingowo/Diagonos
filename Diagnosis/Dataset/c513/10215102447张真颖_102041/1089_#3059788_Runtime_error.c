#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int cnt;
    int v[200];
}BIGINT;

BIGINT mul(BIGINT x,BIGINT y)
{
    BIGINT re={1,{0}};
    re.cnt=x.cnt+y.cnt;
    for(int i=0;i<y.cnt;i++)
    {
        int carry=0,j;
        for(j=0;j<x.cnt;j++)
        {
            int t=x.v[j]*y.v[i]+carry+re.v[i+j];
            re.v[i+j]=t%10;
            carry=t/10;
        }
        int k=i+j;
        while(carry)
        {
            int t=re.v[k]+carry;
            re.v[k]=t%10;
            carry=t/10;
            k++;
        }
    }
    while(re.v[re.cnt-1]==0) re.cnt--;
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
        int i=0;
        for(;a>0;i++)
        {
            data.v[i]=a%10;
            re.v[i]=a%10;
            a/=10;
        }
        data.cnt=i,re.cnt=i;
        for(int i=1;i<b;i++)
        {
            re=mul(re,data);
        }
        printf("case #%d:\n",cas);
        for(int i=0;i<n-re.cnt;i++)
            printf("0");
        int k=re.cnt>n?n:re.cnt;
        for(int i=k-1;i>=0;i--)
            printf("%d",re.v[i]);
        printf("\n");
    }
    return 0;
}