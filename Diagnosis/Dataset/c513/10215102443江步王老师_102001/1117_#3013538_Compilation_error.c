#include<stdio.h>
#include<math.h>

long lon#include<stdio.h>
#include<math.h>

long long count(long long x1,long long y1,long long x2,long long y2);
int main()
{
    long long x0,y0;
    long long n;
    long long x,y;
    long long min=pow(2,63);
    long long res_x=pow(2,63),res_y=pow(2,63);

    scanf("%lld %lld",&x0,&y0);
    scanf("%lld",&n);

    while(scanf("%lld %lld",&x,&y)==2)
    {
        long long d=count(x,y,x0,y0);

        if (d<min)
        {
            min=d;
            res_x=x;res_y=y;
        }
        else if (d==min)
        {
            if (x<res_x)
            {
                res_x=x;res_y=y;
            }
            else if (x==res_x && y<res_y)
            {
                res_x=x;res_y=y;
            }
        }
    }
    printf("%lld\n",min);
    printf("%lld %lld",res_x,res_y);

    return 0;
}

long long count(long long x1,long long y1,long long x2,long long y2)
{
    long long res1,res2;
    if (x1>x2)
    {
        res1=x1-x2;
    }
    else
    {
        res1=x2-x1;
    }

    if (y1>y2)
    {
        res2=y1-y2;
    }
    else
    {
        res2=y2-y1;
    }

    if (res1 > res2) return res1;
    else return res2;
}g count(long long x1,long long y1,long long x2,long long y2);
int main()
{
    long long x0,y0;
    long long n;
    long long x,y;
    long long min=pow(2,63);
    long long res_x,res_y;

    scanf("%lld %lld",&x0,&y0);
    scanf("%lld",&n);

    while(scanf("%lld %lld",&x,&y)==2)
    {
        long long d=count(x,y,x0,y0);

        if (d<min)
        {
            min=d;
            res_x=x;res_y=y;
        }
    }
    printf("%lld\n",min);
    printf("%lld %lld",res_x,res_y);

    return 0;
}

long long count(long long x1,long long y1,long long x2,long long y2)
{
    long long res1,res2;
    if (x1>x2)
    {
        res1=x1-x2;
    }
    else
    {
        res1=x2-x1;
    }

    if (y1>y2)
    {
        res2=y1-y2;
    }
    else
    {
        res2=y2-y1;
    }

    if (res1 > res2) return res1;
    else return res2;
}