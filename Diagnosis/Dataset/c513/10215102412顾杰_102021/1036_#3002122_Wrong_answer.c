#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
//#include "myh.h"
int cmp(const void*a,const void*b)
{
    long long *pa=(long long*)a,*pb=(long long*)b;
    if(pa[2]==pb[2])
        if(pa[0]==pb[0])return pa[1]<pb[1]?-1:1;
        else return pa[0]<pb[0]?-1:1;
    return pa[2]>pb[2]?-1:1;
}
int main()
{
    long long n,a[101][3],i,ans=0;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld%lld",&a[i][0],&a[i][1]);
        a[i][2]=llabs(a[i][0])+llabs(a[i][1]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for(i=0;i<n;i++)printf("%lld %lld %lld\n",a[i][0],a[i][1],a[i][2]);
    for(i=1;i<n;i++)
    {

        long long x=llabs(a[i][0]-a[i-1][0]),y=llabs(a[i][1]-a[i-1][1]);
        if(x+y!=0)
        {
            if((x+y)%2==0){ans=0;break;}
            else ans+=(long long)(log(x+y)/log(2)+1);
        }
    }
    printf("%lld\n%lld",llabs(a[0][0]-a[1][0])+llabs(a[0][1]-a[1][1]),ans);
}
