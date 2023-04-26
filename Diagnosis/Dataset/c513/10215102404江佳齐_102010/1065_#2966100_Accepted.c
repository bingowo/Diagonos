#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,n,m,x;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    int u[20],v[20],su[20],sv[20];
    u[0]=1;u[1]=0;
    for(int i=2;i<n-1;i++) u[i]=u[i-1]+u[i-2];
    v[0]=0;v[1]=1;
    for(int i=2;i<n-1;i++) v[i]=v[i-1]+v[i-2];
    su[0]=1;su[1]=1;
    for(int i=2;i<n-1;i++) su[i]=su[i-1]+v[i-1]-v[i-2];
    sv[0]=0;sv[1]=0;
    for(int i=2;i<n-1;i++) sv[i]=sv[i-1]+v[i]-v[i-1];
    int t=(m-su[n-2]*a)/sv[n-2];
    int sum=su[x-1]*a+sv[x-1]*t;
    printf("%d\n",sum);
    return 0;
}
