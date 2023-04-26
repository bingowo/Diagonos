#include<stdio.h>
#include<stdlib.h>
int main()
{
    int ima[400][400],cpy[400][400];
    int wid,hei,d;
    char dir;
    scanf("%d %d %d ",&wid,&hei,&d);
    dir=getchar();
    d/=90;
    d%=4;
    if(dir=='L') d=4-d;
    for(int i=0;i<hei;i++)
    {
        for(int j=0;j<wid;j++) scanf("%d",&ima[i][j]);
    }
    if(d==0)
    {
        for(int i=0;i<hei;i++)
        {
            for(int j=0;j<wid;j++) printf("%d ",ima[i][j]);
            printf("\n");
        }
        return 0;
    }
    if(d==1)
    {
        for(int i=0;i<wid;i++)
        {
            for(int j=hei-1;j>=0;j--) printf("%d ",ima[j][i]);
            printf("\n");
        }
    }
    if(d==2)
    {
        for(int i=hei-1;i>=0;i--)
        {
            for(int j=wid-1;j>=0;j--) printf("%d ",ima[i][j]);
            printf("\n");
        }
    }
    if(d==3)
    {
        for(int i=wid-1;i>=0;i--)
        {
            for(int j=0;j<hei;j++) printf("%d ",ima[j][i]);
            printf("\n");
        }
    }
}