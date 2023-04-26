#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int val;
    char dir;
}Elem;
//count the shortestpath for each point
void shortestpath(Elem A[][200],int m,int n)
{
    int i,j;
    //if xy==0 only one direction
    for(i=1;i<m;i++)
    {
        A[i][0].val += A[i-1][0].val;
        A[i][0].dir = 'D';
    }
    for(i=1;i<n;i++)
    {
        A[0][i].val += A[0][i-1].val;
        A[0][i].dir = 'R';
    }
    //else
    for(i=1;i<m;i++)
    {
        for(j=1;j<n;j++)
        {
            if(A[i-1][j].val < A[i][j-1].val) //上面的累计值小于左边的累计值，说明要从上面过来，即从上面的一个往下走
            {
                A[i][j].val += A[i-1][j].val;
                A[i][j].dir='D';
            }
            else
            {
                A[i][j].val += A[i][j-1].val;
                A[i][j].dir = 'R';
            }
        }
    }

}

void outputpath(Elem A[][200],int m,int n,int r,int c)
{
    if(r==0 && c==0)return;
    if(A[r][c].dir == 'D')
    {
        outputpath(A,m,n,r-1,c);
        putchar('D');
    }
    else
    {
        outputpath(A,m,n,r,c-1);
        putchar('R');
    }
}
int main()
{
    Elem A[200][200];
    int m,n;
    int i,j;
    //input val
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&A[i][j].val);
            A[i][j].dir=0;
        }
    }
    shortestpath(A,m,n);
    printf("%d\n",A[m-1][n-1].val);
    outputpath(A,m,n,m-1,n-1);
    putchar('\n');
    return 0;
}