#include<stdio.h>
#define SIZE 1000
struct data
{
    int val;
    char dir;
}elem;
void shrotestpath(elem A[][SIZE],int m,int n)
{
    int i,j;
    for(i=1;i<m;i++)
    {
        A[i][0].val+=A[i-1][0].val;
        A[i][0].dir='D';
    }
    for(i=0;i<n;i++)
    {
        A[0][i].val+=A[0][i-1].val;
        A[0][i].dir='R';
    }
    for(i=1;i<m;i++)
    {
        for(j=1;j<n;j++)
        {
            if(A[i-1][j].val<A[i][j-1].val)
            {
                A[i][j].val+=A[i-1][j].val;
                A[i][j].dir='D';
            }
            else
            {
                A[i][j].val+=A[i][j-1].val;
                A[i][j].dir='R';
            }
        }
    }
}
void outpath(elem A[][SIZE],int m,int n,int r,int c)
{
    if(r==0&&c==0)
    {
        return;
    }
    if(A[r][c].dir=='D');
    {
        outpath(A,m,n,r-1,c);
        putchar('D');
    }
    else
    {
        outpath(A,m,n,r,c-1);
        putchar('R');
    }
}
int main()
{
    elem a[SIZE][SIZE];
    int m,n;
    int i,j;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j].val);
            a[i][j].dir=0;
        }
    }
    shortestpath(a,m,n);
    printf("%d\n",a[m-1][n-1].val);
    outpath(a,m,n,m-1,n-1);
    putchar('\n');
    return 0;
}
{
    
}