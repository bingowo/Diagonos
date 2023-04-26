#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        int n;
        scanf("%d",&n);
        long long stair[100]={0};
        stair[0]=0;stair[1]=1;stair[2]=1;
        for(int i=3;i<=n;i++) stair[i]=stair[i-1]+stair[i-2]+stair[i-3];
        printf("case #%d:\n%lld\n",t,stair[n]);
    }
}