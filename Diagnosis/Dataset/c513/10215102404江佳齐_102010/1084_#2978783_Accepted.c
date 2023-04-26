#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        int n;
        scanf("%d",&n);
        printf("%lld\n",(long long int)pow(2,n));
    }
    return 0;
}
