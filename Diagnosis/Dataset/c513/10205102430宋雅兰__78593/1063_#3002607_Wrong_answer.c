#include<stdio.h>
int func(int x,int y)
{
    if(!x||!y)return 0;
    if(x>=y)return 4*y*(x/y)+func(y,x%y);
    return func(y,x);
}
int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%d",func(x,y));
    return 0;
}