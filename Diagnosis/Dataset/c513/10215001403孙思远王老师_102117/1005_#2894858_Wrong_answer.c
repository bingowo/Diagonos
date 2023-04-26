#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int xsw(double x)
{
    int i=0;
    while((x-(int)x)!=0)
    {
        x*=10;
        i++;
    }
    return i;
}

int main()
{
    int t,T;
    scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        double x;
        int len,y;
        long long int all=0;
        double out=0.0;
        printf("case #%d:\n",t);
        scanf("%lf",&x);
        len=xsw(x);
        x*=pow(10,len);
        y=(int)x;
        for(int i=0;i<len;i++)
        {
            int a;
            a=y%10;
            out=out/8+a;
            y/=10;
        }
        printf("%lf\n",out/8);
    }
    return 0;
}
