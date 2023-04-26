#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int tt=0;tt<t;tt++)
    {
        int a,b,k,n,m;
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        long long unsigned sum=1,sum1=1,sum2=1,sum3=1;int temp=2;
        for(int i=n+1;i<=k;i++)
        {
            sum1*=i;
            if(temp<=k-n&&sum1%temp==0) sum1=sum1/temp,temp++;
            if(sum1/10007>1000) sum=sum*(sum1%10007),sum1=1;
            if(sum/10007>1000) sum=sum%10007;
        }
        sum1=(sum*(sum1%10007))%10007;
        for(int i=0;i<n;i++)
        {
            sum2=sum2*a;
            if(sum2/10007>10000) sum1=sum1*(sum2%10007),sum2=1;
        }
        for(int i=0;i<m;i++)
        {
            sum3=sum3*b;
            if(sum3/10007>100000) sum2=sum2*(sum3%10007),sum3=1;
        }
        printf("case #%d:\n",tt);
        printf("%llu\n",((sum1%10007)*(sum2%10007)*(sum3%10007))%10007);
    }
    return 0;
}
