#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
    long long x=*(long long*)a;
    long long y=*(long long*)b;
    if(x>y)
        return 1;
    else
        return -1;

}
long long int min(long long int a,long long int b)
{
    if(a<b)
        return a;
    else
        return b;
}
int main()
{
    int n,m;
    long long sum=0;
    long long x=0;
    scanf("%d%d",&n,&m);
    long long a[1000001];
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    if(n==m)
    {
        for(int j=1;j<n;j++)
        {
            sum=sum+a[0]-a[j];
        }
        printf("%lld",sum);
    }
    else
    {
        for(int v=1;v<m;v++)
        {
            sum=sum+a[0]-a[v];
        }
        x=sum;
        sum=0;
        for(int p=0;p<n-m;p++)
        {
            for(int q=1;q<m;q++)
            {
                sum=sum+a[p]-a[p+q];
            }
            x=min(sum,x);
            sum=0;
        }
        printf("%lld",x);
    }
    return 0;
}