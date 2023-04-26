#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    long long ans[30];
    ans[0]=1;
    for(int i=0;i<30;i++)
    ans[i]=ans[i-1]*2;
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n%lld\n",i,ans[n-1]);
    }
    return 0;
}