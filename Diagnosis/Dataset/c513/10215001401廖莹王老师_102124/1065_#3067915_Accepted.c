#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,n,m,x,i;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    int s[25][25]={0};
    int z[25][25]={0};
    s[1][0]=1;s[1][1]=0;
    s[2][0]=0;s[2][1]=1;
    z[1][0]=1;z[1][1]=0;
    z[2][0]=1;z[2][1]=0;
    for(i=3;i<n;i++)
    {
        s[i][0]=s[i-1][0]+s[i-2][0];s[i][1]=s[i-1][1]+s[i-2][1];
        z[i][0]=z[i-1][0]+s[i-2][0];z[i][1]=z[i-1][1]+s[i-2][1];
    }
    int k,l;
    k=(m-z[n-1][0]*a)/z[n-1][1];
    l=z[x][0]*a+z[x][1]*k;
    printf("%d",l);
    return 0;
}
