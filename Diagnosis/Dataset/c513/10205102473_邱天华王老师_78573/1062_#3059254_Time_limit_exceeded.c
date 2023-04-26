#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count(int n)
{
    if(n<=0) return 0;
    if(n==1) return 1;
    if(n==2) return 2;
    if(n==3) return 4;
    if(n==4) return 8;
    return (count(n-1)+count(n-2)+count(n-3)+count(n-4));
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        long long cnt;
        scanf("%d",&n);
        cnt=count(n);
        printf("case #%d: \n",i);
        printf("%lld\n",cnt);
    }
    return 0;
}