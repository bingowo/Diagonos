#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    //思路：N^N=10^(N*lgN),N*lgN分为整数部分和分数部分，可以发现求第一位数字就是求10^(N*lgN的小数部分)
    double N;
    while(scanf("%lf",&N))
    {
        if((N-0)<1e-10)
            return 0;
        double mi=0,intpart,fractpart;
        mi=N*log10(N);
        fractpart=modf(mi,&intpart);
        double n;
        n=pow(10,fractpart);
        printf("%d\n",(int)n);
    }
}
