#include <stdio.h>
#include <string.h>
typedef long long int ll;

int cmp(const void*a,const void*b)
{
    ll *pa=(ll *)a;
    ll *pb=(ll *)b;
    return (*pa>*pb)?-1:1;
}

int main()
{
    int i,j,n,m;
    scanf("%d %d",&n,&m);
    ll a[n],r,x;
    for(i=0;i<n;i++){scanf("%lld",&a[i]);}
    qsort(a,i,sizeof(ll),cmp);
    r=a[0]*(m-1);
    for(i=1;i<m;i++)
    {
        r-=a[i];
    }
    x=r;
    for(i=1;i<n-m+1;i++)
    {
        //printf("%lld\n",x);
        x=x+a[i]*(m)-a[i-1]*(m-1)-a[m+i-1];
        r=(r<x)?r:x;
    }
    printf("%lld",r);
    return 0;
}
