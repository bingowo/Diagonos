#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int val;
    char dir;
}Elem;

void outpath(Elem a[][200],int r,int c)
{
    if(r==0&&c==0) return;
    else if(a[r][c].dir=='D')
    {
        outpath(a,r-1,c);
        printf("D");
    }
    else
    {
        outpath(a,r,c-1);
        printf("R");
    }
}

int main()
{
    Elem a[200][200]={0};
    int m=0,n=0;
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j].val);
            a[i][j].dir=0;
        }
    }
    for(int i=1;i<m;i++)
    {
        a[i][0].val+=a[i-1][0].val;
        a[i][0].dir='D';
    }
    for(int i=1;i<n;i++)
    {
        a[0][i].val+=a[0][i-1].val;
        a[0][i-1].dir='R';
    }
    for(int i=1;i<m;i++)
        for(int j=1;j<n;j++)
        {
            if(a[i-1][j].val<a[i][j-1].val)
            {
                a[i][j].val+=a[i-1][j].val;
                a[i][j].dir='D';
            }
            else
            {
                a[i][j].val+=a[i][j-1].val;
                a[i][j].dir='R';
            }
        }
    printf("%d\n",a[m-1][n-1].val);
    outpath(a,m-1,n-1);
}