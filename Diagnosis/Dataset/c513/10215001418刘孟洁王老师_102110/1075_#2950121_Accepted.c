#include <stdio.h>
#include <stdlib.h>
#define M 207
#define N 207

typedef struct{int val;char ch;}path;//记录数据和方向

path A[M][N];
void find_minipath(int m,int n)
{
    int i,j;
    for(i = 1;i < m; i++)
        {
            A[i][0].val += A[i-1][0].val;
            A[i][0].ch = 'D';
        }//先把第一列的值初始化，每一个都等于前面相加
    for(j = 1;j < n; j++)
        {
            A[0][j].val += A[0][j-1].val;
            A[0][j].ch = 'R';
        }//再把第一行的值初始化，每一个都等于前面相加
    for(i = 1; i < m; i++)
        for(j = 1; j < n; j++)
       {   if(A[i-1][j].val > A[i][j-1].val)
          {
              A[i][j].val += A[i][j-1].val;
              A[i][j].ch ='R';
          }//若上面的值大于左边的值，就加上左边的值；
           else if(A[i-1][j].val <= A[i][j-1].val)
            {
                A[i][j].val += A[i-1][j].val;
                A[i][j].ch ='D';
            }//若左边的值大于上面的值，就加上上面的值；
       }
}

void direction(int m,int n,int r,int c)
{//递归到最开始的位置
    if(r == 0&&c == 0)return;
    else if(A[r][c].ch == 'D')
    {
        direction(m,n,r-1,c);
        putchar('D');
    }//若是从上面下来的，就返回过上面的值进行递归
    else
    {
        direction(m,n,r,c-1);
        putchar('R');
    }//若是从左边过来的，就返回左边的值进行递归

}


int main()
{
    int m,n,i,j;
    scanf("%d%d",&m,&n);
    for(i = 0;i < m; i++)
        for(j = 0; j < n; j++)scanf("%d",&A[i][j].val);
    find_minipath(m,n);
    printf("%d\n",A[m-1][n-1].val);//输出的是m-1,n-1的值；
    direction(m,n,m-1,n-1);
    putchar('\n');//换行符不要忘记
    return 0;
}