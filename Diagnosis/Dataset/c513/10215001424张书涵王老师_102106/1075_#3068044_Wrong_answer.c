#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elem
{
    int num;
    char dir;
};

struct elem a[10][10];

void reverse(char* s)
{
    int i,j;
    char c;
    for(i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}

void calculate_path(struct elem a[10][10],int M,int N)
{
    int i,j;
    for(i=1;i<M;i++)
    {
        a[i][0].num=a[i-1][0].num+a[i][0].num;
        a[i][0].dir='D';
    }
    for(j=1;j<N;j++)
    {
        a[0][j].num=a[0][j-1].num+a[0][j].num;
        a[0][j].dir='R';
    }
    for(i=1;i<M;i++)
    {
        for(j=1;j<N;j++)
        {
            if(a[i-1][j].num>a[i][j-1].num)
            {
                a[i][j].num=a[i][j].num+a[i][j-1].num;
                a[i][j].dir='R';
            }
            else
            {
                a[i][j].num=a[i][j].num+a[i-1][j].num;
                a[i][j].dir='D';
            }
        }
    }
}

void move_path(int r,int c,char* s,int k)
{
    if(r==0&&c==0)
        return ;
    else
    {
        if(a[r][c].dir=='D')
        {
            s[k]='D';
            move_path(r-1,c,s,k+1);
        }
        if(a[r][c].dir=='R')
        {
            s[k]='R';
            move_path(r,c-1,s,k+1);
        }
    }
}

int main()
{
    int M,N,k=0;
    scanf("%d %d",&M,&N);
    char s[1000]={0};
    int i,j;
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            scanf("%d",&a[i][j].num);
            a[i][j].dir=0;
        }
    }
    calculate_path(a,M,N);
    printf("%d\n",a[M-1][N-1].num);
    move_path(M-1,N-1,s,k);
    reverse(s);
    printf("%s\n",s);
}