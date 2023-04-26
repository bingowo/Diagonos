#include<stdio.h>
#include<stdlib.h>
int a[3][3];
void single(int p,int m,int n)
{
    for(int i=0;i<p;i++)
    {
        a[m][n]=(a[m][n]+1)%2;
        if(m-1>=0)a[m-1][n]=(a[m-1][n]+1)%2;
        if(m+1<3)a[m+1][n]=(a[m+1][n]+1)%2;
        if(n-1>=0)a[m][n-1]=(a[m][n-1]+1)%2;
        if(n+1<3)a[m][n+1]=(a[m][n+1]+1)%2;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        for(int m=0;m<3;m++)
        {
            for(int n=0;n<3;n++)
                a[m][n]=1;
        }
        for(int m=0;m<3;m++)
        {
            for(int n=0;n<3;n++)
            {
                int p;
                scanf("%d",&p);
                single(p,m,n);
            }

        }
        printf("case #%d:\n",i);
        for(int m=0;m<3;m++)
        {
            for(int n=0;n<3;n++)
            {
                printf("%d%c",a[m][n],n==2?'\n':' ');
            }
        }

    }
}
