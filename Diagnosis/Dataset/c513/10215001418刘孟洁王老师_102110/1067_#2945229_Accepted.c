#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main()
{
    int n,i,l;
    long long int k;
    long long int T[77];
    T[0] = 0;
    T[1] = 1;
    T[2] = 1;
    for(l = 3; l < 77; l++)T[l] = T[l-1]+T[l-2]+T[l-3];
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
       scanf("%lld",&k);
       printf("case #%d:\n",i);
       printf("%lld\n",T[k]);
    }
    return 0;
}
