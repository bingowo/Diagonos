#include<stdio.h>
#include<string>
int main()
{
    int t=0,i=0,j=0,sum=0,tmp=0,flag=0;
    scanf("%d\n",&t);
    int T[74][20]={{0},{1},{1}};
    for(i=3;i<100;i++)
    {
        for(j=0;j<20;j++)
        {
            tmp=T[i-1][j]+T[i-2][j]+T[i-3][j]+sum;
            T[i][j]=tmp%10;
            sum=tmp/10;
        }
    }
    for(i=0;i=0;j--)
    {
        if(T[n][j]!=0) flag=1;
        if(flag!=0) printf("%d",T[n][j])
    }
    printf("\n");
    return 0;
}