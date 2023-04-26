#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
    return *(int*)a-*(int*)b;
}

main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        int a[2001] = {};
        for (int j=0;j<2*n;j++) scanf("%d",&a[j]);
        qsort(a,n*2,sizeof(a[0]),cmp);
        int pro =0;
        for (int j=0,k=2*n-1;j<k;j++,k--)
        {
            pro += a[j]*a[k];
        }
        printf("case #%d:\n%d\n",i,pro);
    }
    return 0;
}