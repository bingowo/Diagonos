#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a,const void* b)
{
    int aa = *(int*)a, bb = *(int*)b;
    long long copy_a = aa, copy_b = bb;
    int cnta = 0, cntb = 0;
    for (int i=0;i<64;i++)
    {
        if (aa&1) cnta++;
        if (bb&1) cntb++;
        aa >>= 1, bb >>= 1;
    }
    if (cnta!=cntb) return cntb-cnta;
    else return copy_a-copy_b<0?0:1;
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        int k;
        scanf("%d",&k);
        long long a[10001] = {};
        for (int j=0;j<k;j++) scanf("%lld",&a[j]);
        qsort(a,k,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for (int j=0;j<k;j++) printf("%lld ",a[j]);
        printf("\n");
    }
    system("pause");
    return 0;
}