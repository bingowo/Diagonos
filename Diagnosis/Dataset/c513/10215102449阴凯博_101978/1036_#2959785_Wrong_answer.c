#include <stdio.h>
#include <stdlib.h>

void printsteps(long long x,long long y)
{
    int i=0;
    unsigned long long a1,b1;
    a1=(unsigned long long)(x>0)?x:-x;
    b1=(unsigned long long)(y>0)?y:-y;
    unsigned long long m=a1+b1,m1=m;
    while (m1)
    {
        m1=m1/2;
        i++;
    }
    if (m==0) printf("0");
    else if (m%2==1)
    {
        printf("%d\n",i);
        for (int j=0;j<i;j++)
        {
            if (x%2!=0)
            {
                y=y/2;
                if (x+1==0)
                {
                    x=(x+1)/2;
                    printf("W");
                }
                else if (x-1==0)
                {
                    x=(x-1)/2;
                    printf("E");
                }
                else if (((x+1)/2 +y)%2!=0)
                {
                    x=(x+1)/2;
                    printf("W");
                }

                else if (((x-1)/2 +y)%2!=0)
                {
                    x=(x-1)/2;
                    printf("E");
                }


            }
            else if (y%2!=0)
            {
                x=x/2;
                if (y+1==0)
                {
                    y=(y+1)/2;
                    printf("S");
                }
                else if (y-1==0)
                {
                    y=(y-1)/2;
                    printf("N");
                }
                else if (((y+1)/2 +x)%2!=0 )
                {
                    y=(y+1)/2;
                    printf("S");
                }
                else if (((y-1)/2 +x)%2!=0 )
                {
                    y=(y-1)/2;
                    printf("N");
                }

            }
        }
    }
    else printf("-1");


}

int main()
{
    long long  x,y;
    scanf("%lld %lld",&x,&y);
    printsteps(x,y);
    return 0;
}
