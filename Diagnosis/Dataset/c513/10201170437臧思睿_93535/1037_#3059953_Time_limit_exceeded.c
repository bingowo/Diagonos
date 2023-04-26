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
    ll a[n],r=9223372036854775807,x;
    for(i=0;i<n;i++){scanf("%lld",&a[i]);}
    qsort(a,i,sizeof(ll),cmp);
    for(i=0;i<n-m+1;i++)
    {
        x=a[i]*(m-1);
        for(j=1;j<m;j++)
        {
            x-=a[i+j];
        }
        r=(r<x)?r:x;
    }
    printf("%lld",r);
    return 0;
}
