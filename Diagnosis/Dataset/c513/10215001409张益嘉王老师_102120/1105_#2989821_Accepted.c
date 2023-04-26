#include <stdio.h>
#include <stdlib.h>

int zhuan10(int t[])
{
    int re=0,i;
    for(i=0;i<8;i++)
    {
        re*=2;
        re+=t[i];
    }
    return re;
}

void movecir(int t[])
{
    int i,j,mid=t[0];
    for(i=0;i<7;i++)
    {
        t[i]=t[i+1];
    }
    t[i]=mid;
}

int minlbp(int yuan[][110],int x,int y)
{
    int t[10],i,j,k=0,re,mid;
    memset(t,0,sizeof(int)*10);
    if(yuan[x-1][y-1]>=yuan[x][y]) t[k++]=1;
    else t[k++]=0;

    if(yuan[x-1][y]>=yuan[x][y]) t[k++]=1;
    else t[k++]=0;

    if(yuan[x-1][y+1]>=yuan[x][y]) t[k++]=1;
    else t[k++]=0;

    if(yuan[x][y+1]>=yuan[x][y]) t[k++]=1;
    else t[k++]=0;

    if(yuan[x+1][y+1]>=yuan[x][y]) t[k++]=1;
    else t[k++]=0;

    if(yuan[x+1][y]>=yuan[x][y]) t[k++]=1;
    else t[k++]=0;

    if(yuan[x+1][y-1]>=yuan[x][y]) t[k++]=1;
    else t[k++]=0;

    if(yuan[x][y-1]>=yuan[x][y]) t[k++]=1;
    else t[k++]=0;

    re=zhuan10(t);
    for(i=0;i<7;i++)
    {
        movecir(t);
        mid=zhuan10(t);
        if(mid<re) re=mid;
    }
    return re;


}

int main()
{
    int lie,hang;
    scanf("%d%d",&lie,&hang);
    int i,j;
    int yuan[110][110];
    int zhi[100][100];
    for(i=0;i<100;i++)
    {
        for(j=0;j<100;j++)
        {
            zhi[i][j]=0;
        }
    }

    for(i=0;i<hang;i++)
    {
        for(j=0;j<lie;j++)
        {
            scanf("%d",&yuan[i][j]);
        }
    }

    for(i=1;i<hang-1;i++)
    {
        for(j=1;j<lie-1;j++)
        {
            zhi[i][j]=minlbp(yuan,i,j);
        }
    }

    for(i=1;i<hang-1;i++)
    {
        for(j=1;j<lie-2;j++)
        {
            printf("%d ",zhi[i][j]);
        }
        printf("%d\n",zhi[i][j]);
    }
    return 0;

}
