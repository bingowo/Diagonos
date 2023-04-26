#include<stdio.h>
#include<stdlib.h>
int cmp(const void *pa,const void *pb)
{
    long long int a,b;
    a=*((long long int *)pa);
    b=*((long long int *)pb);
    if(a-b<0)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
int main()
{
    int n;
    int m;
    scanf("%d%d",&n,&m);
    long long int a[n];
    long long int b[n-m+1];
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(long long int),cmp);
    long long int q=0;
    for(int j=0;j<n-m+1;j++)
    {
        for(int k=0;k<m;k++)
        {
            q=q+a[j+m-1]-a[j+k];
        }
        b[j]=q;
        q=0;
    }
    qsort(b,n-m+1,sizeof(long long int),cmp);
    printf("%lld",b[0]);
    return 0;
}