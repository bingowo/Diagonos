#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int cc(int n)
{
    if(n<3)
        return 0;
    else if(n==3)
        return 1;
    else
        return 2*cc(n-1)-cc(n-2)+cc(n-3)+pow(2,n-3);
}
int main()
{
    int n=1;
    while(1)
    {
        scanf("%d",&n);
        if(n==-1)
            break;
        long long int all;
        all=pow(2,n)-cc(n);
        printf("%lld\n",all);
    }
    return 0;
}
