#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    long long x,y;scanf("%lld %lld",&x,&y);
    int i,j,step=0,flag=0;
    for(i=0;(x!=0||y!=0)&&flag==0;i++)
    {
        if(abs(x%2)==1&&abs(y%2)==0&&flag==0)
        {
            if(x-1==0&&y==0||x+1==0&&y==0)
            {
                step++;if(x==1)x--;else x++;
            }
            else if(abs((x-1)/2%2)!=abs(y/2%2)&&flag==0)
            {
                x--;x/=2;y/=2;step++;
            }
            else if(abs((x+1)/2%2)!=abs(y/2%2)&&flag==0)
            {
                x++;x/=2;y/=2;step++;
            }
            else flag=-1;
        }
        else if(abs(x%2)==0&&abs(y%2)==1&&flag==0)
        {
            if(x==0&&(y==1||y==-1))
            {
                step++;if(y==1)y--;else y++;
            }
            else if(abs((y-1)/2%2)!=abs(x/2%2)&&flag==0)
            {
                y--;x/=2;y/=2;step++;
            }
            else if(abs((y+1)/2%2)!=abs(x/2%2)&&flag==0)
            {
                y++;x/=2;y/=2;step++;
            }
            else flag=-1;
        }
        else flag=-1;
    }
    if(flag==0)printf("%d",step);
    else printf("-1");
}
