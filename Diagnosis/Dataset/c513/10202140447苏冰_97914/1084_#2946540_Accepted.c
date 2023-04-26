#include <stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        int n;
        scanf("%d",&n);
        long long ans=1;
        for(int i=0;i<n;i++)
        {
            ans=ans*2;
        }
        printf("case #%d:\n",cas);
        printf("%lld\n",ans);
    }
}