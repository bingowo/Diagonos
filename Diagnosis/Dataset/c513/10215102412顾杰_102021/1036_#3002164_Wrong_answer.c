#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
//#include "myh.h"
typedef struct {long long x,y;unsigned long long d;}M;
int cmp(const void*a,const void*b)
{
    M pa=*(M*)a,pb=*(M*)b;
    if(pa.d==pb.d)
        if(pa.x==pb.x)return pa.y<pb.y?-1:1;
        else return pa.x<pb.x?-1:1;
    return pa.d>pb.d?-1:1;
}

int main()
{
    M a[101];
    long long n,i,ans=0;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld%lld",&a[i].x,&a[i].y);
        a[i].d=llabs(a[i].x)+llabs(a[i].y);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    //for(i=0;i<n;i++)printf("%lld %lld %llu\n",a[i].x,a[i].y,a[i].d);
    for(i=1;i<n;i++)
    {

        unsigned long long x=llabs(a[i].x-a[i-1].x),y=llabs(a[i].y-a[i-1].y);
        if(x+y!=0)
        {
            if((x+y)%2==0){ans=0;break;}
            else ans+=log2(x+y);
        }
    }
    printf("%llu\n%lld",llabs(a[0].x-a[1].x)+llabs(a[0].y-a[1].y),ans);
}
