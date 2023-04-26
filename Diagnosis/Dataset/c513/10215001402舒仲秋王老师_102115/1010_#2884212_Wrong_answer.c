#include <stdio.h>
#include <stdlib.h>
void atob(int a,int ret[])
{
    int i,b;
    for(i=0;i<10;i++) ret[i]=0;
    for(i=0;a!=0;i++)
    {
        b=a%2;
        ret[i]=b;
        a/=2;
    }
}

int main()
{
    char c[505][3];int i=0,j,qb,lx,ret[10],l=0;
    for(i=0;i<505;i++) for(j=0;j<3;j++) c[505][3]=-1;
    for(i=0;;i++)
    {
        for(j=0;(c[i][j]=getchar())!=EOF;j+=3);
        if(j!=3&&c[i][j]==-1) break;
    }
    qb=i;lx=j;l=i*3+j;printf("%d",l);
    /*atob(l,ret);printf("0001");
    for(i=0;i<10;i++) printf("%d",ret[9-i]);
    for(i=0;i<qb;i++)
    {
        int sum=100*(c[i][0]-'0')+10*(c[i][1]-'0')+c[i][2]-'0';
        atob(sum,ret);
        for(j=0;j<10;j++) printf("%d",ret[9-j]);
    }
    if(lx==0);
    //{
    //   int sum=100*c[qb][0]+10*c[qb][1]+c[i][2];
    //   atob(sum,ret);
    //   for(j=0;j<10;j++) printf("%d",ret[9-j]);
    //}
    else if(lx==2)
    {
        int sum=10*(c[qb][0]-'0')+c[qb][1]-'0';
        atob(sum,ret);
        for(j=0;j<7;j++) printf("%d",ret[6-j]);
    }
    else if(lx==1)
    {
        int sum=c[qb][0]-'0';
        atob(sum,ret);
        for(j=0;j<4;j++) printf("%d",ret[3-j]);
    }*/
    return 0;
}
