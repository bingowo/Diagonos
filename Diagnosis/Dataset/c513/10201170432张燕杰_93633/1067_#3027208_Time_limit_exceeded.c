#include<stdio.h>

unsigned long long int tri(int n)
{
    unsigned long long int ans;
    if(n==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    else if(n==2)
    {
        return 1;
    }
    else
    {
        ans = tri(n-1)+tri(n-2)+tri(n-3);
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int n;
        scanf("%d",&n);
        unsigned long long int a0,a1,a2,ans;
        a0 = 0;a1 = 1;a2 = 1;
        ans = tri(n);
        printf("%llu\n",ans);
    }
    return 0;
}
