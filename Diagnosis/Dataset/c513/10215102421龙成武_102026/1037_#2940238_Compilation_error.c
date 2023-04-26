#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int compar(const void *p1,const void *p2);
int main()
{
    int i,j,n,m;
    long long *a,res=0,minlen,mini,temp;
    scanf("%d %d",&n,&m);
    a=(long long*)malloc(n*sizeof(long long));
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(long long),compar);
    minlen=LLONG_MAX;
    mini=0;
    for(i=0;i<=n-m;i++)
    {
        temp=a[i+m-1]-a[i];
        if(temp<minlen)
        {
            minlen=temp;
            mini=i;
        }
    }
    for(i=mini;i<mini+m;i++)
    {
        res+=a[mini+m-1]-a[i];
    }
    return 0;
}
int compar(const void *p1,const void *p2)
{
    int flag=0;
    long long *a=(long long*)p1,*b=(long long*)p2;
    if(*a<*b)
        flag=-1;
    else
        flag=1;
    return flag;
}
