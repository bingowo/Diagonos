#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    long long n;
    scanf("%lld",&n);
    double m=sqrt(n);
    long long int k=(long long int)m;
    long long int x,y,x0,y0;
    if((m-k)>0.5) k+=1;
    //printf("%d\n",k);
    if(k%2==1)
    {
        x0=k/2;y0=x0+1;
        //printf("%d %d\n",x0,y0);
        if(k*k>=n)
        {
            x=x0;y=y0-(k*k-n);
        }
        else
        {
            y=y0;x=x0-(n-k*k);
        }
    }
    else
    {
        x0=-k/2;y0=x0;
        if(k*k>n)
        {
            x=x0;y=y0+(k*k-n);
        }
        else
        {
            y=y0;x=x0+(n-k*k);
        }
    }
    printf("(%lld,%lld)",x,y);
    return 0;
}
