#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum=0;
long long max=0;
int s[220][220];
int b[220][220];
char ans[220][220];
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
            ans[z][j]='0';
        }

    stp(m-1,n-1);
    printf("%d\n",b[m-1][n-1]);


    char out[5000];
    int x=m-1,y=n-1,t=m+n-2;


    while(!(x==0&&y==0))
    {
        out[t--]=ans[x][y];
        if(ans[x][y]=='R')
            y--;
        else
            x--;
    }

    for(int i=1;i<=m+n-2;i++)
        printf("%c",out[i]);

    return 0;
}

//动归
int stp(int x,int y)
{
    if(b[x][y]!=-1) return b[x][y];
    if(x==0&&y==0) return s[0][0];

    if(x==0)
    {
        if(ans[x][y]=='0') ans[x][y]='R';
        int aa=stp(x,y-1);
        int bb=stp(x-1,y);
        b[x][y]=stp(x,y-1)+s[x][y];
    }
    else if(y==0)
    {
        if(ans[x][y]=='0') ans[x][y]='D';
        int aa=stp(x,y-1);
        int bb=stp(x-1,y);
        b[x][y]=stp(x-1,y)+s[x][y];
    }
    else if(stp(x,y-1)<=stp(x-1,y))
    {
        if(ans[x][y]=='0') ans[x][y]='R';
        int aa=stp(x,y-1);
        int bb=stp(x-1,y);
        b[x][y]=stp(x,y-1)+s[x][y];
    }
    else if(stp(x,y-1)>stp(x-1,y))
    {
        if(ans[x][y]=='0') ans[x][y]='D';
        int aa=stp(x,y-1);
        int bb=stp(x-1,y);
        b[x][y]=stp(x-1,y)+s[x][y];
    }
    return b[x][y];
}



