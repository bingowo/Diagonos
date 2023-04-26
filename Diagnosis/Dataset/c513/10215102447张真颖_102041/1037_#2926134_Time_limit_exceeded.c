#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
    long int aa=*(long int*)a,bb=*(long int*)b;
    if(aa>bb) return -1;
    if(aa<bb) return 1;
    return 0;
}

int main()
{
    int n=0,m=0;
    scanf("%d%d",&n,&m);
    long int* a=(long int*)malloc(sizeof(long int)*n);
    long long* b=(long int*)calloc(n-m+1,sizeof(long long));
    for(int i=0;i<n;i++)
        scanf("%ld",a+i);
    qsort(a,n,sizeof(a[0]),cmp);
    for(int i=0,j=0;i<n-m+1;i++,j++)
        for(int x=1;x<m;x++)
            b[j]+=a[i]-a[i+x];
    qsort(b,n-m+1,sizeof(b[0]),cmp);
    printf("%lld",b[n-m]);
    free(b);
    free(a);
    return 0;
}
