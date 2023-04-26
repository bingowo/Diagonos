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
    for(int i=0;i<n;i++)
        scanf("%ld",a+i);
    qsort(a,n,sizeof(a[0]),cmp);
    long long sum=0,tmp=0;
    for(int i=1;i<m;i++)
        sum+=a[0]-a[i];
    for(int i=1;i<n-m+1;i++)
    {
        for(int x=1;x<m;x++)
        {
            tmp+=a[i]-a[i+x];
        }
        if(sum>tmp) sum=tmp;
        tmp=0;
    }
    printf("%lld",sum);
    free(a);
    return 0;
}
