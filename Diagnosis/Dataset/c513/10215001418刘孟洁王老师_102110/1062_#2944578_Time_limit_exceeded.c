#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long ways(long long n)
{
    if(n == 1)return 1;
    else if(n == 2)return 2;
    else if(n == 3)return 4;
    else if(n == 4)return 15;
    else return ways(n-1) + ways(n-2) + ways(n-3) + ways(n-4);
}

int main()
{
    int n,i;
    long long stair;
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
       scanf("%lld",&stair);
       printf("case #%d:\n",i);
       printf("%lld\n",ways(stair));
    }
    return 0;
}
