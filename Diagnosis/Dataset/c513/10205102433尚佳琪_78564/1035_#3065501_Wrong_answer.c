#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
    long long r,h;
    long long sd,sc,s;
}node;
int cmp(const void *a,const void *b)
{
    node s1=*(node*)a;
    node s2=*(node*)b;
    if(s1.s!=s2.s)
    {
        if(s1.s>s2.s)
            return 1;
        else
            return -1;
    }
    else
    {
        if(s1.sd!=s2.sd)
        {
            if(s1.sd>s2.sd)
                return 1;
            else
                return -1;
        }
        else
            return -1;
    }
}
int cmp2(const void *a,const void *b)
{
    node s1=*(node*)a;
    node s2=*(node*)b;
    if(s1.sc!=s2.sc)
    {
        if(s1.sc>s2.sc)
            return -1;
        else
            return 1;
    }
    else
        return -1;
}
int main()
{
   int n,m;
   scanf("%d %d",&n,&m);
   node a[n];
   for(int i=0;i<n;i++)
   {
       scanf("%lld %lld",&a[i].r,&a[i].h);
       a[i].sd=a[i].r*a[i].r;
       a[i].sc=a[i].r*a[i].h*2;
       a[i].s=a[i].sc+a[i].sd;
   }
   qsort(a,n,sizeof(a[0]),cmp);
    long long ans;
    ans=a[n-1].s;
    //printf("%lld",ans);
    qsort(a,n-1,sizeof(a[0]),cmp2);
    int cnt=0;
    for(int i=0;i<n-1;i++)
    {
        if(cnt==m-1)
            break;
        ans+=a[i].sc;
        cnt++;
    }
    printf("%lld",ans);
}
