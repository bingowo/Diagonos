#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        int n;
        scanf("%d",&n);
        long long stair[55]={0};
        stair[1]=1;stair[2]=2;stair[3]=4;stair[4]=8;
        for(int i=5;i<=n;i++) stair[i]=stair[i-1]+stair[i-2]+stair[i-3]+stair[i-4];
        printf("case #%d:\n%d\n",t,stair[n]);
    }
}