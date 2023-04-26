#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define SIZE 201
typedef struct
{
    int cnt;
    char direction;
}s;
void shortestpath(s a[][SIZE],int M,int N)   //计算到达每个位置的最短路径长度
{
    int i,j;
    for(i=1;i<M;i++)
    {
        a[i][0].cnt += a[i-1][0].cnt;
        a[i][0].direction = 'D';//向下
    }
    for(i=1;i<N;i++)
    {
        a[0][i].cnt += a[0][i-1].cnt;
        a[0][i].direction = 'R';//向右
    }
    for(i=1;i<M;i++)
        for(j=1;j<N;j++)
        {
            if(a[i-1][j].cnt<a[i][j-1].cnt)         //向下移动
            {
                a[i][j].cnt += a[i-1][j].cnt;
                a[i][j].direction = 'D';
            }
            else                                                  //向右移动
            {
                a[i][j].cnt += a[i][j-1].cnt;
                a[i][j].direction = 'R';
            }
        }
}
void outpath(s a[][SIZE],int r,int c) //递归输出到A[r][c]的最短路径
{
    if(r==0 && c == 0) return;
    if(a[r][c].direction == 'D')
    {
        outpath(a,r-1,c);
        putchar('D');
    }
    else
    {
        outpath(a,r,c-1);
        putchar('R');
    }
}
int main()
{
    s a[SIZE][SIZE];
    int M,N;
    int i,j;
    scanf("%d %d",&M,&N);
    for(i=0;i<M;i++)
        for(j=0;j<N;j++)
        {
            scanf("%d",&a[i][j].cnt);
            a[i][j].direction = 0;
        }
    shortestpath(a,M,N);
    printf("%d\n",a[M-1][N-1].cnt);
    outpath(a,M-1,N-1);
    putchar('\n');
    return 0;
}

