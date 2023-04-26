#include <stdio.h>

typedef struct
{
    long long advance;
    long long remain;
    long long speed;
    double t;
}A;

int main()
{
    long d,n;
    scanf("%lld",&d);
    scanf("%d",&n);
    A C[1010];
    for(int i = 0; i < n; i++)
    {
        scanf("%lld %lld",&C[i].advance,&C[i].speed);
        C[i].t = (double)(d - C[i].advance) / (double)(C[i].speed);
    }
    double t = 0;
    double speed;
    for(int i = 0; i < n; i++)
    {
        if(t < C[i].t)
        {
            t = C[i].t;
        }
    }
    speed = d / t;
    printf("%.6f",speed);
    return 0;
}
