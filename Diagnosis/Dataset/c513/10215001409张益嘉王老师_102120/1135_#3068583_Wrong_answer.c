#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int wei;
    int a[100];
}bigint;

bigint co[510];

bigint reverse(bigint x)
{
    int i,mid;
    for(i=0;i<x.wei/2;i++)
    {
        mid=x.a[i];
        x.a[i]=x.a[x.wei-1-i];
        x.a[x.wei-1-i]=mid;

    }
    return x;
}

bigint jia(bigint x,bigint b)
{
    x=reverse(x);
    b=reverse(b);
    bigint re;
    memset(re.a,0,sizeof(int)*100);
    int jin=0,i,mid;
    for(i=0;(i<x.wei)||(i<b.wei)||(jin!=0);i++)
    {
        mid=x.a[i]+b.a[i]+jin;
        re.a[i]=mid%10;
        jin=mid/10;
    }
    re.wei=i;
    re=reverse(re);
    return re;
}

bigint sum(int n)
{
    int i;
    if(n==1) {co[n].a[0]=1;co[n].wei=1;return co[n];}
    else if(n==2) {co[n].a[0]=2;co[n].wei=1;return co[n];}
    else if(n==3) {co[n].a[0]=3;co[n].wei=1;return co[n];}
    else if(n==4) {co[n].a[0]=6;co[n].wei=1;return co[n];}
    else
    {
        bigint mid;
        memset(mid.a,0,sizeof(int)*100);
        if(co[n-1].wei==0) {co[n-1]=sum(n-1);}
        if(co[n-2].wei==0) {co[n-2]=sum(n-2);}
        if(co[n-4].wei==0) {co[n-4]=sum(n-4);}
        mid=jia(co[n-1],co[n-2]);

        /*printf("test:mid.wei=%d   ",mid.wei);
        for(i=0;i<mid.wei;i++) printf("%d",mid.a[i]);
        printf("\n");*/

        co[n]=jia(mid,co[n-4]);

        /*printf("test:co[%d].wei=%d   ",n,co[n].wei);
        for(i=0;i<co[n].wei;i++) printf("%d",co[n].a[i]);
        printf("\n");*/

        return co[n];
    }

}

int main()
{
    int n,i;
    bigint re;
    scanf("%d",&n);
    memset(co,0,sizeof(bigint)*510);
    re=sum(n);
    for(i=0;i<re.wei;i++)
    {
        printf("%d",re.a[i]);
    }

}
