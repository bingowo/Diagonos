#include <stdio.h>
#include <stdlib.h>
int sum;
void f(int **p,int x,int y,int temp,int x1,int y1)
{
    if(x1>=x||y1>=y) return ;
    temp+=p[x1][y1];
    if(x1==x-1&&y1==y1-1)
    {
        if(temp<sum) sum=temp;
    }
    else
    {
        f(p,x,y,temp,x1+1,y1);
        f(p,x,y,temp,x1,y1+1);
    }
}
int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    int **p=(int **)malloc(sizeof(int*)*x);
    for(int i=0;i<x;i++)
    {
        p[i]=(int*)malloc(sizeof(int)*y);
        for(int j=0;j<y;j++) scanf("%d",&p[i][j]);
    }
    sum=p[0][0];int x1=0,y1=0;char s[100];int q=0;
    while(x1!=x-1||y1!=y-1)
    {
        if(x1<x-1&&y1<y-1)
        {
            if(p[x1+1][y1]<p[x1][y1+1])
            {
                x1+=1;sum+=p[x1][y1];s[q++]='D';
            }
            else if(p[x1+1][y1]>p[x1][y1+1])
            {
                y1+=1;sum+=p[x1][y1];s[q++]='R';
            }
        }
        else if(x1+1>=x)
        {
            y1++;sum+=p[x1][y1];s[q++]='R';
        }
        else if(y1+1>=y)
        {
            x1++;sum+=p[x1][y1];s[q++]='D';
        }
    }
    int temp=0;x1=0,y1=0;
    f(p,x,y,temp,x1,y1);
    printf("%d\n",sum);
    for(int i=0;i<q;i++) printf("%c",s[i]);
    for(int i=0;i<x;i++) free(p[i]);
    free(p);
    return 0;
}
