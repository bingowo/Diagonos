#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a1[21],b1[21],a2[21],b2[21];
    int a,n,m,x,i;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    a1[0]=1,a1[1]=0;
    for(i=2;i<n;i++)
        a1[i]=a1[i-1]+a1[i-2];
    b1[0]=0,b1[1]=1;
    for(i=2;i<n;i++)
        b1[i]=b1[i-1]+b1[i-2];
    a2[1]=1,a2[2]=2;
    b2[1]=0,b2[2]=0;
    for(i=3;i<n;i++)
    {
        a2[i]=a2[i-1]+a2[i-2]-1;
        b2[i]=b2[i-1]+b2[i-2]+1;
    }
    int t=(m-a2[n-2]*a)/b2[n-2];
    printf("%d",a2[x-1]*a+b2[x-1]*t);
    return 0;
}
