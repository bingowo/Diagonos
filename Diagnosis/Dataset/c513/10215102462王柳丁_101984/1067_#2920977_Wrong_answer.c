#include <stdio.h>
#include <stdlib.h>
long long int NUMS[75];
long long int count(long long int a)
{
    if(NUMS[a]==-1)
    {
        NUMS[a]=count(a-1)+count(a-2)+count(a-3);
        return NUMS[a];
    }
    else if(NUMS[a]!=-1)return NUMS[a];
}
int main()
{
    int T,i;
    for(i=0;i<75;i++)
    {
        NUMS[i]=-1;
    }
    NUMS[0]=0;NUMS[1]=1;NUMS[2]=1;

    long long int res=0;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        long long int n;
        scanf("%lld",&n);
        res=count(n);
        printf("case #%d:\n",i);
        printf("%lld",res);
    }
    return 0;
}
