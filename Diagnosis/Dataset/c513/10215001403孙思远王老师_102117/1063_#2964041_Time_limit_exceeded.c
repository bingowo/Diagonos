#include <stdio.h>
#include <stdlib.h>

int zh(int x,int y,int all)
{
    int mi,ma;
    if(x>y)
    {
        ma=x;
        mi=y;
    }
    else if(x<y)
    {
        ma=y;
        mi=x;
    }
    else
    {
        all+=4*x;
        return all;
    }
    all+=4*mi;
    zh(mi,ma-mi,all);
}
int main()
{
    int x,y,all=0;
    scanf("%d%d",&x,&y);
    all=zh(x,y,all);
    printf("%d",all);
    return 0;
}
