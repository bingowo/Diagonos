#include <stdio.h>
#include <stdlib.h>
int GCD(int m,int n)
{
    if(n<=m && m%n==0)
        return n;
    else if(n>m)
        return GCD(n,m);
    else return GCD(n,m%n);
}
int min(int sg[1100],int wid)
{
    int i=0,l=0;
    for(i=1;i<wid;i++)
    {
        if(sg[i]<sg[l])l=i;
    }
    return l;
}
int main()
{
    int wid=0,s=0,i=0,j=0,k=0,y=0;
    int sg[1100]={0};
    scanf("%d %d",&wid,&s);
    for(i=0;i<wid;i++)scanf("%d",&sg[i]);
    int m=min(sg,wid);
    y=sg[m];
    int d=1,h=0;int zs=0;int xs=0;
    for(i=m,j=m;i>=0,j<wid;i=i,j=j)
    {
        d=1;h=0;

        for(i=i;i+1<wid;i++){if(sg[i+1]==sg[i])d++;else break;}
        i=i-d+1;j=j+d-1;

        if(i==0 && j==wid-1){zs=zs+s/d;xs=s%d;break;}
        else
        {
            if(i-1>=0 && j+1<wid)
        {
            if( sg[i-1]<sg[j+1]) h=sg[i-1]-sg[i];
            else  h=sg[j+1]-sg[i];
        }
        else if(i==0 && j!=wid-1)h=sg[j+1]-sg[i];
        else if (j==wid-1 && i!=0)h=sg[i-1]-sg[i];

        if(s/(d*h)>=1){zs=zs+h;s=s-d*h;}
        else{xs=s;if(xs/d>=1){zs=zs+xs/d;xs=xs%d;}break;}
        if(s==0)break;
        for(k=i;k<i+d;k++){sg[k]=sg[k]+h;}
        i=min(sg,wid);j=min(sg,wid);
        }
    }
    if(xs==0)printf("%d\n",zs+y);
    else
    {
        int g=GCD(xs,d);
        if(zs+y>0)printf("%d""+""%d""/""%d",zs+y,xs/g,d/g);
        else printf("%d""/""%d",xs/g,d/g);

    }

    return 0;
}
