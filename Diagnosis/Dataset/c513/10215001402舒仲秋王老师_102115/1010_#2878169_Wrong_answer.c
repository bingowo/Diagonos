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
    char c[505][3];int i=0,j,qb,lx,ret[10],l;
    for(i=0;i<505;i++) for(j=0;j<3;j++) c[505][3]='0';
    for(i=0;;i++)
    {
        for(j=0;((c[i][j]=getchar())!=EOF)&&(j<3); j++);
        if(j!=3) if(c[i][j]==EOF) break;

    }
    qb=i;lx=j;l=i*3+j;
    atob(l,ret);printf("0001");
    for(i=0;i<10;i++) printf("%d",ret[9-i]);
    
    return 0;
}