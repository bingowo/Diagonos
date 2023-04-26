#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    double modf(double x, double *intptr)用于分解浮点数
    x：要被计算的浮点数；
    intptr：一个指向整数部分的指针。
    返回值：x 的小数部分。
*/

//N^N=10^N*lg(N)    整数部分为十的倍数不影响，小数部分决定首位；

int main()
{
    double n;
    while(scanf("%lf",&n)!=EOF){
        if(n>1e-10){
            double t=n*(log(n)/log(10)),intpart;
            double fractpart=modf(t,&intpart);
            double a=pow(10,fractpart);
            modf(a,&intpart);
            printf("%.0lf\n",intpart);
        }
        else
            return 0;
    }

    return 0;
}
