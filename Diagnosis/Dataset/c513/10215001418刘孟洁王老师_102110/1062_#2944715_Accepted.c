#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int n,i,l;
    long long int stair;
    long long int s[57];
    s[1] = 1;
    s[2] = 2;
    s[3] = 4;
    s[4] = 8;
    for(l = 5; l < 57; l++)s[l] = s[l-1]+s[l-2]+s[l-3]+s[l-4];
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
       scanf("%lld",&stair);
       printf("case #%d:\n",i);
       printf("%lld\n",s[stair]);
    }
    return 0;
}
