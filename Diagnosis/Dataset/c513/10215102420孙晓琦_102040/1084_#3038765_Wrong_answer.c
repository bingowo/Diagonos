#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        long long int ans=1;
        for(int j=0;j<n;j++)
        {
            ans=ans<<1;
        }
        printf("case #%d:\n%lld",i,ans);
    }
    return 0;
}
