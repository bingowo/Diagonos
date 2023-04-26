#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    long long ans[31];
    ans[0]=1;
    for(int i=1;i<31;i++)
    ans[i]=ans[i-1]*2;
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n%lld\n",i,ans[n]);
    }
    return 0;
}