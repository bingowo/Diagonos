#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a=0,n=0,m=0,x=0;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    int su[20]={0},sv[20]={0},v[20]={0};
    su[0]=1,su[1]=1,sv[0]=0,sv[0]=0,v[0]=0,v[1]=1;
    for(int i=2;i<n;i++)
    {
        v[i]=v[i-1]+v[i-2];
        su[i]=su[i-1]+v[i-1]-v[i-2];
        sv[i]=sv[i-1]+v[i]-v[i-1];
    }
    int t=(m-su[n-2]*a)/sv[n-2];
    printf("%d",su[x-1]*a+sv[x-1]*t);
    return 0;
}