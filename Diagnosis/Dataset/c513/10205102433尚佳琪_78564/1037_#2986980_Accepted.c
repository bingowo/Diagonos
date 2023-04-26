#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void *b)
{
    long long s1=*(long long *)a;
    long long s2=*(long long *)b;
    if(s1>s2)
        return -1;
    else
        return 1;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    long long a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    long long ans=0,temp=0;

    for(int i=1;i<m;i++)
    {
        temp=temp+a[0]-a[i];
    }
    ans=temp;
    for(int i=1;i<=(n-m);i++)
    {
        temp=temp+a[i]-a[i+m-1]-(a[i-1]-a[i])*(m-1);
        ans=temp<ans?temp:ans;
    }
    printf("%lld",ans);
    return 0;
}
