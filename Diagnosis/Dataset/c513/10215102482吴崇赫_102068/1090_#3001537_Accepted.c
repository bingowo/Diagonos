#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    double n;
    scanf("%lf\n",&n);
    while(n){
        double lo;
        lo=n*log10(n);
        double loo=(int)lo;
        double t=lo-loo;
        double a=pow(10,t);
        printf("%d\n",(int)a);

        scanf("%lf\n",&n);
    }
}