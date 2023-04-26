#include<stdio.h>
typedef struct
{
    int v,d;
    char way;
}MAP;
MAP map[250][250];

void pr(int x,int y)
{
    if(x!=0 || y!=0)
    {
        if(map[x][y].way=='D')
        {
            pr(x-1,y);
            printf("D");
        }
        else
        {
            pr(x,y-1);
            printf("R");
        }
    }
}
int main()
{
    int m,n,i,j,k;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&map[i][j].v);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==0 && j==0)
            {
                map[i][j].d=map[i][j].v;
            }
            else if(i==0)
            {
                map[i][j].d=map[i][j].v+map[i][j-1].d;
                map[i][j].way='R';
            }
            else if(j==0)
            {
                map[i][j].d=map[i][j].v+map[i-1][j].d;
                map[i][j].way='D';
            }
            else
            {
                if(map[i-1][j].d<map[i][j-1].d)
                {
                    map[i][j].d=map[i][j].v+map[i-1][j].d;
                    map[i][j].way='D';
                }
                else
                {
                    map[i][j].d=map[i][j].v+map[i][j-1].d;
                    map[i][j].way='R';
                }
                
            }
        }
    }
    printf("%d\n",map[m-1][n-1].d);
    pr(m-1,n-1);
    return 0;
}