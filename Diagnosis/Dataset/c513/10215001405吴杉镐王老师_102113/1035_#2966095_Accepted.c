#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int T,n,m;
struct node{
    long long px,r;
}A[1005];
int cmp(const void* a,const void* b)
{
    struct node x=*(struct node*)a,y=*(struct node*)b;
    if(x.px!=y.px)
    {
        if(x.px>y.px)
            return -1;
        else
            return 1;
    }
    else
        return y.r-x.r;
}
int main()
{
    scanf("%d%d",&n,&m);
    long long mxr1=0,mxr2=0;
    for(int i=1;i<=n;i++)
    {
        int r,h;
        scanf("%d%d",&r,&h);
        A[i].px=1ll*r*h;
        A[i].r=r;
        if(mxr1<r)
            mxr1=r;
    }
    qsort(A+1,n,sizeof(struct node),cmp);
    long long ans1=0,ans2=0;
    for(int i=1;i<=m;i++)
    {
        ans1+=2*A[i].px;
        if(mxr2<A[i].r)
            mxr2=A[i].r;
    }
    ans1+=mxr2*mxr2;
    if(mxr1!=mxr2)
    {
        ans2=ans1-mxr2*mxr2-2*A[m].px;
        for(int i=m+1;i<=n;i++)
            if(A[i].r==mxr1)
            {
                ans2+=2*A[i].px;
                ans2+=mxr1*mxr1;
                break;
            }
    }
    //printf("%lld %lld\n",ans1,ans2);
    if(ans2>ans1)
        ans1=ans2;
    printf("%lld\n",ans1);
    return 0;
}

