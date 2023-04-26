#include <stdio.h>
#include <stdlib.h>

int main()
{   long long int i,n,a[10][2];
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld%lld",&a[i][0],&a[i][1]);
    }
    for(i=0;i<n;i++)
    {
        printf("%lld\n",f(a[i][0],a[i][1]));
    }

    return 0;
}
int f(long long int x,long long int y)
{
    long long int z,z1,t=0;
    z=x^y;
    while(z)
    {
        z1=z%2;
        if(z1==1)
        {
            t++;
        }
        z=z/2;
    }
    return t;
}
