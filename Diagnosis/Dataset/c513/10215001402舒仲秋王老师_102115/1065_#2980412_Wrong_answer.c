#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a1[21],b1[21];
    int a,n,m,x,i;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    a1[0]=1,a1[1]=0;
    for(i=2;i<n;i++)
        a1[i]=a1[i-1]+a1[i-2];
    b1[0]=0,b1[1]=1;
    for(i=2;i<n;i++)
        b1[i]=b1[i-1]+b1[i-2];
    int t=(m-a1[n-1]*a)/b1[n-1];
    printf("%d",a1[x-1]*a+b1[x-1]*t);
    return 0;
}
