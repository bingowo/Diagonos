#include <stdio.h>

int f(int x,int y);
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%d\n",f(x,y));

    }
}
int f(int x,int y)
{
    int ans=0,dx,dy;
    for(int i=0;i<32;i++)
    {
        dx=x&1;
        dy=y&1;
        ans=dx^dy?ans+1:ans;
        x=x>>1;
        y=y>>1;
    }
    return ans;
}