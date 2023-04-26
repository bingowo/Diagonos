#include <stdio.h>

int main()
{
    unsigned long long n;
    scanf("%llud",&n);
    long long x=0,y=0;
    int flag=1; //方向
    for(unsigned long long i=0;i<n;i++)
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

