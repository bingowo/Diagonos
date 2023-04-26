#include<stdio.h>
#include<math.h>

long long go(long long n)
{
    long long ans[51]={0};
    ans[0]=1;
    ans[1]=1;
    ans[2]=2;
    ans[3]=4;
    for(int i=4;i<51;i++)
    {
        ans[i]=ans[i-1]+ans[i-2]+ans[i-3]+ans[i-4];
    }
    return ans[n];
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        long long ans;
        scanf("%lld",&ans);
        ans=go(ans);
        printf("case #%d:\n",i);
        printf("%lld\n",ans);
    }
}
