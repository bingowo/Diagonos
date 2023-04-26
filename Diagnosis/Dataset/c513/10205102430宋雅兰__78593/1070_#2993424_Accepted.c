#include<stdio.h>
int main()
{
    int f[21];
    f[0]=1;f[1]=2;f[2]=4;
    for(int i=3;i<=20;++i)
    {
        f[i]=2*f[i-1]-f[i-2]+f[i-3];
    }
    int n;
    while(scanf("%d",&n)&&n!=-1)
    {
        printf("%d\n",f[n]);
    }
    return 0;
}