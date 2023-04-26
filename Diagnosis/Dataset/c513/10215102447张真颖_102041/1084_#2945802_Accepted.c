#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t=0;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n=0;
        scanf("%d",&n);
        long long r=1;
        for(int i=0;i<n;i++)
            r=r*2;
        printf("case #%d:\n%lld\n",i,r);
    }
    return 0;
}