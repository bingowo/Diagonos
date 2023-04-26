#include<stdio.h>
#include<malloc.h>


typedef struct a
{
    int val;
    int d;
    char dir;
}Point;

void cnt_shortest(Point **p, int m, int n);

void output_path(Point **p, int m, int n);

int main()
{
    int m,n;
    int i,j;
    //输入矩阵的信息
    scanf("%d %d",&m,&n);
    //创建m*n的二维数组
    Point **p = (Point **)malloc(sizeof(Point *)*m);
    for (i=0;i<m;i++)
    {
        p[i] = (Point *)malloc(sizeof(Point)*n);
    }
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            //保存每格的数值
            scanf("%d",&p[i][j].val);
        }
    }

    cnt_shortest(p,m,n);
    printf("%d\n",p[m-1][n-1].d);
    output_path(p,m,n);
    return 0;
}


//*(*(p + i) + j) 取出p数组第i行第j列元素
void cnt_shortest(Point **p, int m, int n)
{
    int i=0,j=0;
    (*(*(p + i) + j)).d = (*(*(p + i) + j)).val;
    //储存第1行和第1列的最短路径
    for (j=1;j<n;j++)
    {
        (*(*(p + i) + j)).d = (*(*(p + i) + j)).val + (*(*(p + i) + j-1)).d;
        (*(*(p+i)+j)).dir = 'R';
    }
    j=0;
    for (i=1;i<m;i++)
    {
        (*(*(p + i) + j)).d = (*(*(p + i) + j)).val + (*(*(p + i-1) + j)).d;
        (*(*(p+i)+j)).dir = 'D';
    }

    for (i=1;i<m;i++)
    {
        for (j=1;j<n;j++)
        {
            if ((*(*(p + i-1) + j)).d < (*(*(p+i)+j-1)).d)
            {
                (*(*(p+i)+j)).d = (*(*(p + i-1) + j)).d + (*(*(p+i)+j)).val;
                (*(*(p+i)+j)).dir = 'D';
            }
            else
            {
                (*(*(p+i)+j)).d = (*(*(p + i) + j-1)).d + (*(*(p+i)+j)).val;
                (*(*(p+i)+j)).dir = 'R';
            }
        }
    }
    return;
}


void output_path(Point **p, int m, int n)
{
    if (m==0 && n==0)
    {
        return;
    }
    else if (m==0)
    {
        output_path(p,m,n-1);
        putchar((*(*(p+m)+n)).dir);
    }
    else if (n==0)
    {
        output_path(p,m-1,n);
        putchar((*(*(p+m)+n)).dir);
    }
    else
    {
        if ((*(*(p+m-1)+n)).d < (*(*(p+m)+n-1)).d)
        {
            output_path(p,m-1,n);
        }
        else
        {
            output_path(p,m,n-1);
        }
        putchar((*(*(p+m)+n)).dir);
    }
}
