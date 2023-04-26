#include <stdio.h>
#include <stdlib.h>
int g[100]={0};
int a[10]={0};
int n;
void pdh(int k,int j)
{
    int m=0,l=0;
    if(j<n-1)
    {   pdh(k,j+1);
        m=k+a[j+1];g[abs(m)]=1;
        l=k-a[j+1];g[abs(l)]=1;
        pdh(m,j+1);pdh(l,j+1);
    }
    else return;
}
int main()
{
    int i,sum=0,j=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){scanf("%d",&a[i]);sum=sum+a[i];}
    for(i=0;i<n;i++)
    {   int m=0;
        m=a[i];g[m]=1;
       pdh(m,i);
    }
    for(i=1;i<=sum;i++){printf("%d",g[i]);}

    return 0;
}
