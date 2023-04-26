#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
typedef struct SSS
{
    long long x;
    long long y;
    unsigned long long dis;
}sss;
int cmp(const void*_a,const void*_b)
{
    sss* a=(sss*)_a;
    sss* b=(sss*)_b;
    if((a->dis)!=(b->dis))
        return((a->dis)>(b->dis)?-1:1);
    else if((a->x)!=(b->x))
        return ((a->x)>(b->x)?1:-1);
    else
        return((a->y)>(b->y)?1:-1);
}
int main()
{
    int n;
    scanf("%d",&n);
    sss s[110];
    for(int i=0;i<n;i++)
    {
        scanf("%lld %lld",&s[i].x,&s[i].y);
        long long p=s[i].x,q=s[i].y;
        if(p<0) p=-p;
        if(q<0) q=-q;
        s[i].dis=p+q;
    }
    qsort(s,n,sizeof(sss),cmp);
    int ans=0;unsigned long long man1=0;
    for(int i=0;i<n-1;i++)
    {
        long long k=1;
        long long cnt=0;
        unsigned long long man=0;
        long long p=s[i].x,q=s[i+1].x;
        if(p>q) man+=p-q;
        else man+=q-p;
        p=s[i].y;q=s[i+1].y;
        if(p>q) man+=p-q;
        else man+=q-p;
        if(i==0) man1=man;
        while(cnt<man)
        {
            cnt+=k;
            k*=2;
            ans++;
        }
        if((cnt-man)%2==0) continue;
        else
        {
            ans=0;break;
        }
    }
    printf("%llu\n",man1);
    printf("%d",ans);
    return 0;
}
