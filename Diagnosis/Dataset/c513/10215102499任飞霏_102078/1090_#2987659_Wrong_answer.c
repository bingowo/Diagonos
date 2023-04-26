#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double n;
    while(scanf("%lf",&n)!=EOF){
        if(n>1e-8){
            double t=n*(log(n)/log(10));
            //printf("%lf\n",t);
            double a=pow(10,t);
            //printf("%lf",a);
            int res=(int)a;
            while(res>=10)res/=10;
            printf("%d\n",res);
        }
    }

    return 0;
}
