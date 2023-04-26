#include<stdio.h>
#include<string.h>
int main()
{
    int n,m,k=1,c;
    scanf("%d\n",&n);
    int d[n][101],p[101]={0};
    for(int k=0;k<n;k++)
    {
        scanf("%d ",&d[k][0]);
        for(int j=1;j<=d[k][0];j++)
        {
            scanf("%d ",&d[k][j]);
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=d[i][0];j++)
        {
            if(d[i][j]==d[i-1][k])
            {
                p[k]=d[i][j];
                k++;
            }
        }
        strcpy(d[i],p);
        k=1;
    }
    for(int i=1;i<strlen(p);i++)
    {
        printf("%d ",p[i]);
    }
    return 0;
}