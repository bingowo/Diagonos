#include <stdio.h>
#include <stdlib.h>

struct el
{
    int vl;
    char di;
};
void outp(struct el a[][200],int r,int c);

int main()
{
    int m,n,i,j;
    scanf("%d%d",&m,&n);
    struct el a[200][200];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j].vl);
        }
    }
    for(i=0,j=1;j<n;j++)
    {
        a[i][j].vl+=a[i][j-1].vl;
        a[i][j].di='R';
    }
    for(i=1,j=0;i<m;i++)
    {
        a[i][j].vl+=a[i-1][j].vl;
        a[i][j].di='D';
    }
    for(i=1;i<m;i++)
    {
        for(j=1;j<n;j++)
        {
            if(a[i][j-1].vl>a[i-1][j].vl)
            {
                a[i][j].vl+=a[i-1][j].vl;
                a[i][j].di='D';
            }
            else
            {
                a[i][j].vl+=a[i][j-1].vl;
                a[i][j].di='R';
            }
        }
    }
    printf("%d\n",a[m-1][n-1].vl);
    outp(a,m-1,n-1);
    return 0;
}

void outp(struct el a[][200],int r,int c)
{
    if(r==0&&c==0)
        return;
    if(a[r][c].di=='D')
    {
        outp(a,r-1,c);
        putchar('D');
    }
    else
    {
        outp(a,r,c-1);
        putchar('R');
    }
}
