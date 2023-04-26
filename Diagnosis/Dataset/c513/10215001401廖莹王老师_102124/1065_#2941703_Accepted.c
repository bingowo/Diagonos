#include <stdio.h>
#include <stdlib.h>
int ax[25];
int tx[25];
int suma[25];
int sumt[25];
int shanga(int x)
{
    ax[0]=0;ax[1]=1;ax[2]=0;
    if(x>=3)
    {
    if(ax[x-1]==-1)ax[x-1]=shanga(x-1);
    else if(ax[x-2]==-1)ax[x-2]=shanga(x-2);
     ax[x]=ax[x-1]+ax[x-2];
    }

    return ax[x];
}
int shangt(int x)
{
    tx[0]=0;tx[1]=0;tx[2]=1;
    if(x>=3)
    {
    if(tx[x-1]==-1)tx[x-1]=shangt(x-1);
    else if(tx[x-2]==-1)tx[x-2]=shangt(x-2);
     tx[x]=tx[x-1]+tx[x-2];
    }

    return tx[x];
}
int chea(int x)
{
    suma[0]=0;suma[1]=1;suma[2]=1;
    if(x>=3)
    {
    if(suma[x-1]==-1)suma[x-1]=chea(x-1);
     suma[x]=suma[x-1]+shanga(x-2);
    }

    return suma[x];
}
int chet(int x)
{
    sumt[0]=0;sumt[1]=0;sumt[2]=0;
    if(x>=3)
    {
    if(sumt[x-1]==-1)sumt[x-1]=chet(x-1);
     sumt[x]=sumt[x-1]+shangt(x-2);
    }

    return sumt[x];
}
int main()
{
    int a=0,n=0,m=0,x=0,l=0,re=0;
    int i=0;
    for(i=0;i<25;i++){ax[i]=-1;tx[i]=-1;suma[i]=-1;sumt[i]=-1;}
    scanf("%d %d %d %d",&a,&n,&m,&x);
    l=(m-chea(n-1)*a)/chet(n-1);
    re=chea(x)*a+chet(x)*l;
    printf("%d",re);
    return 0;
}
