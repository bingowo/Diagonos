#include <stdio.h>
#include <stdlib.h>

int com(int a)
{
    int d=1,num=0;
    for(int i=0;i<64;i++)
    {
        if(a&d)num++;
        d=d<<1;
    }
    return num;
}

int main()
{
    int T,x,y;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d %d",&x,&y);
        if(com(x)>=com(y))printf("%d",com(x)-com(y));
        else printf("%d",com(y)-com(x));
    }
    return 0;
}
