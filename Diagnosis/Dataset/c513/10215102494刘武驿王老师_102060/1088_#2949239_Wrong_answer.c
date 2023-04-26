#include<stdio.h>
int main()
{
    int pros;
    scanf("%d",&pros);
    for(int i=0;i<pros;i++)
    {
        long long m,n;
        scanf("%lld %lld",&m,&n);
        long long zi=1,mu=1;
        if(n==0)
        {
            printf("case #%d:\n1\n",i);
            continue;
        }
        for(int j=0;j<n;j++) zi*=(m-j);
        for(int j=1;j<=n;j++) mu*=j;
        unsigned long long int res=zi/mu;
        printf("case #%d:\n%llu\n",i,res);
    }
}