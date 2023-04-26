#include <stdio.h>
#include <math.h>

int main()
{
    long long int n;
    scanf("%lld",&n);
    long long int i;int x=0,y=0;
    if(n==0)
    {
        printf("(%d,%d)",x,y);
        return 0;
    }
    i=sqrt(n);
    /*if(i*i>n)
    {
        i--;
    }*/
    //printf("%lld\n",i*i);
    i=(i-1)/2;
    int flag=0;
    long long int copy=(2*i+1)*(2*i+1);
    //printf("%lld",copy);
    x=i;y=i+1;
    if(copy+(2*i+1)<=n){copy=copy+(2*i+1);x=x-(2*i+1);}
    else
    {
        x=x-n+copy;
        copy=copy+n-copy;
    }
    flag=0;
    if(copy+(2*i+2)<=n){copy=copy+(2*i+2);y=y-(2*i+2);}
    else
    {
        y=y-n+copy;
        copy=copy+n-copy;
    }

    flag=0;
    if(copy+(2*i+2)<=n){copy=copy+(2*i+2);x=x+(2*i+2);}
    else
    {
        x=x+n-copy;

    }

    flag=0;
    if(copy+(2*i+2)<=n){copy=copy+(2*i+2);y=y+(2*i+2);}
    else
    {
        y=y+n-copy;
        copy=copy+n-copy;

    }


    if(copy!=n)y++;
    printf("(%d,%d)",x,y);
}
