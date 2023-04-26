#include<stdio.h>
int main()
{
    long long ans[50];
    int T,n,i;
    ans[0]=1;
    ans[1]=2;
    ans[2]=4;
    ans[3]=8;
    for(i=4;i<50;i++)
    {
        ans[i]=ans[i-1]+ans[i-2]+ans[i-3]+ans[i-4];
    }
    scanf("%d",&T);
    for(n=0;n<T;n++)
    {
        scanf("%d",&i);
        printf("case #%d:\n%lld\n",n,ans[i-1]);
    }
    return 0;
}