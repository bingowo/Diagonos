#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
    retuen *((int *)a)-*((int *)b);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int *a=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    long long ans=a[m-1]*m;
    for(int i=0;i<m-1;i++)
    ans-=a[i];
    printf("%lld",ans);
    
    
}