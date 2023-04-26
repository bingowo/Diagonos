#include<stdio.h>

int main()
{
    int a,n,m,x;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    int num[n][2];
    num[0][0]=1;num[0][1]=0;
    num[1][0]=1;num[1][1]=0;
    num[2][0]=2;num[2][1]=0;
    num[3][0]=2;num[3][1]=1;
    for(int i=4;i<n-1;i++)
    {
        num[i][0] = 2 * num[i-1][0] - num[i-3][0];
        num[i][1] = 2 * num[i-1][1] - num[i-3][1];
    }
    int p = (m - num[n-2][0] * a) / num[n-2][1];
    printf("%d",num[x-1][0]*a+num[x-1][1]*p);

    return 0;
}