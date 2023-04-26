#include <stdio.h>

int main()
{
    int dp1[21];//末尾为1
    int dp0[21];//末尾为0
    dp1[0]=0;
    dp0[0]=0;
    dp1[1]=1;
    dp0[1]=1;
    dp1[2]=2;
    dp0[2]=2;
    for(int i=3;i<21;i++)
    {
        dp1[i]=dp1[i-1]+dp0[i-1]-dp1[i-2];
        dp0[i]=dp1[i-1]+dp0[i-1];
    }
    while(1)
    {
        int n;
        scanf("%d",&n);
        if(n==-1)
        {break;}
        printf("%d\n",dp1[n]+dp0[n]);
    }
    return 0;
}