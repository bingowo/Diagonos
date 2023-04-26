#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long x,y,m;
    int X[501]={0};
    int Y[501]={0};
    char c;


    c=getchar();
    if(c=='.') x=0;
    else {ungetc(c,stdin); scanf("%lld",&x);c=getchar();}
    int i=0;
    while((c=getchar())!=32)
    {
        X[i]=c-'0';
        i++;
    }
    c=getchar();
    if(c=='.') y=0;
    else {ungetc(c,stdin); scanf("%lld",&y);c=getchar();}
    int j=0;
    while((c=getchar())!=32)
    {
        Y[j]=c-'0';
        j++;
    }
    scanf("%d",&m);
    /*printf("%d\n",x);
    printf("%d\n",y);
    printf("%d\n",m);*/


    long long res=x+y;
    int RES[501]={0};
    int n;
    if(i>j)
        n=i;
    else n=j;
    for(int k=n-1;k>0;k=k-1)
    {
        RES[k]=RES[k]+X[k]+Y[k];
        if(RES[k]>=10)
        {RES[k]=RES[k]-10;RES[k-1]++;}
    }
    RES[0]=RES[0]+X[0]+Y[0];
    if(RES[0]>=10)
    {
        RES[0]=RES[0]-10;
        res++;
    }


    printf("%lld",res);
    printf(".");
    for(int k=0;k<m-1;k++)
        printf("%d",RES[k]);
    if(RES[m]>=5)
        printf("%d",RES[m-1]+1);
    else printf("%d",RES[m-1]);
    return 0;
}
