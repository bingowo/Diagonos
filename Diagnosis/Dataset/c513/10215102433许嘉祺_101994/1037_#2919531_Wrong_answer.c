#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b){
    long long a1=*(long long *)a,b1=*(long long *)b;
    if (a1>b1) return -1;
    else return 1;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    long long max=0,max1;
    long long *a=(long long *)malloc(sizeof(long long )*n);
    for (int i=1; i<n; i++)
    {
        scanf("%lld",&a[i]);

    }
    qsort(a,n,sizeof(a[0]),cmp);
    for (int i=0;i<m;i++)
        max+=a[0]-a[i];
    long long maxn=max;
    for (int i=m;i<n;i++)
    {
        max=max-(m-1)*(a[i-m]-a[i-m+1])+a[i-m+1]-a[i];
        if (max>maxn) maxn=max;
    }
    printf("%lld\n",&maxn);
    free(a);
    return 0;
}