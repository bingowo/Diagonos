#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {int val; char dir;} wa;
void path(wa a[][501],int m,int n)
{
    int i,j;
    for(i=1;i<m;i++)
    {
        a[i][0].val+=a[i-1][0].val;
        a[i][0].dir='D';
    }
    for(i=1;i<n;i++)
    {
        a[0][i].val+=a[0][i-1].val;
        a[0][i].dir='R';
    }
    for(i=1;i<m;i++)
    {
        for(j=1;j<n;j++)
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
    }
}
void output(wa a[][501],int r,int c)
{
    if(r==0&&c==0)
        return;
    if(a[r][c].dir=='D')
    {
        output(a,r-1,c);
        putchar('D');
    }
    else
    {
        output(a,r,c-1);
        putchar('R');
    }
}
int main()
{
    wa a[501][501];
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
    path(a,m,n);
    printf("%d\n",a[m-1][n-1].val);
    output(a,m-1,n-1);
    return 0;
}
