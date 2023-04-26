#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    int n,r;
    for(int i=0;i<T;i++)
    {
        scanf("%d%d",&n,&r);
        int ans=0;
        while(n)
        {
            ans+=n%r;
            n/=r;
        }
        printf("case #%d:\n%d\n",i,ans);
    }
    return 0;
}