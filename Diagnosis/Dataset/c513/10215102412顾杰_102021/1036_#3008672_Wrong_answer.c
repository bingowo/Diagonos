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
unsigned long long lluabs(long long a,long long b)
{
    return a>b?a-b:b-a;
}
typedef struct{int cnt,v[500];}BIGINT;
BIGINT llu2BIG(unsigned long long x)
{
    BIGINT R={0,{0}};
    do
    {
        R.v[R.cnt++]=x%10;
        x/=10;
    }
    while(x>0);
    return R;
}
BIGINT ADD(BIGINT S,BIGINT T)
{
    BIGINT R={0};
    int i,carry=0;
    for(i=0;i<S.cnt&&i<T.cnt;i++)
    {
        int temp=(S.v[i]+T.v[i]+carry);
        R.v[i]=temp%10;
        carry=temp/10;
    }
    while(i<S.cnt)
    {
        int temp=S.v[i]+carry;
        R.v[i++]=temp%10;
        carry=temp/10;
    }
    while(i<T.cnt)
    {
        int temp=T.v[i]+carry;
        R.v[i++]=temp%10;
        carry=temp/10;
    }
    if(carry)
    {
        R.v[i++]=carry%10;
    }
    R.cnt=i;
    return R;
}
int isbigger(BIGINT a,BIGINT b)
{
    if(a.cnt>b.cnt)return 1;
    if(a.cnt<b.cnt)return 0;
    for(int i=0;i<a.cnt;i++)if(a.v[i]!=b.v[i])return a.v[i]>b.v[i]?1:0;
    return -1;
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
        unsigned long long x=lluabs(a[i].x,a[i-1].x),y=lluabs(a[i].y,a[i-1].y);
        if(x!=0||y!=0)
        {
            BIGINT xy=ADD(llu2BIG(x),llu2BIG(y));
           // printf("xy=");
           // for(int j=xy.cnt-1;j>=0;j--)printf("%d",xy.v[j]);
            //printf("!!\n");
            if(xy.v[0]%2==0){ans=0;break;}
            //else ans+=((long long)log(x+y))/(log(2))+1LL;
            else {
                    int j;
                    for(j=0;j<64;j++)
                    {
                        int f=isbigger(llu2BIG(1LLU<<j),xy);
                        if(f){if(f==-1)j++;break;}
                    }
                    //if(j==64)ans+=j;
                    ans+=(long long)j;
                    //printf("%lld@%d\n",ans,j);
                    }
        }
    }
    BIGINT an=ADD(llu2BIG(lluabs(a[0].x,a[1].x)),llu2BIG(lluabs(a[0].y,a[1].y)));
    for(int j=an.cnt-1;j>=0;j--)printf("%d",an.v[j]);
    printf("\n%lld",ans);
}
