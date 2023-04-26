#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define SIZE 200
typedef struct
{int val; char dir;}Elem;

void shortestpath(Elem A[][SIZE],int M,int N)
{
    int i,j;
    for(i=1;i<M;i++)
    {
        A[i][0].val += A[i-1][0].val;
        A[i][0].dir = 'D';
    }
    for(i=1;i<N;i++)
    {
        A[0][i].val += A[0][i-1].val;
        A[0][i].dir = 'R';
    }
    for(i=1;i<M;i++)
        for(j=1;j<N;j++)
        {
            if(A[i-1][j].val<A[i][j-1].val)
            {
                A[i][j].val += A[i-1][j].val;
                A[i][j].dir = 'D';
            }
            else
            {
                A[i][j].val += A[i][j-1].val;
                A[i][j].dir = 'R';
            }
        }
}
void outpath(Elem A[][SIZE],int M,int N,int r,int c)
{
    if(r==0 && c == 0) return;
    if(A[r][c].dir == 'D')
    {
        outpath(A,M,N,r-1,c);
        putchar('D');
    }
    else
    {
        outpath(A,M,N,r,c-1);
        putchar('R');

    }
}

int main()
{
    int m,n,i,j; Elem A[SIZE][SIZE];
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)scanf("%d",&A[i][j].val);
    shortestpath(A,m,n);
    printf("%d\n",A[m-1][n-1]);
    outpath(A,m,n,m-1,n-1);
    printtf("\n");
}