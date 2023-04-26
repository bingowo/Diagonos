#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    long long step[50] = {1, 2, 4, 8};
    for(int i = 4; i<50; i++)
        step[i] = step[i-1] + step[i-2] + step[i-3] + step[i-4];
    int T;
    scanf("%d",&T);
    for(int i ; i < T ; i++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n%lld\n",i,step[n]);
    }
    
}
