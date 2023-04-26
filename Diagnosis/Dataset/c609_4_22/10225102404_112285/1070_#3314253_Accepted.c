#include<stdio.h>

int main()
{
    int f[21],g[21],n;
    f[0]=g[0]=0;
    f[1]=g[1]=1;
    for(int i=2;i<=20;i++)
    {
        f[i]=f[i-1]+g[i-1];
        g[i]=f[i]-g[i-2];/*若i-2以结尾，则i-1会出现10，i会出现101*/
    }
    while(scanf("%d",&n)&&n != -1)
    {
        printf("%d\n",f[n]+g[n]);
    }
    return 0;
}
