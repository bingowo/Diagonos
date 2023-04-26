#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int t,n,i;
    long long num;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        num=pow(2,n);
        printf("case #%d:\n",i);
        printf("%lld\n",num);
    }
    return 0;
}
