#include <stdio.h>
#include <math.h>

int recur(int x,int y)
{
    if (x==y) return 1;
    else if (x<y) return 0;
    else return 2*recur(x-1,y)+pow(2,x-y-1)-recur(x-y-1,y);
}

int main()
{
    int x,y;
    while (scanf("%d %d",&x,&y)!=EOF)
    {
        if (x==-1&&y==-1) break;
        printf("%d\n",recur(x,y));
    }
    return 0;
}