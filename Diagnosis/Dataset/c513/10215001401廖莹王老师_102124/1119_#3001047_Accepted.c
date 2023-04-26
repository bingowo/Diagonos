#include <stdio.h>
#include <stdlib.h>
double maxx(double x,double y)
{
    if(x>y)return x;
    else return y;
}
int main()
{
    int d=0,n=0,i=0;
    int a[1000][2]={0};
    double t[1000]={0};
    scanf("%d",&d);scanf("%d",&n);
    for(i=0;i<n;i++)
    {   int m=0;
        scanf("%d %d",&m,&a[i][1]);
        a[i][0]=d-m;
    }
    for(i=0;i<n;i++)
    {
        double p=0;
        if(i==0)t[0]=(double)a[i][0]/(double)a[i][1];
        else
        {
        p=(double)a[i][0]/(double)a[i][1];
        t[i]=maxx(p,t[i-1]);
        }
    }
    double v=0;
    v=(double)d/t[i-1];
    printf("%.6lf\n",v);
    return 0;
}
