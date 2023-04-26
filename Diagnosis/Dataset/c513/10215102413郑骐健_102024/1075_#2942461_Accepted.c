#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int num[200][200]={0};
int res  [200][200]={0};
int judge(int (*p)[200],int p1,int p2)
{
    if(p2 ==0)return 1;
    else if(p1==0)return 0;
    else if(p[p1-1][p2]<p[p1][p2-1])return 1;//向下走的情况
    else if(p[p1-1][p2]>p[p1][p2-1])return 0;//向右走的情况
}
int main()
{
    int r,c;
    scanf("%d%d",&r,&c);
    for(int i =0;i<r;i++)
    {
        for(int z = 0;z<c;z++)
        {
            scanf("%d",&num[i][z]);
        }
    }
    res[0][0] = num[0][0];
    for(int i =1;i<c;i++)
    {
        res[0][i] = res[0][i-1]+num[0][i];
    }
    for(int q =1;q<r;q++)
    {
        res[q][0]+= res[q-1][0]+num[q][0];
    }
    for(int a=1;a<r;a++)
    {
        for(int b =1;b < c;b++)
        {
            res[a][b] = res[a-1][b]>res[a][b-1]?res[a][b-1]+num[a][b]:res[a-1][b]+num[a][b];
        }
    }
    printf("%d\n",res[r-1][c-1]);
    int p1=r-1;
    int p2 = c-1;
    char s[500];
    int n =0;
    while(p1!=0||p2!=0)
    {
        if(judge(res,p1,p2))
        {
            s[n++] ='D';
            p1-=1;

        }
        else
        {
            s[n++] ='R';
            p2-=1;
        }
    }
    for(int k=n-1;k>=0;k--)
        printf("%c",s[k]);

    return 0;
}

