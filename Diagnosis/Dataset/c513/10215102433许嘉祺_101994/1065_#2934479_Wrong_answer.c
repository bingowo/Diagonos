#include <stdio.h>
#include <stdlib.h>
#include<string.h>



int main()
{
    int a,n,m,x;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    int up[21];
    int up1[21];
    up[0]=0;up1[0]=1;
    up[1]=1;up1[1]=0;
    up[2]=1;up1[2]=1;
    for (int i=3;i<n;i++)
    {
        up[i]=up[i-1]+up[i-2];
        up1[i]=up1[i-1]+up1[i-2];
    }
    int t=(m-a*(1+up1[n-2]))/(up[n-2]-1);
    printf("%d\n",a-t+up[x-1]*t+up1[x-1]*a);
    return 0;
}