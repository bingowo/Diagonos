#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void path(long long x,long long y,int k)
{
    if(k>0)
    {
        long long d=(1LL<<(k-1));
        if(llabs(x)> llabs(y))
        {
            if(x>0)
            {
                path(x-d,y,k-1);
                printf("%c",'E');
            }
            else
            {
                path(x+d,y,k-1);
                printf("%c",'W');
            }
        }
        else
        {
            if(y>0)
            {
                path(x,y-d,k-1);
                printf("%c",'N');
            }
            else
            {
                path(x,y+d,k-1);
                printf("%c",'S');
            }
        }
    }
}
int main()
{
    long long x,y;
    int result=0;
    scanf("%lld%lld",&x,&y);
    if((llabs(x)+ llabs(y))%2==0&&(x!=0||y!=0))
    {
        printf("%d",-1);
    }
    else
    {
        for(int k=1;k<42;k++)
        {
            if((llabs(x)+ llabs(y)+1)<=pow(2,k)&&(llabs(x)+ llabs(y)+1)> pow(2,k-1))
            {
                result=k;
                break;
            }
        }
        printf("%d\n",result);
        path(x,y,result);
    }
    return 0;
}
