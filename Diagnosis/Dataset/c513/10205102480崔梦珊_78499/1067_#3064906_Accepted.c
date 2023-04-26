#include<stdio.h>
#include<stdlib.h>
typedef unsigned long long ll;

ll f(int n)
{
    ll ans[74];
    ans[0]=0;
    ans[1]=1;
    ans[2]=1;
    for(int i=3;i<74;i++)
    {
        ans[i]=ans[i-1]+ans[i-2]+ans[i-3];
    }
    return ans[n];
}


int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",i);
        printf("%llu\n",f(n));
    }
}
