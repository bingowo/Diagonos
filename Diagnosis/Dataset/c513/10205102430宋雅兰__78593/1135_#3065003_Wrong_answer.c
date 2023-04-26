#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    long long ans[30];
    ans[1]=1;
    ans[2]=2;
    ans[3]=3;
    ans[4]=6;
    for(int i=5;i<=n;i++)
    {
        ans[i]+=ans[i-1]+ans[i-2]*3+ans[i-4];
    }
    printf("%lld",ans[n]);
    return 0;
}