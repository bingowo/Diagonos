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
    i=(i-1)/2;
    int flag=0;
    long long int copy=(2*i+1)*(2*i+1);
    //printf("%lld",copy);
    x=i;y=i+1;
    if(copy+(2*i+1)<=n){copy=copy+(2*i+1);x=x-(2*i+1);}
    else
    {
        while(flag<(2*i+1)&&(copy!=n))
    {
        flag++;
        x--;
        copy++;
    }
    }

    //printf("(%d,%d)\n",x,y);
    //printf("%lld",copy);

    flag=0;
    if(copy+(2*i+2)<=n){copy=copy+(2*i+2);y=y-(2*i+2);}
    else
    {
        while(flag<(2*i+2)&&(copy!=n))
    {
        flag++;
        y--;
        copy++;
    }
    }

    flag=0;
    if(copy+(2*i+2)<=n){copy=copy+(2*i+2);x=x+(2*i+2);}
    else
    {
        while(flag<(2*i+2)&&(copy!=n))
    {
        flag++;
        x++;
        copy++;
    }
    }

    //printf("(%d,%d)",x,y);
    //printf("%lld",copy);
    flag=0;
    if(copy+(2*i+2)<=n){copy=copy+(2*i+2);y=y+(2*i+2);}
    else
    {
            while(flag<(2*i+2)&&(copy!=n))
        {
            flag++;
            y++;
            copy++;
        }
    }

    //printf("(%d,%d)",x,y);
    if(copy!=n)y++;
    printf("(%d,%d)",x,y);
}
