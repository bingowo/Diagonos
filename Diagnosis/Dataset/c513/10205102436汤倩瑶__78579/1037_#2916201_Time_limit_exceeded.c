#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
    long long int p1= *((long long int *)a);
    long long int p2=*((long long int *)b);
    if(p1>p2)return 1;
    else return -1;
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
    long long int ans=1e18;
    for(int i=m-1;i<n;i++)
    {
       long long tmp=0;
       for(int j=0;j<m-1;j++)
    tmp+=a[i]-a[i-j-1];
    if(tmp<ans)ans=tmp;
    }


    printf("%lld",ans);


}
