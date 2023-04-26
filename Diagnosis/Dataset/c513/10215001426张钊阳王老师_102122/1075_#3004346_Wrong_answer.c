#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum=0;
long long max=0;
int s[200][200];
int b[200][200];
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
            b[z][j]=-1; 
        }
    int sit[1][2];
    sit[0][0]=0;sit[0][1]=0;

    memset(ans,'\0',4000);




    printf("%d\n",stp(m-1,n-1));

    return 0;
}

//记忆递归型动态规划程序
int stp(int x,int y)
{
    if(b[x][y]!=-1) return b[x][y];
    if(x==0&&y==0) return s[0][0];

    if(x==0)
    {
        ans[i++]='R';
        int aa=stp(x,y-1);
        int bb=stp(x-1,y);
        b[x][y]=stp(x,y-1)+s[x][y];
    }
    else if(y==0)
    {
        ans[i++]='D';
        int aa=stp(x,y-1);
        int bb=stp(x-1,y);
        b[x][y]=stp(x-1,y)+s[x][y];
    }
    else if(stp(x,y-1)<=stp(x-1,y))
    {
        ans[i++]='R';
        int aa=stp(x,y-1);
        int bb=stp(x-1,y);
        b[x][y]=stp(x,y-1)+s[x][y];
    }
    else if(stp(x,y-1)>stp(x-1,y))
    {
        ans[i++]='D';
        int aa=stp(x,y-1);
        int bb=stp(x-1,y);
        b[x][y]=stp(x-1,y)+s[x][y];
    }
    return b[x][y];
}


