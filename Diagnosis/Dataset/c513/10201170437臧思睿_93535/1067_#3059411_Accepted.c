#include <stdio.h>
typedef long long int ll;

int main()
{
    int t=0,T,n,i;
    ll a[74]={0,1,1};
    for(i=3;i<74;i++)
    {
        a[i]=a[i-1]+a[i-2]+a[i-3];
    }
    scanf("%d",&T);
    while(t++<T)
    {
        printf("case #%d:\n",t-1);
        scanf("%d",&n);
        printf("%lld\n",a[n]);
    }
    return 0;
}
