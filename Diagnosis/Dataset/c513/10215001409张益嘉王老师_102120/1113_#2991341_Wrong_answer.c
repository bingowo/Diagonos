#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k,n,i,j;
    unsigned long long shu[110],sum;
    shu[0]=0;
    shu[1]=1;
    scanf("%d%d",&k,&n);
    for(i=2;i<n;i++)
    {
        sum=0;
        for(j=0;j<k;j++)
        {
            if(i-1-j>=0) sum+=shu[i-1-j];
        }
        shu[i]=sum;
    }
    printf("%llu",shu[n-1]);
    return 0;
}
