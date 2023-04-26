#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
    return *((int *)a)-*((int *)b);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    long long int *a=(long long int *)malloc(sizeof(long long int)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    long long ans=a[m-1]*(m-1);
    for(int i=0;i<m-1;i++)
    ans-=a[i];
    printf("%lld",ans);
    
    
}