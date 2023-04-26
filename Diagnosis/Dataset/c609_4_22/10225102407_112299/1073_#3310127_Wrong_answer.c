#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void path (long long x,long long y,int k)
{
    if (k)
    {
        long long d= (1LL << (k-1));
        if (llabs(x)>llabs(y))
        {
            if (x>0)
            {
                path (x-d,y,k-1);
                printf("E");
            }
            else
            {
                path (x+d,y,k-1);
                printf ("W");
            }
        }
        else
        {
            if (y>0)
            {
                path (x,y-d,k-1);
                printf("N");
            }
            else
            {
                path (x,y+d,k-1);
                printf ("S");
            }
        }
    }
}
int main()
{
    long long int a,b;
    scanf("%lld %lld",&a,&b);
    if ((llabs(a)+llabs (b))%2!=0)
    {
        int c;
        c=(int)log(a+b)/log (2) ;
        c=c+1;
        printf ("%d\n",c );
        path(a,b,c);

    }
    else printf ("-1");
    return 0;
}


