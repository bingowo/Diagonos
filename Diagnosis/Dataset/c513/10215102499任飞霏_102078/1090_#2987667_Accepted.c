#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double n;
    while(scanf("%lf",&n)!=EOF){
        if(n>1e-10){
            double t=n*(log(n)/log(10)),intpart;
            //printf("%lf\n",t);
            double fractpart=modf(t,&intpart);
            double a=pow(10,fractpart);
            //printf("%lf",a);
            modf(a,&intpart);
            printf("%.0lf\n",intpart);
        }
        else
            return 0;
    }

    return 0;
}
