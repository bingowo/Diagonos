#include<stdio.h>
#include<math.h>
int main()
{
    int x,y;
    scanf("%d",&x,&y);
    int dx=abs(x);
    int dy=abs(y);
    if((dx*dy)%4!=2)
    {
        printf("%d",-1);
    }
    return 0;
}