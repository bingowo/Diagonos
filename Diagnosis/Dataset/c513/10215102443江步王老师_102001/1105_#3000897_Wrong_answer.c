#include<stdio.h>
#include<malloc.h>


int cmp(int a, int b);
int main()
{
    int w,h;
    int i,j;
    scanf("%d %d\n",&w,&h);

    //创建h行w列的二维数组
    int** a = (int**)malloc(sizeof(int*)*h);
    for (i=0;i<h;++i)
    {
        a[i]=(int*)malloc(sizeof(int)*w);
    }
    //把各行各列数据存入二维数组中
    for (i=0;i<h;++i)
    {
        for (j=0;j<w;++j)
        {
            scanf("%d",&a[i][j]);
        }
    }

    for (i=1;i<h-1;++i)
    {
        for (j=1;j<w-1;++j)
        {
            int res=0;
            int row=i-1,col=j-1;
            for (;col<j+1;++col)
            {
                res=res*2+cmp(a[row][col],a[i][j]);
            }
            for (;row<i+1;++row)
            {
                res=res*2+cmp(a[row][col],a[i][j]);
            }
            for (;col>j-1;--col)
            {
                res=res*2+cmp(a[row][col],a[i][j]);
            }
            for (;row>i-1;--row)
            {
                res=res*2+cmp(a[row][col],a[i][j]);
            }
            printf("%d",res);if (j!=w-2) {putchar(' ');}
        }
        putchar('\n');
        
    }
    for (i=0;i<h;++i)
    {
        free(a[i]);
    }
    free(a);
    return 0;
}

int cmp(int a, int b)
{
    if (a>=b) return 1;
    else return 0;
}