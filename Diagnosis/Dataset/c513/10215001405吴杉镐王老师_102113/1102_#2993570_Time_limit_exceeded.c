#include <stdio.h>

int main()
{
    unsigned long long n;
    scanf("%llud",&n);
    unsigned long long i;
    if(n<=6)
        i=-1;
    else
    {
        for(i=0;4*i*i+10*i+6<n;i++);
        i--;
    }
    unsigned long long sum;
    long long x=0,y=0;
    if(i==-1)
        sum=n;
    else
    {
        sum=n-4*i*i-10*i-6;
        x=i+1;
        y=-i-1;
    }
    //unsigned long long l=2*i+1;
    int flag=1; //方向
    for(;sum;sum--)
    {
        if(flag==1)
            y++;
        else if(flag==2)
            x--;
        else if(flag==3)
            y--;
        else
            x++;
        if(x==-1*y || (x==y && x<0) || (y==x+1 && x>=0))
        {
            if(flag!=4)
                flag++;
            else
                flag=1;
        }
    }
    printf("(%lld,%lld)\n",x,y);
}
