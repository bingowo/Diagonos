#include <stdio.h>
#include <math.h>

int A[50][50]={1};

int F(int n,int m)
{
    if(A[n][m]!=0)
    {
        return A[n][m];
    }
    if(m==0)
    {
        return A[n][m]=1;
    }
    if(n==0)
    {
        return A[n][m]=0;
    }

    if(m==1)
    {
        return A[n][1]=pow(2,n)-1;
    }
    else if(n==m)
    {
        return A[n][m]=1;
    }
    else if(n-m-1>m)
    {
        return A[n][m]=F(n-1,m)*F(1,1)+F(n-1,m)*F(1,0)+pow(2,n-m-1)*F(1,1)-F(n-m-1,m);
    }
    else
    {
        return A[n][m]=F(n-1,m)*F(1,1)+F(n-1,m)*F(1,0)+pow(2,n-m-1)*F(1,1);
    }
}

int main()
{
    int n,m;
    while(1)
    {
        scanf("%d %d",&n,&m);
        if(n==-1&m==-1)
        {
            break;
        }
        printf("%d\n",F(n,m));
    }
}
