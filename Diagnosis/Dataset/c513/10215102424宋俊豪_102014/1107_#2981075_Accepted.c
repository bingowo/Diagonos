#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
void sol(int (*b)[4])
{
    int a[5][5]= {0};
    for(int i=1; i<=3; i++)
        for(int j=1; j<=3; j++)
        {
            if(b[i][j]==0)
                continue;
            if(a[i-1][j]==1)
                a[i-1][j]=0;
            else
                a[i-1][j]=1;
            if(a[i][j-1]==1)
                a[i][j-1]=0;
            else
                a[i][j-1]=1;
            if(a[i][j]==1)
                a[i][j]=0;
            else
                a[i][j]=1;
            if(a[i][j+1]==1)
                a[i][j+1]=0;
            else
                a[i][j+1]=1;
            if(a[i+1][j]==1)
                a[i+1][j]=0;
            else
                a[i+1][j]=1;
        }
    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=3; j++)
        {   if(a[i][j]==1)
              a[i][j]=0;
            else
                a[i][j]=1;
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        printf("case #%d:\n",i);
        int a[4][4]= {0};
        for(int q=1; q<=3; q++)
            for(int m=1; m<=3; m++)
            {
                scanf("%d",&a[q][m]);
                a[q][m]=a[q][m]%2;
            }
        sol(a);
    }
}
