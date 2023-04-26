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
        printf("case #%d:\n",i);
        printf("%lld\n",1<<n);
    }
    return 0;
}