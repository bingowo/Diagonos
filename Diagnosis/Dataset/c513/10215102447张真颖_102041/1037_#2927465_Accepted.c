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
    long long int* a=(long long int*)malloc(sizeof(long long int)*n);
    long long int* b=(long long int*)malloc(sizeof(long long int)*n);
    for(int i=0;i<n;i++)
        scanf("%lld",a+i);
    qsort(a,n,sizeof(a[0]),cmp);
    b[0]=a[0];
    for(int i=1;i<n;i++)
        b[i]=a[i]+b[i-1];
    long long sum=(m-1)*a[0]-(b[m-1]-b[0]),tmp=0;
    for(int i=1;i<n-m+1;i++)
    {
        tmp=(m-1)*a[i]-(b[i+m-1]-b[i]);
        if(sum>tmp) sum=tmp;
        tmp=0;
    }
    printf("%lld",sum);
    free(b);
    free(a);
    return 0;
}
