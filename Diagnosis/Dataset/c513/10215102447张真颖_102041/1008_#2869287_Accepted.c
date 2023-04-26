#include <stdio.h>
#include <stdlib.h>

int f(int x,int y)
{
    int n=0;
    int tmp=x^y;
    while(tmp)
    {
        tmp=tmp&(tmp-1);
        n++;
    }
    return n;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%d\n",f(x,y));
    }
    return 0;
}
