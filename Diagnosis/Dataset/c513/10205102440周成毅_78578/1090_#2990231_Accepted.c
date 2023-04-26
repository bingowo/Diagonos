#include <stdio.h>
#include <math.h>

int main()
{
    double k;
    while(scanf("%lf", &k) && k != 0)
    {
        double a;
        a = k * log10(k);
        a -= (int) a;
        a = pow(10, a);
        int b = (int) a;
        while (b >= 10)
        {
            b /= 10;
        }
        printf("%d\n", b);
    }
    return 0;
}