#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int cmp(const void*a,const void*b)
{
    long long aa=*(long long*)a;
    long long bb=*(long long*)b;
    if(bb>aa) return 1;
    else return -1;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    long long *a;
    long long *b;
    long long *c;
    a=(long long*)malloc(n*sizeof(long long));
    b=(long long*)malloc(n*sizeof(long long));
    c=(long long*)malloc(n*sizeof(long long));
    int i;
    for(i=0; i<n; i++)
    {
        scanf("%lld",&a[i]);
        b[i]=0;
        c[i]=0;
    }
    qsort(a,n,sizeof(long long),cmp);//递推法减少复杂度
    for(i=1; i<n; i++) b[i]=a[i-1]-a[i];
    int j;
    for(i=1; i<m; i++) c[0]+=b[i]*(m-i);
    for(j=1; j<=n-m+1; j++) c[j]=c[j-1]-(m-1)*b[j]+a[j]-a[j+m-1];
    qsort(c,n-m+1,sizeof(long long),cmp);
    printf("%lld",c[n-m]);
    free(a);
    free(b);
    free(c);
    return 0;
}