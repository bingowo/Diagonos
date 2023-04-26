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
        int a[1001] = {};
        int b[1001] = {};
        for (int j=0;j<n;j++) scanf("%d",&a[j]);
        for (int j=0;j<n;j++) scanf("%d",&b[j]);
        qsort(a,n,sizeof(a[0]),cmp);
        qsort(b,n,sizeof(b[0]),cmp);
        int pro =0;
        for (int j=0,k=n-1;j<n;j++,k--)
        {
            pro += a[j]*b[k];
        }
        printf("case #%d:\n%d\n",i,pro);
    }
    return 0;
}