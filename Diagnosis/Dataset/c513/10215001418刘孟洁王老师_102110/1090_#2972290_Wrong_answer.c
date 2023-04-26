#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    double a;
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n == 0)break;
        if(n%10 == 0){printf("1\n");continue;}
        a = n*log10(n);
        while(a >= 1)
        {
            a /= 10;
        }
        a *= 10;
        printf("%.0lf\n",a);
    }
    return 0;
}