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
    long long int ans=1e14;
    for(int i=m-1;i<n;i++)
    {
       long long tmp=a[i]*(m-1);
       for(int j=0;j<m-1;j++)
    tmp-=a[i-j-1];
    if(tmp<ans)ans=tmp;
    }


    printf("%lld",ans);


}
