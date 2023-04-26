#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    int a[50]={0},b[50]={0};int i=49,j=49;
    int x1=x/y,x2=x%y;
    while(x1)
    {
        a[i--]=x1%3;
        x1=x1/3;
    }
    int temp[50]={0};
    while(x2)
    {
        temp[j--]=x2%3;
        x2=x2/3;
    }
    for(int k=j+1,ii=0;k<50;k++,ii++) b[ii]=temp[k];
    int last=0;//加
    for(int k=1;k>=0;k--)
    {
        int t=b[k]+1+last;
        if(t>=3) b[k]=t-3,last=1;
        else b[k]=t,last=0;
    }
    for(int k=49;k<50;k--)
    {
        int t;
        if(k>=46) t=a[k]+1+last;
        else t=a[k]+last;
        if(t>=3) a[k]=t-3,last=1;
        else a[k]=t,last=0;
        if(last==0&&k<=46) break;
    }
    for(int k=1;k>=0;k--)//减
    {
        int t=b[k]-1;
        if(t==-1) b[k]=2;
        else b[k]=t;
    }
    for(int k=49;k>=46;k--)
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
