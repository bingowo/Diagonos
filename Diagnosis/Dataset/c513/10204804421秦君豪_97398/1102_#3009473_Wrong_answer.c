#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef long long int lli;

lli square_root(lli n)
{
    double root = n/2;
    while(abs(root*root-n)>1)
    {
        root = root-(root*root-n)/(2*root)*(1.0);

    }
    lli r=root/1;
    return root;
}



int main()
{
    lli n;scanf("%lld",&n);
    lli root =square_root(n);
    if(root*(root+1)>n) root--;

    lli x,y;
    if (root%2==0)
    {
        x=root/2;
        y=root/2*(-1);
    }
    else
    {
        x=(root-1)/2+(-1)*root;
        y=(-1)*(root-1)/2+root;
    }

    lli step=n-root*(root+1);
    if(step!=0)
    {
        if(x==0&&y==0)
        {
            y++;
        }
        if(x<0&&y>0)
        {
            y-=(step>=root+1)?root+1:step;
            x+=(step>=root+1)?step%(root+1):0;
        }
        else if (x>0&&y>0)
        {
            x-=(step>=root+1)?root+1:step;
            y-=(step>=root+1)?step%(root+1):0;
        }
        else if(x<0&&y<0)
        {
            x+=(step>=root+1)?root+1:step;
            y+=(step>=root+1)?step%(root+1):0;
        }
        else if(x>0&&y<0)
        {
            y+=(step>=root+1)?root+1:step;
            x-=(step>=root+1)?step%(root+1):0;
        }
    }
    printf("(%lld,%lld)",x,y);
}
