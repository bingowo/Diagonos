#include <stdio.h>

int farming(int x,int y)
{
    static int spend = 0;
    if (x==0||y==0) return spend;
    if (x>=y) {x^=y; y^=x; x^=y;}
    spend += x*4;
    y -= x;
    return farming(x,y);
}

int main()
{
    int x,y;
    scanf("%d %d",&x,&y);
    printf("%d\n",farming(x,y));
    return 0;
}