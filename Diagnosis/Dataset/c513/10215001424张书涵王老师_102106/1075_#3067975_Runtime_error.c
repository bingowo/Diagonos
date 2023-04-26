#include <stdio.h>
#include <stdlib.h>

int lenth,lenth1;
char c[1000]={0};
int M,N;

void move(int i,int j,int a[10][20],char* c1,int k)
{
    if(i==(M-1)&&j==(N-1))
    {
        if(lenth1<lenth)
        {
            lenth=lenth1;
            int p;
            for(p=0;c1[p];p++)
                c[p]=c1[p];
        }
        return;
    }
    else
    {
        if(i==M-1)
        {
            c1[k]='R';
            lenth1=lenth1+a[i][j+1];
            move(i,j+1,a,c1,k+1);
        }
        if(j==N-1)
        {
            c1[k]='D';
            lenth1=lenth1+a[i+1][j];
            move(i+1,j,a,c1,k+1);
        }
        else
        {
            int p;
            for(p=0;p<=1;p++)
            {
                if(p==0)
                {
                    c1[k]='R';
                    lenth1=lenth1+a[i][j+1];
                    move(i,j+1,a,c1,k+1);
                }
                else
                {
                    c1[k]='D';
                    lenth1=lenth1+a[i+1][j];
                    move(i+1,j,a,c1,k+1);
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d",&M,&N);
    int a[20][20]={0};
    char c1[1000]={0};
    int i,j,k=0;
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
            scanf("%d",&a[i][j]);
    }
    for(j=0;j<N;j++)
        lenth=lenth+a[0][j];
    for(i=1,j=N-1;i<M;i++)
        lenth=lenth+a[i][j];
    for(i=0;i<(M-1);i++)
        c[i]='R';
    for(j=0;j<(N-1);j++,i++)
        c[i]='D';
    lenth1=a[0][0];
    move(0,0,a,c1,k);
    printf("%d\n%s",lenth,c);
}