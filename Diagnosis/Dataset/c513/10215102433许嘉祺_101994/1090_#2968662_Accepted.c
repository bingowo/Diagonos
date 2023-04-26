#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
int fun(double x){
    x=x*log10(x);
    double b;
    x=modf(x,&b);
    x=pow(10.0,x);
    x=modf(x,&b);
    return (int)b;
}

int main()
{
    double a;
    while (scanf("%lf",&a)!=EOF){

        if (a-0.0<1e-10) return 0;
        printf("%d\n",fun(a));
    }
    return 0;
}
