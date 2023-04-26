#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
    return (*(long long*)a>*(long long*)b)?1:-1;
}

main()
{
    int T; scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        int n,m; scanf("%d %d",&n,&m);
        int num[1001] = {};
        long long comb[500501] = {}; int index = 0;
        for (int j=1;j<=n;j++) {scanf("%d",&num[j]); num[j] += num[j-1];}
        for (int j=1;j<=n;j++)
            for (int k=1;k<=n-j+1;k++) comb[++index] = num[k+j-1]-num[k-1];
        qsort(comb,index,sizeof(comb[0]),cmp);
        for (int j=1;j<=index;j++) {comb[j] += comb[j-1];}
        printf("case #%d:\n",i);
        for (int j=0;j<m;j++)
        {
            int l,r; scanf("%d %d",&l,&r);
            printf("%lld\n",comb[r]-comb[l-1]);
        }
    }
    return 0;
}