#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double n=1;
    while(n)
    {
        scanf("%lf",&n);
        if(n!=0)
        {
            double x=n*log10(n);
            double intpart,fracpart=modf(x,&intpart);
            double res=pow(10,fracpart);
            double resint,resfrac=modf(res,&resint);
            printf("%.0lf\n",resint);
        }
    }

    return 0;
}
