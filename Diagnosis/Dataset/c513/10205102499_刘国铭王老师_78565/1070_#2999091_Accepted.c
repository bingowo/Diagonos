#include <stdio.h>

int main()
{
    int n;
    int f[21],g[21];
    f[0]=0;f[1]=1;
    g[0]=0;g[1]=1;
    for(int i=2;i<21;i++)
    {
        f[i]=f[i-1]+g[i-1];
        g[i]=f[i]-g[i-2];
    }
    while((scanf("%d",&n))!=EOF &&n!=-1)
    {
        int res=f[n]+g[n];
        printf("%d\n",res);
    }

    return 0;

}
