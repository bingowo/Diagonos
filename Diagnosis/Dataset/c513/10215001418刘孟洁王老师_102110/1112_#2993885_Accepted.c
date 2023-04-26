#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cas,i,j,n;
    long long w[1007] = {0},x[1007] = {0},y[1007] = {0},z[1007] = {0};
    scanf("%d",&cas);
    for(i = 0; i < 1007; i++){z[i] = 1;y[i] = i/2;}
    x[3] = 1;
    for(i = 4; i < 1007; i++)
    {
        for(j = 1; j <= i/3; j++)
        {
            x[i] += z[i-j*3] + y[i-j*3];//x不为0，是n-j倍3的y的个数加n-j倍3的z的个数的和；
        }
    }
    w[4] = 1;
    for(i = 5; i < 1007; i++)
    {
        for(j = 1; j <= i/4; j++)
        {
            w[i] += x[i-j*4] + y[i-j*4] + z[i-j*4];//w同上；
        }
    }
    for(i = 0; i < cas; i++)
    {
        scanf("%d",&n);
        printf("%lld\n",z[n]+y[n]+x[n]+w[n]);
    }
    return 0;
}