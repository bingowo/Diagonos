#include <stdio.h>
#include <stdlib.h>

#define SIZE 200
typedef struct{
    int val;
    char dir;
}Elem;

void stp(Elem A[][SIZE],int M,int N)
{
    int i,j;
    for(i=1;i<M;i++)
    {
        A[i][0].val+=A[i-1][0].val;
        A[i][0].dir='D';
    }
    for(i=1;i<N;i++)
    {
        A[0][i].val+=A[0][i-1].val;
        A[0][i].dir='R';
    }
    for(i=1;i<M;i++)
    {
        for(j=1;j<N;j++)
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

void otp(Elem A[][SIZE],int r,int c)
{
    if(r==0&&c==0) return;
    if(A[r][c].dir=='D')
    {
        otp(A,r-1,c);
        putchar('D');
    }
    else
    {
        otp(A,r,c-1);
        putchar('R');
    }
}
int main()
{
    Elem A[SIZE][SIZE];
    int M,N;
    int i,j;
    scanf("%d %d",&M,&N);
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            scanf("%d",&A[i][j].val);
            A[i][j].dir=0;
        }
    }
    stp(A,M,N);
    printf("%d\n",A[M-1][N-1].val);
    otp(A,M-1,N-1);
    printf("\n");
    return 0;
}
