#include<stdio.h>
long long func(int x,int y)
{
    if(!x||!y)return 0;
    if(x>=y)return 4*y*(x/y)+func(y,x%y);
    return 4*x*(y/x)+func(x,y%x);
}
int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%lld",func(x,y));
    return 0;
}