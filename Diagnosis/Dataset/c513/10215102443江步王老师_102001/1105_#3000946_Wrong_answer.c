#include<stdio.h>
#include<malloc.h>


int cmp(int a, int b);
int main()
{
    int w,h;
    int i,j,k;
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
            int min=255;
            int row[15];int col[15];
            row[0]=i-1;row[1]=i-1;row[2]=i-1;row[3]=i;row[4]=i+1;row[5]=i+1;row[6]=i+1;row[7]=i;
            for (k=0;k<=6;++k) {row[k+8]=row[k];}
            col[0]=j-1;col[1]=j;col[2]=j+1;col[3]=j+1;col[4]=j+1;col[5]=j;col[6]=j-1;col[7]=j-1;
            for (k=0;k<=6;++k) {col[k+8]=col[k];}
            
            for (k=0;k<8;++k)
            {
                int res=0;
                int t=0;
                while (t<8)
                {
                    res=res*2+cmp(a[row[t]][col[t]],a[i][j]);
                    t++;
                }
                if (res<min)
                {
                    min=res;
                }
            }
            /*for (;col<j+1;++col)
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
            }*/
            printf("%d",min);if (j!=w-2) {putchar(' ');}
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