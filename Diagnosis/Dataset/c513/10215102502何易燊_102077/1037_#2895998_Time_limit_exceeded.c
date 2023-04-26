#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int cmp(const void* a,const void* b)
{
    long long* c = (long long*)a; long long* d = (long long*)b;
    return (*c>*d)?-1:1;
}

main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    long long* a = (long long*)malloc(n*sizeof(long long));
    for (int i=0;i<n;i++) scanf("%lld",&a[i]);
    qsort(a,n,sizeof(a[0]),cmp);
    long long* b = (long long*)malloc((n-m+1)*sizeof(long long));
    for (int i=0;i<n-m+1;i++)
    {
        b[i] = (m-1)*a[i];
        for (int j=i+1;j<m+i;j++) b[i] -= a[j];
    }
    qsort(b,n-m+1,sizeof(b[0]),cmp);
    printf("%lld\n",b[n-m]);
    system("pause");
    return 0;
}