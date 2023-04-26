#include <stdio.h>
#include <stdlib.h>

int sum=0;
long long max=0;
int s[200][200];
char ans[4000];
int step;
int i=0;
int main()
{
    int m,n;
    scanf("%d %d\n",&m,&n);

    step=m+n-2;

    for(int z=0;z<m;z++)
        for(int j=0;j<n;j++)
        {
            scanf("%d",&s[z][j]);
        }
    int sit[1][2];
    sit[0][0]=0;sit[0][1]=0;
    int output=stp(m-1,n-1);

    printf("%d\n",output);



    return 0;
}


int stp(int x,int y)
{
    if(x==0&&y==0) return s[0][0];
    else if(x==0)
    {
        return stp(x,y-1)+s[x][y];
    }
    else if(y==0)
    {
        return stp(x-1,y)+s[x][y];
    }
    else if(stp(x,y-1)<=stp(x-1,y))
    {
        return stp(x,y-1)+s[x][y];
    }
    else if(stp(x,y-1)>stp(x-1,y))
    {
        return stp(x-1,y)+s[x][y];
    }
}


