#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int nofa;
    int nofy;
}geshu;

typedef struct
{
    geshu shang;
    geshu xia;
    geshu hou;

}station;

int main()
{

    int a,n,m,x,y;
    int re,i;
    scanf("%d%d%d%d",&a,&n,&m,&x);


    station *zhan=(station*)malloc(sizeof(station)*(n+1));

    zhan[1].shang.nofa=1;
    zhan[1].shang.nofy=0;
    zhan[1].xia.nofa=0;
    zhan[1].xia.nofy=0;
    zhan[1].hou.nofa=zhan[1].shang.nofa-zhan[1].xia.nofa;
    zhan[1].hou.nofy=zhan[1].shang.nofy-zhan[1].xia.nofy;


    zhan[2].shang.nofa=0;
    zhan[2].shang.nofy=1;
    zhan[2].xia.nofa=0;
    zhan[2].xia.nofy=1;
    zhan[2].hou.nofa=zhan[2].shang.nofa-zhan[2].xia.nofa+zhan[1].hou.nofa;
    zhan[2].hou.nofy=zhan[2].shang.nofy-zhan[2].xia.nofy+zhan[1].hou.nofy;


    for(i=3;i<=n;i++)
    {
        zhan[i].shang.nofa=zhan[i-1].shang.nofa+zhan[i-2].shang.nofa;
        zhan[i].shang.nofy=zhan[i-1].shang.nofy+zhan[i-2].shang.nofy;
        zhan[i].xia.nofa=zhan[i-1].xia.nofa;
        zhan[i].xia.nofy=zhan[i-1].xia.nofy;
        zhan[i].hou.nofa=zhan[i].shang.nofa-zhan[i].xia.nofa+zhan[i-1].hou.nofa;
        zhan[i].hou.nofy=zhan[i].shang.nofy-zhan[i].xia.nofy+zhan[i-1].hou.nofy;
    }

    y=(m-(zhan[n].hou.nofa*a))/zhan[n].hou.nofy;

    re=y*zhan[x].hou.nofy+a*zhan[x].hou.nofa;
    printf("%d",re);
    return 0;


}
