#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int type(int n,int m,int* a)
{
    int n1;
    for(n1=0;n1<m;n1++)
        a[n1]=0;
    a[n1]=1;
    for(n1=n1+1;n1<=n;n1++)
        a[n1]=2*a[n1-1]+pow(2,n-m-1)-a[n-m-1];
    return a[n];
}

int main()
{
    int n,m,num=0;
    while(scanf("%d %d",&n,&m))
    {
        if(n==-1&&m==-1)
            break;
        if(n==m)
            num=1;
        else
        {
            int a[100]={0};
            num=type(n,m,a);
        }
        printf("%d\n",num);
    }
}