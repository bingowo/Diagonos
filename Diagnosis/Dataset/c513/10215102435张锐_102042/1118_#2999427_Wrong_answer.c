#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y;int jiao;char c;
    scanf("%d %d %d %c",&x,&y,&jiao,&c);
    int num=0;
    while(jiao>=90) {num++;jiao=jiao/90;}
    int **p=(int**)malloc(y*sizeof(int*));
    for(int i=0;i<y;i++)
    {
        p[i]=(int*)malloc(sizeof(int)*x);
        for(int j=0;j<x;j++) scanf("%d",&p[i][j]);
    }
    if(num%4==0)
    {
        printf("%d %d\n",x,y);
        for(int i=0;i<y;i++)
        {
            for(int j=0;j<x;j++)
            {
                if(j!=x-1) printf("%d ",p[i][j]);
                else printf("%d",p[i][j]);
            }
            printf("%n");
        }
    }
    if((num%4==1&&c=='R')||(num%4==3&&c=='L'))
    {
        printf("%d %d\n",y,x);
        for(int j=0;j<x;j++)
        {
            for(int i=y-1;i>=0;i--)
            {
                if(i!=0) printf("%d ",p[i][j]);
                else printf("%d",p[i][j]);
            }
            printf("\n");
        }
    }
    if(num%4==2)
    {
        printf("%d %d\n",x,y);
        for(int i=0;i<y;i++)
        {
            for(int j=x-1;j>=0;j--)
            {
                if(j!=0) printf("%d ",p[i][j]);
                else printf("%d",p[i][j]);
            }
            printf("%n");
        }
    }
    if((num%4==3&&c=='R')||(num%4==1&&c=='L'))
    {
        printf("%d %d\n",y,x);
        for(int j=x-1;j>=0;j--)
        {
            for(int i=y-1;i>=0;i--)
            {
                if(i!=0) printf("%d ",p[i][j]);
                else printf("%d",p[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
