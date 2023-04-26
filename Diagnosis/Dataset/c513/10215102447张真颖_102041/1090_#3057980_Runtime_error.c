#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int cnt;
    int v[50];
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
    if(re.v[re.cnt-1]==0) re.cnt--;
    return re;
}

int main()
{
    long int n=0;
    while(scanf("%ld",&n)!=EOF&&n)
    {
        BIGINT data={0,{0}},re={0,{0}};
        long int t=n;
        int i=0;
        for(i=0;t>0;i++)
        {
            data.v[i]=t%10;
            re.v[i]=t%10;
            t/=10;
        }
        data.cnt=i,re.cnt=i;
        for(long int i=1;i<n;i++)
        {
            re=mul(re,data);
        }
        printf("%d\n",re.v[re.cnt-1]);
    }
    return 0;
}