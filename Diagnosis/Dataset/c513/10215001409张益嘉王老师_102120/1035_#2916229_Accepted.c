#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int r;
    int h;
}zhuti;

int cmpr(const void*a,const void*b)
{
    zhuti aa=*((zhuti*)a);
    zhuti bb=*((zhuti*)b);
    if(aa.r>bb.r) return -1;
    else if(aa.r<bb.r) return 1;
    else
    {
        if(aa.h>bb.h) return -1;
        else return 1;
    }

}

int cmph(const void*a,const void*b)
{
    zhuti aa=*((zhuti*)a);
    zhuti bb=*((zhuti*)b);
    long long scea=(long long)aa.h*2*aa.r;
    long long sceb=(long long)bb.h*2*bb.r;
    if(scea>sceb) return -1;
    else if(scea<sceb) return 1;
    else
    {
        if(aa.r>bb.r) return -1;
        else return 1;
    }

}


int main()
{
    zhuti z[1100];
    memset(z,0,sizeof(zhuti)*1100);
    int m,n,i,j,k;
    long long re,ans=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&z[i].r,&z[i].h);

    }
    qsort(z,n,sizeof(zhuti),cmpr);
    for(j=0;j<=n-m;j++)
    {

    int rr=z[j].r;
    long long high=(long long)2*z[j].h*z[j].r;
    zhuti mid[1100];
    memset(mid,0,sizeof(zhuti)*1100);
    for(i=j+1,k=0;i<n;i++,k++)
    {
        mid[k]=z[i];

    }
    qsort(mid,k,sizeof(zhuti),cmph);
    for(i=0;i<m-1;i++)
    {
        high+=((long long)mid[i].h*2*mid[i].r);
    }
    re=(long long)rr*rr+high;
    //printf("j=%lld  re=%lld\n",j,re);
    if(re>=ans) ans=re;
    }
    printf("%lld",ans);
}
