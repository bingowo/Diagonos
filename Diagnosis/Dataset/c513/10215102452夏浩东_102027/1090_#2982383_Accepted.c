#include <stdio.h>
#include <math.h>
int main()
{
    while(1){
        double N=0;
        scanf("%lf",&N);
        if((N-0)<0.001) break;
        double res = N*log10(N);
        res = res-(int)res;
        double r=pow(10,res);
        printf("%d\n",(int)r);
    }
    return 0;
}