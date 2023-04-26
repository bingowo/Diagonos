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
    if(aa.h>bb.h) return -1;
    else if(aa.h<bb.h) return 1;
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
    int m,n,i,re,j,ans=0,k;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&z[i].r,&z[i].h);

    }
    qsort(z,n,sizeof(zhuti),cmpr);
    for(j=0;j<=n-m;j++)
    {

    int rr=z[j].r;
    int high=2*z[j].h*z[j].r;
    zhuti mid[1100];
    memset(mid,0,sizeof(zhuti)*1100);
    for(i=j+1,k=0;i<n;i++,k++)
    {
        mid[k]=z[i];

    }
    qsort(mid,k,sizeof(zhuti),cmph);
    for(i=0;i<m-1;i++)
    {
        high+=(mid[i].h*2*mid[i].r);
    }
    re=rr*rr+high;
    //printf("j=%d  re=%d\n",j,re);
    if(re>=ans) ans=re;
    }
    printf("%d",ans);
}
