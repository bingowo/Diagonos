#include <stdio.h>

unsigned long long layer[51];

main()
{
    layer[1] = 1; layer[2] = 2; layer[3] = 4; layer[4] = 8;
    for (int i=5;i<=50;i++) layer[i] = layer[i-4]+layer[i-3]+layer[i-2]+layer[i-1];
    int T; scanf("%d",&T);
    for (int i=0;i<T;i++) 
    {
        int n; scanf("%d",&n);
        printf("case #%d:\n%llu\n",i,layer[n]);
    }
    return 0;
}