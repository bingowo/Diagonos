#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int x,y;
    scanf("%lld%lld",&x,&y);
    int a[50]={0},b[50]={0};int i=49;
    long long int x1=x/y,x2=x%y;int n=0;
    while(y)
    {
        if(y/3>0) n++;
        y=y/3;
    }
    for(int k=n-1;k>=0;k--)
    {
        b[k]=x2%3;
        x2=x2/3;
    }
    while(x1)
    {
        a[i--]=x1%3;
        x1=x1/3;
    }
    int last=0;//加
    for(int k=n-1;k>=0;k--)
    {
        int t=b[k]+1+last;
        if(t>=3) b[k]=t-3,last=1;
        else b[k]=t,last=0;
    }
    for(int k=49;k>=0;k--)
    {
        int t;
        if(k>i) t=a[k]+1+last;
        else t=a[k]+last;
        if(t>=3) a[k]=t-3,last=1;
        else a[k]=t,last=0;
    }
    for(int k=n-1;k>=0;k--)//减
    {
        int t=b[k]-1;
        if(t==-1) b[k]=2;
        else b[k]=t;
    }
    for(int k=49;k>i;k--)
    {
        int t=a[k]-1;
        if(t==-1) a[k]=2;
        else a[k]=t;
    }
    int p1,p2;
    for(p1=0;p1<50;p1++) if(a[p1]!=0) break;
    for(p2=49;p2>=0;p2--) if(b[p2]!=0) break;
    if(p1==50) printf("0");
    else
    {
        for(int k=p1;k<50;k++) printf("%d",a[k]);
    }
    if(p2==-1) ;
    else
    {
        printf(".");
        for(int k=0;k<=p2;k++) printf("%d",b[k]);
    }
    return 0;
}
